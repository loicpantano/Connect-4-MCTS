//
// Created by loicp on 27/02/2023.
//

#include "bot/MCTS/MCTS.hpp"

//Constructor
MCTS::MCTS(Board board, Color color){
    root = TreeNode(GameState(board, color));
}

//Functions
void MCTS::run() {
    int numIterations = 0;
    while (numIterations < 50000) {
        TreeNode *current_node = &root;

        while (!current_node->getChildren().empty()) {
            current_node = current_node->getBestChild();
        }

        current_node->expand();
        if(!current_node->getChildren().empty()) {
            current_node = current_node->getBestChild();
        }

        for(int j  = 0; j < 100; j++){
            current_node->backpropagate(current_node->simulate());
        }
        numIterations++;
    }
}


int MCTS::getMove() const{
    TreeNode *best_child = root.getChildren().at(0);
    for(TreeNode* child : root.getChildren()){
        if(child->getScore() > best_child->getScore()){
            best_child = child;
        }
    }
    return best_child->getMove();
}




