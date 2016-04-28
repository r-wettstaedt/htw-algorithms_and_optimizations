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

void timeAsString (char *buffer, unsigned long start) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long end = 1000000 * tv.tv_sec + tv.tv_usec;
    unsigned long diff = end - start;

    char *unity = "µs";
    if (diff >= 10000000) {
        diff /= 1000000;
        unity = "s";
    } else if (diff >= 10000) {
         diff /= 1000;
         unity = "ms";
    }

    snprintf(buffer, sizeof(buffer), "%lu%s", diff, unity);
}

int main (int argc, char *argv[]) {

    int arraysizes[5] = {10, 100, 1000, 10000, 100000};
    int arraysize;
    int *array;

    struct timeval tv;
    unsigned long start;
    char *timeString = malloc(256);

    for (int i = 0; i < 5; ++i) {
        arraysize = arraysizes[i];
        printf("\n\n~~~~= Arraysize %d =~~~~\n", arraysize);

        array = getRandomArray(arraysize);
        printf("\n  ~~= Random Array =~~\n");
        // printArray(array, arraysize);


        /* INSERTIONSORT */
        int *A = copyArray(array, arraysize);
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _insertionsort(A, arraysize);

        timeAsString(timeString, start);
        printf("  Insertionsort done in %s\n", timeString);
        // printArray(A, arraysize);


        /* MERGESORT */
        A = copyArray(array, arraysize);
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _mergesort(A, arraysize);

        timeAsString(timeString, start);
        printf("  Mergesort     done in %s\n", timeString);
        // printArray(A, arraysize);


        /* QUICKSORT */
        A = copyArray(array, arraysize);
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _quicksort(A, arraysize);

        timeAsString(timeString, start);
        printf("  Quicksort     done in %s\n", timeString);
        // printArray(A, arraysize);


        printf("\n  ~~= Presorted Array =~~\n");


        /* INSERTIONSORT */
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _insertionsort(A, arraysize);

        timeAsString(timeString, start);
        printf("  Insertionsort done in %s\n", timeString);
        // printArray(A, arraysize);


        /* MERGESORT */
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _mergesort(A, arraysize);

        timeAsString(timeString, start);
        printf("  Mergesort     done in %s\n", timeString);
        // printArray(A, arraysize);


        /* QUICKSORT */
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _quicksort(A, arraysize);

        timeAsString(timeString, start);
        printf("  Quicksort     done in %s\n", timeString);
        // printArray(A, arraysize);
    }

    printf("\n\n");

}