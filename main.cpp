#include <iostream>
#include <algorithm>
#include "quick_sort.h"

using namespace std;

int main() {
    int arraySize, i;
    int *arr;

    srand((unsigned)time(0));

    cin >> arraySize;

    while(!cin.eof()){
        arr = new int[arraySize];

        for(i = 0; i < arraySize; i++){
            cin >> arr[i];
        }

        quicksort(arr, 0, arraySize-1);
        delete [] arr;
        cin >> arraySize;
    }
    return 0;
}
