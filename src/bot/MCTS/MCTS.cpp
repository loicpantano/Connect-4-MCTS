//
// Created by loicp on 27/02/2023.
//

#include "bot/MCTS/MCTS.hpp"
#include <queue>
#include <iostream>
#include <chrono>

MCTS::MCTS(Board board, Color color){
    root = TreeNode(GameState(board, color));
}

void MCTS::run() {
    int numSimulations = 10000;
    int numIterations = 0;
    while (numIterations < numSimulations) {
        TreeNode *current_node = &root;

        while (!current_node->children.empty()) {
            current_node = current_node->getBestChild();
        }

        current_node->expand();
        if(!current_node->children.empty()) {
            current_node = current_node->getBestChild();
        }


        int reward;
        for(int i = 0; i < 100; i++) {
            reward = current_node->simulate();
            current_node->backpropagate(reward);
        }
        //printTree();
        numIterations++;
    }
    std::cout << "MCTS completed " << numIterations << " iterations." << std::endl;
}


int MCTS::getMove() {
    TreeNode *best_child = root.children.at(0);
    for(TreeNode* child : root.children){
        if(child->score > best_child->score){
            best_child = child;
        }
    }
    return best_child->move;
}

void MCTS::printTree() {
    std::cout << "tree:" << std::endl;
    std::queue<TreeNode*> q{{&root}};
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->getUCT() << " ";
            for (auto child : node->children) {
                q.push(child);
            }
            std::cout << "| ";
        }
        std::cout << std::endl;
    }

}


