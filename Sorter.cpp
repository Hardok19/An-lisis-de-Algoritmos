//
// Created by harold-madriz on 20/09/24.
//

#include "Sorter.h"

#include <queue>


void Sorter::BubbleSort(Lista& lista) {
        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;

        if (lista.getHead() == nullptr)
            return;

        do {
            swapped = false;
            ptr1 = lista.getHead();

            while (ptr1->next != lptr) {
                if (ptr1->dato > ptr1->next->dato) {
                    std::swap(ptr1->dato, ptr1->next->dato);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }



void Sorter::SelectionSort(Lista& lista) {
    Node* head = lista.getHead();
    if (head == nullptr) return;

    Node* temp = head;

    // Recorremos la lista
    while (temp != nullptr) {
        Node* min = temp;
        Node* r = temp->next;

        // Encontrar el nodo con el valor mínimo en la sublista no ordenada
        while (r != nullptr) {
            if (r->dato < min->dato) {
                min = r;
            }
            r = r->next;
        }

        // Intercambiar los valores del nodo actual con el nodo mínimo
        if (min != temp) {
            std::swap(temp->dato, min->dato);
        }

        temp = temp->next;
    }
}
