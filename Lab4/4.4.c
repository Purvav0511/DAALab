/*Write a program that uses a divide-and-conquer algorithm/user defined function for the
exponentiation problem of computing an where a > 0 and n is a positive integer. How
does this algorithm compare with the brute-force algorithm in terms of number of
multiplications made by both algorithms.*/

#include<stdio.h>
#include<stdlib.h>

long power(int a,int n)
{
	if(n==0)
		return 1;
	if(a==0)
		return 0;
	if(n%2==0)
		return power(a*a,n/2);
	else
		return a*power(a*a,n/2);
}
void main()
{
	int x,y;
	printf("Enter the number and exponent: ");
	scanf("%d%d",&x,&y);
	long z=power(x,y);
	printf("The calculated value is %ld.\n",z);
}
