// Online C compiler to run C program online
#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
//zombie process;
int main() {
    // Write C code here
    int p=fork();
    if(p>0)
    {
        printf("In parent process\n");
        exit(0);
    }
    else
    {
        sleep(5);
        printf("in child process\n");
        
    }

    return 0;
}