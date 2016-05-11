#include "quicksort.h"

void _my_swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void my_quicksort(int* arr, int n) {
	quicksort_body(arr, 0, n-1);
}
/* taken from: http://www.comp.dit.ie/rlawlor/Alg_DS/sorting/quickSort.c */
void quicksort_body( int a[], int l, int r) {
	int j;
	if( l < r ) {
		/* divide and conquer */
		j = partition( a, l, r);
		quicksort_body( a, l, j-1);
		quicksort_body( a, j+1, r);
	}
}

int partition( int a[], int l, int r) {
	int pivot, i, j;
	pivot = ninther(a, l, r);
	_my_swap(a + l, a + pivot);
	pivot = a[l];
	i = l; j = r+1;
	while(1) {
		do ++i; while( a[i] <= pivot && i <= r );
		do --j; while( a[j] > pivot );
		if( i >= j ) break;
		_my_swap(a + i, a + j);
	}
	_my_swap(a + l, a + j);
	return j;
}


int ninther (int *a, int l, int r) {
	int diff = r-l+1;
	int one = l + diff / 3;
	int two = l + 2 * diff / 3;
	int med1 = median3 (a, l,   (l   + one) / 2, one);
	int med2 = median3 (a, one, (one + two) / 2, two);
	int med3 = median3 (a, two, (two + r  ) / 2, r);
	return median3 (a, med1, med2, med3);
}

/* taken from http://stackoverflow.com/questions/17158667/minimum-no-of-comparisons-to-find-median-of-3-numbers */
int median3(int * v, int a, int b , int c) {
	int x = v[a]-v[b];
	int y = v[b]-v[c];
	int z = v[a]-v[c];
	if(x*y > 0) return b;
	if(x*z > 0) return c;
	return a;
}
