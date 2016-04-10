// fibonacci sequence
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>


int fibonacci (int N, int i, mpz_t n_1, mpz_t n_2) {
    mpz_t n;
    mpz_init (n);
    mpz_add(n, n_1, n_2);

    if (i == 1 || i == 2) mpz_set_str(n, "1", 10);

    gmp_printf("n = %d\t: %Zd\n", i, n);
    if (i++ >= N) return i;

    return fibonacci(N, i, n, n_1);
}

int main (int argc, char *argv[]) {

    int N;

    if (argc < 2) {
        N = 5;
    } else {
        N = atoi(argv[1]);
    }

    mpz_t n_1;
    mpz_t n_2;
    mpz_init(n_1);
    mpz_init(n_2);

    fibonacci(N, 0, n_1, n_2);
    printf("\n");

    return 0;

}
