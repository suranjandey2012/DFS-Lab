#include<stdio.h>
#include<string.h>


void main()
{
    int i;
	char buffer[100];
    do{
    	fgets(buffer,sizeof(buffer),stdin);
    	for (i=0;i<strlen(buffer);i++)
    	{
    		if(buffer[i]<=90 && buffer[i]>=65)
    		   buffer[i]=buffer[i]+32;
		}
		for(i=0;i<strlen(buffer)-1;i++)
		{
			if((buffer[i]>=97 && buffer[i]<=122) && (buffer[i+1]>=97 && buffer[i+1]<=122) && (buffer[i]<=buffer[i+1]))
			    printf("%c%c %d\n",buffer[i],buffer[i+1],1);
		}
	}while(strlen(buffer)!=0);
}
