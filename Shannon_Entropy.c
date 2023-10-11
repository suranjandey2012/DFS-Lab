#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
	char ch;
	int ocount=0,zcount=0,qcount=0;
	int den=0;
	while('\n'!=(ch=getchar()))
	{
	   if(ch=='0')
          zcount++;
   	   else if(ch=='1')
		  ocount++;
       else
          qcount++;
	   den++;
 	}
	
	//printf("%d %d %d %d",zcount,ocount,qcount,den);
	double min,max;
	if(qcount==0)
	{
	   if(zcount==0 || ocount==0){
		   min=0;max=0;
		   printf("%5.3lf %5.3lf",min,max);
	   }
	   else{
	       double pr0=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		   double pr1=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
		   min=pr0+pr1;
		   max=pr0+pr1;
		   printf("%5.3lf %5.3lf",min,max);
	   }
	}
	else{
	  int diff=abs(zcount-ocount);
	  //printf("%d",diff);
	  if(qcount<diff)
	  {
	      if(zcount<ocount)
		  {
		   zcount+=qcount;
		   double przma=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		   double proma=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
		   max=przma+proma;
		   //printf("%d %d\n",zcount,ocount);
		   zcount-=qcount;
		   ocount+=qcount;
		   double przmi=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		   double promi=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
		   min=przmi+promi;
		   //printf("%d %d\n",zcount,ocount);
		   printf("%5.3lf %5.3lf",min,max);
		  }else{
		   ocount+=qcount;
		   double przma=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		   double proma=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
		   max=przma+proma;
		   ocount-=qcount;
		   zcount+=qcount;
		   double przmi=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		   double promi=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
		   min=przmi+promi;
		   printf("%5.3lf %5.3lf",min,max);
		  }
	  }
	  else if(qcount==diff){
	      if(zcount<ocount)
		  {
		    ocount+=qcount;
		    double przmi=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		    double promi=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
			min=przmi+promi;
			max=1;
			printf("%5.3lf %5.3lf",min,max);
		  }else{
		    zcount+=qcount;
		    double przmi=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		    double promi=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
			min=przmi+promi;
			max=1;
			printf("%5.3lf %5.3lf",min,max);
		  }
	  }
	  else if(qcount>diff){
		  if(zcount<ocount)
		  {
			  ocount+=qcount;
			  double przmi=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		      double promi=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
			  min=przmi+promi;
			  ocount-=qcount;
			  zcount=ocount;
			  qcount-=diff;
			  ocount+=(qcount%2);
			  qcount-=(qcount%2);
			  zcount+=qcount/2;
			  ocount+=qcount/2;
			  double pr0=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		      double pr1=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
			  max=pr0+pr1;
			  printf("%5.3lf %5.3lf",min,max);
		}else if(zcount>ocount)
		{
		      zcount+=qcount;
			  double przmi=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		      double promi=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
			  min=przmi+promi;
			  zcount-=qcount;
			  ocount=zcount;
			  qcount-=diff;
			  ocount+=(qcount%2);
			  qcount-=(qcount%2);
			  zcount+=qcount/2;
			  ocount+=qcount/2;
			  double przma=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		      double proma=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
			  max=przma+proma;
			  printf("%5.3lf %5.3lf",min,max);
		}
		else{
			zcount+=qcount;
			double przmi=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		    double promi=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
			min=przmi+promi;
		    zcount-=qcount;
			ocount+=(qcount%2);
			qcount-=(qcount%2);
			zcount+=qcount/2;
			ocount+=qcount/2;
			double przma=(-1)*((double)zcount/ (double) den)*log2((double) zcount/(double) den);
		    double proma=(-1)*((double) ocount/(double) den)*log2((double) ocount/(double) den);
			max=przma+proma;
			printf("%5.3lf %5.3lf",min,max);	
		}
		
		  
	  }
	}
		
}