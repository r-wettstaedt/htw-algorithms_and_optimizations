// extended greatest common divisor
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>


int calc (int a, int b) {

    int c = a;
    int u_c = 1;
    int v_c = 0;

    int d = b;
    int u_d = 0;
    int v_d = 1;

    int i = 0;

    while (c != 0) {
        const int q = floor(d / c);
        const int c_c = c;
        c = d - q * c;
        d = c_c;

        u_d = u_c;
        u_c = u_d - q * u_c;

        v_d = v_c;
        v_d = q * v_c;

        i++;
    }

    printf("d: %d\tu_d: %d\tv_d: %d\n", d, u_d, v_d);
    return i;

}


int main (int argc, char *argv[]) {

    if (argc != 3) {
        printf("Wrong number of parameters\n");
        printf("Passed arguments: %d\tRequired arguments: 2\n", argc - 1);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if (a < 0 || b < 0) {
        printf("Parameters must be positive\n");
        if (a == 0 && b == 0) {
            printf("Only one parameter is allowed to be 0\n");
        }

        return 1;
    }

    printf("a: %d\tb: %d\n", a, b);

    struct timeval tv;
    gettimeofday(&tv, NULL);
    const double start = tv.tv_usec;

    const int steps = calc(a, b);

    gettimeofday(&tv, NULL);
    printf("Done in %gμs\n", tv.tv_usec - start);
    printf("Required iterations %d\n", steps);

    return 0;

}
