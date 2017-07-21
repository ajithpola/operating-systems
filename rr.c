#include<stdio.h>
void main()
{
	int n,bt[n],tq,a[n],i,j,k=0,b[2][50],wt=0,c,tat=0;
	float avwt,avtat;
	printf("enter no of processes");
	scanf("%d",&n);
	printf("enter time quantum");
	scanf("%d",&tq);
	printf("enter burst times\n");
	for(i=0;i<n;i++)
	{
		printf("p[%d]",i+1);
		scanf("%d",&bt[i]);
		a[i]=bt[i];
	}
	for(i=0;i<25;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]>tq)
			{
				a[j]=a[j]-tq;
				b[0][k]=j;
				b[1][k]=tq;
				k++;
			}
			else if(a[j]<=tq&&a[j]!=0)
			{
				b[0][k]=j;
			    b[1][k]=a[j];
				a[j]=0;
				k++;
			}
		}
	}
	c=k;
	for(j=0;j<c;j++)
	{
		printf("%d ",b[0][j]);
		    printf("%d ",b[1][j]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=c-1;j>=0;j--)
		{   
			if(b[0][j]==i)
			{
				for(k=0;k<=j;k++)
				{
					tat=tat+b[1][k];
				}
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		wt=wt+bt[i];
	}
	wt=tat-wt;
	avwt=wt/(float)n;
	avtat=tat/(float)n;
	printf("average waiting time=%f\n",avwt);
	printf("average turn around time=%f\n",avtat);
}

