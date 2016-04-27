#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <gmp.h>

mpz_t ZERO;
mpz_t ONE;
mpz_t TWO;

int exp_si (const int a, const int n) {

    if (n < 0) return exp_si(1 / a, -n);
    else if (n == 0) return 1;
    else if (n == 1) return a;
    else if (n %  2) return (a * exp_si(a * a, (n - 1) / 2));
    else return exp_si(a * a,  n / 2);

}

void exp_mpz (mpz_t res, mpz_t a, mpz_t n) {

    if (mpz_cmp(n, ZERO) < 0) {

        mpz_fdiv_q(a, ONE, a);
        mpz_mul_si(n, a, -1);
        exp_mpz(res, a, n);

    } else if (mpz_cmp(n, ZERO) == 0) {

        mpz_set(res, ONE);

    } else if (mpz_cmp(n, ONE) == 0) {

        mpz_set(res, a);

    } else if (mpz_odd_p(n)) {

        mpz_t a_temp;
        mpz_init(a_temp);
        mpz_mul(a_temp, a, a);

        mpz_sub(n, n, ONE);
        mpz_fdiv_q(n, n, TWO);

        exp_mpz(res, a_temp, n);
        mpz_mul(res, a, res);

    } else {

        mpz_mul(a, a, a);
        mpz_fdiv_q(n, n, TWO);
        exp_mpz(res, a, n);

    }

}

int main (int argc, char *argv[]) {

    if (argc != 3) {
        printf("Wrong number of parameters\n");
        printf("Passed arguments: %d\tRequired arguments: 2\n", argc - 1);
        printf("Usage: fractal [a] [n]\n");
        return 1;
    }

    mpz_init(ZERO);
    mpz_init_set_ui(ONE, 1);
    mpz_init_set_ui(TWO, 2);

    mpz_t a_mpz;
    mpz_t n_mpz;
    mpz_t res_mpz;
    mpz_init(res_mpz);



    const int a_ui = atoi(argv[1]);
    const int n_ui = atoi(argv[2]);
    mpz_init_set_str(a_mpz, argv[1], 10);
    mpz_init_set_str(n_mpz, argv[2], 10);


    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long start = 1000000 * tv.tv_sec + tv.tv_usec;

    const int res_ui = exp_si(a_ui, n_ui);

    gettimeofday(&tv, NULL);
    unsigned long end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("Done in %luµs\n", (end - start));
    printf("Result: %d\n", res_ui);

    gettimeofday(&tv, NULL);
    start = 1000000 * tv.tv_sec + tv.tv_usec;

    exp_mpz(res_mpz, a_mpz, n_mpz);

    gettimeofday(&tv, NULL);
    end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("Done in %luµs\n", (end - start));
    gmp_printf("Result: %Zd\n", res_mpz);

}