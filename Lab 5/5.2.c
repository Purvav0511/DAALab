#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n1;
void reverseArray(int arr[], int start, int end) 
{ 
    
    int temp; 
    
    
    while (start < end) 
    { 
        temp = arr[start];    
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    
    }
} 
void min_heapify(int arr[], int n, int i)  
{  

int min=i;    
int left=(2*i)+1;  
int right=(2*i)+2;    
  
if (left<n && arr[left]<arr[min])  
    min =left;

  
if (right<n && arr[right]<arr[min])  
    min = right;  

  
if (i!= min)  
{  
     int temp = arr[i];  
        arr[i]= arr[min];   
        arr[min] = temp;  
    min_heapify(arr,n,min);  
}  
}

void heap_create(int arr[],int n){
int i;  
    for(i =((n/2)-1);i>=0;i--)  
    min_heapify(arr,n,i);  
 
}

void heap_sort(int arr[],int n){
     
    heap_create(arr,n);
    while(n>1){

        int temp=arr[0];
        arr[0]=arr[n-1];
        arr[n-1]=temp;
        n--;
        min_heapify(arr,n,0);
    }

}

int heap_extract_min(int arr[],int n){

    
    int min=arr[0];
    arr[0]=arr[n-1];
    n--;
    heap_create(arr,n);
    //min_heapify(arr,n,0);
    
    
return min;
}

void heap_replace(int arr[],int n,int key,int pos){

    arr[pos]=key;
    min_heapify(arr,n,0);

}
void heap_insert(int arr[],int *n,int new_val){
    *n=*n+1;
    //heap_replace(arr,n,new_val,n-1);
    arr[*n-1]=new_val;
    int i=*n-1;
    while(i>=0 && arr[i]>arr[(i-1)/2]){
        int temp=arr[i];
        arr[i]=arr[(i-1)/2];
        arr[(i-1)/2]=temp;
        i=(i-1)/2;
    }


}

int heap_delete(int arr[],int* n,int val){
//n1=n;
int p=*n;
int i;
    for(i=0;i<p;i++){
        if(arr[i]==val){
            int temp=arr[i];
            arr[i]=arr[p-1];
            arr[p-1]=temp;
            p--;
            //printf("%d",p);
            min_heapify(arr,p,i);
            break;
        }    

    }
return p;
}
int main(){
int i,j, k;
clock_t start_time,end_time;
double total_time;
int n,size,as,ds,rnd,*p;
char ch='y';
int *arr;
//int arr[100];
int pos,val,del;
do{
printf("\n Press 0 to exit\n Press 1 to Input Random Numbers\n Press 2 to Display the Data\n Press 3 to Sort data in Descending Order using min-heap\n Press 4 to Sort data in Ascending order using any algorithm\n Press 5 to find Time Complexity for ascending order of randomly sorted data\n Press 6 to find Time Complexity for ascending of ascending sorted data\n Press 7 to find Time Complexity for ascending of descendingly sorted data\n Press 8 to find Time Complexity for all cases of sorted data\n Press 9 to extract the minimum element\n Press 10 to replace the value of a node with a new value\n Press 11 to insert an element\n Press 12 to delete an element");

scanf("%d",&n);

    if(n==0){
        exit(0);
    }

    else if(n==1){
        
        printf("Enter the desired size of the array");
        scanf("%d",&size);
        arr=(int *)malloc(sizeof(int)*size);
        
        
            for(i=0;i<size;i++){
                arr[i]=rand()%100;
                
            }
            heap_create(arr,size);
            
        }

    else if(n==2){
        
        for(i=0;i<size;i++){
            printf("\narr[%d]=%d ",i,arr[i]);
        }
        
    }
    
    else if(n==3){
        heap_sort(arr,size);  
    }

    else if(n==4){
        heap_sort(arr,size); 
        reverseArray(arr,0,size-1); 
    }

    else if(n==5){
        start_time=clock();
         heap_sort(arr,size);
        end_time=clock();
         total_time=((double)(end_time-start_time))/CLOCKS_PER_SEC;
        printf("\nTime taken to sort data in ascending of randomn data= %f",total_time);
    }

    else if(n==6){
        heap_sort(arr,size);
        start_time=clock();
         heap_sort(arr,size);
        end_time=clock();
         total_time=((double)(end_time-start_time))/CLOCKS_PER_SEC;
        printf("\nTime taken to sort data in ascending of ascendingly sorted data= %f",total_time);
    }
    
    else if(n==7){
        heap_sort(arr,size);
        reverseArray(arr,0,size-1);
        start_time=clock();
         heap_sort(arr,size);
        end_time=clock();
         total_time=((double)(end_time-start_time))/CLOCKS_PER_SEC;
        printf("\nTime taken to sort data in ascending of descendingly sorted data= %f",total_time);
    }

    else if(n==8){
            printf("\n\t\t Worst Case\t Average Case \tBest Case\n");
            for(k=5000;k<=50000;k=k+5000){
                p=(int *)malloc(k*sizeof(int));
                
                    for(j=0;j<k;j++){
                        *(p+j)=rand()%100;
                    }
                printf("%d",k);
                heap_sort(p,k);
                reverseArray(p,0,k-1);
                start_time=clock();
                heap_sort(p,k);
                end_time=clock();
                total_time=((double)(end_time-start_time))/CLOCKS_PER_SEC;
                //printf("\nWorst Case time = %f",total_time);
                printf("\t\t%f",total_time);
                start_time=clock();
                heap_sort(p,k);
                end_time=clock();
                total_time=((double)(end_time-start_time))/CLOCKS_PER_SEC;
                //printf("\nAverage Case time for %d = %f",k,total_time);
                printf("\t%f",total_time);
                start_time=clock();
                 heap_sort(p,k);
                end_time=clock();
                 total_time=((double)(end_time-start_time))/CLOCKS_PER_SEC;
                //printf("\nBest Case time = %f",total_time);
                printf("\t%f",total_time);
                printf("\n");
            }
        }
        else if(n==9){
            heap_create(arr,size);
            int min=heap_extract_min(arr,size);
            printf("\nMinimum element is %d ",min);
        }

        else if(n==10){
            
            printf("\nEnter the position where you want to replace");
            scanf("%d",&pos);
            printf("\nEnter the new value");
            scanf("%d",&val);
            heap_create(arr,size);
            heap_replace(arr,size,val,pos);
        }

        else if(n==11){

            printf("\nEnter the element you want to insert");
            int new_val;
            scanf("%d",&new_val);
            //size++;
            heap_insert(arr,&size,new_val);
        }
        else if(n==12){

            printf("\nEnter the element you want to delete");
            scanf("%d",&del);
            int d;
                 d=heap_delete(arr,&size,del);
            size=d;
                printf("\nDeleted %d",size);

        }    
        
printf("\n Do you want to continue y/n");
scanf(" %c",&ch);
}while(ch=='y' || ch=='Y');

return 0;
}
