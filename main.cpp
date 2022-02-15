#include <iostream>
#include <algorithm>
using namespace std;
#include "quick_sort.h"


int main() {

    int arraySize, i, j, med, controle = 0, p = 0;
    int *arr;
    int *copyArray;
    cin >> arraySize;

    while(!cin.eof()){
        arr = new int[arraySize];
        copyArray = new int[arraySize];

        for(i = 0; i < arraySize; i++){
            cin >> arr[i];
        }

        quicksort(arr, 0, arraySize-1);
        delete [] arr;
        delete [] copyArray;
        cin >> arraySize;
    }
    return 0;
}
