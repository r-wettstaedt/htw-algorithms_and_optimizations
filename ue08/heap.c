#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct heap *newheap (const unsigned capacity) {
    struct heap *h = malloc(sizeof(struct heap));
    h->size = 0;
    h->capacity = capacity;
    h->nodes = malloc(h->capacity * sizeof(struct heapNode*));
    return h;
}

struct heapNode *newNode (const unsigned index, const int dist) {
    struct heapNode *n = malloc(sizeof(struct heapNode));
    n->index = index;
    n->dist = dist;
    return n;
}

void swap (struct heapNode **i, struct heapNode **j) {
    struct heapNode *t = *i;
    *i = *j;
    *j = t;
}

void heapify (struct heap *h, int i) {

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int minimum = i;

    if (l < h->size && h->nodes[l]->dist < h->nodes[minimum]->dist)
        minimum = l;

    if (r < h->size && h->nodes[r]->dist < h->nodes[minimum]->dist)
        minimum = r;

    if (minimum != i) {
        swap(&h->nodes[minimum], &h->nodes[i]);
        heapify(h, minimum);
    }
}

void buildHeap (struct heap *h) {
    for(int i = h->size / 2 - 1; i >= 0; i--){
        heapify(h, i);
    }
}

struct heapNode *extractMin (struct heap *h) {
    struct heapNode *n = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;

    heapify(h, 0);
    return n;
}

struct heapNode *findInHeap (struct heap *h, const int index) {
    for (int q = 0; q < h->size; q++) {
        if (h->nodes[q]->index == index) return h->nodes[q];
    }

    return NULL;
}

void printHeap (struct heap *h, char *prefix) {
    for (int v = 0; v < h->size; v++) {
        printf("%sv: %d | i: %d | d: %d\n", prefix, v, h->nodes[v]->index, h->nodes[v]->dist);
    }
}
