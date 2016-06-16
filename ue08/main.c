#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

#include "graph.h"

#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_RESET   "\x1B[0m"


int main (int argc, char *argv[]) {
    printShortestPath(0, 4);
    // for (int i = 0; i < numberOfNodes; i++) {
    //     for (int j = 0; j < numberOfNodes; j++) {
    //         printShortestPath(i, j);
    //     }
    // }

    return 0;
}
