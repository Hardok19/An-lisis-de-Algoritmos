//
// Created by harold-madriz on 20/09/24.
//
#include <chrono>
#include <iostream>
#include "BinarySearchTree.h"
#include "Lista.h"
#include "Sorter.h"
#include <random>

#ifndef PROMEDIO_H
#define PROMEDIO_H

double promedioBubbleSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 0; i < 100; ++i) {
        std::random_device rd;
        std::mt19937 gen(rd());
        int random_number = std::uniform_int_distribution<>(1, 100)(gen);
        lista.Insert(random_number);
    }

    // Medir el tiempo de ejecución
    auto start = std::chrono::high_resolution_clock::now();

    sorter.BubbleSort(lista); // Llamada al método de ordenación

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;



    // Imprimir el tiempo de ejecución
    std::cout << "Tiempo de ejecución para caso Promedio Bubblesort (nanosegundos): " << duration.count() << std::endl;
    return duration.count();
}

double promedioSelectionSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 0; i < 100; ++i) {
        std::random_device rd;
        std::mt19937 gen(rd());
        int random_number = std::uniform_int_distribution<>(1, 100)(gen);
        lista.Insert(random_number);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.SelectionSort(lista);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;


    std::cout << "Tiempo de ejecución para caso Promedio SelectionSort (nanosegundos): " << duration.count() << std::endl;
    return duration.count();
}

double promedioMergeSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 0; i < 100; ++i) {
        std::random_device rd;
        std::mt19937 gen(rd());
        int random_number = std::uniform_int_distribution<>(1, 100)(gen);
        lista.Insert(random_number);

    }


    auto start = std::chrono::high_resolution_clock::now();
    sorter.MergeSort(lista);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;


    std::cout << "Tiempo de ejecución para caso Promedio MergeSort (nanosegundos): " << duration.count() << std::endl;
    return duration.count();
}


double promedioLinkedListSearch() {
    Lista lista;

    // Insertar elementos en la lista ordenada
    for (int i = 1; i <= 100; ++i) {
        lista.InsertinO(i);
    }

    int elementoBuscado = 50;

    auto start = std::chrono::high_resolution_clock::now();
    bool encontrado = lista.Search(elementoBuscado);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;

    std::cout << "Promedio caso All Sorted LinkedList Search ";
    std::cout << "Tiempo de ejecución (nanosegundos): " << duration.count() << std::endl;
    return duration.count();
}


double promediocasoBSTInsert() {
    BinarySearchTree bst;

    for (int i = 1; i <= 100; ++i) {
        bst.insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();


    bst.insert(50);


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;

    std::cout << "Tiempo de ejecución caso Promedio BSTInsert (nanosegundos): " << duration.count() << std::endl;
    return duration.count();
}




#endif //PROMEDIO_H
