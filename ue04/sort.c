#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "_quicksort.h"
#include "_mergesort.h"
#include "_insertionsort.h"

void printArray (int array[], const int ARRAYSIZE) {
    printf("[ ");
    for (int i = 0; i < ARRAYSIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int *getRandomArray (const int size) {
    time_t t;
    srand((unsigned) time(&t));
    int *array = calloc(size, sizeof(int));

    for (int i = 0; i < size; ++i) {
        array[i] = rand();
    }
    return array;
}

int main (int argc, char *argv[]) {

    const int ARRAYSIZE = 5;
    int *array = getRandomArray(ARRAYSIZE);
    printf("\n\nRandom Array\n");
    printArray(array, ARRAYSIZE);

    struct timeval tv;
    unsigned long start;
    unsigned long end;

    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;
    _quicksort(array);
    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("\n\nQuicksort done in %luµs\n", (end - start));
    printArray(array, ARRAYSIZE);


    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;
    _mergesort(array);
    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("\n\nMergesort done in %luµs\n", (end - start));
    printArray(array, ARRAYSIZE);


    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;
    _insertionsort(array);
    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("\n\nInsertionsort done in %luµs\n", (end - start));
    printArray(array, ARRAYSIZE);

}