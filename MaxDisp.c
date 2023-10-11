#include<stdio.h>
#include<stdlib.h>

void main()
{
   int n;
   
   scanf("%d",&n);
   int array1[n];
   int array2[n];
   //Array A Input
   for(int i=0;i<n;i++)
     scanf("%d",&array1[i]);
   
   //Array B Input
   for(int i=0;i<n;i++)
     scanf("%d",&array2[i]);
   
   
   //Print Array1 and Array21 2
   /*for(int i=0;i<n;i++)
      printf("%d ",array1[i]);
   for(int j=0;j<n;j++)
      printf("%d ",array2[j]); */      
   int maxdisp=-1;
   int minval=array1[0];
   int minindex=-1,maxindex=-1;
   for(int i=0;i<n;i++)
   {
      
      for(int j=0;j<n;j++)
      {
         if(array1[i]==array2[j]){
              /*maxdisp=abs(i-j)>maxdisp?abs(i-j):maxdisp;
              if(array1[i]<minval){
                  minval=array1[i];
                  minindex=(i<=j)?i:j;
                  maxindex=(i>=j)?i:j;
                  }
              break;*/
              
              if(abs(i-j)>maxdisp)
              {
                 maxdisp=abs(i-j);
                 minval=array1[i];
                 minindex=(i<=j)?i:j;
                 maxindex=(i>=j)?i:j; 
              }
              else if(abs(i-j)==maxdisp){
                 if(array1[i]<minval)
                 {
                    maxdisp=abs(i-j);
                    minval=array1[i];
                    minindex=(i<=j)?i:j;
                    maxindex=(i>=j)?i:j; 
                 
                 }
              
              }
              
              break;
              }    
      }
   }
   
   printf("%d %d %d",minval,minindex,maxindex);

}

