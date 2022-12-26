#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int st;
    int rt;
}arr[100];



int main()
{
    int completed = 0;
    int n;
    bool is_completed[100]={false};
    int bt_remaining[n];
    int current_time = 0;
    float sum_ct=0;
    float sum_wt=0;
    float sum_tat=0;
    float sum_rt=0;
    printf("enter number of processes\n");
    scanf("%d",&n);
     for(int i=0;i<n;i++)
    {
        printf("\nEnter Process %d Arrival Time: ",i);
        scanf("%d",&arr[i].at);
        arr[i].pid = i ;
    }
    
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Process %d Burst Time: ",i);
        scanf("%d",&arr[i].bt);
        bt_remaining[i]= arr[i].bt;
    }
    while (completed != n)
    {
       
       int min_index = -1;
    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].at <= current_time && is_completed[i] ==false)
        {
            if (bt_remaining[i] < minimum)
            {
                minimum = bt_remaining[i];
                min_index = i;
            }
             if (bt_remaining[i] == minimum)
            {
                if (arr[i].at < arr[min_index].at)
                {
                    minimum = bt_remaining[i];
                    min_index = i;
                }
            }
        }
    }
        if (min_index == -1)
        {current_time++;
        }
        else{
            if(bt_remaining[min_index]==arr[min_index].bt){
            arr[min_index].st=current_time;}

            bt_remaining[min_index]-=1;
            current_time++;
            if(bt_remaining[min_index]==0)
            {
                arr[min_index].ct=current_time;
                arr[min_index].tat=arr[min_index].ct-arr[min_index].at;
                arr[min_index].wt=arr[min_index].tat-arr[min_index].bt;
                arr[min_index].rt=arr[min_index].st-arr[min_index].at;
                sum_ct+=arr[min_index].ct;
                sum_rt+=arr[min_index].rt;
                sum_tat+=arr[min_index].tat;
                sum_wt+=arr[min_index].wt;
                completed++;
                is_completed[min_index]=true;
            }
        }
       
    }

         printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++)
     printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);

    printf("\n");    
    
    
        printf("average waiting time=%f\n",sum_wt/n);
        printf("average response time=%f\n",sum_rt/n);
        printf("average turn around time=%f\n",sum_tat/n);
        printf("average completion time=%f\n",sum_ct/n);
    return 0;
}
