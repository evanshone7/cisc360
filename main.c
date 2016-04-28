#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"


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
  
  
  //main function begins...
  int main( int argc, const char* argv[] ){
  
  }
  
  
