#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>

struct process{
    int max[10];
    int aloc[10];
    int need[10];
};
int main()
{
    int np,nr;
    // np=no. of proess | nr=no. of resources
    printf("enter number of proccess\n");
    scanf("%d",&np);
    printf("enter number of resourses \n");
    scanf("%d",&nr);
// ************************************************
    int aval[nr];
    int is_complete[np];
    int res[np],ind=0;
    bool proceed=true;
// ************************************************

    for(int i=0;i<np;i++)
    {
        is_complete[i]=0;
    }
    struct process ps[np];
    for(int i=0;i<np;i++)
    {
        printf("enter maximum need for process %d\n",i);
        for(int j=0;j<nr;j++)
        {
            scanf("%d",&ps[i].max[j]);
        }
        printf("enter allocated need for process %d\n",i);
        for(int j=0;j<nr;j++)
        {
            scanf("%d",&ps[i].aloc[j]);
            ps[i].need[j]=ps[i].max[j]-ps[i].aloc[j];
        }
    }

    printf("enter available resources\n");
    for(int i=0;i<nr;i++)
    scanf("%d",&aval[i]);


// *************** MAIN ALGO *************************
    while(proceed)
    {
        proceed=false;
        for(int i=0;i<np;i++)
        {
            int flag=0;
            if(is_complete[i]==0)
            {
                for(int j=0;j<nr;j++)
                {
                    if(ps[i].need[j]<=aval[j])
                    {
                        continue;
                    }
                    else{
                    flag=1;
                    break;
                    }
                }
                if(flag==0)
                {
                    res[ind++]=i;
                    is_complete[i]=1;
                    for(int j=0;j<nr;j++)
                    {
                        aval[j]+=ps[i].aloc[j];
                    }
                    proceed=true;
                }
            }
        }
    }
    int fg=0;
    for(int i=0;i<np;i++)
    {
        if(is_complete[i]==0)
        fg=1;
    }
    if(fg==0)
    {
        printf("we have a safe sequence\n");
        for(int i=0;i<np;i++)
        {
            printf("P%d->",res[i]);
        }
    }
    if(fg==1)
    {
        printf("we do not have a safe sequence\n");
    }

}