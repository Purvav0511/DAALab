/*Write a program to search an element x in an array of n integers using binary search
algorithm that uses divide and conquer technique. Find out the best case, worst case and
average case time complexities for different values of n and plot a graph of the time
taken versus n. The n integers can be generated randomly and x can be choosen
randomly, or any element of the array or middle or last element of the array depending
on type of time complexity analysis.*/



#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int *x, int *y)  
{  
	int temp;
    temp = *x;  
    *x = *y;  
    *y = temp;  
}  
  
  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
     
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
int bsear(int arr[],int s,int l,int ele){

	int mid;
	if(s<=l){
		mid=(s+l)/2;
		
	if(arr[mid]==ele)
		return mid;
	else if(ele>arr[mid])
		bsear(arr,mid+1,l,ele);
	else if(ele<arr[mid])
		bsear(arr,s,mid-1,ele);
}

return -1;
}

int main(){
	
	int pos, i;
	int n,ele;
	int c;
	clock_t t1,t2;
	float t;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[100000];

	for(i=0;i<n;i++)
	arr[i]=rand()%n;
	bubbleSort(arr,n);

	while(c!=4)
	{
	printf("\n Time complexity of which case: \n 1.Best Case \n 2.Average Case \n 3.Worst Case\n 4.Quit\n");
	scanf("%d",&c);
	if(c==1)
		ele=arr[n/2];
	else if(c==2)
		ele=arr[n-2];
	else if(c==3)
		ele=arr[n-1];
	else break;

	printf("---%d---",ele);
	t1=clock();
	pos=bsear(arr,0,n,ele);
	t2=clock();
	t=(double)((t2-t1)/CLOCKS_PER_SEC);
	t=(float)t2-(float)t1;
	if(pos==-1)
		printf("\n The element searched was not found.");
	else 
		printf("\n The position of the element found is: %d",pos);

	printf("\n The time taken to find the element was: %f",t);
	}
	return 0;
}
