# Programmieraufgabe 6
    Robert Wettstädt 535161
    Sona Pecenakova 540607

### 1. Wieso kann eine natürliche Zahl n nicht pseudoprim bezüglich einer Zahl a sein, wenn ggT(a, n) ≠ 1 gilt?
* weil die Definition von Primzahlen besagt, dass sie sich nicht als Produkt zweier natürlicher Zahlen, die beide größer als 1 sind, darstellen lassen


### 2. Finden Sie natürliche Zahlen n und 1 < a < n-1, für die a^(n-1) ≡ 1 mod n gilt, wobei n aber keine Primzahl ist.
Implementation:
```c
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
}
```
Output:
```
n:15, a:4
4^(15 - 1) mod 15 = 1
1 mod 15 = 1
```

### 3. Implementieren Sie den Algorithmus von Rabin und Miller; einen Pseudocode dazu finden Sie in moodle. Testen Sie Ihre Implementierung, indem Sie diese mit der java-BigInteger-Methode isProbablePrime vergleichen. Wie viele Primzahlen < 1.000.000 findet Ihr Programm? Mit welchem Parameter k?
Implementation:
```c
bool isPrime(const mpz_t n_mpz, const int maxK) {
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
```
```c
int assignment3 (int argc, char *argv[]) {
    bool _isPrime, __isPrime, _isDivergent = false;
    int _isPrimeProb, numberOfPrimes = 0;
    const int maxK = 64, numberOfTests = 100000;

    mpz_t n_mpz;
    mpz_init(n_mpz);

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

    if (!_isDivergent) {
        printf("%sAll %d tests passed%s\n", COLOR_GREEN, numberOfTests, COLOR_RESET);
        printf("Number of primes found: %d\n", numberOfPrimes);
        printf("k: %d\n", maxK);
    }

    printf("\n");
    return 0;
}
```
Output:
```bash
All 1.000.000 tests passed
Number of primes found: 78.496
k: 64
```

### 4. Finden Sie eine 32-bit-Zahl, die bei einem (k = 1) Durchlauf des MillerRabin-Testes nicht als zusammengesetzt erkannt wird, obwohl sie das aber ist. Wie viele Zahlen müssen dabei getestet werden?
Implementation:
```c
int assignment4 (int argc, char *argv[]) {
    const int maxK = 32;
    mpz_t n_min_mpz, n_mpz, n_max_mpz,
          max_count_mpz, count_mpz;

    mpz_init_set_ui(n_min_mpz, 2);
    mpz_init_set_ui(n_mpz, 0);
    mpz_init_set_ui(n_max_mpz, 2);
    mpz_init(max_count_mpz);
    mpz_init(count_mpz);

    mpz_pow_ui(n_min_mpz, n_min_mpz, 32);
    mpz_pow_ui(n_max_mpz, n_max_mpz, 33);

    mpz_set(n_mpz, n_min_mpz);
    mpz_add_ui(n_mpz, n_mpz, 1);
    mpz_sub(max_count_mpz, n_max_mpz, n_min_mpz);
    mpz_cdiv_q_ui(max_count_mpz, max_count_mpz, 2);
    gmp_printf("Max count of numbers to be tested:\n%Zd\n\n", max_count_mpz);

    while (mpz_cmp(n_mpz, n_max_mpz) < 0 && !(isPrime(n_mpz, 1) && !isPrime(n_mpz, maxK))) {

        mpz_add_ui(n_mpz, n_mpz, 2);
        mpz_add_ui(count_mpz, count_mpz, 1);
    }

    gmp_printf("Count of numbers tested:\n%Zd\n\n", count_mpz);
    gmp_printf("Number found:\n%Zd\n", n_mpz);

    printf("\n");
    return 0;
}
```
Output:
```bash
Max count of numbers to be tested:
(2^33 - 2^32) / 2 = 2.147.483.648

Count of numbers tested:
501.793

Number found:
4.295.970.883
```

### 5. Finden Sie mit Ihrer Implementierung des Rabin-Miller-Algorithmus eine Zufalls(pseudo)primzahl mit 512 bit. Wie viele Zahlen müssen dabei getestet werden?
Implementation:
```c
int assignment5 (int argc, char *argv[]) {
    bool _isPrime = false;
    const int maxK = 32;
    unsigned long seed;
    struct timeval tv;

    mpz_t n_min_mpz, n_mpz, n_max_mpz,
          max_count_mpz, count_mpz;
    gmp_randstate_t state;

    mpz_init_set_ui(n_min_mpz, 2);
    mpz_init_set_ui(n_mpz, 0);
    mpz_init_set_ui(n_max_mpz, 2);
    mpz_init(max_count_mpz);
    mpz_init(count_mpz);

    mpz_pow_ui(n_min_mpz, n_min_mpz, 512);
    mpz_pow_ui(n_max_mpz, n_max_mpz, 513);
    mpz_sub(max_count_mpz, n_max_mpz, n_min_mpz);

    gmp_printf("Max count of numbers to be tested:\n%Zd\n\n", max_count_mpz);

    gmp_randinit_mt(state);
    gettimeofday(&tv, NULL);
    seed = 1000000 * tv.tv_sec + tv.tv_usec;
    gmp_randseed_ui(state, seed);

    while (!_isPrime) {

        mpz_urandomm(n_mpz, state, n_max_mpz);

        while (mpz_cmp(n_mpz, n_min_mpz) < 0) {
            mpz_add_ui(count_mpz, count_mpz, 1);
            mpz_urandomm(n_mpz, state, n_max_mpz);
        }

        _isPrime = isPrime(n_mpz, maxK);
        mpz_add_ui(count_mpz, count_mpz, 1);

    }

    gmp_printf("Count of numbers tested:\n%Zd\n\n", count_mpz);
    gmp_printf("Found prime number:\n%Zd\n", n_mpz);

    printf("\n");
    return 0;
}
```
Output:
```bash
Max count of numbers to be tested:
2^513 - 2^512 = 13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096

Count of numbers tested:
301

Found prime number:
22217638908594694483827437169228357357275109749930845558291885487544431946190055624329602279515026752088967757871798254880285545055060125654636895449509671
```