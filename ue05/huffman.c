#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "_heapsort.h"

struct vertex {
    int freq;
    struct vertex *left, *right;
};
typedef struct vertex Vertex;


int heapMaximum (int A[]) {
    return A[1];
}

int heapExtractMax (int A[], int heapSize) {
    if (heapSize < 1)
        printf("Error: heapSize < 1: %d < 1\n", heapSize);

    const int max = A[1];
    A[1] = A[heapSize];
    maxHeapify(A, 1, --heapSize, 0);
    return max;
}

void heapIncreaseKey (int A[], int i, const int key) {
    if (key < A[i])
        printf("Error: key < A[i]: %d < %d\n", key, A[i]);

    A[i] = key;
    int p = i / 2;
    while (i > 1 && A[p] < A[i]) {
        hSwap(A, i, p);
        i = p;
        p = i / 2;
    }
}

void maxHeapInsert (int A[], int heapSize, const int key) {
    A[++heapSize] = INT_MIN;
    heapIncreaseKey(A, heapSize, key);
}

int huffman (int C[]) {// C: frequencies
    int n = sizeof(C) / sizeof(C[0]);
    int* Q = C; // Q: MinPriorityQueue
    for (int i = 1; n < n - 1; i++) {
        Vertex *v = malloc(sizeof(Vertex));
        v->left = MinHeapExtractMin(Q);
        v->right = MinHeapExtractMin(Q);
        v->freq = v->left->freq + v->right->freq;
        MinHeapInsert(Q, v);
    }
    return MinHeapExtractMin(Q);