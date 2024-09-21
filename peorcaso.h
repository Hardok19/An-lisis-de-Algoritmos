//
// Created by harold-madriz on 20/09/24.
//
#include <chrono>
#include <iostream>
#include "Lista.h"
#include "Sorter.h"



#ifndef PEORCASO_H
#define PEORCASO_H
void peorcasoBubbleSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 100; i > 0; --i) {
        lista.Insert(i);
    }

    // Medir el tiempo de ejecución
    auto start = std::chrono::high_resolution_clock::now();

    sorter.BubbleSort(lista); // Llamada al método de ordenación

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;



    // Imprimir el tiempo de ejecución
    std::cout << "Tiempo de ejecución para peorcasoBubblesort (nanosegundos): " << duration.count() << std::endl;
}

void peorcasoSelectionSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 100; i > 0; --i) {
        lista.Insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.SelectionSort(lista);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;


    std::cout << "Tiempo de ejecución para peorcasoSelectionSort (nanosegundos): " << duration.count() << std::endl;
}

void peorcasoMergeSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 100; i > 0; --i) {
        lista.Insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.MergeSort(lista);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;


    std::cout << "Tiempo de ejecución para peorcasoMergeSort (nanosegundos): " << duration.count() << std::endl;
}





void peorcasoLinkedListSearch() {
    Lista lista;

    // Insertar elementos en la lista ordenada
    for (int i = 1; i <= 100; ++i) {
        lista.InsertinO(i); // Asumiendo que Insert mantiene la lista ordenada
    }

    int elementoBuscado = 101;

    auto start = std::chrono::high_resolution_clock::now();
    bool encontrado = lista.Search(elementoBuscado); // Método de búsqueda
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;

    std::cout << "Peor caso All Sorted LinkedList Search (Elemento no encontrado) " ;
    std::cout << "Tiempo de ejecución (nanosegundos): " << duration.count() << std::endl;
}

void peorcasoBSTInsert() {
    BinarySearchTree bst;

    for (int i = 1; i <= 100; ++i) {
        bst.insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();


    bst.insert(101);


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;

    std::cout << "Tiempo de ejecución Peorcaso BSTInsert (nanosegundos): " << duration.count() << std::endl;
}














#endif //PEORCASO_H
