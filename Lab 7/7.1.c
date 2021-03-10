#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}   

void lcs( char *x, char *y, int m, int n ) 
{ 
	int c[m+1][n+1];
	char b[m][n]; 
	int i, j;
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			b[i][j] = '0';
	}
	  
	for (i=0; i<=m; i++) 
   	{ 
   		for (j=0; j<=n; j++) 
     	{ 
       		if (i == 0 || j == 0)
         		c[i][j] = 0; 
       		else 
       		if (x[i-1] == y[j-1])
       		{
         		c[i][j] = c[i-1][j-1] + 1;
         		b[i-1][j-1] = 'L';
       		} 
       		else
       		if(c[i-1][j] >= c[i][j-1])
       		{
       			c[i][j] = c[i-1][j];
       			b[i-1][j-1] = '^';
       		}
       		else
       		{
       			c[i][j] = c[i][j-1];
       			b[i-1][j-1] = '<';
       		} 
     	} 
   	}     
   	int index = c[m][n];     
   	char lcs[index+1]; 
   	lcs[index] = '\0'; 
   	i = m, j = n; 
   	while (i > 0 && j > 0) 
   	{ 
   
      	if (x[i-1] == y[j-1]) 
      	{ 
       	 	lcs[index-1] = x[i-1]; 
         	i--; j--; index--;      
      	} 

      	else 
      	if (c[i-1][j] > c[i][j-1]) 
        	i--; 
      	else
         	j--; 
   	} 
  
   	printf("\n The strings are: %s and %s",x, y);
   	
   	printf("\n The b-table :- \n");
   	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			printf(" %c ",b[i][j]);
		printf("\n");
	}
	
   	printf("\n The c-talbe :- \n");
   	for(i=0; i<=m; i++)
	{
		for(j=0; j<=n; j++)
			printf(" %d ",c[i][j]);
		printf("\n");
	}
	
   	printf("\n LCS is %s \n", lcs);
} 
  

int main() 
{ 
	char X[50],Y[50];
	printf("enter first sequence :- \n");
	scanf("%s",X);
	printf("enter second sequence :- \n");
	scanf("%s",Y); 
  	int m = strlen(X); 
  	int n = strlen(Y); 
  	lcs(X, Y, m, n); 
  	return 0; 
}
