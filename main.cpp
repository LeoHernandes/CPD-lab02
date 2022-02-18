#include <iostream>
#include <algorithm>
#include <string>
#include "quick_sort.h"

using namespace std;

int main(int argc, char* argv[]) {
    int arraySize, i, algorithmChoice;
    int *arr;
    bool hoare, randomPivot;

    if(argc > 1){
        srand((unsigned)time(0));
        algorithmChoice = stoi(argv[1]);

        quickSortType(algorithmChoice, &hoare, &randomPivot);

        cin >> arraySize;

        while(!cin.eof()){
            arr = new int[arraySize];         // allocate memory space

            for(i = 0; i < arraySize; i++){
                cin >> arr[i];                // read array values
            }

            quicksort(arr, 0, arraySize - 1, hoare, randomPivot); // sort array

            delete [] arr;                    // free memory space
            cin >> arraySize;                 // get size of next array
        }
    }

    return 0;
}
