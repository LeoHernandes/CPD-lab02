#include <random>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

void printArray(int *arr, int length){
    for(int i = 0; i < length; i++){
        cout << arr[i];
        cout << " ";
    }
    cout << "\n\n";
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int median (int arr[], int a, int b, int c) {
    if ((arr[a] <= arr[b]) && (arr[b] <= arr[c])) return b;  // a b c
    if ((arr[a] <= arr[c]) && (arr[c] <= arr[b])) return c;  // a c b
    if ((arr[b] <= arr[a]) && (arr[a] <= arr[c])) return a;  // b a c
    if ((arr[b] <= arr[c]) && (arr[c] <= arr[a])) return c;  // b c a
    if ((arr[c] <= arr[a]) && (arr[a] <= arr[b])) return a;  // c a b
    return b;                            // c b a
}

int randomValue(int start, int end){
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(start, end);
    return distr(gen);
}

int hoare(int arr[], int low, int high, int *swaps){
    int posMiddle = (low + high) / 2;
    int a = arr[low], b = arr[posMiddle], c = arr[high];
    int posMedian;

    //posMedian = median(arr, low, posMiddle, high);
    posMedian = randomValue(low, high);
    swap(&arr[low], &arr[posMedian]);
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
    swap(&arr[i], &arr[j]);
    }
    *swaps = *swaps+1;
    swap(&arr[low], &arr[j]);
    return j;
}

int lomuto(int arr[], int low, int high, int *swaps){
    int posMiddle = (low + high) / 2;
    int a = arr[low], b = arr[posMiddle], c = arr[high];
    int posMedian;

    posMedian = median(arr, low, posMiddle, high);
    //posMedian = randomValue(low, high);
    swap(&arr[low], &arr[posMedian]);
    *swaps = *swaps+1;

    int pivot = arr[low];
    int j = low+1, flag = 0;

    int i;
    for (i = low+1; i <= high; i++) {
        if (arr[i] <= pivot) {
            swap(&arr[i], &arr[j]);
            j++;
        }
    }

    swap(&arr[j-1], &arr[low]);

    return j-1;
}
