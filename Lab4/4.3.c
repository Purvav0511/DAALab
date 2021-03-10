/*Write a program to use divide and conquer method to determine the time required to find
the maximum and minimum element in a list of n elements. The data for the list can be
generated randomly. Compare this time with the time taken by straight forward
algorithm or brute force algorithm for finding the maximum and minimum element for
the same list of n elements. Show the comparison by plotting a required graph for this
problem.*/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//Divide and Conquer
int min = INT_MAX,max = INT_MIN;
int arr[] = {76,54,19,36,11,96,47,78,4};
int minmax(int start,int end)
{
	int min1,max1;
	if(start==end)	//one element
	{
		if(max<arr[start])
			max=arr[start];
		if(min>arr[start])
			min=arr[start];
		return arr[start];
	}
	if(start-end==1)	//two elements
	{
		if(arr[start]<arr[end])
		{
			if(max<arr[end])
				max =  arr[end];
			if(min>arr[start])
				min = arr[start];
		}
		else
		{
			if(max<arr[start])
				max =  arr[start];
			if(min>arr[end])
				min = arr[end];
		}
		return 0;
	}
	int middle;
	
	middle = (start+end)/2;
	minmax(start,middle);
	min1=min;
	max1=max;
	minmax(middle+1,end);
	if(min>min1)
		min=min1;
	if(max>max1)
		max=max1;
	return 0;
}
void main()
{
	int n = 9;
	int k = minmax(0,8);
	printf("The min and max elements are:%d\t%d\n",min,max);
}
