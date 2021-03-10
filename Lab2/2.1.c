#include <stdio.h>
#include<stdlib.h>


int algo1(int n)
{
	int i;
    int counter=1;
    int c=0;
    for(i=1;i<=n;i++)
    {
        counter++;
        if(n%i==0)
        {
            c++;
            counter++;
        }
    }
    if(c==2){
        
        counter++;
    }
    else{
        
        counter++;
    }
    
    return counter;
}

int algo2(int n)
{
	int i;
    int counter=1,c=0;
    for(i=2;i<n;i++)
    {
        counter++;
        if(n%i==0)
        {
            counter++;
            c++;
        }
    }
    if(c==0){
        
        counter++;
    }
    else
    {
        counter++;
        
    }
    
    return counter;
}

int algo3(int n)
{
	int i, p;
    int counter=1,prime[n+1];  
    for(i=0;i<n+1;i++)
    {
        prime[i]=1;
        counter++;
    }
    for (p=2; p*p<=n; p++) 
    {
        counter++;
        if (prime[p] == 1) 
        { 
            for(i=p*p; i<=n; i += p) 
            prime[i] = 0; 
            counter++;
        } 
    }
    if(prime[n]==1){
        
        counter++;
    }
    else{
        
        counter++;
    }
    return counter;
}


int main()
{
	int i;
    printf("Number  Algo1  Algo2  Algo3  Faster\n");
    for(i=0;i<10;i++)
    {
        int n=rand()%100;

        int p1=algo1(n);
        int p2=algo2(n);
        int p3=algo3(n);

        printf("%d\t%d\t%d\t%d\t",n,p1,p2,p3);

        if(p1<p2 && p1<p3)
        {
            printf(" algo1 is having least step\n");
        }
        else if(p2<p3 && p2<p1)
        {
            printf(" algo2 is having least step\n");
        }
        else
        {
            printf(" algo3 is having least step\n");
        }
    }
}
