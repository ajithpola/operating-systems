#include<stdio.h>
int main()
{
int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j,an[20],t=0;
printf("enter total no.of processes\n");
scanf("%d",&n);
printf("enter process burst time");
for(i=0;i<n;i++)
{
printf("p[%d]:",i+1);
scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
an[i]=bt[i];
}
for(i=1;i<20;i++)
{
for(j=0;j<n-1;j++)
{
if(an[j]>an[j+1])
{
t=an[j];
an[j]=an[j+1];
an[j+1]=t;
}
}
}
for(i=0;i<n;i++)
{
printf("%d",an[i]);
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+an[i-1];
//for(j=0;j<1;j++)
//wt[i]+=bt[j];
//wt[i]=wt[i-1]+wt[i];

}
printf("\nprocess\t\tbursttime\twaitingtime\ttutn aroundtime\n");
for(i=0;i<n;i++)
{
tat[i]=an[i]+wt[i];
avwt+=wt[i];
avtat+=tat[i];
printf("\np[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
}
avwt/=n;
avtat/=n;
printf("\n\navg waiting time:%d",avwt);
printf("\n avg turn around time:%d",avtat);
return 0;
}
