#include <stdio.h>
#include <sys/time.h>
#include "quicksort.h"
#include "mergesort.h"
#include "insertionsort.h"

int main (int argc, char *argv[]) {

    int array[5] = {3, 2, 5, 7, 50};
    struct timeval tv;
    unsigned long start;
    unsigned long end;

    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;
    quicksort(array);
    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("Quicksort done in %luµs\n", (end - start));


    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;
    mergesort(array);
    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("Mergesort done in %luµs\n", (end - start));


    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;
    insertionsort(array);
    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("Insertionsort done in %luµs\n", (end - start));

}