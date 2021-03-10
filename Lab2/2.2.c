#include <stdio.h> 
  
// Euclid's Algorithm
int counter1=0,counter2=0,counter3=0;
int algo1(int a, int b) 
{ 
    if (a == 0) 
    {
        counter1++;
        return b; 
    }
    return algo1(b%a, a);
    counter1++; 
} 
  
// Consecutive Algorithm checking

int algo2(int m,int n)
{ 
    int t; counter2++;
    if(m<n)
    { 
        counter2++;
        t=m;
        counter2++;
    }
    else
    {
        
        counter2++;
        t=n;
        counter2++;
    
    }
    while(t>0)
    {
        counter2++;
        if(m%t==0)
        {
            counter2++;
            if(n%t==0)
            {
                 counter2++;
                return t;
               
            }
        }
        t--; counter2++;
    }
}
//Prime Number Method
int algo3(int a, int b) 
{ 
   
    if (a == 0)
    {
        counter3++;
       return b; 
    }
    if (b == 0) 
    {
        counter3++;
       return a; 
    }
    
    if (a == b) 
    {
        counter3++;
        return a; 
    }
    
    if (a > b) 
    {
        counter3++;
        return algo3(a-b, b);
    } 
    return algo3(a, b-a); 
    counter3++;
} 

int main() 
{ 
    int a[]={31415,56,34218,12,31415,12};
    int b[]={14142,32566,56,15,31415,12};
    int i;
    printf("Numbers\t\t\tGCD by algo1\tSteps of Algo1\tGCD by algo2\tSteps of Algo2\tGCD by algo3\tSteps of Algo3\tFaster\n");
    for(i=0;i<6;i++)
    {
        counter1=0;
        counter2=0;
        int p1=algo1(a[i],b[i]);
        int p2=algo2(a[i],b[i]);
        int p3=algo3(a[i],b[i]);
       
        printf("GCD of (%d,%d)\t\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d",a[i],b[i],p1,counter1,p2,counter2,p3,counter3);
        if(counter1<counter2 && counter1<counter3)
        {
            printf("\t\talgo1 is having least step\n");
        }
        else if(counter2<counter3 && counter2<counter1)
        {
            printf("\t\talgo2 is having least step\n");
        }
        else
        {
            printf("\t\talgo3 is having least step\n");
        }
    }
}
