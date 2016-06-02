#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>
#include <gmp.h>

#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define RESET   "\x1B[0m"


bool isPrime(mpz_t n_mpz, const int maxK) {
    if (mpz_even_p(n_mpz)) return false;
    if (mpz_cmp_ui(n_mpz, 3) < 0) return false;

    long t, k, i;

    mpz_t n_minus_1_mpz, n_minus_3_mpz,
          s_mpz, a_mpz, v_mpz;

    mpz_init(n_minus_1_mpz);
    mpz_init(n_minus_3_mpz);

    mpz_sub_ui(n_minus_1_mpz, n_mpz, 1);
    mpz_sub_ui(n_minus_3_mpz, n_mpz, 3);

    mpz_init(s_mpz);
    mpz_init(a_mpz);
    mpz_init(v_mpz);

    mpz_set(s_mpz, n_minus_1_mpz); /*s = n - 1;*/
    t = 0;
    while (mpz_even_p(s_mpz) /*s % 2 = 0*/) {
        mpz_cdiv_q_ui(s_mpz, s_mpz, 2); /*s /= 2;*/
        t++;
    }

    k = 0;
    while (k < maxK) {

        mpz_set_ui(a_mpz, rand()); /*a = (rand() % (n - 3)) + 2;*/
        mpz_mod(a_mpz, a_mpz, n_minus_3_mpz);
        mpz_add_ui(a_mpz, a_mpz, 2);

        mpz_powm(v_mpz, a_mpz, s_mpz, n_mpz); /*v = ((long) pow(a, s)) % n;*/

        if (mpz_cmp_ui(v_mpz, 1) != 0 /*v != 1*/) {
            i = 0;

            while (mpz_cmp(v_mpz, n_minus_1_mpz) != 0 /*v != n - 1*/) {
                if (i == t - 1) return false;

                mpz_powm_ui(v_mpz, v_mpz, 2, n_mpz); /*v = (v * v) % n;*/
                i++;
            }
        }

        k += 2;
    }

    return true;
}


int main (int argc, char *argv[]) {
    bool _isPrime, __isPrime, _isDivergent = false;
    int _isPrimeProb, numberOfPrimes = 0;
    const int maxK = 64, numberOfTests = 1000000;

    mpz_t n_mpz;
    mpz_init(n_mpz);

    if (argc > 1) {
        mpz_set_str(n_mpz, argv[1], 10);
        _isPrime = isPrime(n_mpz, maxK);

        if (_isPrime) {
            gmp_printf("%Zd is prime\n", n_mpz);
            return 0;
        }
        gmp_printf("%Zd is not prime\n", n_mpz);
        return 0;
    }

    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long start = 1000000 * tv.tv_sec + tv.tv_usec;

    for (int i = 5; i < numberOfTests; i+=2) {
        mpz_set_ui(n_mpz, i);
        _isPrime = isPrime(n_mpz, maxK);
        _isPrimeProb = mpz_probab_prime_p(n_mpz, maxK);
        __isPrime = _isPrimeProb == 2;

        if (_isPrime) numberOfPrimes++;
        if (_isPrime != __isPrime) {
            printf("%s%d: %d == %d%s\n", RED, i, _isPrime, _isPrimeProb, RESET);
            _isDivergent = true;
        }
    }
    printf("\n");

    gettimeofday(&tv, NULL);
    unsigned long end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("Done in %lus (%lums)\n", (end - start) / 1000000, (end - start) / 1000);

    if (!_isDivergent) {
        printf("%sAll %d tests passed%s\n", GREEN, numberOfTests, RESET);
        printf("Number of primes found: %d\n", numberOfPrimes);
        printf("k: %d\n", maxK);
    }

    printf("\n");

}