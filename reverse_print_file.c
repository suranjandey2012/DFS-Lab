#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse_print(char *s)
{
    int i,j,k;
    char temp;
    j=strlen(s)-1;
    k=j;
    while(j>=-1){
        if(' '==s[j] || -1==j){
            i=j+1;
            while(i<k){
                temp=s[i];
                s[i]=s[k];
                s[k]=temp;
                i++;k--;
            }
            k=j-1;
        }
        j--;
    }
    j=strlen(s)-1;
    while(j>-1)
        printf("%c",s[j--]);       
} 

void main(int argc,char **argv)
{
    char s[129];
    FILE *fptr=fopen(argv[1],"r");
    fscanf(fptr,"%[^\n]s",s);
    puts(s);
    //printf(reverse_print(s));
    //reverse_print(s);
    fclose(fptr);
}