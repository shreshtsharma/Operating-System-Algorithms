#include <stdio.h>
#include <stdlib.h>
typedef struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} process;
void sort(process arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].bt > arr[j + 1].bt)
            {
                process temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void display(process arr[], int n)
{
    printf("process_id\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", arr[i].pid);
        printf("%d\t", arr[i].at);
        printf("%d\t", arr[i].bt);
        printf("%d\t", arr[i].ct);
        printf("%d\t", arr[i].tat);
        printf("%d\t", arr[i].wt);
        printf(" \n");
    }
}
int main()
{
    int n;
    printf("enter number of processes\n");
    scanf("%d", &n);
    process arr[n];
    int iscompleted[n];
    for(int i=0;i<n;i++)
    {
        iscompleted[i]=0;
    }
    printf("enter process_id ,arrival time and burst time of each process respectively\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].pid);
        scanf("%d", &arr[i].at);
        scanf("%d", &arr[i].bt);
    }
    sort(arr, n);
    int start_time = 0;
    int sum_ct=0;
    int sum_tat=0;
    int sum_wt=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].at <= start_time && iscompleted[arr[i].pid - 1] == 0)
        {
            iscompleted[arr[i].pid - 1] = 1;
            start_time += arr[i].bt;
            arr[i].ct = start_time;
            arr[i].tat = arr[i].ct - arr[i].at;
            arr[i].wt = arr[i].tat - arr[i].bt;
            sum_ct += arr[i].ct;
            sum_tat += arr[i].tat;
            sum_wt += arr[i].wt;
        }
        else
        start_time++;
    }
    display(arr,n);
    printf("Average COMPLETION Time = %f\n",(float)sum_ct/n);
    printf("Average TURN-AROUND Time = %f\n",(float)sum_tat/n);
    printf("Average WAITING Time = %f\n",(float)sum_wt/n);

}