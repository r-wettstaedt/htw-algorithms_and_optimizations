#ifndef HEAP_H_   /* Include guard */
#define HEAP_H_

struct heapNode {
    unsigned index;
    int dist;
    struct heapNode *left, *right;
};

struct heap {
    unsigned size;
    unsigned capacity;
    struct heapNode **nodes;
};

struct heap* newheap(const unsigned capacity);
struct heapNode* newNode(const unsigned index, const int dist);
struct heapNode* extractMin(struct heap* h);

void buildHeap(struct heap *h, const int heapSize);
void heapify(struct heap *h, int i);

#endif // HEAP_H_
