//
// Created by loicp on 27/02/2023.
//

#include "bot/MCTS/MCTS.hpp"
#include <queue>
#include <iostream>

MCTS::MCTS(Board board, Color color){
    root = TreeNode(GameState(board, color));
}

void MCTS::run() {
    std::cout << "expanded" << std::endl;
    int i = 0;
    while (!this->root.isFull() && root.depth() < 11) {
        TreeNode *current_node = &root;

        while (!current_node->children.empty()) {
            current_node = current_node->getBestChild();
        }

        current_node->expand();
        std::cout << root.depth() << std::endl;
        printTree();
        i++;
    }
}

int MCTS::getMove() {
    TreeNode * best_child = root.getBestChild();
    return best_child->getMove();
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


