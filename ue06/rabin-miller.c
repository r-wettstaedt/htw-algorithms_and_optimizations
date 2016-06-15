#include <stdlib.h>
#include <stdbool.h>
#include <gmp.h>

#include "rabin-miller.h"

bool isPrime (const mpz_t n_mpz, const int maxK) {
    if (mpz_even_p(n_mpz)) return false;
    if (mpz_cmp_ui(n_mpz, 3) < 0) return false;

    unsigned long t, k, i;

    mpz_t n_minus_1_mpz, n_minus_3_mpz,
          s_mpz, a_mpz, v_mpz;

    mpz_init(n_minus_1_mpz);
    mpz_init(n_minus_3_mpz);

    mpz_sub_ui(n_minus_1_mpz, n_mpz, 1);
    mpz_sub_ui(n_minus_3_mpz, n_mpz, 3);

    mpz_init(s_mpz);
    mpz_init(a_mpz);
    mpz_init(v_mpz);

    /* s = n - 1; */
    mpz_set(s_mpz, n_minus_1_mpz);
    t = 0;

           /* s % 2 = 0 */
    while (mpz_even_p(s_mpz)) {

        /* s /= 2; */
        mpz_cdiv_q_ui(s_mpz, s_mpz, 2);
        t++;
    }

    k = 0;
    while (k < maxK) {

        /* a = (rand() % (n - 3)) + 2; */
        /* a = rand() */
        mpz_set_ui(a_mpz, rand());
        /* a = a % n - 3 */
        mpz_mod(a_mpz, a_mpz, n_minus_3_mpz);
        /* a = a + 2 */
        mpz_add_ui(a_mpz, a_mpz, 2);

        /* v = pow(a, s) % n; */
        mpz_powm(v_mpz, a_mpz, s_mpz, n_mpz);

            /* v != 1 */
        if (mpz_cmp_ui(v_mpz, 1) != 0) {
            i = 0;

                   /* v != n - 1 */
            while (mpz_cmp(v_mpz, n_minus_1_mpz) != 0) {
                if (i == t - 1) return false;

                /* v = (v * v) % n; */
                mpz_powm_ui(v_mpz, v_mpz, 2, n_mpz);
                i++;
            }
        }

        k += 2;
    }

    return true;
}