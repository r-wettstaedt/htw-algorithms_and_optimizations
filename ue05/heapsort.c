#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>


void maxHeapify(int A[], int i){
	int l = A[i*2];
	int r = A[i*2+1];
	int maximum = 0;
	
	if(l <= size && A[l] > A[i]){
		maximum = l;
	}
	else {
		maximum = i;
	}
	
	if((r <= size) && (A[r] > A[maximum])){
		maximum = r;
	}
	
	if(maximum != i){
		swap(A, i, maximum);
		MaxHeapify(A, maximum);
	}
}

void buildMaxHeap(int A[], int size){
	for(int i = size/2; i >= 1; i--){
		maxHeapify(A, i);
	}
}


int *hSort(int A[], int size){
	buildMaxHeap(A, size);
	for(int i = size; i >= 2; i--){
		swap(A, 1, i);
		size = size - 1;
		maxHeapify(A, 1);
	}
	return A;
}



int main(int argc, char *argv[])
{
	return 0;
}