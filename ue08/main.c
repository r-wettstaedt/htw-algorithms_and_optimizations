#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

#include "graph.h"

#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_RESET   "\x1B[0m"


int main (int argc, char *argv[]) {
    for (int i = 0; i < numberOfNodes; i++) {
        printShortestPath(i);
        printf("\n");
    }

    return 0;
}
