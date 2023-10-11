#include<stdio.h>

void main(int argc,char **argv){
    FILE *fptr=fopen(argv[1],"r");
    char sequence[100];
    fscanf(fptr,"%s",sequence);
    //printf("%s",sequence);
    int i=0,zcount=0,ocount=0;
    while(sequence[i]!='\0')
    {
        if(sequence[i]=='0')
           zcount++;
        else
          ocount++;
        i++;
    }
    while(0!=zcount--)
       printf("0");
    while(0!=ocount--)
       printf("1");   
    fclose(fptr);
}