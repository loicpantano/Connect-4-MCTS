//
// Created by loicp on 27/02/2023.
//

#ifndef NOUVEAU_DOSSIER_MCTS_HPP
#define NOUVEAU_DOSSIER_MCTS_HPP


#include "TreeNode.hpp"

class MCTS {
private:
    TreeNode root;
public:
    explicit MCTS(Board board, Color color);

    void run();

    int getMove() const;
};


#endif //NOUVEAU_DOSSIER_MCTS_HPP
