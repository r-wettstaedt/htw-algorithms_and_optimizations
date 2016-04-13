#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int extendedGCD(int a, int b){

	
	int r = b;
	int old_r = a;
	
	int s = 0; 
	int old_s = 1;
	int t = 1;
	int old_t = 0;
	
	int iterations = 0;
	
	while(r != 0){
		
		
		int q = floor(old_r/r); 		
		int h_r = r; 			
		r = old_r - q * r;		
		old_r = h_r;	
		
		int h_s = old_s;			
		old_s = s;
		s = h_s - q * s;
		
		int h_t = old_t;			
		old_t = t;
		t = h_t - q * t;	
		iterations++;
					
		

	}
	
	
	printf("Bézout coefficients are: %d, %d\n", old_s, old_t);
    printf("Greatest common divisor: %d\n", old_r);
    printf("\n");
    printf("extendedGCD algorithm took %d iterations to execute \n", iterations);

	return 0; 
	
}

int main(int argc, char *argv[]){

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    
    clock_t t;
	
	
	t = clock();
	
	int result = extendedGCD(a, b);
	
	t = clock() - t;
	
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("extendedGCD algorithm took %f seconds to execute \n", time_taken);
	

	
	return 0;
}