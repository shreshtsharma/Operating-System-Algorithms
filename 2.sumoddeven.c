// C++ program to demonstrate calculation in parent and
// child processes using fork()
#include <stdio.h>
#include <unistd.h>


// Driver code
int main()
{
    
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sumOdd = 0, sumEven = 0, n, i;
	n = fork();

if(n==0){
		for (i = 0; i < 10; i++) {
			if (a[i] % 2 != 0)
				sumOdd = sumOdd + a[i];
		}
	printf("child process \n");
		printf("Sum of odd no. is %d\n " ,sumOdd);
	}
	// Checking if n is not 0
	else {
	    wait();
		for (i = 0; i < 10; i++) {
			if (a[i] % 2 == 0)
				sumEven = sumEven + a[i];
		}
		printf("Parent process \n");
		printf("Sum of even no. is %d\n " ,sumEven);
	}

	// If n is 0 i.e. we are in child process
	
	return 0;
}
