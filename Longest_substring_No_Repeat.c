#include<stdio.h>
#include<string.h>
#define N 50000

int lengthofLongestSubstring(char *s){
    int maxascii,j=0,i=0;
    while(s[i]!='\0'){
      maxascii=maxascii>s[i]?maxascii:s[i];
      i++;
    }
    //printf("%d\n",maxascii);
    int charcount[maxascii+1];
    if(strlen(s)==0)
       return 0;
    if(strlen(s)==1)
       return 1;
    for(int i=0;i<=maxascii;i++)
        charcount[i]=-1;
    int maxlen=0,len=0;
    while(s[j]!='\0')
    {
         if(charcount[s[j]]==-1)
         {
            charcount[s[j]]=j;
            len++;
            maxlen=len>maxlen?len:maxlen;
         }
         else if(charcount[s[j]]<(j-len))
         {
           charcount[s[j]]=j;
           len++;
           maxlen=len>maxlen?len:maxlen;
         }
         else{
          maxlen=len>maxlen?len:maxlen;
          len=j-charcount[s[j]];
          charcount[s[j]]=j;
         }
         j++;
    }
    return maxlen;

}

void main()
{
    
    char s[N];
    scanf("%s",s);
    printf("%d",lengthofLongestSubstring(s));

}