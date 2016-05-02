#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

//INSERTION SORT
int *iSort (int A[], int size) {
    int i, key;
    for (int j = 0; j < size; ++j) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
    return A;
}

//MERGESORT
void merge(int A[], int al, int ar, int B[], int bl, int br, int C[]) {
    int i = al, j = bl;
    for (int k = 0; k <= ar - al + br - bl + 1; k++) {
        if (i > ar) {
            C[k] = B[j++];
            continue;
        }
        if (j > br) {
            C[k] = A[i++];
            continue;
        }
        C[k] = (A[i] < B[j]) ? A[i++] : B[j++];
    }
}

int *mSort(int A[], int al, int ar) {
    if (ar > al) {
        int m = (ar + al) / 2;
        mSort(A, al, m);
        mSort(A, m + 1, ar);
        int *B = calloc(ar - al + 1, sizeof(int));
        merge(A, al, m, A, m + 1, ar, B);
        for (int i = 0; i < ar - al + 1; i++)
            A[al + i] = B[i];
    }
    return A;
}

//QUICKSORT
void swap(int A[], int i, int j) {
    const int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

int *qSort (int A[], int al, int ar) {
    if (al < ar) {
        int pivot = A[al], i = al, j = ar + 1;
        while (1) {
            while (A[++i] < pivot && i < ar) {}
            while (A[--j] > pivot && j > al) {}
            if (i < j) swap(A, i, j);
            else break;
        }
        swap(A, j, al);
        qSort(A, al, j - 1);
        qSort(A, j + 1, ar);
    }
    return A;
}

//HELPER FUNCTIONS FOR OUTPUT
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


int main(int argc, char *argv[])
{
	int arraysizes[5] = {10, 100, 1000, 10000, 100000};
    int arraysize;
    int *array;
	
	clock_t t;
	
	//array to hold run times of each sort
	int sortTypes = 6;
	double runTimes[6] = {0};
	//number of test executions
	int numberOfTests = 5;
	
	for(int j = 0; j < numberOfTests; j++){
	printf("Running test execution: %d of %d...\n", j, numberOfTests - 1);
	
		for (int i = 0; i < 5; ++i) {
			arraysize = arraysizes[i];
			//printf("\n\n~~~~= Arraysize %d =~~~~\n", arraysize);

			array = getRandomArray(arraysize);
			//printf("\n  ~~= Random Array =~~\n");
			//if(arraysize == 10) printArray(array, arraysize);


			/* INSERTIONSORT */
			int *A = copyArray(array, arraysize);
			t = clock();
			iSort(A, arraysize);
			t = clock() - t;
	
			double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			runTimes[0] += time_taken;
			//printf("Insertion done in %f seconds\n", time_taken);
			//if(arraysize == 10) printArray(A, arraysize);


			/* MERGESORT */
			A = copyArray(array, arraysize);
			t = clock();
			mSort(A, 0, arraysize - 1);
			t = clock() - t;
	
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			runTimes[1] += time_taken;
			//printf("Mergesort done in %f seconds\n", time_taken);
			//if(arraysize == 10) printArray(A, arraysize);


			/* QUICKSORT */
			A = copyArray(array, arraysize);
			t = clock();
			qSort(A, 0, arraysize - 1);
			t = clock() - t;
	
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			runTimes[2] += time_taken;
			//printf("Quicksort done in %f seconds\n", time_taken);
			//if(arraysize == 10) printArray(A, arraysize);


			//printf("\n  ~~= Presorted Array =~~\n");


			/* INSERTIONSORT */
			t = clock();
			iSort(A, arraysize);
			t = clock() - t;
	
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			runTimes[3] += time_taken;
			//printf("Insertion done in %f seconds\n", time_taken);
			//if(arraysize == 10) printArray(A, arraysize);


			/* MERGESORT */
			t = clock();
			mSort(A, 0, arraysize - 1);
			t = clock() - t;
	
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			runTimes[4] += time_taken;
			//printf("Mergesort done in %f seconds\n", time_taken);
			//if(arraysize == 10) printArray(A, arraysize);


			/* QUICKSORT */
			t = clock();
			qSort(A, 0, arraysize - 1);
			t = clock() - t;
	
			time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			runTimes[5] += time_taken;
			//printf("Quicksort done in %f seconds\n", time_taken);
			//if(arraysize == 10) printArray(A, arraysize);
		}
    
    }
	
	printf("\n\n");
	
	printf("Average run times on random arrays:\n");
	printf("Insertion: %f seconds\n", runTimes[0]/numberOfTests);
	printf("Mergesort: %f seconds\n", runTimes[1]/numberOfTests);
	printf("Quicksort: %f seconds\n", runTimes[2]/numberOfTests);
	printf("\n");
	
	printf("Average run times on presorted arrays:\n");
	printf("Insertion: %f seconds\n", runTimes[3]/numberOfTests);
	printf("Mergesort: %f seconds\n", runTimes[4]/numberOfTests);
	printf("Quicksort: %f seconds\n", runTimes[5]/numberOfTests);
	
	
    printf("\n\n");

    return 0;
}