#include<stdio.h>
#include<time.h>
double insertion(int a[],int n,int k)
{
	clock_t start_t,end_t,total_t;
	k++;
	int i,j,temp;
	double f=0.0;
	start_t=clock();
	for(i=1;i<n;i++)
	{
		temp=a[i];f++;
		for(j=i-1;j>=0;j--)
			{
			    f++;
			    if(a[j]>temp)
                   {
                       f++;
                       a[j+1]=a[j];f++;
                   }
                else
                   {
                       break;
                       f++;
                   }
			}
		a[j+1]=temp;f++;
	}
	end_t=clock();
	double t=(double)(end_t - start_t)/CLOCKS_PER_SEC;
	if(k==10)
    {
        printf("\tTime count is : %f\t",t);
        insertion(a,n,k);
        return t;
    }
    else if(k==11)
    {
        printf("\tTime count is : %f\t",t);
        int b[n];
        for(i=0;i<n;i++)
            b[i]=a[n-i-1];
        insertion(b,n,k);
        return t;
    }
    else if(k==12)
    {
        printf("\tTime count is : %f\t",t);
        return t;
    }

    return t;

}
void main()
{
    int m[50000],n, c, i, j;
    double f=0.0;
    int b[50000];
	for(c=1;c!=0;)
    {

	printf("\n\n\n MENU \n0. Exit\n1. n Random numbers=>Array\n2. Display the Array\n3. Sort the Array in Ascending Order by using Insertion SortAlgorithm \n4. Sort the Array in Descending Order by using any sorting algorithm\n5. Time Complexity to sort ascending of random data\n6. Time Complexity to sort ascending of data already sorted in ascending order\n7. Time Complexity to sort ascending of data already sorted in descending order\n8. Time Complexity to sort ascending of data for all Cases (Ascending, Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000\n\nEnter Choice : ");
    scanf("%d",&c);
    if(c==1)
    {
      printf("\nEnter n : ");
      scanf("%d",&n);
      for(i=0;i<n;i++)
            m[i]=(rand()%n)+0;
    }
   else if(c==2)
       {
           for(i=0;i<n;i++)
            printf("\t%d",m[i]);
       }
    else if(c==3)
    {
        f=insertion(m,n,100);
        //for(int i=0;i<n;i++)
            //printf("\t%d",m[i]);
            printf("\nSorting Completed\n");

    }
    else if(c==4)
    {

        for(i=0;i<n;i++)
            b[i]=m[n-i-1];
        //for(int i=0;i<n;i++)
            //printf("\t%d",b[i]);
        printf("\nSorting Completed\n");
    }
    else if(c==5)
    {
        printf("\nFrequency for Random Data is : %f",f);
    }
    if(c==6)
    {
        f=insertion(m,n,100);
        printf("\nFrequency for already Ascending sorted Data is : %f",f);
    }
    if(c==7)
    {
         f=insertion(b,n,100);
         printf("\nFrequency for already Descending sorted Data is : %f",f);
    }
    if(c==8)
   {
	printf("N Value\t\t\tIn Random Order\t\t\tIn Ascending Order\t\tIn Descending Order");
	printf("\n_______________");
	int n,i;
    for(j=5000;j<=50000;j+=5000)
	{
	    printf("\n%d\t",j);
	    int a[j];
	    for(i=0;i<j;i++)
            a[i]=(rand()%j)+0;
	    insertion(a,j,9);
	    printf("\n");
	}

}
 }
}
