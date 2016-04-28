/*
 * main.c
 *
 *  Created on: Apr 27, 2016
 *      Author: Megan
 */

#include <time.h>
#include<stdio.h>
#include "heapsort.c"
#include "quicksort.c"
#include "mergesort.c"
#include "heapsort.c"



int main(){
    clock_t beginQuick, beginMerge,beginHeap,endQuick,endMerge,endHeap;

    double timeQuick,timeMerge,timeHeap;
    srand(0); // seed
    int array[1000]; // generate 1000 random number in an array

    for(int i=0; i<1000; i++){
        array[i] = rand();
        printf(" %d", array[i]);
    }
    
     int array2[40] = {1,1,2,2,2,3,4,4,4,5,
    		           3,7,8,8,8,9,1,20,15,11,
					   11,12,13,13,13,14,2,16,11,16,
					   17,17,18,18,18,19,19,20,20,20
                       };
    quicksort(array2,40);
    mergesort_body(array2,40);
    myheapsort(array2,40);

    beginQuick = clock();
    quicksort(array,1000);
    endQuick = clock();
    timeQuick = (double)(endQuick-beginQuick)/CLOCKS_PER_SEC;
    beginMerge = clock();
    mergesort_body(array,1000);
    endMerge = clock();
    timeMerge = (double)(endMerge - beginMerge)/CLOCKS_PER_SEC;
    beginHeap = clock();
    myheapsort(array,1000);
    endHeap = clock();
    timeHeap = (double)(endHeap-beginHeap)/ CLOCKS_PER_SEC;

printf("Quick sort: %lf, Merge sort: %lf, Heap sort: %lf",&timeQuick, &timeMerge, &timeHeap);

}
