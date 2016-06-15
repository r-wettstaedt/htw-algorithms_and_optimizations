#include <stdio.h>
#include "_heapsort.h"

void hSwap (int A[], const int i, const int j) {
    const int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

void maxHeapify (int A[], const int i, const int heapSize, unsigned long* modifications) {
    (*modifications)++;

    const int l = 2 * i;
    const int r = 2 * i + 1;
    int maximum = i;

    if (l <= heapSize && A[l] > A[i])
        maximum = l;

    if (r <= heapSize && A[r] > A[maximum])
        maximum = r;

    if (maximum != i) {
        hSwap(A, i, maximum);
        maxHeapify(A, maximum, heapSize, modifications);
    }
}

void buildMaxHeap (int A[], const int size, unsigned long* modifications) {
    for (int i = size / 2; i >= 0; i--) {
        maxHeapify(A, i, size, modifications);
    }
}

int *hSort (int A[], int size, unsigned long* modifications) {
    buildMaxHeap(A, size, modifications);
    for (int i = size; i >= 1; i--) {
        hSwap(A, 0, i);
        maxHeapify(A, 0, --size, modifications);
    }

    return A;
}

int* _heapsort (int array[], const int size, unsigned long* modifications) {
    return hSort(array, size - 1, modifications);
}
