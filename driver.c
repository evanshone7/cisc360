#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"

  
  
  //main function begins...
  int main( int argc, const char* argv[] ){
	  
	  
clock_t t;
int arraySize = 100000;
int random[arraySize];
int reverse[arraySize];
int inOrder[arraySize];
int nearlySorted[arraySize];


//Create arrays for testing 

//inOrder array creation
for(int i = 0; i < arraySize; i++){
  inOrder[i] = i;
}

//reverse array creation
for(int j = 0; j < arraySize; j++){
  reverse[j] = arraySize - j;
  }
  
//nearlySorted array creation
for(int k = 0; k < arraySize; k++){

  if(k = 99998 || k == 1){
    nearlySorted[k] = 28;
    }
    
  else{
    nearlySorted[k] = k;
    }
    
  }
  
//random array creation
for(int l = 0; l < arraySize; l++){
  int r = rand() % arraySize;
  random[l] = r;
  }
  
	  
	  
	  
  
  printf("\nWe begin by measuring the time to run our sorting algorithms without optimization...\n");
  
  //Quicksort
  printf("Quicksort is being tested...\n");
  
  //Quicksort on a sorted array
  t = clock();
  quicksort(inOrder, arraySize);
  t = clock() - t;
  printf("Quicksort took  %f seconds to run on an already sorted array.\n",  t/CLOCKS_PER_SEC);
  
  //Quicksort on an inversely sorted array
  t = clock();
  quicksort(reverse, arraySize);
  t = clock() - t;
  printf("Quicksort took  %f seconds to run on a reversely sorted array.\n",  t/CLOCKS_PER_SEC);
  
  //Quicksort on a nearly sorted array
  t = clock();
  quicksort(nearlySorted, arraySize);
  t = clock() - t;
  printf("Quicksort took  %f seconds to run on a nearly sorted array.\n",  t/CLOCKS_PER_SEC);
  
  //Quicksort on a randomly sorted array
  t = clock();
  quicksort(random, arraySize);
  t = clock() - t;
  printf("Quicksort took  %f seconds to run on an randomly sorted array.\n",  t/CLOCKS_PER_SEC);
  
  //Mergesort
  printf("Mergesort is being tested...\n");
  
  //Mergesort on a sorted array
  t = clock();
  mergesort(inOrder, arraySize);
  t = clock() - t;
  printf("Mergesort took  %f seconds to run on an already sorted array.\n",  t/CLOCKS_PER_SEC);
  
  //Mergesort on an inversely sorted array
  t = clock();
  mergesort(reverse, arraySize);
  t = clock() - t;
  printf("Mergesort took  %f seconds to run on a reversely sorted array.\n",  t/CLOCKS_PER_SEC);
  
  //Mergesort on a nearly sorted array
  t = clock();
  mergesort(nearlySorted, arraySize);
  t = clock() - t;
  printf("Mergesort took  %f seconds to run on a nearly sorted array.\n",  t/CLOCKS_PER_SEC);
  
  //Mergesort on a randomly sorted array
  t = clock();
  mergesort(random, arraySize);
  t = clock() - t;
  printf("Mergesort took  %f seconds to run on an randomly sorted array.\n",  t/CLOCKS_PER_SEC);
  
  
  return 0;
  
  }
  
  
