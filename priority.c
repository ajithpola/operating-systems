#include<stdio.h>
int main()
{
int n,bp[2][20],wt[20],tat[20],avwt=0,avtat=0,i,j,new[20],t=0;
printf("enter total no.of processes\n");
scanf("%d",&n);
printf("enter process burst time");
for(i=0;i<n;i++)
{
printf("p[%d]:",i+1);
scanf("%d",&bp[0][i]);
}
printf("enter priorities");
for(i=0;i<n;i++)
{
printf("p[%d]:",i+1);
scanf("%d",&bp[1][i]);
}
for(i=0;i<n;i++)
{
new[i]=bp[1][i];
}
for(i=1;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(new[j]>new[j+1])
{
t=new[j];
new[j]=new[j+1];
new[j+1]=t;
}
}
}
wt[0]=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(new[i]==bp[1][j])
{
wt[i+1]=wt[i]+bp[0][j];
break;
}
}
}
printf("\nprocess\t\tbursttime\twaitingtime\ttutn aroundtime\n");
for(i=0;i<n;i++)
{
tat[i]=bp[0][i]+wt[i];
avwt+=wt[i];
avtat+=tat[i];
printf("\np[%d]\t\t%d\t\t%d\t\t%d",i+1,bp[0][i],wt[i],tat[i]);
}
avwt/=n;
avtat/=n;
printf("\n\navg waiting time:%d",avwt);
printf("\n avg turn around time:%d",avtat);
return 0;
}
