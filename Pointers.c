#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int size;
    char **array;
};



struct node *create_list()
{
   struct node *head=(struct node *)malloc(sizeof(struct node));
   if(head==NULL)
   {
    printf("ERROR");
    return NULL;
   }
   head->size=0;
   head->array=NULL;
   return head;
}

void append(struct node *head,char str[])
{
   if(head->array==NULL)
   {
     head->size+=1;
     char *new=(char *)malloc(sizeof(char)*10);
     strcpy(new,str);
     head->array=&new;
   }
}

void main()
{
   struct node *head=create_list();
   append(head,"Apple");
   printf("%s",*(head->array));
}