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

printf("%lf",&time);

}
