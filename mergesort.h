#include <stdlib.h>
#include <stdio.h>

void mergesort_body(int* arr, int len);
void merge(int *left, int *right, int leftlen, int rightlen, int *fullarr);