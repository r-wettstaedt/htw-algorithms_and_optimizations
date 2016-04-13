#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int extendedGCD(int a, int b){

	
	int r = b;
	int old_r = a;
	
	int s = 0; 
	int old_s = 1;
	int t = 1;
	int old_t = 0;
	
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
					
		

	}
	
	
	printf("Bézout coefficients are: %d, %d\n", old_s, old_t);
    printf("Greatest common divisor: %d\n", old_r);

	return 0; 
	
}

int main(int argc, char *argv[]){

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
	int result = extendedGCD(a, b);
	
	return 0;
}