#include<stdio.h>
#include<stdlib.h>
typedef struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}process;

void sort(process arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j].at>arr[j+1].at)
            {
                process temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
}
void display(process arr[],int n)
{
    printf("process_id\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t",arr[i].pid);
        printf("%d\t",arr[i].at);
        printf("%d\t",arr[i].bt);
        printf("%d\t",arr[i].ct);
        printf("%d\t",arr[i].tat);
        printf("%d\t",arr[i].wt);
        printf(" \n");
    }
}
int findmax(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int n;
    printf("enter number of processes\n");
    scanf("%d",&n);
    process arr[n];
    printf("enter process_id ,arrival time and burst time of each process respectively\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i].pid);
        scanf("%d",&arr[i].at);
        scanf("%d",&arr[i].bt);
    }
    sort(arr,n);
    // display(arr,n);
    int start_time=0;
    int sum_tat=0;
    int sum_ct=0;
    int sum_wt=0;
    int total_idle_time=0;
    for(int i=0;i<n;i++)
    {
        start_time=(i==0)?arr[i].at : findmax(arr[i].at,arr[i-1].ct);
        arr[i].ct=start_time+arr[i].bt;
        arr[i].tat=arr[i].ct-arr[i].at;
        arr[i].wt=arr[i].tat-arr[i].bt;
        sum_ct+=arr[i].ct;
        sum_tat+=arr[i].tat;
        sum_wt+=arr[i].wt;
        total_idle_time+=start_time-arr[i-1].ct;
    }
    display(arr,n);
    printf("Average COMPLETION Time = %f\n",(float)sum_ct/n);
    printf("Average TURN-AROUND Time = %f\n",(float)sum_tat/n);
    printf("Average WAITING Time = %f\n",(float)sum_wt/n);
    int length_cyle=arr[n-1].ct-arr[0].at;
    printf("throughput = %f\n",n/(float)length_cyle);
    printf("total cpu utilization=%f\n",length_cyle-total_idle_time)/length_cyle;
}
