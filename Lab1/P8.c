#include<stdio.h>
#include<stdlib.h>



public int[] product_without_self(int[] arr) {
    int[] result = new int[arr.length];
    result[result.length-1] = 1;
    int i;
  
    for(i=arr.length-2; i>=0; i--) {
        result[i] = result[i+1] * arr[i+1];
    }
  
    int left = 1;
    for(i=0; i<arr.length; i++) {
        result[i] *= left;
        left *= arr[i];
    }
  
    return result;
}

