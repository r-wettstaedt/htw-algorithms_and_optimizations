// ackermann function

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <gmp.h>

mpz_t ZERO;
mpz_t ONE;


int ackermannNative (int m, int n) {

    if (!m) return n + 1;
    if (!n) return ackermannNative(m - 1, 1);

    return ackermannNative(m - 1, ackermannNative(m, n - 1));

}


int ackermannBig (mpz_t result, mpz_t m, mpz_t n) {

    // gmp_printf("m: %Zd\tn: %Zd\tr: %Zd\n", m, n, result);

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


int main (int argc, char *argv[]) {

    if (argc != 3) {
        printf("Wrong number of parameters\n");
        printf("Passed arguments: %d\tRequired arguments: 2\n", argc - 1);
        return 1;
    }

    mpz_init(ZERO);
    mpz_init_set_ui(ONE, 1);

    mpz_t mBig;
    mpz_t nBig;
    mpz_init_set_str(mBig, argv[1], 10);
    mpz_init_set_str(nBig, argv[2], 10);

    mpz_t resultBig;
    mpz_init(resultBig);


    int mNative = atoi(argv[1]);
    int nNative = atoi(argv[2]);

    int resultNative;


    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long start = 1000000 * tv.tv_sec + tv.tv_usec;

    ackermannBig(resultBig, mBig, nBig);

    gettimeofday(&tv, NULL);
    unsigned long end = 1000000 * tv.tv_sec + tv.tv_usec;

    printf("Big Integer \t| Done in %luμs\n", end - start);
    gmp_printf("A(%Zd, %Zd) = %Zd\n", mBig, nBig, resultBig);


    printf("-------------------\n");


    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;

    resultNative = ackermannNative(mNative, nNative);

    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;

    printf("Native Integer \t| Done in %luμs\n", end - start);
    printf("A(%d, %d) = %d\n", mNative, nNative, resultNative);

}