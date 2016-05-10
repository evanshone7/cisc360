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
    // CHOOSE A BETTER PIVOT NINTHER()
    //pivot = a[l];
    pivot = ninther(a, l, r);
    t = a[l]; a[l] = a[pivot], a[pivot] = t;
    pivot = a[l];
    printf("pivot:%d\n", pivot);
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


int ninther (int *a, int l, int r) {
    return median3(a, l, r, (l+r)/2); 
    /*int diff = r-l;
    int one = (1/3)*diff + l;
    int two = (2/3)*diff + l;
    int med1 = median3(a[l], a[(l+one)/2], a[one]);
    int med2 = median3(a[one], a[(one+two)/2], a[two]);
    int med3 = median3(a[two], a[(two+r)/2], a[r]);
    printf("%d:%d:%d\n", med1, med2, med3);
    return median3(med1, med2, med3);*/
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

