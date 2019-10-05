#include<stdio.h>
#include <stdlib.h>
void main()
{
int i,n,bt[25],wt[25],tat[25],p[25],rt[25],at[25],tq,remain,
time,flag=0;
FILE *fp;
char str[3];
fp = fopen("test4.txt","r");
fgets(str,2,fp);
n = atoi(str);
for(i=0;i<n;i++)
{
fscanf(fp,"%d : %d",&p[i],&bt[i]);
}
for(i=0;i<n;i++)
{
at[i]=0;
rt[i]=bt[i];
}
remain=n;
printf("Enter the time quantum:");
scanf("%d",&tq);
printf("Process WaitingTime TurnAroundTime\n------- ----------- --------------\n");
for(time=0,i=0;remain!=0;)
{
if(rt[i]<=tq&&rt[i]>0)
{
time+=rt[i];
rt[i]=0;
flag=1;
}
else if(rt[i]>0)
{
rt[i]-=tq;
time+=tq;
}
if(rt[i]==0&&flag==1)
{
remain--;
printf("\n P%d\t\t%d\t\t%d\n",i+1,(time-at[i]-bt[i]),(time-at[i]));
flag=0;
}
if(i==n-1)
i=0;
else if(at[i+1]<=time)
i++;
else
i=0;
}
}
