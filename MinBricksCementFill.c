#include<stdio.h>
#include<string.h>


int findminbricks(int arr[],int s,int e)
{
   if(e-s<2)
	   return 0;
   int i=s,j=s+1,sum=0,flag=0;
   while(j<=e)
   {
      flag=0;
	  if(arr[j]>=arr[i])
	  {
		 int level=arr[i];
		 flag=1;
	     while(i<j)
		 {
		    sum+=(level-arr[i]);
			//printf("%d\n",sum);
			i++;
		 }
	  }
	  j++;
   }
   if(flag==0)
	   return sum+findminbricks(arr,i+1,e);
   return sum;
   
}


void main()
{
    int length;
	
	scanf("%d",&length);
	
	int array[length];
	
	for(int i=0;i<length;i++)
		scanf("%d",&array[i]);
	
	//for(int i=0;i<length;i++)
	//	printf("%d ",array[i]);
    
	printf("%d",findminbricks(array,0,length-1));
 
 

}