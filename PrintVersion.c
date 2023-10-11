#include<stdio.h>
#include<string.h>

void printversion(int version,int n)
{
   char pversion[2*n];
   int i=0;
   while(version!=0)
   {
     int rem=version%10;
     pversion[i++]=rem+'0';
     version=version/10;
     if(version!=0)
       pversion[i++]='.';
   }
   pversion[i]='\0';
   strrev(pversion);
   puts(pversion);
}


void findversions(char *version1,char *version2,int n)
{
   int lv=0,uv=0;
   int lcount=0;
   while(*version1!='\0' || lcount<n)
   {
     if(*version1!='.'){
           lv=(lv*10) + (*version1-'0');
           version1++;
           lcount++;}
     else if(*version1=='\0' && lcount<n){
           lv*=10;
           lcount++;}      
   }
  lcount=0; 
  while(*version2!='\0' || lcount<n)
   {
     if(*version2!='.'){
           uv=(uv*10) + (*version2-'0');
           version2++;
           lcount++;
     }
     else if(*version2=='\0' && lcount<n){
          uv*=10;lcount++;}
   }

   printf("%d %d",lv,uv);
   //for(int i=lv;i<=uv;i++)
   //    printversion(i,n);

}


void main()
{
    int n;
    scanf("%d",&n);
    char version1[2*n],version2[2*n];
    scanf("%s",version1);
    scanf("%s",version2);
    //printf("%s %s",version1,version2);
    findversions(version1,version2,n);
}