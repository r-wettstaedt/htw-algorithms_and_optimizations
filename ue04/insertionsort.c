#include <stdio.h>
#include "_insertionsort.h"

int *iSort (int A[], const int size) {
    int i, key;
    for (int j = 0; j < size; ++j) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
    return A;
}

int* _insertionsort (int array[], const int size) {
    return iSort(array, size);
}
