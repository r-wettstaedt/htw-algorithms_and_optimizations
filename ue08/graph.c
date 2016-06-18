#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

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
struct heapNode *prev[numberOfNodes];
struct heap *Q;

int getWeight (const int u, const int v) {
    return matrix[u * numberOfNodes + v];
}

struct heap *getNeighbors (struct heap *Q, struct heapNode *u) {
    int n, u_pos;
    struct heapNode **neighbors;
    struct heapNode *neighbor;

    for (int v = n = 0; v < numberOfNodes; v++) {
        u_pos = u->index * numberOfNodes + v;
        neighbor = findInHeap(Q, v);

        if (matrix[u_pos] > 0 && neighbor != NULL) {
            n++;
        }
    }

    if (n == 0) return NULL;
    neighbors = malloc(n * sizeof(struct heapNode *));

    for (int v = n = 0; v < numberOfNodes; v++) {
        u_pos = u->index * numberOfNodes + v;
        neighbor = findInHeap(Q, v);

        if (matrix[u_pos] > 0 && neighbor != NULL) {
            neighbors[n++] = neighbor;
        }
    }

    struct heap *h = malloc(sizeof(struct heap));
    h->size = n;
    h->nodes = neighbors;

    return h;
}

void dijkstra (const int s) {
    Q = newheap(numberOfNodes);

    for (int v = 0; v < numberOfNodes; v++) {
        dist[v] = INT_MAX / 2;
        prev[v] = NULL;

        struct heapNode* n = newNode(v, dist[v]);
        Q->nodes[v] = n;
        Q->size++;
    }

    dist[s] = 0;
    Q->nodes[s]->dist = 0;

    buildHeap(Q);

    while (Q->size > 0) {
        struct heapNode *u = extractMin(Q);
        struct heap *neighbors = getNeighbors(Q, u);

        if (neighbors == NULL) continue;

        for (int _v = 0; _v < neighbors->size; _v++) {
            struct heapNode *v = neighbors->nodes[_v];

            const int alt = dist[u->index] + getWeight(u->index, v->index);

            if (dist[v->index] > alt) {
                dist[v->index] = alt;
                prev[v->index] = u;

                v->dist = alt;
                buildHeap(Q);
            }
        }
    }
}

void printShortestPath(const int s) {
    dijkstra(s);
    for (int i = 0; i < numberOfNodes; i++) {
        if (prev[i] == NULL) continue;

        printf("distance (%c -> %c) is %d", map[s], map[i], dist[i]);
        if (prev[i]->index != s)
            printf(" via %c", map[prev[i]->index]);
        printf("\n");
    }
}
