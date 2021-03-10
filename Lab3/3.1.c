#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

int main()
{
    printf("Array size\n");
    int n, i;
    scanf("%d",&n);
    int arr[n];

    for (i=0;i<n;i++)
    {
        arr[i]=n-i;
        
    }
    clock_t start_t, end_t;

    start_t = clock();
    insertionSort(arr,n);
    end_t = clock();
    float total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Time Taken worst case = %f\n",total_t);

    for(i =0;i<n;i++)
    {
        arr[i]=rand()%n;
        
    }

    start_t = clock();
    insertionSort(arr,n);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Time Taken average case = %f\n",total_t);

    for(i =0;i<n;i++)
    {
        arr[i]=i;
        
    }

    start_t = clock();
    insertionSort(arr,n);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Time Taken best case = %f\n",total_t);
    
    return 0;
}
