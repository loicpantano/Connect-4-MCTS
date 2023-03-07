//
// Created by loicp on 27/02/2023.
//

#include <cmath>
#include <iostream>
#include "bot/MCTS/TreeNode.hpp"

TreeNode::TreeNode(GameState gameState): gameState(gameState),move(-1) {

}

TreeNode::TreeNode(GameState gameState, int move): gameState(gameState),move(move) {

}

TreeNode::TreeNode() {

}


bool TreeNode::isLeaf() {
    return gameState.isTerminal();
}

TreeNode * TreeNode::getBestChild() {
    int best_child = 0;
    double best_uct = std::numeric_limits<double>::lowest();

    for(int i = 0; i < children.size(); i++) {
        double uct = children[i]->getUCT();
        if(children[i]->isFull()) uct = -100;
        if(gameState.playerColor == gameState.turnColor) {
            if (uct > best_uct) {
                best_uct = uct;
                best_child = i;
            }
        } else {
            if (uct < best_uct) {
                best_uct = uct;
                best_child = i;
            }
        }
    }
    return children[best_child];
}

double TreeNode::getUCT() {
    double c = 1.41;
    TreeNode* child_node = this;
    double w_i = child_node->getReward();
    double n_i = child_node->getSimulations();
    double N = this->getSimulations();

    return (w_i / n_i) + c * sqrt(log(N) / n_i);
}


int TreeNode::getSimulations() {
    if(this->isLeaf())
        return 1;
    int simulations = 1;
    for(TreeNode* child : children) {
        simulations += child->getSimulations();
    }
    return simulations;
}

double TreeNode::getReward() {

    if (isTerminal()) {
        if(gameState.board.checkWin()){
            Color winner = getWinner();
            if (winner == gameState.playerColor){
                return 100;
            } else {
                return -100;
            }
        }

    } else {
        double reward = 0;
        for(TreeNode* child : children) {
            reward += child->getReward();
        }
        reward /= children.size()+1;
        return reward;
    }
}

void TreeNode::expand() {

    std::vector<int> legal_moves = gameState.getLegalMoves();
    for (int mv : legal_moves) {
        // Create a new game state by making the current move
        GameState new_state = gameState.makeMove(mv);

        // Create a new node for the new game state
        auto* new_node = new TreeNode(new_state,mv);

        // Add the new node as a child of this node
        children.push_back(new_node);
    }
}

bool TreeNode::isTerminal() {
    return gameState.isTerminal();
}

Color TreeNode::getWinner() {
    return gameState.getWinner();
}

bool TreeNode::isFull() {
    bool isFull = true;
    this->gameState.getLegalMoves().empty() ? isFull = true : isFull = false;
    for(TreeNode* child : children){
        if(!child->isFull()){
            isFull = false;
        }
    }
    return isFull;
}

int TreeNode::getMove() const {
    return move;
}

void TreeNode::printTree() {
    std::cout << "Move: " << this->move << std::endl;
    for(TreeNode* child : children){
        child->printTree();
    }

}

int TreeNode::depth() {
    int maxDepth = 0;
    for (auto child : this->children) {
        int depth = child->depth();
        if (depth > maxDepth) {
            maxDepth = depth;
        }
    }
    return maxDepth + 1;
}
