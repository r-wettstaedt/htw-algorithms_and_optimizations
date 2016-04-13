#include <stdio.h>
#include <time.h>
#include <stdlib.h>

 
int fibonacci(int n){
	if(n == 0){
		return 0;
	}
	
	else if(n == 1){
		return 1;
	}
	
	else return (fibonacci(n - 1) + fibonacci(n-2));	
	
}

int main(int argc, char *argv[]){
	

	int i = 0;
	int c;
	clock_t t;
	int f = atoi(argv[1]);
	
	t = clock();
	
	for(c = 1; c <= f; c++){
		printf("%d\n", fibonacci(i));
		i++;
	}
	
	t = clock() - t;
	
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("fibonacci algorithm took %f seconds to execute \n", time_taken);
	
	return 0;
}