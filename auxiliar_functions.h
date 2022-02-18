#ifndef AUXILIAR_FUNCTIONS_H
#define AUXILIAR_FUNCTIONS_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <math.h>

/* Prints on standard output stream the current status of an array. The values are separeted with commas.
 * Inputs:
 *      int *arr = array of numbers to be printed
 *      int length = array size
 */
void printArray(int *arr, int length);

/* Tests if a array of numbers is sorted in ascending order
 * Inputs:
 *      int *arr = array of numbers to be analysed
 *      int length = array size
 * Output:
 *      bool = true, if the array is sorted
 *             false, if the array is not sorted
 */
bool sorted(int *arr, int length);

/* Finds the median value position between three values in an array
 * Inputs:
 *      int arr[] = array of integers
 *      int a = first value index
 *      int b = second value index
 *      int c = third value index
 * Output:
 *      int = median value index
 */
int medianPos(int arr[], int a, int b, int c);

/* Return a random number in the closed interval [minValue, maxValue]
 * Inputs:
 *      int minValue = interval bottom value
 *      int maxValue = interval upper value
 * Output:
 *      int = random number
 */
int randomValue(int minValue, int maxValue);

/* Swap the values of two elements in an integer array
 * Inputs:
 *      int *a = first element pointer
 *      int *b = second element pointer
 */
void swapValues(int* a, int* b);

/* Choose the type of quicksort algorithm
 * Inputs:
 *      int algorithmChoice = 1, hoare's partition, median pivot
 *                            2, lomuto's partition, median pivot
 *                            3, hoare's partition, random pivot
 *                            4, lomuto's partition, random pivot
 *      bool *hoare = pointer to partition choice
 *      bool *randomPivot = pointer to pivot choice
 */
void quickSortType(int algorithmChoice, bool *hoare, bool *randomPivot);

#endif //AUXILIAR_FUNCTIONS_H
