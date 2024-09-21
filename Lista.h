//
// Created by harold-madriz on 20/09/24.
//

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

struct Node {
    int dato;
    Node* next;
    Node (int i) : dato(i), next(nullptr) {}
};

class Lista {
private:
    Node* head;

public:

    Lista(): head(nullptr) {};

    ~Lista() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Insert(int dato);

    bool Search(int dato);

    void Delete(int dato);

    void print();

    void InsertinO(int dato);

    void Clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Node* getHead() {return head;}
    void setHead(Node* newHead) {head = newHead;}
};


#endif //LISTADOBLE_H
