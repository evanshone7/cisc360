#include <stdlib.h>

void my_heapsort(int*,int); //sorts elements via heap.
void heapify(int*,int); //takes an array, makes it so that it represents a heap
void adjust(int*,int);  //moves around elements in a heapified array
