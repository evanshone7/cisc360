#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"

void printTime(char *sortType, char *arrayType, float time);
void timeSort(int sortType, int arraySize);

void createArrays(int arraySize, int **array);

int QUICK = 0;
int MERGE = 1;
int HEAP = 2;

void (*p[3]) (int *array, int size);

//main function begins...
int main( int argc, const char* argv[] ){
    // array of function pointers
    p[0] = my_quicksort;
    p[1] = my_mergesort;
    p[2] = my_heapsort;
    
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
        /* arrays[0] = random
         * arrays[1] = in_order
         * arrays[2] = reverse
         * arrays[3] = nearly_sorted
         */
        int **arrays = malloc(sizeof(int) * arraySize * 4);
        int *block = malloc(sizeof(int*)*4);
        for (int i = 0; i < 4; i++) {
            arrays[i] = block + i * arraySize;
        }
        // fill the arrays
        createArrays(arraySize, arrays);
        
        // time the execution
        t = clock();
        (*p[sortType]) (random, arraySize);
        t = clock() - t;
        printf("sort:%d, \ttime:%lu\n", sortType, t/CLOCKS_PER_SEC);
        free(arrays[0]);
        free(arrays);

    }

    void createArrays(int arraySize, int **arrays) {

        for (int i = 0; i < arraySize; i++) {
            arrays[0][i] = rand() % arraySize;
            arrays[1][i] = i;
            arrays[2][i] = arraySize - i;
            arrays[3][i] = i;
        }
        // TODO - swap some entries of nearly_sorted

    }
