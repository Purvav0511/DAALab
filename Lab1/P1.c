#include<stdio.h>

#include<stdlib.h>


int main()
{
    int i,n;

    printf("Enter a number\n");
    scanf("%d",&n);
    int a[n];
    int max=0,min=32767;
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        printf("%d  ", a[i]);
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }

    
    printf("\n Largest Number : %d\n",max);
    printf("Minimum Number : %d\n",min);
    
}
