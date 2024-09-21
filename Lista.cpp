//
// Created by harold-madriz on 20/09/24.
//

#include "Lista.h"

#include <cstdio>
#include <iostream>
#include <ostream>


void Lista::Insert(int dato) {
    Node *newNode = new Node(dato);
    if (head == nullptr) {
        head = newNode;  // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    } else {
        Node *curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;  // Mover al siguiente nodo
        }
        curr->next = newNode;  // Añadir el nuevo nodo al final
    }
}
void Lista::InsertinO(int dat) {
    Node *newNode = new Node(dat);


    if (head == nullptr || head->dato > dat) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *curr = head;
        // Buscar la posición correcta para el nuevo nodo
        while (curr->next != nullptr && curr->next->dato < dat) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}





void Lista::Delete(int dato) {
    Node *curr = head;
    while (curr != nullptr && curr->dato == dato) {
        Node *temp = curr;
        head = curr->next;
        curr = curr->next;
        delete temp;
    }

    while (curr != nullptr) {
        if (curr->next != nullptr && curr->next->dato == dato) {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}


bool Lista::Search(int dato) {
    Node *curr = head;
    int i = 1;
    while(curr != nullptr) {
        if(curr->dato == dato) {
            //std::cout << "El dato " << dato <<" se encuentra en la posición: " << i << std::endl;
            return true;
        }
        i++;
        curr = curr->next;
    }
    return false;
}

void Lista::print() {
Node *curr = head;
    while(curr != nullptr) {
        printf("%d ", curr->dato);
        curr = curr->next;
    }
    std::cout << std::endl;
}
