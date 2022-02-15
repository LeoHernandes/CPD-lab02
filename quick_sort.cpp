#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#include "auxiliar_functions.h"

void quicksortRec(int *arr, int posStart, int posEnd, int *swaps, int *recursions){
    if (posStart >= posEnd) return;
    //int pivot = hoare(arr, posStart, posEnd, swaps);
    int pivot = lomuto(arr, posStart, posEnd, swaps);
    quicksortRec(arr, posStart, pivot - 1, swaps, recursions);
    quicksortRec(arr, pivot + 1, posEnd, swaps, recursions);
    *recursions = *recursions+2;
}

void quicksort(int *arr, int posStart, int posEnd)
{
    int swaps = 0, recursions = 0;
    clock_t startClock, endClock;
    startClock = clock();
    quicksortRec(arr, posStart, posEnd, &swaps, &recursions);
    endClock = clock();
    cout << "TAMANHO ENTRADA " << posEnd+1 << endl;
    cout << "SWAPS " << swaps << endl;
    cout << "RECURSOES " << recursions << endl;
    cout << "TEMPO EM SEGUNDOS " << ((endClock - startClock)/(double)CLOCKS_PER_SEC) << endl;
}
