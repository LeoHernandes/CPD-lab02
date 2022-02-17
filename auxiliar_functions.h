#ifndef AUXILIAR_FUNCTIONS_H_INCLUDED
#define AUXILIAR_FUNCTIONS_H_INCLUDED

int hoare(int arr[], int low, int high, int *swaps);

int lomuto(int arr[], int low, int high, int *swaps);

void swapValues(int* a, int* b);

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

int randomValue(int start, int end);

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

#endif // AUXILIAR_FUNCTIONS_H_INCLUDED
