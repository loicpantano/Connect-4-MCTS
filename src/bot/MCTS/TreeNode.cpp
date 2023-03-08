//
// Created by loicp on 27/02/2023.
//

#include <cmath>
#include <iostream>
#include "bot/MCTS/TreeNode.hpp"

TreeNode::TreeNode(GameState gameState): gameState(gameState),move(-1) {

}

TreeNode::TreeNode(GameState gameState, int move,TreeNode * parent): gameState(gameState),move(move),parent(parent) {

}

TreeNode::TreeNode() {

}


bool TreeNode::isLeaf() {
    return gameState.isTerminal();
}

TreeNode* TreeNode::getBestChild() {
    double maxScore = -std::numeric_limits<double>::infinity();
    TreeNode* bestChild = nullptr;

    for (TreeNode* child : children) {
        double ucb1Score = child->getUCT();
        if (ucb1Score > maxScore) {
            maxScore = ucb1Score;
            bestChild = child;
        }
    }

    return bestChild;
}

double TreeNode::getUCT() {
    if (visits == 0) {
        return std::numeric_limits<double>::infinity();
    }
    return (double) score / visits + 1.41 * sqrt(log(parent->visits) / visits);
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
        auto* new_node = new TreeNode(new_state,mv, this);

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

void TreeNode::backpropagate(double value) {
    visits++;
    score += value;

    if (parent != nullptr) {
        parent->backpropagate(value);
    }
}

int TreeNode::simulate() {
    GameState gameStateCopy = gameState;

    // Randomly play out the game from the current state until a terminal state is reached
    while (!gameStateCopy.isTerminal()) {
        std::vector<int> availableMoves = gameStateCopy.getLegalMoves();
        int randomMove = availableMoves[rand() % availableMoves.size()];
        gameStateCopy = gameStateCopy.makeMove(randomMove);
    }

    // Return the score of the game from the perspective of the player whose turn it is in the current state
    Color winner = gameStateCopy.board.getWinner();
    if(winner == gameState.playerColor)
        return 1;
    else if(winner == NO)
        return 0;
    else
        return -2;
}
