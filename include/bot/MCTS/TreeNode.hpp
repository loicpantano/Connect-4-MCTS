//
// Created by loicp on 27/02/2023.
//

#ifndef NOUVEAU_DOSSIER_TREENODE_HPP
#define NOUVEAU_DOSSIER_TREENODE_HPP


#include "GameState.hpp"
#include <vector>
#include <memory>

class TreeNode {
private:
    GameState gameState;
    int move;
    int visits = 1;
    int score = 0;

    TreeNode *parent = nullptr;
    std::vector<TreeNode *> children;

    TreeNode(GameState gameState, int move, TreeNode *parent);

    double getUCT() const;

public:
    TreeNode();

    explicit TreeNode(GameState gameState);

    void expand();

    int simulate();

    void backpropagate(double reward);

    TreeNode *getBestChild() const;

    std::vector<TreeNode *> getChildren() const;

    int getMove() const;

    int getScore() const;
};


#endif //NOUVEAU_DOSSIER_TREENODE_HPP
