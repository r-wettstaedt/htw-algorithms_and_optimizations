// fibonacci sequence
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
// https://gmplib.org/manual/Integer-Arithmetic.html#Integer-Arithmetic
#include <gmp.h>


int fibonacci (int N, int i, mpz_t n_1, mpz_t n_2) {
    mpz_t n;
    mpz_init (n);
    mpz_add(n, n_1, n_2);

    if (i == 1 || i == 2) mpz_set_str(n, "1", 10);

    // gmp_printf("N: %d\t= %Zd\n", i, n);
    if (i++ >= N) return --i;

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

    struct timeval tv;
    gettimeofday(&tv, NULL);
    const double start = tv.tv_usec;

    const int steps = fibonacci(N, 0, n_1, n_2);
    printf("\n");

    gettimeofday(&tv, NULL);
    printf("Done in %gμs\n", tv.tv_usec - start);
    printf("Required iterations %d\n", steps);


    return 0;

}
