#include "mergesort.h"

void mergesort_body(int* arr, int len) {
	if(len < 2) {
		return;
	}
	
	int i;
	int lenleft, lenright;
	int *arrleft, *arrright;
	
	lenleft = len / 2;
	lenright = len - lenleft;
	arrleft = (int*)malloc(sizeof(int) * lenleft);
	arrright  = (int*)malloc(sizeof(int) * lenright);
	
	for(i = 0, i < lenleft, i++) {
		arrleft[i] = arr[i];
	}
	
	for(i = 0, i < lenright, i++) {
		arrright[i] = arr[i + lenleft];
	}
	
	mergesort_body(arrleft, lenleft);
	mergesort_body(arrright, lenright);
	
	merge(arrleft, arrright, lenleft, lenright, arr);
	free(arrleft);
	free(arrright);
}

void merge(int *left, int *right, int leftlen, int rightlen, int *fullarr) {
	int i, j, k = 0;
	
	while (i < leftlen && j < rightlen) {
		if(left[i] <= right[j]) {
			fullarr[k] = left[i];
			i++;
			k++;
		}
		else {
			fullarr[k] = right[j];
			j++;
			k++;
		}
	}
	
	while (i < leftlen) {
		fullarr[k] = left[i];
		i++;
		k++;
	}
	
	while (j < rightlen) {
		fullarr[k] = right[j];
		j++;
		k++;
	}
}