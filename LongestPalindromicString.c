#include<stdio.h>
#include<string.h>
#define N 1000

int checkpalindrome(char *s,int start,int end)
{
     int i=start,j=end;
	 
	 while(i<=j)
	 {
	      if(s[i]!=s[j])
			  return 0;
		  //printf("%c %c\n",s[i],s[j]);
		  i++;
		  j--;
	 }
     return 1;	 
}

char * longestPalindrome(char * s){
    int len=strlen(s);
	int end=len-1;
	static char result[N];
	//printf("%d %d",len,end);
	if(len<=1)
		return s;
	while(len>1)
	{
	   for(int i=0;s[i+len-1]!='\0';i++)
	   {
	        if(1==checkpalindrome(s,i,i+len-1))
			{
			   int c=0;
			   for(int j=i;j<=i+len-1;j++)
                  	result[c++]=s[j];
			   result[c]='\0';
			   return result;
			}
	   }
       len--;	   
	}
	result[0]=*s;
	result[1]='\0';
	return result;
	
}

void main()
{
   char buffer[N];
   scanf("%s",buffer);
   printf("%s",longestPalindrome(buffer));
}