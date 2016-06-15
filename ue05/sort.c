#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "_heapsort.h"
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

void timeAsString (char *buffer, unsigned long start, unsigned long end) {
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

    unsigned long modifications;
    int *array;
    int *A;

    unsigned long start, end;
    struct timeval tv;

    char *fileString = malloc(1048576);
    char *currentLine = malloc(256);
    char *timeString = malloc(256);

    sprintf(currentLine, "arraysize\trandom heapsort\trandom quicksort\tpresorted heapsort\tpresorted quicksort\n");
    strcat(fileString, currentLine);

    int arraysize = 1;
    for (int i = 0; i < 5; ++i) {
        arraysize *= 10;

        sprintf(currentLine, "%d\t", arraysize);
        strcat(fileString, currentLine);

        printf("\n\n~~~~= Arraysize %d =~~~~\n", arraysize);

        array = getRandomArray(arraysize);
        printf("\n  ~~= Random Array =~~\n");
        // printArray(array, arraysize);


        /* HEAPSORT */
        A = copyArray(array, arraysize);
        modifications = 0;
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _heapsort(A, arraysize, &modifications);

        gettimeofday(&tv, NULL);
        end = 1000000 * tv.tv_sec + tv.tv_usec;
        timeAsString(timeString, start, end);
        printf("  Heapsort     done in %s \t| modifications %lu\n", timeString, modifications);
        sprintf(currentLine, "%f\t", ((float)modifications / 1000));
        strcat(fileString, currentLine);
        // printArray(A, arraysize);


        /* QUICKSORT */
        A = copyArray(array, arraysize);
        modifications = 0;
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _quicksort(A, arraysize, &modifications);

        gettimeofday(&tv, NULL);
        end = 1000000 * tv.tv_sec + tv.tv_usec;
        timeAsString(timeString, start, end);
        printf("  Quicksort     done in %s \t| modifications %lu\n", timeString, modifications);
        sprintf(currentLine, "%f\t", ((float)modifications / 1000));
        strcat(fileString, currentLine);
        // printArray(A, arraysize);


        printf("\n  ~~= Presorted Array =~~\n");


        /* HEAPSORT */
        modifications = 0;
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _heapsort(A, arraysize, &modifications);

        gettimeofday(&tv, NULL);
        end = 1000000 * tv.tv_sec + tv.tv_usec;
        timeAsString(timeString, start, end);
        printf("  Heapsort     done in %s \t| modifications %lu\n", timeString, modifications);
        sprintf(currentLine, "%f", ((float)modifications / 1000));
        strcat(fileString, currentLine);
        // printArray(A, arraysize);


        /* QUICKSORT */
        modifications = 0;
        gettimeofday(&tv, NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        _quicksort(A, arraysize, &modifications);

        gettimeofday(&tv, NULL);
        end = 1000000 * tv.tv_sec + tv.tv_usec;
        timeAsString(timeString, start, end);
        printf("  Quicksort     done in %s \t| modifications %lu\n", timeString, modifications);
        sprintf(currentLine, "%f", ((float)modifications / 1000));
        strcat(fileString, currentLine);
        // printArray(A, arraysize);


        sprintf(currentLine, "\n");
        strcat(fileString, currentLine);
    }

    printf("\n\n");

    FILE *fp = fopen("results.txt", "w");
    fputs(fileString, fp);
    fclose(fp);

}