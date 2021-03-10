#include<stdio.h>

#include<stdlib.h>


int main()
{
    int i,n;

    printf("Enter a number\n");
    scanf("%d",&n);
    int a[100];
    int key[n];
    for( i=0;i<100;i++)
        a[i]=0;


    for(i=0;i<n;i++)
    {
		int k = rand()%10;
        printf("%d ",k);
        a[k]++;
        key[i]=k;
	}
    
    int m=0,c=0,k;
    for(i=0;i<n;i++)
    {
        if(a[key[i]]>1)
        {
            c++;
            printf("\n%d %d\n",key[i],a[key[i]]);
        }
        if(a[key[i]]>m)
        {
            m=a[i];
            k=i;
        }
    }

    printf("No. of duplicate elements %d \n",c);
    printf("Most duplicate elements %d \n",k);
}

