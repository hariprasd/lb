FCFS :

#include<stdio.h>
#include<conio.h>
int p[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],FCFS_wt=0,FCFS_tat=0;
float awt,avg_tat,avg_wt;
void main()
{
int i;
clrscr();
printf("\nEnter the no.of processes \n");
scanf("%d",&n);
printf("Enter burst time for each process\n")
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
p[i] = i;
}
printf("\n FCFS Algorithm \n");
WT_TAT(&FCFS_tat,&FCFS_wt);
printf("\n\nTotal Turn around Time:%d",FCFS_tat);
printf("\nAverage Turn around Time :%d ", FCFS_tat/n);
printf("\nTotal Waiting Time:%d",FCFS_wt);
printf("\nTotal avg. Waiting Time:%d",FCFS_wt/n);
getch();
}
int WT_TAT(int *a, int *b)
{
int i;
for(i=0;i<n;i++)
{
if(i==0)
tat[i] = bt[i];
else
tat[i] = tat[i-1] + bt[i];
tot_tat=tot_tat+tat[i];
}
*a = tot_tat;
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tot_wt = tot_wt+wt[i];
}
*b = tot_wt;
printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME");
for(i=0; i<n; i++)
printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
return 0;
}


SJF:

#include<stdio.h>
#include<conio.h>
int p[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],SJF_wt=0,SJF_tat=0;
float awt,avg_tat,avg_wt;
void main()
{
int i;
clrscr();
printf("\nEnter the no.of processes \n");
scanf("%d",&n);
printf("Enter burst time for each process\n");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
p[i] = i;
}
sort();
WT_TAT(&SJF_tat,&SJF_wt);
printf("\n\nTotal Turn around Time:%d",SJF_tat);
printf("\nAverage Turn around Time :%d ", SJF_tat/n);
printf("\nTotal Waiting Time:%d",SJF_wt);
printf("\nTotal avg. Waiting Time:%d",SJF_wt/n);
getch();
}
int sort()
{
int t,i,j;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(bt[i]>bt[j])
{
swap(&bt[j],&bt[i]);
swap(&p[j],&p[i]);
}
}
}
return 0;
}
int swap(int *a, int *b)
{
int t;
t = *a;
*a = *b;
*b = t;
return 0;
}
int WT_TAT(int *a, int *b)
{
int i;
for(i=0;i<n;i++)
{
if(i==0)
tat[i] = bt[i];
else
tat[i] = tat[i-1] + bt[i];
tot_tat=tot_tat+tat[i];
}
*a = tot_tat;
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tot_wt = tot_wt+wt[i];
}
*b = tot_wt;
printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME");
for(i=0; i<n; i++)
printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",p[i]+1,bt[i],tat[i],wt[i]);
return 0;
}


Priority Scheduling Algo :

#include<stdio.h>
#include<conio.h>
int p[30],bt[30],tot_tat=0,pr[30],wt[30],n,tot_wt=0,tat[30],PR_wt=0,PR_tat=0;
float awt,avg_tat,avg_wt;
void main()
{
int i;
clrscr();
printf("\nEnter the no.of processes \n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter burst time and priority of process[%d]:",i+1);
scanf("%d%d",&bt[i],&pr[i]);
p[i] = i;
}
sort();
WT_TAT(&PR_tat,&PR_wt);
printf("\n\nTotal Turn around Time:%d",PR_tat);
printf("\nAverage Turn around Time :%d ", PR_tat/n);
printf("\nTotal Waiting Time:%d",PR_wt);
printf("\nTotal avg. Waiting Time:%d",PR_wt/n);
getch();
}
int sort()
{
int t,i,j,t2,t1;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(pr[i]>pr[j])
{
swap(&bt[j],&bt[i]);
swap(&p[j],&p[i]);
swap(&pr[j],&pr[i]);
}
}
}
return 0;
}
int swap(int *a, int *b)
{
int t;
t = *a;
*a = *b;
*b = t;
return 0;
}
int WT_TAT(int *a, int *b)
{
int i;
for(i=0;i<n;i++)
{
if(i==0)
tat[i] = bt[i];
else
tat[i] = tat[i-1] + bt[i];
tot_tat=tot_tat+tat[i];
}
*a = tot_tat;
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tot_wt = tot_wt+wt[i];
}
*b = tot_wt;
printf("\nPROCESS\t\tBURST TIME\tPRIORITY\tTURN AROUND TIME\tWAITING
TIME");
for(i=0; i<n; i++)
printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d\t\t%d"
,p[i]+1,bt[i],pr[i],tat[i],wt[i]);
return 0; }


RoundRobin Sheduling Algo :

#include<stdio.h>
#include<conio.h>
int TRUE = 0;
int FALSE = -1;
int tbt[30],bt[30],tat[30],n=0,wt[30],qt=0,tqt=0,time=0,lmore,t_tat=0,t_wt=0;
void main()
{
int i,j;
clrscr();
printf("\nEnter no. of processors:");
scanf("%d",&n);
printf("\nEnter Quantum Time:");
scanf("%d",&qt);
for(i=0;i<n;i++)
{
printf("\nEnter Burst Time of Processor[%d]:",i+1);
scanf("%d",&bt[i]);
tbt[i] = bt[i];
wt[i] = tat[i] = 0;
}

lmore = TRUE;
while(lmore == TRUE)
{
lmore = FALSE;
for(i=0;i<n;i++)
{
if(bt[i] != 0)
wt[i] = wt[i] + (time - tat[i]);
tqt = 1;
while(tqt <= qt && bt[i] !=0)
{
lmore = TRUE;
bt[i] = bt[i] -1;
tqt++;
time++;
tat[i] = time;
}
}
}
printf("\nProcessor ID\tBurstTime\tTurnAroundTime\tWaitingTime\n");
for(i=0;i<n;i++)
{
printf("Processor%d\t\t%d\t\t%d\t\t%d\n",i+1,tbt[i],tat[i],wt[i]);
t_tat = t_tat + tat[i];
t_wt = t_wt + wt[i];
}
printf("\nTotal Turn Around Time:%d",t_tat);
printf("\nAverage Turn Around Time:%d",t_tat/n);
printf("\nTotal Waiting Time:%d",t_wt);
printf("\nAverage Waiting Time:%d",t_wt/n);
getch();
}

Semaphore :

#include<stdio.h>
int n=0,buffersize=0,currentsize=0;
void producer()
{
printf("\nEnter number of elements to be produced: ");
scanf("%d",&n);
if(0<=(buffersize-(currentsize+n)))
{
currentsize+=n;
printf("%d Elements produced by producer where buffersize is %d\n", currentsize,buffersize);
1
}
else
printf("\nBuffer is not sufficient\n");
}
void consumer()
{
int x;
printf("\nEnter no. of elements to be consumed: ");
scanf("%d",&x);
if(currentsize>=x)
{
currentsize-=x;
printf("\nNumber of elements consumed: %d, Number of Elements left: %d", x, currentsize);
}
else
{
printf("\nNumber of Elements consumed should not be greater than Number of Elements
produced\n");
}
}
void main()
{
int c;
printf("\nEnter maximum size of buffer:");
scanf("%d",&buffersize);
do
{
printf("\n1.Producer 2.Consumer 3.Exit");
printf("\nEnter Choice:");
scanf("%d",&c);
switch(c)
{
case 1:
if(currentsize >= buffersize)
printf("\nBuffer is full. Cannot produce");
else
producer();
break; case 2:
if(currentsize <= 0)
printf("\nBuffer is Empty. Cannot consume");
else
consumer();
break;
default:
exit();
break;
}
}
while(c!=3);
}


FirstFit :

#include<stdio.h>
struct process
{
int ps;
int flag;
struct sizes
{
int size;
int alloc;
}
s[5];
int main()
{
int i=0,np=0,n=0,j=0;
printf("\n first fit");
printf("\n");
printf("enter the number of blocks \t");
scanf("%d",&n);
printf("\t\t\n enter the size for %d blocks\n",n);
for(i=0;i<n;i++)
{
printf("enter the size for %d block \t",i);
scanf("%d",&s[i].size);
}
printf("\n\t\t enter the number of process\t",i);
scanf("%d",&np);
printf("enter the size of %d processors !\t",np);
printf("/n");
for(i=0;i<np;i++)
{
printf("enter the size of process %d\t",i);
scanf("\n%d",&p[i].ps);
}
printf("\n\t\t Allocation of blocks using first fit is as follows\n");
printf("\n\t\t process \t process size\t blocks\n");
for(i=0;i<np;i++)
{
for(j=0;j<n;j++)
{
if(p[i].flag!=1)
{
if(p[i].flag!=1)
{
if(p[i].ps<=s[j].size)
{
if(!s[j].alloc)
{
p[i].flag=1;
s[j].alloc=1;
printf("\n\t\t %d\t\t\t%d\t%d\t",i,p[i].ps,s[j].size);
}
}
}
}
}
}
for(i=0;i<np;i++)
{
if(p[i].flag!=1)
printf("sorry !!!!!!!process %d must wait as there is no sufficient memory");
}
}


BestFit :

#include<stdio.h>
#define MAX 20
int main()
{
int bsize[MAX],fsize[MAX],nb,nf;
int temp,low=10000;
static int bflag[MAX],fflag[MAX];
int i,j;
printf("\n enter the number of blocks");
scanf("%d",&nb);
for(i=1;i<=nb;i++)
{
printf("Enter the size of memory block % d",i);
scanf("%d", &bsize[i]);
}
printf("\n enter the number of files");
scanf("%d",&nf);
for(i=1;i<=nf;i++)
{
printf("\n enetr the size of file %d",i);
scanf("%d",&fsize[i]);
}
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
if(bflag[j]!=1)
{
temp=bsize[j]-fsize[i];
if(temp>=0)
{
if(low>temp)
{
fflag[i]=j;
low=temp;
}
}
}}
bflag[fflag[i]]=1;
low=10000;
}
printf("\n file no \t file.size\t block no \t block size");
for(i=1;i<=nf;i++)
printf("\n \n %d \t\t%d\t\t%d\t\t%d",i,fsize[i],fflag[i],bsize[fflag[i]]);
}

} p[50];
