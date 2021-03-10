#include <stdio.h>
#include <stdlib.h>


int* activity_selection(int a[], int s[], int f[], int n) {
  int* arr = malloc(sizeof(int)*n); // array arr of size n
  arr[0] = 0; //array will start from index 1. So, fake item at index 0
  arr[1] = a[1];

  int k=1;
  int i;
  int iter = 1;

  for(i=2; i<=n; i++) {
    if(s[i] >= f[k]) {
      iter++;
      arr[iter] = a[i];
      k=i;
    }
  }

  arr[0] = iter;
  return arr;
}

int main() {
  //Arrays staring from 1. Elements at index 0 are fake
  int a[] = {0, 2, 3, 5, 1, 4};
  int s[] = {0, 0, 1, 3, 4, 1};
  int f[] = {0, 2, 3, 4, 6, 6};
  int *p = activity_selection(a, s, f, 5);

  int i;
  for(i=1; i<=p[0]; i++) {
    printf("%d\n",p[i]);
  }
  return 0;
}
