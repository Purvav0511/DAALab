#include<stdio.h>
#include<math.h>
double squareroot(int number)
{

    float temp, sqrt;


    // store the half of the given number e.g from 256 => 128
    sqrt = number / 2;
    temp = 0;

    // Iterate until sqrt is different of temp, that is updated on the loop
    while(sqrt != temp){
        // initially 0, is updated with the initial value of 128
        // (on second iteration = 65)
        // and so on
        temp = sqrt;

        // Then, replace values (256 / 128 + 128 ) / 2 = 65
        // (on second iteration 34.46923076923077)
        // and so on
        sqrt = ( number/temp + temp) / 2;
    }

    printf("The square root of '%d' is '%f'", number, sqrt);
    return sqrt;
}

int main(){
	int num;
	double root;
	printf("\n Enter the number to compute: ");
	scanf("%d", &num);
	
	root=squareroot(num);
	root=floor(root);
	printf("\n After computing the number is %f",  root);
	
	return 0;
}
