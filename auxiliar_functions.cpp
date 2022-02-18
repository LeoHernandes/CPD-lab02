#include "auxiliar_functions.h"
using namespace std;

/* Prints on standard output stream the current status of an array. The values are separeted with commas.
 * Inputs:
 *      int *arr = array of numbers to be printed
 *      int length = array size
 */
void printArray(int *arr, int length){
    for(int i = 0; i < length; i++){
        cout << arr[i];
        cout << " ";
    }
    cout << "\n\n";
}

/* Tests if a array of numbers is sorted in ascending order
 * Inputs:
 *      int *arr = array of numbers to be analysed
 *      int length = array size
 * Output:
 *      bool = true, if the array is sorted
 *             false, if the array is not sorted
 */
bool sorted(int *arr, int length){
    int i = 1;

    while(i < length){
        if(arr[i] < arr[i - 1])
            return false;
        i++;
    }

    return true;
}

/* Swap the values of two elements in an integer array
 * Inputs:
 *      int *a = first element pointer
 *      int *b = second element pointer
 */
void swapValues(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

/* Finds the median value position between three values in an array
 * Inputs:
 *      int arr[] = array of integers
 *      int a = first value index
 *      int b = second value index
 *      int c = third value index
 * Output:
 *      int = median value index
 */
int medianPos(int arr[], int a, int b, int c) {
    if(arr[a] >= arr[b] && arr[a] >= arr[c]){  // if arr[a] is the bigger value
        if(arr[b] >= arr[c])                   // if arr[b] is the middle value
            return b;                          // returns b
        return c;                              // else, returns c
    }else if(arr[b] >= arr[c]){                //
        if(arr[a] >= arr[c])                   //
            return a;                          //
        return c;                              // analogue algorith
    }else{                                     //
        if(arr[a] >= arr[b])                   //
            return a;                          //
        return b;                              //
    }
}

/* Return a random number in the closed interval [minValue, maxValue]
 * Inputs:
 *      int minValue = interval bottom value
 *      int maxValue = interval upper value
 * Output:
 *      int = random number
 */
int randomValue(int minValue, int maxValue){
    return((rand() % (maxValue - minValue + 1)) + minValue);
}

/* Choose the type of quicksort algorithm
 * Inputs:
 *      int algorithmChoice = 1, hoare's partition, median pivot
 *                            2, lomuto's partition, median pivot
 *                            3, hoare's partition, random pivot
 *                            4, lomuto's partition, random pivot
 *      bool *hoare = pointer to partition choice
 *      bool *randomPivot = pointer to pivot choice
 */
void quickSortType(int algorithmChoice, bool *hoare, bool *randomPivot){
    switch(algorithmChoice){
        case 1:
            *hoare = true;
            *randomPivot = false;
            break;
        case 2:
            *hoare = false;
            *randomPivot = false;
            break;
        case 3:
            *hoare = true;
            *randomPivot = true;
            break;
        case 4:
            *hoare = false;
            *randomPivot = true;
    }
}
