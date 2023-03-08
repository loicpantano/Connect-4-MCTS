//
// Created by loicp on 27/02/2023.
//

#ifndef NOUVEAU_DOSSIER_TREENODE_HPP
#define NOUVEAU_DOSSIER_TREENODE_HPP


#include "GameState.hpp"
#include <vector>
#include <memory>

class TreeNode {
public:
    GameState gameState;
    std::vector<TreeNode*> children;
    int move;
    int visits = 1;
    int score = 0;
    TreeNode * parent = nullptr;
    explicit TreeNode(GameState gameState);
    TreeNode(GameState gameState, int move, TreeNode * parent);
    TreeNode();


    TreeNode * getBestChild();
    int getSimulations();
    bool isLeaf();
    double getReward();
    bool isTerminal();
    bool isFull();
    Color getWinner();
    double getUCT();
    void expand();
    void expand(TreeNode* node);
    int getMove() const;
    void printTree();
    int depth();
    void backpropagate(double reward);

    int simulate();
};


#endif //NOUVEAU_DOSSIER_TREENODE_HPP
