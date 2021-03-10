#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxSumOn2(int *p, int n)
{
	int i, j;
    int max = INT_MIN;
    for (i = 0; i < n; ++i)
    {
        int sum = 0;
        for (j = i; j < n; ++j)
        {
            sum += p[j];
            if (sum > max)
            {
                max = sum;
            }
        }
    }

    return max;
}

void main()
{
    int n, i;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    int *p = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
        *(p + i) = rand()%10;
        printf("%d \t", p[i]);
    printf("Maximum sum = %d\n", maxSumOn2(p, n));
}
