#include<stdio.h>
int count=0,n,f[5];
int main()
{
	void disp();
	int no,pg[30],i,j,k,b=0;
	int a[2][5],t[5],q=0,p;
	printf("enter frame size");
	scanf("%d",&n);
	printf("enter no of pages");
	scanf("%d",&no);
	printf("enter string");
	for(i=0;i<no;i++)
	{
		scanf("%d",&pg[i]);
	}
	printf("refernce_no\tpage_frame\n");
	for(i=0;i<n;i++)
	{
		f[i]=-1;
	}
	for(i=0;i<no;i++)
	{
		printf("%d\t\t",pg[i]);
		k=0;
		for(j=0;j<n;j++)
		{
			if(pg[i]==f[j])
			k=1;
		}
		if(k==0&&b<n)
		{
			f[b]=pg[i];
			b++;
			count++;
			disp();
		}
		else if(b==n&&k==0)
        {
		    for(j=0;j<n;j++)
		    {
		    	for(p=0;p<i;p++)
		    	{
		    		if(f[j]==pg[p])
		    		a[0][j]=p+1;
				}
				a[1][j]=j;
			}
			for(j=0;j<n;j++)
			{
				t[j]=a[0][j];
			}
			for(j=0;j<n;j++)
			{
				for(p=0;p<n-1;p++)
				{
					if(t[p]<t[p+1])
					{
						q=t[p];
						t[p]=t[p+1];
						t[p+1]=q;
					}
				}
			}
			for(j=0;j<n;j++)
			{
			if(t[0]==a[0][j])
			{
				q=a[1][j];
				f[q]=pg[i];
			}
		}
			count++;
			disp();
		}
	
		else if(k==1)
		{
			printf("  \n");
		}
	}
	printf("page faults no::%d",count);
 return 0;
}
void disp()
{
	int j;
	for(j=0;j<n;j++)
	{
		printf("%d  ",f[j]);
	}
	printf("\n");
}
