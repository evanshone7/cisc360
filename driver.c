#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"

void printTime(char *sortType, char *arrayType, float time);
void timeSort(int sortType, int arraySize);
void printBreak();
void createArrays(int arraySize, int **array);
double time_diff(struct timeval x, struct timeval y);

int QUICK = 0;
int MERGE = 1;
int HEAP = 2;

int PERCENT_SWAP = 10;

int **arrays;

typedef void (*sortfunction_t) (int *array, int size);

sortfunction_t ALGORITHMS[3] = { my_quicksort, my_mergesort, my_heapsort };

//main function begins...
int main( int argc, const char* argv[] ){
    // array of function pointers

    printBreak();
    printf("Sort:\n\t0: quicksort\n\t1: mergesort\n\t2: heapsort\n");
    printf("Array:\n\t0: random\n\t1: in_order\n");
    printf("\t2: reverse\n\t3: nearly_sorted\n");

    for (int size = 10; size < 1000000; size *= 10) {
        printBreak();
        printf("Array Size:%d\n", size);
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
    arrays = (int **) malloc(sizeof(int *) * 4);
    int *block = (int *) malloc(sizeof(int) * arraySize * 4);
    for (int i = 0; i < 4; i++) {
        arrays[i] = block + i * arraySize;
    }
    // fill the arrays
    createArrays(arraySize, arrays);
    // time the execution
    struct timeval before, after;
    for (int i = 0; i < 4; i++) {
        gettimeofday(&before, NULL);
//        (*ALGORITHMS[sortType]) (arrays[i], arraySize);
        gettimeofday(&after, NULL);
        printf("sort:%d, array:%d, time:%lf\n",
                sortType, i, time_diff(before, after));
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

double time_diff(struct timeval x, struct timeval y) {
    return (y.tv_sec - x.tv_sec) + (1e-6 * (y.tv_usec - x.tv_usec));
}
void printBreak() {
    printf("---------------------------------------------------\n");
}
