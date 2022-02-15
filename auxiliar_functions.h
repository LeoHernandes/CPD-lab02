#ifndef AUXILIAR_FUNCTIONS_H_INCLUDED
#define AUXILIAR_FUNCTIONS_H_INCLUDED

int hoare(int arr[], int low, int high, int *swaps);
int lomuto(int arr[], int low, int high, int *swaps);
void swap(int* a, int* b);
int median (int arr[], int a, int b, int c) ;
int randomValue(int start, int end);
void printArray(int *arr, int length);

#endif // AUXILIAR_FUNCTIONS_H_INCLUDED
