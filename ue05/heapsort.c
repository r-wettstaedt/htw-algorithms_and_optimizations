#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int heapSize = 0;

void swap(int A[], int i, int j) {
    const int t = A[i];
    A[i] = A[j];
    A[j] = t;
}


void maxHeapify(int A[], int i){

	int l = i*2+1;
	int r = i*2+2;
	int maximum = 0;
	
	if(l < heapSize && A[l] > A[i]){
		maximum = l;
	}
	else {
		maximum = i;
	}
	
	if(r < heapSize && A[r] > A[maximum]){
		maximum = r;
	}
	
	if(maximum != i){
		swap(A, i, maximum);
		maxHeapify(A, maximum);
	}
}

void buildMaxHeap(int A[], int size){
	heapSize = size;
	for(int i = (size-1)/2; i >= 0; i--){
		maxHeapify(A, i);
	}
}


int *hSort(int A[], int size){
	buildMaxHeap(A, size);
	for(int i = (size-1); i >= 1; i--){
		swap(A, 0, i);
		heapSize = heapSize - 1;
		maxHeapify(A, 0);
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
	int arraysize;
    int *array;
	clock_t t;
	
	arraysize = 10;
	printf("\n\n~~~~= Arraysize %d =~~~~\n", arraysize);

	array = getRandomArray(arraysize);
	printArray(array, arraysize);

	int *A = copyArray(array, arraysize);
	t = clock();
	hSort(A, arraysize);
			
	t = clock() - t;
			
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printArray(A, arraysize);
}