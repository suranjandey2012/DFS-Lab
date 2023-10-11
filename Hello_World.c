#include <stdio.h>

int r,c;

void rotate(int arr[][c],char ch,int rot,int layer)
{
  for(int i=0;i<r;i++)
  {
      for(int j=0;j<c;j++)
		  printf("%d ",arr[i][j]);
	  printf("\n");
  }
  printf("%c %d %d",ch,rot,layer);  

}


void main()
{
  int layer,rot;
  scanf("%d %d",&r,&c);
  int array[r][c];
  for(int i=0;i<r;i++)
  {
      for(int j=0;j<c;j++)
		  scanf("%d",&array[i][j]);
  }
  char ch;
  scanf("%c %d %d",&ch,&rot,&layer);
  rotate(array,ch,rot,layer);
}
