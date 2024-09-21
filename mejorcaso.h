//
// Created by harold-madriz on 20/09/24.
//
#include <chrono>
#include <iostream>
#include "BinarySearchTree.h"
#include "Lista.h"
#include "Sorter.h"



#ifndef MEJORCASO_H
#define MEJORCASO_H



double mejorBubbleSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 0; i < 100; ++i) {
        lista.Insert(i);
    }

    // Medir el tiempo de ejecución
    auto start = std::chrono::high_resolution_clock::now();

    sorter.BubbleSort(lista);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;



    // Imprimir el tiempo de ejecución
    std::cout << "Tiempo de ejecución para Mejorcaso Bubblesort (nanosegundos): " << duration.count() << std::endl;
    return duration.count();

}

double mejorSelectionSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 0; i < 100; ++i) {
        lista.Insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.SelectionSort(lista);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;


    std::cout << "Tiempo de ejecución para Mejorcaso SelectionSort (nanosegundos): " << duration.count() << std::endl;
    return duration.count();
}

double mejorMergeSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 0; i < 100; ++i) {
        lista.Insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.MergeSort(lista);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;


    std::cout << "Tiempo de ejecución para Mejorcaso MergeSort (nanosegundos): " << duration.count() << std::endl;
    return duration.count();
}


double mejorLinkedListSearch() {
    Lista lista;

    // Insertar elementos en la lista ordenada
    for (int i = 1; i <= 100; ++i) {
        lista.InsertinO(i);
    }

    int elementoBuscado = 1;

    auto start = std::chrono::high_resolution_clock::now();
    bool encontrado = lista.Search(elementoBuscado);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;

    std::cout << "Mejor caso All Sorted LinkedList Search ";
    std::cout << "Tiempo de ejecución (nanosegundos): " << duration.count() << std::endl;
    return duration.count();
}


double mejorcasoBSTInsert() {
    BinarySearchTree bst;

    for (int i = 1; i <= 100; ++i) {
        bst.insert(i); // Inserción en orden ascendente
    }

    auto start = std::chrono::high_resolution_clock::now();


    bst.insert(1);


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;

    std::cout << "Tiempo de ejecución mejorcaso BSTInsert (nanosegundos): " << duration.count() << std::endl;
    return duration.count();
}





#endif //MEJORCASO_H
