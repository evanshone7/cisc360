#include "quicksort.h"

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
    int pivot, i, j, t;
    pivot = a[l];
    i = l; j = r+1;
                    
    while(1) {
        do ++i; while( a[i] <= pivot && i <= r );
        do --j; while( a[j] > pivot );
        if( i >= j ) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[l]; a[l] = a[j]; a[j] = t;
    return j;
}

