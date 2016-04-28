#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "_insertionsort.h"
#include "_mergesort.h"
#include "_quicksort.h"

void printArray (int array[], const int size) {
    printf("[ ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int *getRandomArray (const int size) {
    time_t t;
    srand((unsigned) time(&t));
    int *array = calloc(size, sizeof(int));

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 1000;
    }
    return array;
}

int *copyArray (int array[], const int size) {
    int *A = calloc(size, sizeof(int));
    memcpy(A, array, size * sizeof(int));
    return A;
}

int main (int argc, char *argv[]) {

    const int ARRAYSIZE = 5;
    int *array = getRandomArray(ARRAYSIZE);
    printf("\n\nRandom Array\n");
    printArray(array, ARRAYSIZE);

    struct timeval tv;
    unsigned long start;
    unsigned long end;


    /* INSERTIONSORT */
    int *A = copyArray(array, ARRAYSIZE);
    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;

    _insertionsort(A, ARRAYSIZE);

    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("\n\nInsertionsort done in %luµs\n", (end - start));
    printArray(A, ARRAYSIZE);


    /* MERGESORT */
    A = copyArray(array, ARRAYSIZE);
    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;

    _mergesort(A, ARRAYSIZE);

    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("\n\nMergesort done in %luµs\n", (end - start));
    printArray(A, ARRAYSIZE);


    /* QUICKSORT */
    A = copyArray(array, ARRAYSIZE);
    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;

    _quicksort(A, ARRAYSIZE);

    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("\n\nQuicksort done in %luµs\n", (end - start));
    printArray(A, ARRAYSIZE);

}