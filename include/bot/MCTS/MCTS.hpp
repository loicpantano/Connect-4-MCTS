//
// Created by loicp on 27/02/2023.
//

#ifndef NOUVEAU_DOSSIER_MCTS_HPP
#define NOUVEAU_DOSSIER_MCTS_HPP


#include "TreeNode.hpp"

class MCTS {
public:
    TreeNode root;
    explicit MCTS(Board board, Color color);
    void run();
    int getMove();
    void printTree();
};


#endif //NOUVEAU_DOSSIER_MCTS_HPP
