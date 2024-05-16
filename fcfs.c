#include<stdio.h>


int at[10];
int bt[10];
int ct[10];
int tat[10];

float turnaroundtime(int,int[],int[]);
float waitingtime(int,int[],int[]);
float tp(int,int[]);

void main()
{
    int n;
    printf("Enter no.of processes:\n");
    scanf("%d",&n);

    printf("Enter the arrival time and burst time for each process:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
    }
    ct[0]=bt[0];

    for(int i=1;i<n;i++)
    {
        if(ct[i-1]<at[i])
        {
            ct[i]=ct[i-1]+bt[i]+(at[i]-ct[i-1]);
        }
        else
        {
            ct[i]=ct[i-1]+bt[i];
        }
    }
    float avgtat=turnaroundtime(n,at,ct);
    float avgwt=waitingtime(n,tat,bt);
    float throughput=tp(n,ct);

    printf("\n");
    printf("Average turn around time: %f\n",avgtat);
    printf("Average waiting time: %f\n",avgwt);
    printf("Throughput: %f\n",throughput);
}

float turnaroundtime(int n,int at[],int ct[])
{
    printf("Turn around times for the processes are:\n");
    printf("Process \t TAT\n");
    float sum=0;
    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        sum=sum+tat[i];
        printf("%d\t%d\n",(i+1),tat[i]);
    }
    float avg=sum/n;
    return avg;
}

float waitingtime(int n,int tat[],int bt[])
{
    printf("Waiting time for the processes are:\n");
    printf("Process \t WT\n");
    int wt[n];
    float sum=0;
    for(int i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        sum=sum+wt[i];
        printf("%d\t%d\n",(i+1),wt[i]);
    }
    float avg=sum/n;
    return avg;
}

float tp(int n,int ct[])
{
    float tp=(float)ct[n-1]/n;
    return tp;
}
