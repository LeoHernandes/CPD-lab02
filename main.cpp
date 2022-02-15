#include <iostream>
#include <algorithm>
using namespace std;
#include "quick_sort.h"


int main() {

    int arraySize, i, j, med, controle = 0, p = 0;
    int *arr;
    int *copyArray;
    cin >> arraySize;
    int teste = 0;
    while(teste == 0){  //while not in end of file
        arr = new int[arraySize];        //dynamic arrays
        copyArray = new int[arraySize];

        for(i = 0; i < arraySize; i++){
            cin >> arr[i];               //gets all values
        }

        quicksort(arr, 0, arraySize-1);
        printArray(arr, arraySize);
        delete [] arr;          //free memory space
        delete [] copyArray;      //free memory space
        teste = 1;
        cin >> arraySize;
    }
    return 0;
}
