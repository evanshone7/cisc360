#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"

void printTime(char *sortType, char *arrayType, float time);

int QUICK = 0;
int MERGE = 1;
int HEAP = 2;

int (*p[3]) (int *array, int size);

//main function begins...
int main( int argc, const char* argv[] ){
    // array of function pointers
    p[0] = quicksort;
    p[1] = mergesort;
    p[2] = myheapsort;

    printf("\nWe begin by measuring the time to 
            run our sorting algorithms without optimization...\n");
  
    int size = 100000;
    //Quicksort
    printf("Quicksort is being tested with size %d...\n", size);
    timeSort(QUICK, size);

    // Mergesort 
    printf("Mergesort is being tested with size %d...\n", size);
    timeSort(MERGE, size);

    // Heapsort
    printf("Heapsort is being tested with size %d...\n", size);
    timeSort(HEAP, size);
    return 0;
}
    
    void timeSort(int sortType, int arraySize) {
        clock_t t;
        int random[arraySize];
        int reverse[arraySize];
        int inOrder[arraySize];
        int nearlySorted[arraySize];
        // fill the arrays
        createArrays(arraySize, random, reverse, inOrder, nearlySorted);
        
        // time the execution
        t = clock();
        (*p[sortType]) (random, arraySize);
        t = clock() - t;
        printf("sort:%d, \ttime:%f\n", sortType, t/CLOCKS_PER_SEC);

    }

    void createArrays(int arraySize, int *random, int *reverse, 
                        int *inOrder, int *nearlySorted)
        //inOrder array creation
        for(int i = 0; i < arraySize; i++)
            inOrder[i] = i;

        //reverse array creation
        for(int j = 0; j < arraySize; j++)
            reverse[j] = arraySize - j;
  
        //nearlySorted array creation
        for(int k = 0; k < arraySize; k++){
            if(k = 99998 || k == 1){
                nearlySorted[k] = 28;
            } else {
                nearlySorted[k] = k;
            }
        }
  
        //random array creation
        for(int l = 0; l < arraySize; l++){
            int r = rand() % arraySize;
            random[l] = r;
        }
    }
