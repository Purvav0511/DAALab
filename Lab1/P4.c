#include<stdio.h>
#include<stdlib.h>


void swapThree(int *a, int *b, int *c)
{
// Store sum of all in a
*a = *a + *b + *c; // (a = 60)

// After this, b has value of a
*b = *a - (*b+*c); // (b = 60 – (20+30) =10)

// After this, c has value of b
*c = *a - (*b+*c); // (c = 60 – (10 + 30) = 20)

// After this, a has value of c
*a = *a - (*b+*c); //(a = 60 – (10 + 20) = 30)
}

// Driver code
int main()
{
    int a = 10, b = 20, c = 30;

    printf("Value before swapping:\n");
    printf("a = %d \nb = %d \nc = %d\n", a, b, c);

    swapThree(&a,&b,&c);

    printf("Value after swapping:\n");
    printf("a = %d \nb = %d \nc = %d", a, b, c);


    return 0;
}
