#include <stdio.h>
#include "_insertionsort.h"

int* iSort (int A[], const int size, unsigned long* modifications) {
    int i, key;
    for (int j = 0; j < size; ++j) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
            (*modifications)++;
        }
        A[i + 1] = key;
        (*modifications)++;
    }
    return A;
}

int* _insertionsort (int array[], const int size, unsigned long* modifications) {
    return iSort(array, size, modifications);
}
