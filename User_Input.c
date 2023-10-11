#include<stdio.h>
#include<string.h>

void add(char num1[],char num2[])
{
	//printf("%s %s Addition",num1,num2);
	int len1,len2,i,j,k,sum=0,carry=0,res=0;
	char num3[200];
	len1=strlen(num1);
	len2=strlen(num2);
	i=len1-1;
	j=len2-1;
	k=0;
	while(i>=0 && j>=0)
	{
		res=((int) num1[i] - (int) '0') + ((int) num2[j]- (int) '0') +carry;
		sum=res%10;
		carry=res/10;
		num3[k]=sum+'0';
		//printf("%d %d \n",sum,carry);
		
		i--;j--;k++;
	}
	while(i>=0)
	{
		res=((int) num1[i] -'0') + 0 + carry;
		sum=res%10;
		carry=res/10;
		num3[k]=sum+'0';
		//printf("%d %d \n",sum,carry);
		i--;k++;
	}
	while(j>=0)
	{
		res=((int) num2[j] - '0') + carry;
        sum=res%10;
		carry=res/10;
		num3[k]=sum+'0';
		//printf("%d %d \n",sum,carry);
		j--;k++;
	}
	num3[k]='\0';
	printf("%s",strrev(num3));

}


void sub(char num1[],char num2[])
{
	//printf("%s %s subtraction",num1,num2);
	int len1,len2,i,j,k,diff=0,borrow=0,res=0;
	char num3[101];
	len1=strlen(num1);
	len2=strlen(num2);
	i=len1-1;
	j=len2-1;
	k=0;
	while(i>=0 && j>=0)
	{
		if(((int) num1[i] - '0') < ((int) num2[j] - '0'))
		{
			if(borrow==1)
			    res=(((int) num1[i]-'0')+9)-((int) num2[j] - '0');
			else
			   res=(((int) num1[i]-'0')+10)-((int) num2[j] - '0');    
		    borrow=1;
		    //printf("%c %c %d b1\n",num1[i],num2[j],res);
		    num3[k]=res+'0';
		}
		else
		{
			if(borrow==1)
			      if((((int) num1[i]-'0')-1) < ((int) num2[j] - '0')){
				        res=(((int) num1[i]-'0')+9)-((int) num2[j] - '0');
				        borrow=1;
						}
			      else{
				       res=(((int) num1[i]-'0')-1)-((int) num2[j] - '0');
					   borrow=0;
				}
			else{
			     res=(((int) num1[i]-'0'))-((int) num2[j] - '0');
				 borrow=0;	
		}
		//printf("%c %c %d b2\n",num1[i],num2[j],res);
		num3[k]=res+'0';
		}
		i--;j--;k++;
	}
	while(i>=0)
	{
		if(borrow==1)
		{
			if((((int) num1[i] - '0') - 1) < 0){
			    res=(((int) num1[i]-'0')+9)-0;
			    borrow=1;
			}
			else{
			    res=(((int) num1[i] - '0') - 1) - 0;		    
		        borrow=0;
		    }
		}
		else{
			res=(int) num1[i] - '0';
			borrow=0;
		}
		//printf("%c %d b3\n",num1[i],res);
		num3[k]=res+'0';
		i--;
	    k++;
	}
	num3[k]='\0';
	printf("%s",strrev(num3));
}



void main()
{
	char num1[101],num2[101],sign[2];
	scanf("%s",num1);
	scanf("%s",num2);
	scanf("%s",sign);
	if(strcmp(sign,"+")==0)
	     add(num1,num2);
    else if(strcmp(sign,"-")==0)
         sub(num1,num2);	     
}
