#ifndef RABINMILLER_H_   /* Include guard */
#define RABINMILLER_H_

#include <gmp.h>
bool isPrime(const mpz_t n_mpz, const int maxK);
bool isComposite (const mpz_t n_mpz);

#endif // RABINMILLER_H_