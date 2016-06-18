#ifndef HEAP_H_   /* Include guard */
#define HEAP_H_

struct heapNode {
    unsigned index;
    int dist;
};

struct heap {
    unsigned size;
    unsigned capacity;
    struct heapNode **nodes;
};

struct heap* newheap(const unsigned capacity);
struct heapNode* newNode(const unsigned index, const int dist);

struct heapNode* extractMin(struct heap* h);
void buildHeap(struct heap *h);
void heapify(struct heap *h, int i);

struct heapNode *findInHeap(struct heap *h, const int index);

void printHeap (struct heap *h, char *prefix);

#endif // HEAP_H_
