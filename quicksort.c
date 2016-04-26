#include "quicksort.h"
void quicksort(long int arr[]) {
    quicksort_body(arr, arr[0],  arr[sizeof(arr)/sizeof(arr[0])]);
}

void quicksort_body(long int arr[], int left, int right) {       
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
        quickSort(arr, left, j);  
    if (i < right)
        quickSort(arr, i, right);   
}

