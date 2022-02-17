#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "auxiliar_functions.h"

using namespace std;

void quicksortRec(int *arr, int posStart, int posEnd, int *swaps, int *recursions);

void quicksort(int *arr, int posStart, int posEnd);

#endif //QUICK_SORT_H
