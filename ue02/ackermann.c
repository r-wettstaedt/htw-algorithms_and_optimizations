#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

 
int ackermann(int m, int n)
{
    if (m == 0) return n + 1;
    if (n == 0) return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

int ackermannBig(mpz_t result, mpz_t m, mpz_t n){
	
	mpz_t ZERO;
	mpz_t ONE;	
	mpz_init(ZERO);
    mpz_init_set_ui(ONE, 1);
	
	if (mpz_cmp(m, ZERO) == 0) {
        mpz_add(result, n, ONE);
        return 0;
    }
    
    if (mpz_cmp(n, ZERO) == 0) {
        mpz_sub(result, m, ONE);
        ackermannBig(result, result, ONE);
        return 0;
    }
	
	mpz_t n_1;
    mpz_init(n_1);
    mpz_t n_2;
    mpz_init(n_2);
    mpz_sub(n_1, n, ONE);
    ackermannBig(n_2, m, n_1);

    mpz_t m_1;
    mpz_init(m_1);
    mpz_sub(m_1, m, ONE);
    ackermannBig(result, m_1, n_2);

    return 0;
}
 
int main(int argc, char *argv[])
{
        
	mpz_t mBig;
	mpz_t nBig;
	mpz_init_set_str(mBig, argv[1], 10);
    mpz_init_set_str(nBig, argv[2], 10);

    mpz_t resultBig;
    mpz_init(resultBig);
    
    ackermannBig(resultBig, mBig, nBig);

    gmp_printf("With Big Integer: A(%Zd, %Zd) = %Zd\n", mBig, nBig, resultBig);


        
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
  
	printf("With Integer: A(%d, %d) = %d\n", m, n, ackermann(m, n));
    return 0;
}