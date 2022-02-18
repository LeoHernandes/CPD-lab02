#ifndef AUXILIAR_FUNCTIONS_H
#define AUXILIAR_FUNCTIONS_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <math.h>

int hoare(int arr[], int low, int high, int *swaps);

int lomuto(int arr[], int low, int high, int *swaps);

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

#endif //AUXILIAR_FUNCTIONS_H
