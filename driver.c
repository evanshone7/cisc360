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

int PERCENT_SWAP = 10;

void (*p[3]) (int *array, int size);

//main function begins...
int main( int argc, const char* argv[] ){
    // array of function pointers
    p[0] = my_quicksort;
    p[1] = my_mergesort;
    p[2] = my_heapsort;
    
    printf("Sort:\n\t0:quicksort\n\t1:mergesort\n\t2:heapsort\n");
    printf("Array:\n\t0:random\n\t1:in_order\n\t2:reverse\n\t3:nearly_sorted\n");

    for (int size = 10; size < 1000000; size *= 10) {
        printf("Array Size:%di\n", size);
        timeSort(QUICK, size);
        timeSort(MERGE, size);
        timeSort(HEAP, size);
    }
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
        for (int i = 0; i < 4; i++) {
            t = clock();
            (*p[sortType]) (arrays[i], arraySize);
            t = clock() - t;
            printf("sort:%d,\tarray:%d,\ttime:%lu\n", sortType, i, t/CLOCKS_PER_SEC);
        }
        free(arrays[0]);
        free(arrays);

    }

    void createArrays(int arraySize, int **arrays) {
        // fill the arrays with data
        for (int i = 0; i < arraySize; i++) {
            arrays[0][i] = (int) (rand() % arraySize);
            arrays[1][i] = i;
            arrays[2][i] = arraySize - i;
            arrays[3][i] = i;
        }
        // TODO - swap some entries of nearly_sorted

    }
