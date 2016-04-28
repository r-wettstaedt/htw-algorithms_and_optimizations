#include <stdio.h>
#include "_quicksort.h"

void swap(int A[], const int i, const int j) {
    const int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

int *qSort (int A[], const int al, const int ar) {
    if (al < ar) {
        int pivot = A[al], i = al, j = ar + 1;
        while (1) {
            while (A[++i] < pivot && i < ar) {}
            while (A[--j] > pivot && j > al) {}
            if (i < j) swap(A, i, j);
            else break;
        }
        swap(A, j, al);
        qSort(A, al, j - 1);
        qSort(A, j + 1, ar);
    }
    return A;
}

int* _quicksort (int array[], const int size) {
    return qSort(array, 0, size - 1);
}
