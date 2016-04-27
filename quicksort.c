#include "quicksort.h"
void quicksort(int* arr, int n) {
  quicksort_body(arr, 0, n);
}

void quicksort_body(int* arr, int left, int right) {       
    int i = left, j = right;  
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;  
        while (arr[j] > pivot)    
            j--;
        if (i <= j) {   
            tmp = arr[i]; 
            arr[i] = arr[j];    
            arr[j] = tmp; 
            i++;    
            j--;  
        } 
    }
    if (left < j)
        quicksort_body(arr, left, j);  
    if (i < right)
        quicksort_body(arr, i, right);   
}

