#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "auxiliar_functions.h"

using namespace std;

/* QuickSort algorithm central function, running different types of array partitions and pivot choices
 * Inputs:
 *      int arr[] = array to be sorted
 *      int posStart = index of the first element in partition
 *      int posEnd = index of the last element in partition
 *      bool hoare = true, if the partition choice is hoare
 *                   false, if the partition choice is lomuto
 *      bool randomPivot = true, if pivot is chosen in a random index
 *                         false, if pivot is equal to median of 3 values (first element, middle element, last element)
 */
void quicksort(int *arr, int posStart, int posEnd, bool hoare, bool randomPivot);

#endif //QUICK_SORT_H
