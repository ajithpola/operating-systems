#include<stdio.h>
int f[7],n,count=0;
int main()
{
void disp();
int pg[34],i,j,k,b=0,p,no;
printf("enter frame size");
scanf("%d",&n);
printf("enter no of pages");
scanf("%d",&no);
printf("enter page no");
  for(i=0;i<no;i++)
{
scanf("%d",&pg[i]);
}
for(i=0;i<n;i++)
{
f[i]=-1;
}
printf("ref string \t page frame \n ");
  for(i=0;i<no;i++)
{
printf("%d\t\t",pg[i]);
k=0;
for(j=0;j<n;j++)
{
if(pg[i] == f[j])
k=1;
}
if (k==0 && b<n )
{
f[b] = pg[i];
b++;
count++;
disp();
}
else if (k==0 && b==n)
{
b=0;
f[b]=pg[i];
b++;
count++;
disp();
}
else if(k==1)
{
printf("\n ");
}
}
printf("no of page faults :: %d",count);
return 0;
}
void disp()
{
int j;
for(j=0;j<n;j++)
{printf(" %d  ",f[j]);
}
printf("\n");
}

