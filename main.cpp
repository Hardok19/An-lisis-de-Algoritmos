#include <iostream>

#include "peorcaso.h"
#include "mejorcaso.h"
#include "promedio.h"

using namespace std;





int main() {
    std::cout << std::endl;


    peorcasoBubbleSort();
    peorcasoSelectionSort();
    peorcasoMergeSort();
    peorcasoLinkedListSearch();
    peorcasoBSTInsert();
    cout << "<---------------------------<---------------------------------------->--------------------------->" << endl;

    std::cout << std::endl;

    mejorBubbleSort();
    mejorSelectionSort();
    mejorMergeSort();
    mejorLinkedListSearch();
    mejorcasoBSTInsert();

    std::cout << std::endl;



    cout << "<---------------------------<---------------------------------------->--------------------------->" << endl;
    promedioBubbleSort();
    promedioSelectionSort();
    promedioMergeSort();
    promedioLinkedListSearch();
    promediocasoBSTInsert();



    std::cout << std::endl;




    return 0;
}


