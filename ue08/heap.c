#include <stdlib.h>
#include "heap.h"

struct heap *newheap(const unsigned capacity) {
    struct heap *h = malloc(sizeof(struct heap));
    h->size = 0;
    h->capacity = capacity;
    h->nodes = malloc(h->capacity * sizeof(struct heapNode*));
    return h;
}

struct heapNode *newNode(const unsigned index, const int dist) {
    struct heapNode *n = malloc(sizeof(struct heapNode));
    n->left = n->right = NULL;
    n->index = index;
    n->dist = dist;
    return n;
}


void swap(struct heapNode *i, struct heapNode *j) {
    struct heapNode *t = i;
    i = j;
    j = t;
}

void heapify(struct heap *h, int i) {

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int minimum = i;

    if (l < h->size && h->nodes[l]->dist < h->nodes[minimum]->dist)
        minimum = l;

    if (r < h->size && h->nodes[r]->dist < h->nodes[minimum]->dist)
        minimum = r;

    if (minimum != i) {
        swap(h->nodes[minimum], h->nodes[i]);
        heapify(h, minimum);
    }
}

void buildHeap(struct heap *h, const int heapSize) {
    for(int i = heapSize/2 - 1; i >= 0; i--){
        heapify(h, i);
    }
}

struct heapNode *extractMin(struct heap *h) {
    struct heapNode *n = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;

    heapify(h, 0);
    return n;
}
