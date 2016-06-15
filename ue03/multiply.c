#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <math.h>
#include <time.h>

mpz_t ZERO;
mpz_t TEN;
mpz_t TWO;


int multiply(mpz_t number, mpz_t exp)
{	
	
    mpz_t result;
    mpz_init_set_ui(result, 1);
    int i;
    
    for(i = 1; i <= mpz_get_ui(exp); i++){
    	mpz_mul(result, result, number);
    }
	
	//gmp_printf("%Zd^%Zd is %.Zd\n", number, exp, result);
 
	return 0;
}

int main(int argc, char *argv[])
{
    clock_t t;     
    mpz_t n;
    mpz_t e;
    mpz_init(ZERO);
    mpz_init_set_ui(TEN, 10);
    mpz_init_set_ui(TWO, 2);
    
    mpz_init_set_str(n, argv[1], 10);
    mpz_init_set_str(e, argv[2], 10);
	
	mpz_t result;
	mpz_init(result);
	
	t = clock();
	multiply(n, e);
	t = clock() - t;
	
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Algorithm took %f seconds to execute \n", time_taken);


    return 0;
}