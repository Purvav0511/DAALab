#include <stdio.h>
#include<stdlib.h>



int main(){
	int n, i, j;
	printf("\n Enter the size of the matrix: ");
	scanf("%d", &n);
	int a[n][n];

	for(i=0;i<n;i++)
    {
		for( j=0;j<n;j++)
        {
			a[i][j] = rand() % 10;	
		}
	}

	for(i=0;i<n;i++)
    {
		for( j=0;j<n;j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

    int nonZero = 0;
	for(i=0;i<n;i++)
    {
		for( j=0;j<n;j++)
        {
			if(a[i][j] != 0)nonZero++;
		}

	}	
   
    int sum= 0;
	for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
        {
			if(j>i)
				sum+=a[i][j];
		}
	}
    printf("a) Number of non-zero elements: %d\n",nonZero);
	printf("b) Sum of elements above the leading diagonal: %d\n",sum);
	printf("c) Elements below the minor diagonal: ");
    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i+j >= n){
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");

	int major_product =1;
	int minor_product =1;

	for(i=0;i<n;i++){
		major_product *= a[i][i];
		minor_product *= a[i][n-i-1];
	}
    printf("d) Major Diagonal: %d\nMinor Diagonal: %d\n", major_product, minor_product);
	return 0;
}
