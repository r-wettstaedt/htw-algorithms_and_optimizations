#include <stdio.h>
#include <limits.h>

#include "graph.h"
#include "heap.h"

const int numberOfNodes = 5;

const char map[numberOfNodes] = {'s', 't', 'x', 'y', 'z'};
const int matrix[numberOfNodes * numberOfNodes] = {
    /*     s   t   x   y   z      */
    /* s */0, 10,  0,  5,  0,/* s */
    /* t */0,  0,  1,  2,  0,/* t */
    /* x */0,  0,  0,  0,  4,/* x */
    /* y */0,  3,  9,  0,  2,/* y */
    /* z */7,  0,  6,  0,  0,/* z */
    /*     s   t   x   y   z      */
};
int dist[numberOfNodes];
int prev[numberOfNodes];
struct heap* Q;

void dijkstra (const int s) {
    Q = newheap(numberOfNodes);

    for (int v = 0; v < numberOfNodes; v++) {
        dist[v] = INT_MAX;
        prev[v] = -1;

        struct heapNode* n = newNode(v, dist[v]);
        Q->nodes[v] = n;
        Q->size++;
        heapify(Q, v);
        printf("v: %d | size: %d | %d\n", v, Q->size, Q->nodes[v]->dist);
    }

    dist[s] = 0;
    buildHeap(Q, numberOfNodes);

    while (Q->size > 0) {
        printf("while %d > 0\n", Q->size);
        struct heapNode *u = extractMin(Q);
        struct heapNode *neighbors[2] = {u->left, u->right};
        printf("%d\n", u->left->dist);
        for (int v = 0; v < 2; v++) {
            // printf("v: %d | size: %d ", v, neighbors[v]->dist);
            // dist[v] > dist[v] +
        }
    }
}

void printShortestPath(const int a, const int b) {
    printf("%c -> %c\n", map[a], map[b]);
    dijkstra(a);
}
