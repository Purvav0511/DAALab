#include <stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,n;

    printf("Enter a number\n");
    scanf("%d",&n);

    int a[n];

     for(i=0;i<n;i++)
    {
		a[i] = rand()%100;
    }

    for(i=0;i<n;i++)
    {
		printf("%d ", a[i]);
	}
    printf("\n");
    for(i=0;i<n-1;i++)
    {
        if(a[i]%2!=0)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]%2==0)
                {
                    int t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                    break;
                }
            }
        }
    }
    printf("\n After seperating odd and even: \n");
    for(i=0;i<n;i++)
    {
		printf("%d ", a[i]);
	}
}
