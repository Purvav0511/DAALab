#include<stdio.h>
int main(){
    int start[1000];
    int finish[1000],n, k;
	printf("\nEnter no of activities: ");
	scanf("%d",&n);
	printf("\nEnter start time: ");
	for(k=0; k<n; k++)
		scanf("%d",&start[k]);
	printf("\nEnter finish time: ");
	for(k=0; k<n; k++)
		scanf("%d",&finish[k]);
    int activities = n;
    int i, j;
    printf ("\nFollowing activities are selected \n\t");
    i = 0;
    printf("%d\t", i);
    for (j = 1; j < activities; j++){
       if (start[j] >= finish[i]){
          printf ("%d ", j);
          i = j;
       }
    }
printf("\n");
    return 0;
}
