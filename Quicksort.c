#include<stdio.h>

int arr[10]={5,6,3,2,4,6,3,8,-3,11};

int partition(int a[],int s,int e){
    int pivot=a[s];
    int i=s+1,j=s+1,temp;
    while(j<=e){
        if(a[j]<pivot){
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
        j++;
    }
    temp=a[i-1];
    a[i-1]=pivot;
    a[s]=temp;
    return (i-1);
}

void Quicksort(int a[],int s,int e)
{
    int m;
    if(s>=e)
          return;      
    m=partition(a,s,e);
    Quicksort(a,0,m-1);
    Quicksort(a,m+1,e);
   
}

int main()
{
    int i;
    Quicksort(arr,0,9);
    for(i=0;i<10;i++)
      printf("%d ",arr[i]);
    return 0;
}