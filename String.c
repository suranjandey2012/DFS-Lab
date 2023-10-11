#include<stdio.h>

void add(char num1[],char num2[])
{
    printf("%s %s",num1,num2);
}


void main()
{
    char num1[101],num2[101],sign;
    scanf("%s",num1);
    scanf("%s",num2);
    scanf("%s",sign);

    if(sign=='+')
    {
        add(num1,num2);
    }

}
