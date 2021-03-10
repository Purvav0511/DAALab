#include <stdio.h>
#include<stdlib.h>
 
void knapsack(int n, int v[], int c[], int w) {
    int curr_w, i;
    float tot_v;
    int maxi;
    int used[1000];
 
    for (i = 0; i < n; ++i)
        used[i] = 0; 
 
    curr_w = w;
    while (curr_w > 0) { 
        maxi = -1;
        for (i = 0; i<n; ++i)
            if ((used[i] == 0) &&((maxi == -1) || ((float)v[i]/c[i] > (float)v[maxi]/c[maxi]))) 
                maxi = i;
 
        used[maxi] = 1; 
        cur_w -= c[maxi]; 
        tot_v += v[maxi];
        if (cur_w >= 0)
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, v[maxi], c[maxi], curr_w);
        else {
            printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n", (int)((1 + (float)curr_w/c[maxi]) * 100), v[maxi], c[maxi], maxi + 1);
            tot_v -= v[maxi];
            tot_v += (1 + (float)curr_w/c[maxi]) * v[maxi];
        }
    }
 
    printf("Filled the bag with objects worth %.2f$.\n", tot_v);
}
 
int main() {
	int n, w, i; 
	
	printf("\n Enter the number of objects: ");
	scanf("%d", &n);
	int c[n], v[n];
	printf("\n Enter the weight of Knapsack: ");
	scanf("%d", w);
	printf("\n Enter the cost of the objects: ");
	for(i=0;i<n;i++){
		scanf("%d", v[i]);
	}
	printf("\n Enter the weight of the objects: ");
	for(i=0;i<n;i++){
		scanf("%d", c[i]);
	}
    knapsack(n,v,c,w);
 
    return 0;
}
