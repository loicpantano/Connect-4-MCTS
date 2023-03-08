//
// Created by loicp on 27/02/2023.
//

#include <cmath>
#include <iostream>
#include "bot/MCTS/TreeNode.hpp"
//Constructors
TreeNode::TreeNode(GameState gameState): gameState(gameState),move(-1) {

}

TreeNode::TreeNode(GameState gameState, int move,TreeNode * parent): gameState(gameState),move(move),parent(parent) {

}

TreeNode::TreeNode() {

}

//Functions
double TreeNode::getUCT() const {
    if (visits == 0) {
        return std::numeric_limits<double>::infinity();
    }
    return (double) score / visits + 1.41 * sqrt(log(parent->visits) / visits);
}

void TreeNode::expand() {

    std::vector<int> legal_moves = gameState.getLegalMoves();
    for (int mv : legal_moves) {
        GameState new_state = gameState.makeMove(mv);

        auto* new_node = new TreeNode(new_state,mv, this);

        children.push_back(new_node);
    }
}

int TreeNode::simulate() {
    GameState gameStateCopy = gameState;

    while (!gameStateCopy.isTerminal()) {
        std::vector<int> availableMoves = gameStateCopy.getLegalMoves();
        int randomMove = availableMoves[rand() % availableMoves.size()];
        gameStateCopy = gameStateCopy.makeMove(randomMove);
    }

    Color winner = gameStateCopy.getWinner();
    if(winner == gameState.getPlayerColor())
        return 1;
    else if(winner == NO)
        return 0;
    else
        return -2;
}

void TreeNode::backpropagate(double value) {
    visits++;
    score += value;

    if (parent != nullptr) {
        parent->backpropagate(value);
    }
}

TreeNode* TreeNode::getBestChild()  const{
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

//Getters

std::vector<TreeNode*> TreeNode::getChildren() const {
    return children;
}

int TreeNode::getScore() const {
    return score;
}

int TreeNode::getMove() const {
    return move;
}
