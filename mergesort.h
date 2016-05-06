#include <stdlib.h>
#include <stdio.h>

void my_mergesort(int* arr, int len);
void merge(int *left, int *right, int leftlen, int rightlen, int *fullarr);
void imsort(int* xs, int l, int u);
void wmerge(int* xs, int i, int m, int j, int n, int w);
void swap(int* xs, int i, int j);
void my_mergesort_body(int* xs, int l, int u, int w);
