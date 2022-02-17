#include <random>
#include <iostream>
#include <algorithm>
#include <math.h>

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
    if(arr[a] >= arr[b] && arr[a] >= arr[c]){
        if(arr[b] >= arr[c])
            return b;
        return c;
    }else if(arr[b] >= arr[c]){
        if(arr[a] >= arr[c])
            return a;
        return c;
    }else{
        if(arr[a] >= arr[b])
            return a;
        return b;
    }
}

int randomValue(int start, int end){
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(start, end);
    return distr(gen);
}

int hoare(int arr[], int low, int high, int *swaps){
    int posMiddle = (low + high) / 2;
    int posMedian;

    //posMedian = medianPos(arr, low, posMiddle, high);
    posMedian = randomValue(low, high);
    swapValues(&arr[low], &arr[posMedian]);
    *swaps = *swaps+1;
    int pivot = arr[low];
    int i = low;
    int j = high + 1;
    while (1) {
    while (arr[++i] < pivot)
        if (i == high) break;
    while (arr[--j] > pivot)
        if (j == low) break;

    if (i >= j) break;
    *swaps = *swaps+1;
    swapValues(&arr[i], &arr[j]);
    }
    *swaps = *swaps+1;
    swapValues(&arr[low], &arr[j]);
    return j;
}

int lomuto(int arr[], int low, int high, int *swaps){
    int posMiddle = (low + high) / 2;
    int posMedian;

    posMedian = medianPos(arr, low, posMiddle, high);
    //posMedian = randomValue(low, high);
    swapValues(&arr[low], &arr[posMedian]);
    *swaps = *swaps+1;

    int pivot = arr[low];
    int j = low+1, flag = 0;

    int i;
    for (i = low+1; i <= high; i++) {
        if (arr[i] <= pivot) {
            swapValues(&arr[i], &arr[j]);
            j++;
        }
    }

    swapValues(&arr[j-1], &arr[low]);

    return j-1;
}
