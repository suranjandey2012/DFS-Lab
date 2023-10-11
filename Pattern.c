#include<stdio.h>



void main()
{
   int n;
   scanf("%d",&n);
   int array[n][n];
   //Input array
   for(int i=0;i<n;i++){
     for(int j=0;j<n;j++)
          scanf("%d",&array[i][j]);
     }
   //Print values  
  /*for(int i=0;i<n;i++){
     for(int j=0;j<n;j++)
          printf("%d",array[i][j]);
     printf("\n");     
     }*/
     
   //Part1  
   for(int i=0;i<n;i++)
   {
      int r=i,j=0;
      for(int s=0;s<n-i-1;s++)
             printf("  "); 
      while(r>=0)
      {
                 
          printf(" %d  ",array[r][j]);
          r--;j++;
          
      }
      printf("\n");
      
   }
   
   
   
   //Part2
   for(int i=1;i<n;i++)
   {
      int r=n-1,j=i;
      
      for(int s=0;s<i;s++)
         printf("  ");
      while(r>=i)
      {
          printf(" %d  ",array[r][j]);
          r--;j++;
      }
      printf("\n");
      
      
   }
        
}
