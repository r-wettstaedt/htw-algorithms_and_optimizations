#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int extendedGCD(int a, int b){

	
	int c = a; 
	int d = b; 
	
	int uc = 1; 
	int vc = 0;
	int ud = 0;
	int vd = 1;
	
	while(c != 0){
		
		
		int q = floor(d/c); 		
		int h = c; 			
		c = d - q * c;		
		d = h;				
		uc = ud - q * uc;	
		vc = vd - q * vc;	
		ud = uc;			
		vd = vc;			
		

	}
	
	printf("The GCD of %d and %d is %d\n", a, b, d );
	printf("(u, v): (%d, %d)\n", ud, vd);
	return 0; 
	
}

int main(int argc, char *argv[]){

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
	int result = extendedGCD(a, b);
	
	return 0;
}