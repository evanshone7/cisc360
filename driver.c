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
double time_diff(struct timespec x, struct timespec y);
int compare(const void *a, const void *b);
void deepCopy(int *copy, int *OG, int size);
void checkCorrectness();
int sameArray(int *a, int *b, int size);
void printArray(int *a, int size);

int QUICK = 0;
int MERGE = 1;
int HEAP = 2;

int PERCENT_SWAP = 10;
int TEST_SIZE = 20;

int **arrays;

typedef void (*sortfunction_t) (int *array, int size);

sortfunction_t ALGORITHMS[3] = { my_quicksort, my_mergesort, my_heapsort };

int main(){
  printBreak();
  printf("Sort:\n\t0: quicksort\n\t1: mergesort\n\t2: heapsort\n");
  printf("Array:\n\t0: random\n\t1: in_order\n");
  printf("\t2: reverse\n\t3: nearly_sorted\n");

  printBreak();
  printf("Test the correctness of the sorts\n");
  printf("Size: %d, and qsort\n", TEST_SIZE);
  printBreak();
  checkCorrectness();

  printBreak();
  printf("Time the sorts\n");
  for (int size = 100; size < 10000000; size *= 10) {
    printBreak();
    printf("Array Size:%d\n", size);
    printBreak();
    timeSort(QUICK, size);
    printf("\n");
    timeSort(MERGE, size);
    printf("\n");
    timeSort(HEAP, size);
  }
  return 0;
}

void timeSort(int sortType, int arraySize) {
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
  /* fill the arrays */
  createArrays(arraySize, arrays);
  /* time the execution */
  struct timespec before, after;
  for (int i = 0; i < 4; i++) {
    clock_gettime(CLOCK_MONOTONIC, &before);
    (*ALGORITHMS[sortType]) (arrays[i], arraySize);
    clock_gettime(CLOCK_MONOTONIC, &after);
    printf("sort:%d, array:%d, time:%lf\n",
           sortType, i, time_diff(before, after));
  }
  free(arrays[0]);
  free(arrays);
}

void createArrays(int arraySize, int **arrays) {
  /* seed */
  srand(time(NULL));
  /* fill the arrays with data */
  for (int i = 0; i < arraySize; i++) {
    arrays[0][i] = (int) (rand() % arraySize);
    arrays[1][i] = i;
    arrays[2][i] = arraySize - i;
    arrays[3][i] = i;
  }

  /* swap random indexes */
  float numberOfSwaps = arraySize * (PERCENT_SWAP/100);
  for (int i = 0; i < numberOfSwaps; i++) {
    int a = (int) (rand() % arraySize);
    int b = (int) (rand() % arraySize);
    int temp = arrays[3][a];
    arrays[3][a] = arrays[3][b];
    arrays[3][b] = temp;
  }
}

/* check if the sorts are correct */
void checkCorrectness() {
  int *OG, *test, *correct;

  OG = (int *) malloc (sizeof(int) * TEST_SIZE);
  test = (int *) malloc (sizeof(int) * TEST_SIZE);
  correct = (int *) malloc (sizeof(int) * TEST_SIZE);

  /* make random array */
  srand(time(NULL));
  for (int i = 0; i < TEST_SIZE; i++)
    OG[i] = (int) (rand() % TEST_SIZE);

  printBreak();
  printf("OG array\n");
  printArray(OG, TEST_SIZE);
  printBreak();
  /* get correct */
  deepCopy(correct, OG, TEST_SIZE);
  qsort(correct, TEST_SIZE, sizeof(int), compare);

  /* check each one against correct */
  for (int i = 0; i < 3; i++) {
    deepCopy(test, OG, TEST_SIZE);
    (*ALGORITHMS[i]) (test, TEST_SIZE);
    if (sameArray(correct, test, TEST_SIZE))
      printf("sort:%d is correct\n", i);
    else {
      printf("sort:%d is incorrect\n", i);
      printArray(test, TEST_SIZE);
      printArray(correct, TEST_SIZE);
    }
  }

  free(OG);
  free(test);
  free(correct);
}

/* return 1 if same contents 0 otherwise */
int sameArray(int *a, int *b, int size) {
  int res = 1;
  for (int i = 0; i < size; i++) {
    res = res && a[i] == b[i];
  }
  return res;
}

/* get the difference in time */
double time_diff(struct timespec x, struct timespec y) {
  return 1e3 * (y.tv_sec - x.tv_sec) + (1e-6 * (y.tv_nsec - x.tv_nsec));
}

/* Taken from http://stackoverflow.com/questions/3893937/c-array-sorting-tips */
int compare( const void* a, const void* b) {
  int int_a = * ( (int*) a );
  int int_b = * ( (int*) b );

  if ( int_a == int_b ) return 0;
  else if ( int_a < int_b ) return -1;
  else return 1;
}

/* copy each element individually */
void deepCopy(int *copy, int *OG, int size) {
  for (int i = 0; i < size; i++) {
    copy[i] = OG[i];
  }
}

/* pretty self explanatory */
void printBreak() {
  printf("--------------------------------------------------\n");
}

/* prints the array */
void printArray(int *a, int size) {
  printf("{");
  char* delim = "";
  for (int i = 0; i < size; i++) {
    printf("%s%d", delim, a[i]);
    delim = ",";
  }
  printf("}\n");
}
