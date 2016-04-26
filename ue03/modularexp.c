#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <math.h>
#include <time.h>

mpz_t ZERO;
mpz_t TEN;
mpz_t TWO;

int convertTo2(mpz_t result, mpz_t d)
{
	mpz_t rem;
	mpz_t i;
	
	mpz_init(rem);
	mpz_init_set_ui(i, 1);
   
    while (mpz_cmp(d, ZERO) != 0)
    {
    	
        mpz_fdiv_qr(d, rem, d, TWO);
        mpz_mul(rem, rem, i);
        mpz_add(result, result, rem);
        mpz_mul(i, i, TEN);
    }
    
    return 0;
		
		
}

int squareAndMultiply(mpz_t number, mpz_t exp, mpz_t modulo)
{	
	
	mpz_t exponent;
	mpz_init_set(exponent, exp);
	mpz_t binexp;
	mpz_init(binexp);
	//gmp_printf("Exp is: %Zd\n", exp);
	convertTo2(binexp, exp);
	//gmp_printf("Binexp is: %Zd\n", binexp);
	
	size_t length = mpz_sizeinbase(binexp, 10);
	//printf("Size is %zu\n", length);
    int i;
    int *expArray = calloc(length, sizeof(int));
    for ( i = 0; i < length; ++i, mpz_fdiv_q(binexp, binexp, TEN))
    {
    	mpz_t h;
		mpz_init(h);
        mpz_fdiv_r(h, binexp, TEN);
        expArray[i] = mpz_get_ui(h);
        //printf("[%d]", expArray[i]);
    }
    
    //printf("\n");
    
    mpz_t result;
    mpz_init_set(result, number);
    //gmp_printf("Number is: %Zd\n", result);
    
    for(i = length - 2; i >= 0; i--){
    	if(expArray[i] == 0){
    		mpz_mul(result, result, result);
    		mpz_fdiv_r(result, result, modulo);
    		//gmp_printf("expArray[i] = 0 square: %Zd\n", result);
    	}
    	else if(expArray[i] == 1){
    		mpz_mul(result, result, result);
    		//gmp_printf("expArray[i] = 1 square: %Zd\n", result);
    		mpz_mul(result, result, number);
    		mpz_fdiv_r(result, result, modulo);
    		//gmp_printf("and multiply: %Zd\n", result);
    	}
    }
	
	gmp_printf("%Zd^%Zd mod %Zd is %Zd\n", number, exponent, modulo, result);
 
	return 0;
}

int main(int argc, char *argv[])
{
    clock_t t;     
    mpz_t a;
    mpz_t b;
    mpz_t m;
    mpz_init(ZERO);
    mpz_init_set_ui(TEN, 10);
    mpz_init_set_ui(TWO, 2);
    
    mpz_init_set_str(a, argv[1], 10);
    mpz_init_set_str(b, argv[2], 10);
    mpz_init_set_str(m, argv[3], 10);
	
	mpz_t result;
	mpz_init(result);
	
	t = clock();
	squareAndMultiply(a, b, m);
	t = clock() - t;
	
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Algorithm took %f seconds to execute \n", time_taken);


    return 0;
}