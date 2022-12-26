// Q. Write a C program to demonstrate the use of fork() System call
// Online C compiler to run C program online
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
    // Write C code her
    int p;
    p=fork();
    if(p<0)
    {
        printf("error occured\n");
        exit(1);
    }
    else if(p==0)
    {
        printf("i am child  %d\n",getpid());
        
    }
    else
    {
        printf("i am parent   %d\n",getpid());
    }
    return 0;
}