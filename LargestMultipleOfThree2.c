#include<stdio.h>

void main()
{
   static int array[10];
   char ch;
   int sum=0;
   while('\n'!=(ch=getchar()))
   {
      array[ch-'0']++;
      sum+=ch-'0';
   }
   
   //Printing the frequency of digits
   /*for(int i=0;i<10;i++)
     printf("%d",array[i]);*/
   
   //printf("%d",sum);
   
   if(sum%3==0)
   {
       for(int j=9;j>=0;j--)
       {
          for(int i=0;i<array[j];i++)
              printf("%d",j); 
       }
       //printf("part1");
   }
   else{
   //printf("Part2");
   int rem=sum%3;
   if(rem==1)
   {
       int flag=0;
       for(int i=0;i<9;i++)
        {
           if(array[1]!=0){
              array[1]--;
              flag=1;
              break;
              }
           else if(array[4]!=0){
             array[4]--;
             flag=1;
             break;
             }
           else if(array[7]!=0){
             array[7]--;
             flag=1;
             break;
             }      
        }
       if(flag==0)
       {
         
         
            if(array[2]>=2){
               array[2]--;
               array[2]--;
               }
            else if(array[2]==1 && array[5]==1)
            {
                array[2]--;
                array[5]--;
                
            }   
            else if(array[2]==1 && array[8]==1)
            {
                array[2]--;
                array[8]--;
                
            }
            else if(array[5]>=2)
            {
                array[2]--;
                array[2]--;
                
            }
            else if(array[5]==1 && array[8]==1)
            {
                 array[5]--;
                 array[8]--;
                 
            }
            else if(array[8]>=2)
            {
                 array[8]--;
                 array[8]--;
                
            }   
          }
        
       
       
       for(int j=9;j>=0;j--)
       {
          for(int i=0;i<array[j];i++)
              printf("%d",j);     
       }
          
   }
   if(rem==2)
   {
       int flag=0;
       for(int i=0;i<9;i++)
        {
           if(array[2]!=0){
              array[2]--;
              flag=1;
              break;
              }
           else if(array[5]!=0){
             array[5]--;
             flag=1;
             break;
             }
           else if(array[8]!=0){
             array[8]--;
             flag=1;
             break;
             }      
        }
       if(flag==0)
       {
           
            if(array[1]>=2){
               array[1]--;
               array[1]--;
               }
            else if(array[1]==1 && (array[4]==1))
            {
                array[1]--;
                array[4]--;
               
            }   
            else if(array[1]==1 && (array[7]==1))
            {
                array[1]--;
                array[7]--;
                
            }
            else if(array[4]>=2)
            {
                array[4]--;
                array[4]--;
                
            }
            else if(array[4]==1 && array[7]==1)
            {
                 array[4]--;
                 array[7]--;
                 
            }
            else if(array[7]>=2)
            {
                 array[7]--;
                 array[7]--;
                 
            }   
          }
        
       
       
       for(int j=9;j>=0;j--)
       {
          for(int i=0;i<array[j];i++)
              printf("%d",j); 
       }
          
   }
   
  }
   
}
