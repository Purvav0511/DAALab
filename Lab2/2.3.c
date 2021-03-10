#include<stdio.h>
#include<stdlib.h>
void init(int c);
unsigned long int n,sum,sum1,sum2,sum3,arr[50000],brr[50000];
int main(){
int c;
X : printf("1.Quit\n");
printf("2.Enter the array\n");
printf("3.Display the array\n");
printf("4.Sort in Ascending Order\n");
printf("5.Sort in Descending Order\n");
printf("6.Time complexity to sort in ascending order\n");
printf("7.Time complexity to sort ascending of data already sorted in ascending order\n");
printf("8.Time complexity to sort ascending of data already sorted in descending order\n");
printf("9.Time complexity to sort ascending of data for all cases\n\n");
printf("Enter your choice=");
scanf("%d",&c);
switch(c){
   case 1: break;
   case 2: init(c);
           break;
   case 3: init(c);
           break;
   case 4: init(c);
           break;
   case 5: init(c);
           break;
   case 6: init(c);
           break;
   case 7: init(c);
           break;
   case 8: init(c);
           break;
   case 9: init(c);
           break;
   default: printf("\nYou have Entered a Wrong Choice, Please Try again");
           break;
 }
 if(c!=1)
 goto X;
 else
 exit(0);
}

void init(int c){
	int i, j, temp;
  if(c==2){
     printf("\nEnter the size of array=");
     scanf("%d",&n);
     for(i=0;i<n;i++)
       arr[i]=rand()%10;
    }
  if(c==3){
    for(i=0;i<n;i++)
      printf("%d ",arr[i]);
      printf("\n\n");
   }
   
  if(c==4){
    sum1=0;
   for(i=0;i<n;i++){
     j=i;
     sum1+=2;
     while(j>0 && arr[j-1]>arr[j]){
        temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
        j--;
        sum1+=5;
       }
       sum1++;
     }
     sum1++;
     /*for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
       printf("\n\n");*/
    }
   if(c==5){
        int j=0;
      for(i=n-1;i>=0;i--,j++)
         brr[j]=arr[i];
      /*for(int i=0;i<n;i++)
         printf("%d ",brr[i]);
         printf("\n\n");*/
     }
    if(c==6){
      printf("\n%d\n\n",sum1);
     }
    if(c==7){
      sum2=0;
      int j,temp;
      for(i=0;i<n;i++){
       j=i;
       sum2+=2;
       while(j>0 && arr[j-1]>arr[j]){
        temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
        j--;
        sum2+=5;
       }
       sum2++;
     }
     sum2++;
     printf("\n%d\n\n",sum2);
   }
   if(c==8){
     sum3=0;
      int j,temp;
      for(i=0;i<n;i++){
       j=i;
       sum3+=2;
       while(j>0 && brr[j-1]>brr[j]){
        temp=brr[j];
        brr[j]=brr[j-1];
        brr[j-1]=temp;
        j--;
        sum3+=5;
       }
       sum3++;
     }
     sum3++;
     printf("\n%d\n\n",sum3);
   }
  if(c==9){
   sum=sum1+sum2+sum3;
   printf("\n%d\n\n",sum);
  }
 }
     
      
    
      
          
         
     
       
  
   


