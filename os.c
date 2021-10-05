Banker :

#include <stdio.h>
int main()
{
  // change values of m  and n according to your input choice :)
  
    int n, m, i, j, k;
    n = 5; 
    m = 3; 
    int alloc[5][3] = { { 0, 1, 0 }, 
                        { 2, 0, 0 }, 
                        { 3, 0, 2 }, 
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } }; 
  
    int max[5][3] = { { 7, 5, 3 }, 
                      { 3, 2, 2 }, 
                      { 9, 0, 2 }, 
                      { 2, 2, 2 }, 
                      { 4, 3, 3 } }; 
    int avail[3] = { 3, 3, 2 }; 
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
  
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
  
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
  
    printf("Following is the SAFE Sequence\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);
    printf("\n\n");
  
    return (0);
 
}



FirstFit :

#include<stdio.h>
void main(){
    int n,i,p[30], bt[30] ,tat[30], wt[30], tot_tat = 0, tot_wt = 0;
    float avg_tat, avg_wt;
    printf("Enter the no. of processes :");
    scanf("%d",&n);
    printf("Enter burst time for each process : ");
    for(i = 0 ; i < n ; i++){
    scanf("%d",&bt[i]);
    }
    for(i = 0; i< n;i ++){
        if( i == 0){
            tat[i] = bt[i];
        }
        else{
        tat[i] = tat[i-1] + bt[i];
    }
        tot_tat += tat[i];
    }
    for(i = 0 ; i < n ; i++){
        if( i == 0 ){
            wt[i] == 0;
        }
        else{
            wt[i] = tat[i] - bt[i];
        }
        tot_wt += wt[i];
    }
     avg_tat = tot_tat/(float)n;
     avg_wt = tot_wt/(float)n;
    printf("PROCESS  \t\t BURST TIME \t\t TAT \t\t WT");
    for(i = 0 ; i < n ; i++){
        printf("\nProcess[%d] \t\t %d  \t\t\t %d \t\t %d \n",i, bt[i], tat[i], wt[i]);
    }
    printf("\n Total TURN AROUND TIME = %d", tot_tat);
    printf("\n Average TURN AROUND TIME = %f", avg_tat);
    printf("\n Total WAITING TIME = %d", tot_wt);
    printf("\n Average WAITING TIME = %f", avg_wt);
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
printf("\n enter the size of file %d",i);
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


Semaphore :

#include<stdio.h>
#include<stdlib.h>
int n=0,buffersize=0,currentsize=0;
void producer()
{
printf("\nEnter number of elements to be produced: ");
scanf("%d",&n);
if(0<=(buffersize-(currentsize+n)))
{
currentsize+=n;
printf("%d Elements produced by producer where buffersize is %d\n",currentsize,buffersize);
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
printf("\nNumber of Elements consumed should not be greater than Number of Elements produced\n");
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
exit(0);
break;

}
}
while(c!=3);
}



FCFS :

#include<stdio.h>
int WT_TAT (int *, int *);
int p[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],FCFS_wt=0,FCFS_tat=0;
float awt,avg_tat,avg_wt;
void main()
{
int i;
printf("\nEnter the no.of processes \n");
scanf("%d",&n);
printf("Enter burst time for each process\n");
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


SJF :

#include<stdio.h>
int WT_TAT (int *, int *);
int sort();
int swap(int *, int *);
int p[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],SJF_wt=0,SJF_tat=0;
float awt,avg_tat,avg_wt;
void main()
{
int i;
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
