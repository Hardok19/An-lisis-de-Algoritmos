//
// Created by harold-madriz on 20/09/24.
//
#include <iostream>
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

struct TreeNode {
    int value;           // Valor del nodo
    TreeNode* left;     // Puntero al hijo izquierdo
    TreeNode* right;    // Puntero al hijo derecho

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};


class BinarySearchTree {
private:
    TreeNode* root;

    // Función auxiliar para insertar un nuevo valor
    TreeNode* insert(TreeNode* node, int value);

    void inOrderTraversal(TreeNode* node);

public:
    BinarySearchTree() : root(nullptr) {}


    // Función pública para insertar un nuevo valor
    void insert(int value) {
        root = insert(root, value);
    }
    void printTree();

};




#endif //BINARYSEARCHTREE_H
