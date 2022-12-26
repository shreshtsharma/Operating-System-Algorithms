#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
 int page,frame,i,j,fault=0,hits=0,flag1,flag2,pos,count=0;
 printf("Enter the no of Pages:");
 scanf("%d",&page);

 printf("Enter the Reference String:");
 int str[page];
 for(i=0;i<page;i++){scanf("%d",&str[i]);}

 printf("Enter the Number of Frames:");
 scanf("%d",&frame);

 int temp[frame];
 int time[frame];
 for(j=0;j<frame;j++){temp[j]=-1;}

 for(i=0;i<page;i++)
 {
    flag1=flag2=0;

    for(j=0;j<frame;j++){
        if(temp[j]==str[i])
        {
            count++;
            time[j]=count;
            hits++;
            flag1=flag2=1;
            break;
        }
    }
   
    if(flag1==0)
    {
      for(j=0;j<frame;j++)
       { 
       if(temp[j]==-1)
       {
        count++;
        time[j]=count;
        fault++;
        temp[j]=str[i];
        flag2=1;
        break;
       }
       }
    }

    if(flag2==0)
    {   pos=0;
        for(j=1;j<frame;j++)
        {
         if(time[j]<time[pos]){pos=j;}
        }
        count++;
        fault++;
        time[pos]=count;
        temp[pos]=str[i];
        }
    printf("\n");
    for(j=0;j<frame;j++){printf("%d\t",temp[j]);}
 }
printf("Total Hits and Miss:%d %d",hits,fault);
}