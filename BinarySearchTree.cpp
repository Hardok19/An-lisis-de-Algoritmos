//
// Created by harold-madriz on 20/09/24.
//

#include "BinarySearchTree.h"

    // Función auxiliar para insertar un nuevo valor
TreeNode* BinarySearchTree::insert(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

void BinarySearchTree::inOrderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    // Recorrido en orden: izquierda, raíz, derecha
    inOrderTraversal(node->left);
    std::cout << node->value << " ";  // Imprimir el valor del nodo
    inOrderTraversal(node->right);
}

void BinarySearchTree::printTree() {
    inOrderTraversal(root);
    std::cout << std::endl;  // Para una nueva línea al final
}
