#ifndef HEAPSORT_H_   /* Include guard */
#define HEAPSORT_H_

int* _heapsort (int array[], const int size, unsigned long* modifications);
void maxHeapify (int A[], const int i, const int heapSize, unsigned long* modifications);
void hSwap (int A[], const int i, const int j);

#endif // HEAPSORT_H_