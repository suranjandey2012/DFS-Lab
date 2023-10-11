#include<stdio.h>

void main(int argc,char **argv)
{
      FILE *fptr=fopen(argv[1],"r");
      int c;
      while(EOF!=(c=fgetc(fptr)))
          printf("%c %d\n",c,c);     
}