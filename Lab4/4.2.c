/*Write a program to sort a list of n elements using the merge sort method and determine
the time required to sort the elements. Repeat the experiment for different values of n
and different nature of data (random data, sorted data, reversely sorted data) in the list.
n is the user input and n integers can be generated randomly. Finally plot a graph of the
time taken versus n.*/


#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
   
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
   
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
         
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
}  

int main()
{
    clock_t start_t, end_t;
    double total_t;
    int n,key,i;
    printf("Enter array size:\t");
    scanf("%d",&n);
    int arr[n];
    int low = 0, high = n-1;

    printf("\nSorted....\n");
    for(i =0; i<n; i++)
    {
        arr[i] = i;
    }


    start_t = clock();
    mergeSort(arr,low,high);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  
    printf("Time Taken = %f\n\n",total_t);

    printf("\nRandom....\n");
    for(i =0; i<n; i++)
    {
        arr[i] = rand()%n;
    }


    start_t = clock();
    mergeSort(arr,low,high);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Time Taken = %f\n\n",total_t);


    printf("\nReverse Sorted....\n");
    for(i =0; i<n; i++)
    {
        arr[i] = n-i;
    }


    start_t = clock();
    mergeSort(arr,low,high);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Time Taken = %f\n\n",total_t);

	return 0;
	

}
