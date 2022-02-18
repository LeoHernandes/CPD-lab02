#include "quick_sort.h"

/* individual step of quickSort algorithm using hoare's partition to go through the array
 * Inputs:
 *      int arr[] = array to be sorted
 *      int low = index of the first element in partition
 *      int high = index of the last element in partition
 *      int *swaps = counts the number of values swapped in the array
 *      bool randomPivot = true, if pivot is chosen in a random index
 *                         false, if pivot is equal to median of 3 values (first element, middle element, last element)
 * Output:
 *      int = pivot index
 */
int hoare(int arr[], int low, int high, int *swaps, bool randomPivot){
    int i = low;
    int j = high + 1;
    int pivot;
    int posMiddle = (low + high) / 2;
    int posMedian;

    posMedian = randomPivot? randomValue(low, high) : medianPos(arr, low, posMiddle, high);

    swapValues(&arr[low], &arr[posMedian]);
    *swaps = *swaps+1;
    pivot = arr[low];

    while (1) {
        while (arr[++i] < pivot)
            if (i == high) break;
        while (arr[--j] > pivot)
            if (j == low) break;

        if (i >= j) break;

        swapValues(&arr[i], &arr[j]);
        *swaps = *swaps+1;
    }
    swapValues(&arr[low], &arr[j]);
    *swaps = *swaps+1;

    return j;
}

/* Individual step of quickSort algorithm using lomuto's partition to go through the array
 * Inputs:
 *      int arr[] = array to be sorted
 *      int low = index of the first element in partition
 *      int high = index of the last element in partition
 *      int *swaps = counts the number of values swapped in the array
 *      bool randomPivot = true, if pivot is chosen in a random index
 *                         false, if pivot is equal to median of 3 values (first element, middle element, last element)
 * Output:
 *      int = pivot index
 */
int lomuto(int arr[], int low, int high, int *swaps, bool randomPivot){
    int i;
    int j = low+1;
    int pivot;
    int posMiddle = (low + high) / 2;
    int posMedian;

    posMedian = randomPivot? randomValue(low, high) : medianPos(arr, low, posMiddle, high);

    swapValues(&arr[low], &arr[posMedian]);
    *swaps = *swaps+1;

    pivot = arr[low];

    for (i = low+1; i <= high; i++) {
        if (arr[i] <= pivot) {
            swapValues(&arr[i], &arr[j]);
            *swaps = *swaps+1;
            j++;
        }
    }

    swapValues(&arr[j-1], &arr[low]);
    *swaps = *swaps+1;

    return j-1;
}

/* Complete recursive quickSort algorithm using hoare's partition to go through the array
 * Inputs:
 *      int arr[] = array to be sorted
 *      int posStart = index of the first element in partition
 *      int posEnd = index of the last element in partition
 *      int *swaps = counts the number of values swapped in the array
 *      int *recursions = counts the number of recrusive calls made
 *      bool randomPivot = true, if pivot is chosen in a random index
 *                         false, if pivot is equal to median of 3 values (first element, middle element, last element)
 */
void quicksortRecHoare(int *arr, int posStart, int posEnd, int *swaps, int *recursions, bool randomPivot){
    if (posStart < posEnd){
        int pivot = hoare(arr, posStart, posEnd, swaps, randomPivot);
        quicksortRecHoare(arr, posStart, pivot - 1, swaps, recursions, randomPivot);
        quicksortRecHoare(arr, pivot + 1, posEnd, swaps, recursions, randomPivot);
        *recursions = *recursions + 2;
    }
}

/* Complete recursive quickSort algorithm using lomuto's partition to go through the array
 * Inputs:
 *      int arr[] = array to be sorted
 *      int posStart = index of the first element in partition
 *      int posEnd = index of the last element in partition
 *      int *swaps = counts the number of values swapped in the array
 *      int *recursions = counts the number of recrusive calls made
 *      bool randomPivot = true, if pivot is chosen in a random index
 *                         false, if pivot is equal to median of 3 values (first element, middle element, last element)
 */
void quicksortRecLomuto(int *arr, int posStart, int posEnd, int *swaps, int *recursions, bool randomPivot){
    if (posStart < posEnd){
        int pivot = lomuto(arr, posStart, posEnd, swaps, randomPivot);
        quicksortRecLomuto(arr, posStart, pivot - 1, swaps, recursions, randomPivot);
        quicksortRecLomuto(arr, pivot + 1, posEnd, swaps, recursions, randomPivot);
        *recursions = *recursions + 2;
    }
}

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
void quicksort(int *arr, int posStart, int posEnd, bool hoare, bool randomPivot){
    int swaps = 0, recursions = 0;
    clock_t startClock, endClock;
    startClock = clock();

    if(hoare)
        quicksortRecHoare(arr, posStart, posEnd, &swaps, &recursions, randomPivot);
    else
        quicksortRecLomuto(arr, posStart, posEnd, &swaps, &recursions, randomPivot);

    endClock = clock();

    cout << "TAMANHO ENTRADA " << posEnd+1 << endl;
    cout << "SWAPS " << swaps << endl;
    cout << "RECURSOES " << recursions << endl;
    cout << "TEMPO EM SEGUNDOS " << ((endClock - startClock)/(double)CLOCKS_PER_SEC) << endl;
}
