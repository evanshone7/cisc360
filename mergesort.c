#include "mergesort.h"

void my_mergesort(int* arr, int len) {
return;
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
	
	for(i = 0; i < lenleft; i++) {
		arrleft[i] = arr[i];
	}
	
	for(i = 0; i < lenright; i++) {
		arrright[i] = arr[i + lenleft];
	}
	
	my_mergesort(arrleft, lenleft);
	my_mergesort(arrright, lenright);
	
	merge(arrleft, arrright, lenleft, lenright, arr);
	free(arrleft);
	free(arrright);
}

void merge(int *left, int *right, int leftlen, int rightlen, int *fullarr) {
	int i = 0, j = 0, k = 0;
	
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
