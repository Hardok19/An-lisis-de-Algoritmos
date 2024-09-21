//
// Created by harold-madriz on 20/09/24.
//

#ifndef SORTER_H
#define SORTER_H

#include "Lista.h"

class Sorter {
public:
    void BubbleSort(Lista& lista);
    void SelectionSort(Lista& lista);
    // MergeSort para listas enlazadas
    void MergeSort(Lista& lista) {
        lista.setHead(mergeSortRec(lista.getHead()));
    }


    private:
    // Función recursiva que divide y ordena la lista
    Node* mergeSortRec(Node* head) {
        // Caso base: Si la lista es vacía o tiene un solo elemento
        if (!head || !head->next) {
            return head;
        }

        // Partir la lista en dos mitades
        Node* middle = getMiddle(head);
        Node* nextToMiddle = middle->next;

        middle->next = nullptr;  // Dividir la lista

        // Llamadas recursivas para ambas mitades
        Node* left = mergeSortRec(head);
        Node* right = mergeSortRec(nextToMiddle);

        // Fusionar las dos mitades ordenadas
        return merge(left, right);
    }

    // Función para fusionar dos listas ordenadas
    Node* merge(Node* left, Node* right) {
        if (!left)
            return right;
        if (!right)
            return left;

        Node* result = nullptr;

        if (left->dato <= right->dato) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }

        return result;
    }

    // Función para obtener el nodo del medio de la lista
    Node* getMiddle(Node* head) {
        if (!head) {
            return head;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

};




#endif //SORTER_H
