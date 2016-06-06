#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <gmp.h>

#include "rabin-miller.h"

#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_RESET   "\x1B[0m"


int assignment2 (int argc, char *argv[]) {
    bool isCongruent;
    const int maxK = 64, numberOfTests = 100000;

    mpz_t n_mpz;
    mpz_t a_mpz;
    mpz_init(n_mpz);
    mpz_init(a_mpz);

    for (int n = 5; n < numberOfTests; n+=2) {
        mpz_set_ui(n_mpz, n);
        for (int a = 2; a < n - 1; a++) {
            mpz_set_ui(a_mpz, a);
            mpz_powm_ui(a_mpz, a_mpz, n - 1, n_mpz);
            isCongruent = mpz_cmp_ui(a_mpz, 1) == 0;

            if (isCongruent && !isPrime(n_mpz, maxK)) {
                printf("n:%d, a:%d\n", n, a);
                gmp_printf("%d^(%d - 1) mod %d = %Zd\n", a, n, n, a_mpz);
                printf("1 mod %d = %d\n", n, 1 % n);

                printf("\n");
                return 0;
            }
        }
    }

    return 0;
}

int assignment3 (int argc, char *argv[]) {
    bool _isPrime, __isPrime, _isDivergent = false;
    int _isPrimeProb, numberOfPrimes = 0;
    const int maxK = 64, numberOfTests = 100000;

    mpz_t n_mpz;
    mpz_init(n_mpz);

    if (argc > 2) {
        mpz_set_str(n_mpz, argv[2], 10);
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

    for (int n = 5; n < numberOfTests; n+=2) {
        mpz_set_ui(n_mpz, n);
        _isPrime = isPrime(n_mpz, maxK);
        if (_isPrime) numberOfPrimes++;

        /* Check against gmp's isPrime implementation */
        _isPrimeProb = mpz_probab_prime_p(n_mpz, maxK);
        __isPrime = _isPrimeProb == 2;

        if (_isPrime != __isPrime) {
            printf("%s%d: %d == %d%s\n", COLOR_RED, n, _isPrime, _isPrimeProb, COLOR_RESET);
            _isDivergent = true;
        }
    }

    gettimeofday(&tv, NULL);
    unsigned long end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("Done in %lus (%lums)\n", (end - start) / 1000000, (end - start) / 1000);

    if (!_isDivergent) {
        printf("%sAll %d tests passed%s\n", COLOR_GREEN, numberOfTests, COLOR_RESET);
        printf("Number of primes found: %d\n", numberOfPrimes);
        printf("k: %d\n", maxK);
    }

    printf("\n");
    return 0;
}


int assignment4 (int argc, char *argv[]) {
    bool _isComposite;

    mpz_t n_start_mpz, n_mpz, n_max_mpz,
          max_count_mpz, count_mpz;

    mpz_init_set_ui(n_start_mpz, 2);
    mpz_init(n_mpz);
    mpz_init_set_ui(n_max_mpz, 2);
    mpz_init(max_count_mpz);
    mpz_init(count_mpz);

    mpz_pow_ui(n_start_mpz, n_start_mpz, 32);
    mpz_add_ui(n_start_mpz, n_start_mpz, 1);

    mpz_set(n_mpz, n_start_mpz);
    mpz_pow_ui(n_max_mpz, n_max_mpz, 33);

    while (mpz_cmp(n_mpz, n_max_mpz) < 0) {
        _isComposite = isComposite(n_mpz);
        if (!_isComposite) {
            mpz_sub(max_count_mpz, n_max_mpz, n_start_mpz);
            mpz_cdiv_q_ui(max_count_mpz, max_count_mpz, 2);

            mpz_sub(count_mpz, n_mpz, n_start_mpz);
            mpz_cdiv_q_ui(count_mpz, count_mpz, 2);

            gmp_printf("Result:\n%Zd\n\n", n_mpz);
            gmp_printf("Max count of numbers to be tested:\n%Zd\n\n", max_count_mpz);
            gmp_printf("Count of numbers tested:\n%Zd\n", count_mpz);

            printf("\n");
            return 0;
        }
        mpz_add_ui(n_mpz, n_mpz, 2);
    }
    return 0;
}


int assignment5 (int argc, char *argv[]) {
    bool _isPrime;
    const int maxK = 32;

    mpz_t n_start_mpz, n_mpz, n_max_mpz,
          max_count_mpz, count_mpz;

    mpz_init_set_ui(n_start_mpz, 2);
    mpz_init(n_mpz);
    mpz_init_set_ui(n_max_mpz, 2);
    mpz_init(max_count_mpz);
    mpz_init(count_mpz);

    mpz_pow_ui(n_start_mpz, n_start_mpz, 512);
    mpz_add_ui(n_start_mpz, n_start_mpz, 1);

    mpz_set(n_mpz, n_start_mpz);
    mpz_pow_ui(n_max_mpz, n_max_mpz, 513);

    while (mpz_cmp(n_mpz, n_max_mpz) < 0) {
        _isPrime = isPrime(n_mpz, maxK);
        if (_isPrime) {
            mpz_sub(max_count_mpz, n_max_mpz, n_start_mpz);
            mpz_cdiv_q_ui(max_count_mpz, max_count_mpz, 2);

            mpz_sub(count_mpz, n_mpz, n_start_mpz);
            mpz_cdiv_q_ui(count_mpz, count_mpz, 2);

            gmp_printf("Result:\n%Zd\n\n", n_mpz);
            gmp_printf("Max count of numbers to be tested:\n%Zd\n\n", max_count_mpz);
            gmp_printf("Count of numbers tested:\n%Zd\n", count_mpz);

            printf("\n");
            return 0;
        }
        mpz_add_ui(n_mpz, n_mpz, 2);
    }
    return 0;
}


int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please specify an assignment number\n");
        return 0;
    }
    const int assignment = atoi(argv[1]);
    switch (assignment) {
        case 2:
            printf("Launching assignment2\n\n");
            return assignment2(argc, argv);
            break;
        case 3:
            printf("Launching assignment3\n\n");
            return assignment3(argc, argv);
            break;
        case 4:
            printf("Launching assignment4\n\n");
            return assignment4(argc, argv);
            break;
        case 5:
            printf("Launching assignment5\n\n");
            return assignment5(argc, argv);
            break;
        default:
            printf("Assignment not found\n");
            break;
    }

    return 0;
}