#include<stdio.h>
#include<stdlib.h>

void main(){
	int **mat1,**mat2,**mat3,**im,i,j,k,ra,ca,rb,cb,rc,cc,imr,imc,cost1,cost2,sum;
	scanf("%d %d",&ra,&ca);
	mat1=(int **)malloc(ra*sizeof(int *));
	if(mat1==NULL)
	   exit(-1);
	for(i=0;i<ra;i++)
	{
		mat1[i]=(int *)malloc(ca*sizeof(int));
	    if(mat1[i]==NULL)
	       exit(-1);
    }
    for(i=0;i<ra;i++)
    {   
        for(j=0;j<ca;j++)
            scanf("%d",&mat1[i][j]);
    }
    
    /*for(i=0;i<ra;i++){
    	for(j=0;j<ca;j++)
    	      printf("%d ",mat1[i][j]);
    	printf("\n");      
	}*/
	
	scanf("%d %d",&rb,&cb);
	mat2=(int **)malloc(rb*sizeof(int *));
	if(mat2==NULL)
	    exit(-1);
	for(i=0;i<rb;i++)
	 {
	 	mat2[i]=(int *)malloc(cb*sizeof(int));
	 	if(mat2[i]==NULL)
	 	   exit(-1);
		 }
	for(i=0;i<rb;i++){
		for(j=0;j<cb;j++)
		    scanf("%d",&mat2[i][j]); 
	}
	
	/*for(i=0;i<rb;i++){
    	for(j=0;j<cb;j++)
    	      printf("%d ",mat2[i][j]);
    	printf("\n");      
	}*/
	
	scanf("%d %d",&rc,&cc);
	mat3=(int **)malloc(rc*sizeof(int *));
	if(mat3==NULL)
	    exit(-1);
	for(i=0;i<rc;i++)
	{
		mat3[i]=(int *)malloc(cc*sizeof(int));
		if(mat3[i]==NULL)
		    exit(-1);
	}
	for(i=0;i<rc;i++){
		for(j=0;j<cc;j++)
		   scanf("%d",&mat3[i][j]);
	}
	
	/*for(i=0;i<rc;i++){
    	for(j=0;j<cc;j++)
    	      printf("%d ",mat3[i][j]);
    	printf("\n");      
	}*/	
	
	if(ca!=rb || cb!=rc){
	    printf("ERROR");
	    exit(-1);
	}
	
	cost1=(ra*ca*cb)+(ra*cb*cc);
	cost2=(rb*cb*cc)+(ra*rb*cc);
	
	if(cost1<=cost2)
	{
		imr=ra;imc=cb;
		im=(int **)malloc(imr*sizeof(int *));
		if(im==NULL)
		   exit(-1);
		for(i=0;i<imr;i++){
			im[i]=(int *)malloc(imc*sizeof(int));
			if(im[i]==NULL)
			   exit(-1);
		}
		for(i=0;i<ra;i++)
		  {
		  	for(j=0;j<cb;j++)
		  	{
		  		im[i][j]=0;
				for(k=0;k<rb;k++)
		  		   im[i][j]+=mat1[i][k]*mat2[k][j];
			  }
		  }
		for(i=0;i<ra;i++)
		{
			for(j=0;j<cc;j++)
			{
				sum=0;
				for(k=0;k<cb;k++)
				    sum+=im[i][k]*mat3[k][j];
				printf("%d ",sum);    
			}
			printf("\n");
		  }
		  for(i=0;i<imr;i++)
		      free(im[i]);
		  free(im);    
	}
	else{
		imr=rb;imc=cc;
		im=(int **)malloc(imr*sizeof(int *));
		if(im==NULL)
		   exit(-1);
		for(i=0;i<imr;i++){
			im[i]=(int *)malloc(imc*sizeof(int));
			if(im[i]==NULL)
			   exit(-1);
		}
		for(i=0;i<rb;i++)
		  {
		  	for(j=0;j<cc;j++)
		  	{
		  		im[i][j]=0;
				for(k=0;k<rc;k++)
		  		   im[i][j]+=mat2[i][k]*mat3[k][j];
			  }
		  }
		for(i=0;i<ra;i++)
		{
			for(j=0;j<cc;j++)
			{
				sum=0;
				for(k=0;k<ca;k++)
				    sum+=mat1[i][k]*im[k][j];
				printf("%d ",sum);    
			}
			printf("\n");
		  }
		for(i=0;i<imr;i++)
		    free(im[i]);
		free(im);    
		
	}
	
	for(i=0;i<ra;i++)
	     free(mat1[i]);
	free(mat1);     
    for(i=0;i<rb;i++)
         free(mat2[i]);
    free(mat2);
	for(i=0;i<rc;i++)
	     free(mat3[i]);
	free(mat3);	      
}
