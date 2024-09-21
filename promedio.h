//
// Created by harold-madriz on 20/09/24.
//
#include <chrono>
#include <iostream>

#include "Lista.h"
#include "Sorter.h"
#include <random>

#ifndef PROMEDIO_H
#define PROMEDIO_H

void promedioBubbleSort() {
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
    std::cout << "Tiempo de ejecución para Mejorcaso Bubblesort (nanosegundos): " << duration.count() << std::endl;
}

void promedioSelectionSort() {
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
}

void promedioMergeSort() {
    Sorter sorter;
    Lista lista;

    for (int i = 0; i < 100; ++i) {
        lista.Insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.MergeSort(lista);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;


    std::cout << "Tiempo de ejecución para promedio MergeSort (nanosegundos): " << duration.count() << std::endl;
}


void promedioLinkedListSearch() {
    Lista lista;

    // Insertar elementos en la lista ordenada
    for (int i = 1; i <= 100; ++i) {
        lista.InsertinO(i); // Asumiendo que Insert mantiene la lista ordenada
    }

    int elementoBuscado = 50;

    auto start = std::chrono::high_resolution_clock::now();
    bool encontrado = lista.Search(elementoBuscado);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;

    std::cout << "Promedio caso All Sorted LinkedList Search ";
    std::cout << "Tiempo de ejecución (nanosegundos): " << duration.count() << std::endl;
}


void promediocasoBSTInsert() {
    BinarySearchTree bst;

    for (int i = 1; i <= 100; ++i) {
        bst.insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();


    bst.insert(50);


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;

    std::cout << "Tiempo de ejecución mejorcaso BSTInsert (nanosegundos): " << duration.count() << std::endl;
}




#endif //PROMEDIO_H
