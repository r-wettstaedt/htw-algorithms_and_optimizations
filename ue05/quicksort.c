#include <stdio.h>
#include "_quicksort.h"

void qSwap(int A[], const int i, const int j) {
    const int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

int *qSort (int A[], const int al, const int ar, unsigned long* modifications) {
    if (al < ar) {
        int pivot = A[al], i = al, j = ar + 1;
        while (1) {
            (*modifications)++;
            while (A[++i] < pivot && i < ar) {}
            while (A[--j] > pivot && j > al) {}
            if (i < j) qSwap(A, i, j);
            else break;
        }
        qSwap(A, j, al);
        qSort(A, al, j - 1, modifications);
        qSort(A, j + 1, ar, modifications);
    }
    return A;
}

int* _quicksort (int array[], const int size, unsigned long* modifications) {
    return qSort(array, 0, size - 1, modifications);
}
