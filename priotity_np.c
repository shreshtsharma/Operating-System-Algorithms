#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

struct program{
    int at, bt, pid;
    int priority;
    int ct, tat, wt, rt, start_time;
}ps[100];

int main(){
    int n;
    printf("enter the value of n");
    scanf("%d",&n);

    int completed=0;
    bool is_completed[100] ={false};
    int current_time=0;

    printf("enter at\n");
    for(int i=0; i<n ; i++){
        scanf("%d",&ps[i].at);
        ps[i].pid=i;
    }

    printf("enter bt\n");
    for(int i=0; i<n ; i++){
        scanf("%d",&ps[i].bt);
    }

    printf("enter priority\n");
    for(int i=0; i<n ; i++){
        scanf("%d",&ps[i].priority);
    }

    while(n!=completed){
        int max_index=-1;
        int max=-1;
        for(int i=0; i<n; i++){
            if(ps[i].at<=current_time && is_completed[i]==false){
                if(ps[i].priority>max){
                    max=ps[i].priority;
                    max_index=i;
                }
                if(ps[i].priority==max){
                    if(ps[i].at<ps[max_index].at){
                        max=ps[i].priority;
                        max_index=i;
                    }
                }
            }
        }
        if(max_index==-1)
            current_time++;
        else{
            ps[max_index].ct = ps[max_index].start_time + ps[max_index].bt;
            ps[max_index].tat = ps[max_index].ct - ps[max_index].at;
            ps[max_index].wt= ps[max_index].tat - ps[max_index].bt;
            ps[max_index].rt = ps[max_index].start_time - ps[max_index].at;
            completed++;
            is_completed[max_index]=true;
            current_time=ps[max_index].ct;
        }
    }
}