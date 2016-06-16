#include <stdio.h>

#include "graph.h"

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

void printShortestPath(const int a, const int b) {
    printf("%c -> %c\n", map[a], map[b]);
}

void dijkstra () {

}
