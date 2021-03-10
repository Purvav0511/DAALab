/*6.1 Write a program to implementation of Fractional Knapsack algorithm.*/

#include <stdio.h>
#include<stdio.h>

void knapsack(int n, int c[], int v[], int W)
{
	int curr_w;
	float tot_v;
	int i, obj;
	int used[1000];
	for (i = 0; i < n; ++i)
		used[i] = 0; 
	curr_w = W;
	while (curr_w > 0)
	{ 
         obj= -1;
	     for (i = 0; i < n; ++i)
			if ((used[i] == 0) && ((obj == -1) || ((float)v[i]/c[i] > (float)v[obj]/c[obj])))
				obj = i;
		used[obj] = 1; 
		curr_w -= c[obj]; 
		tot_v += v[obj];

    	if (curr_w >= 0)
		printf("Added object %d (%dRs, %dKg) completely in the bag. Space left: %d.\n", obj + 1, v[obj], c[obj], curr_w);

       	else
		{
			printf("Added %d%% (%dRs, %dKg) of object %d in the bag.\n", (int)((1 + (float)curr_w/c[obj]) * 100), v[obj], c[obj], obj + 1);
			tot_v -= v[obj];
			tot_v += (1 + (float)curr_w/c[obj]) * v[obj];
        }
    }

     printf("Filled the bag with objects worth %.2fRs.\n", tot_v);
}

int main(int argc, char *argv[]) 
{
	int n, v[1000], c[1000], W, i;	
	printf("\nEnter number of objects: ");
	scanf("%d",&n);
	printf("\n Enter weight of the objects: ");
	for(i=0; i<n; i++)
		scanf("%d",&c[i]);
	printf("\n Enter the value of each object: ");
	for(i=0; i<n; i++)
		scanf("%d",&v[i]);
	printf("Enter knapsack weight: ");
	scanf("%d",&W);
	knapsack(n,c,v,W);
	return 0;
}
