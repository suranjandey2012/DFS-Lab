#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 9

int Isunique(int *array)
{
    int bins[N];
    for(int i=0;i<=N;i++)
         bins[i]=0;
    for (int i=0;i<N;i++){
        if(array[i]>9 || array[i]<1)
            return 0;    
        bins[array[i]]++;
        if(2<=bins[array[i]])
           return 0;
     }

    /*for(int j=0;j<N;j++)
       printf("%d ",array[j]);
    printf("\n");*/   
    return 1;   
}


int Issudoku(int sudoku[][N])
{
    int column[N];
    //row level check
    for(int i=0;i<N;i++)
        if(!Isunique(*(sudoku+i)))
            return 0;
    
    //column level check
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
           column[j]=sudoku[j][i];
        if(!Isunique(column))
            return 0;
    }

    //3*3 level matrix check
    int rstart=0,rend=2;
    while(rend<N){
        int cstart=0,cend=2;
        while(cend<N){
        int index=0;
        for(int i=rstart;i<=rend;i++)
        {   
            for(int j=cstart;j<=cend;j++,index++)
                column[index]=sudoku[i][j];
        }   

        if(!Isunique(column))
           return 0;
        cstart=cend+1;
        cend=cend+3;
        }
        rstart=rend+1;
        rend=rend+3;
    }
    return 1;    
}

void main(int argc,char **argv)
{
    int sudoku[N][N]; 
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
           scanf("%d",&sudoku[i][j]);
    }

    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
           printf("%d ",sudoku[i][j]);
        printf("\n");   
    }*/
   if(Issudoku(sudoku))
      printf("Valid");
   else
     printf("Invalid");   
}