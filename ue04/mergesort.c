#include <stdio.h>
#include <stdlib.h>
#include "_mergesort.h"

void merge(int A[], const int al, const int ar, int B[], const int bl, const int br, int C[], unsigned long* modifications) {
    int i = al, j = bl;
    for (int k = 0; k <= ar - al + br - bl + 1; k++) {
        if (i > ar) {
            C[k] = B[j++];
            continue;
        }
        if (j > br) {
            C[k] = A[i++];
            continue;
        }
        C[k] = (A[i] < B[j]) ? A[i++] : B[j++];
        (*modifications)++;
    }
}

int *mSort(int A[], const int al, const int ar, unsigned long* modifications) {
    if (ar > al) {
        int m = (ar + al) / 2;
        mSort(A, al, m, modifications);
        mSort(A, m + 1, ar, modifications);
        int *B = calloc(ar - al + 1, sizeof(int));
        merge(A, al, m, A, m + 1, ar, B, modifications);
        for (int i = 0; i < ar - al + 1; i++)
            A[al + i] = B[i];
    }
    return A;
}

int* _mergesort (int array[], const int size, unsigned long* modifications) {
    return mSort(array, 0, size - 1, modifications);
}
