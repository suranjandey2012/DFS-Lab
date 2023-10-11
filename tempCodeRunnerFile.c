#include<stdio.h>

int main()
{
    char num1[101],num2[101],sum[101];
    fgets(num1,sizeof(num1),stdin);
    fgets(num2,sizeof(num2),stdin);
    puts(num1);
    puts(num2);
    return 0;
}
