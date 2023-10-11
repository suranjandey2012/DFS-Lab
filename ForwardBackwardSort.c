#include<stdio.h>

void fbsort(int arr[],int start,int end,char filename[100])
{
    int swaps,len=end;
    do
    {
        swaps=0;
        for(int i=start;i<=end-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                swaps++;
            }
            
        }
        end--;
        for(int i=end;i>=start+1;i--)
        {
            if(arr[i]<arr[i-1]){
                int temp=arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=temp;
                swaps++;
                }
        }
        start++;
    
    }while(swaps!=0);
    FILE *fptr=fopen(filename,"w");

    for(int i=0;i<=len;i++){
        printf("%d ",arr[i]);
        fprintf(fptr,"%d ",arr[i]);
    }
    fclose(fptr); 
}

void main(int argc,char **argv)
{
    FILE *fptr=fopen(argv[1],"r");
    int array[100];
    int start=0,end=0;
    while(1==fscanf(fptr,"%d",(array+end)))
           end++;
    /*for(int i=0;i<end;i++)
           printf("%d ",array[i]);*/       
    fclose(fptr);
    fbsort(array,start,--end,argv[1]);
    
}