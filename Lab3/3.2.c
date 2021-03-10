#include <stdio.h>
#include <math.h>

int checkOccurance1(int arr[], int n)
{
	int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                return 1;
        }
    }
    return 0;
}

int checkOccurance2(int arr[], int n)
{
	int i;
    int count = 0;
    for (i = 0; i < n; i++) 
    { 
        int index = arr[i] % n; 
        arr[index] += n; 
    }
    for (i = 0; i < n; i++) 
    { 
        if ((arr[i]/n) > 1) 
            count = 1; 
    }
    return count;
}

int main()
{
    int length = 0;
    int i;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    int arr[length];
    for (i = 0; i < length; i++)
    {
        arr[i] = rand() % 5;
    }
    printf("Your Array: ");
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    if (checkOccurance2(arr, length))
    {
        printf("\nNumbers Repeat\n");
    }
    else
    {
        printf("\nNumbers Don't Repeat\n");
    }
    return 0;
}
