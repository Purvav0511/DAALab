
#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n,b;
    int i, j;
    printf("Enter value of n \n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i] = rand()%(n*2);
    }
    printf("\n The array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
      for (i = 0; i < n; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if (a[i] < a[j])
                {
                    b = a[i];
                    a[i] = a[j];
                    a[j] = b;
                }
            }
 
        }
    printf(" Second Smallest Number: %d\n",a[n - 2]);
    printf(" Second Largest Number:%d\n",a[1]);
}
