// fractal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include "vector.h"
#include "svg.h"

const double rad = M_PI / 180;
const double deg = 180 / M_PI;

unsigned int origAlpha;
double sinAlpha;


int fractalPart (struct Vector *a, struct Vector *b, double alpha, double h, int depth) {

    if (depth > 13 || h < 0.1) return h;

    struct Vector *ab = newVector(b->x - a->x, b->y - a->y);
    const double length_ab = vectorLength(ab);

    struct Vector *c = newVector(ab->y + a->x, -(ab->x - a->y));
    struct Vector *d = newVector((b->x + c->x) - a->x, (b->y + c->y) - a->y);

    const double length_ce = fabs(h / sinAlpha);
    const double e_x = length_ce * cos(-alpha * rad);
    const double e_y = length_ce * sin(-alpha * rad);
    struct Vector *e = newVector(c->x + e_x, c->y + e_y);

    insertPath(a, b, c, d, e, depth);

    struct Vector *de = newVector(d->x - e->x, d->y - e->y);
    const double length_de = vectorLength(de);

    const double beta = asin(h / length_de) * deg;

    const double leftH = h * length_ce / length_ab;
    const double rightH = h * length_de / length_ab;

    ++depth;

    return
        fractalPart(c, e, alpha + origAlpha, leftH, depth) +
        fractalPart(e, d, alpha - beta, rightH, depth);

}


int main (int argc, char *argv[]) {

    if (argc != 5) {
        printf("Wrong number of parameters\n");
        printf("Passed arguments: %d\tRequired arguments: 4\n", argc - 1);
        printf("Usage: fractal [A] [B] [alpha] [h]\n");
        return 1;
    }

    newSvg = malloc(strlen(svgTpl) + 1);
    sprintf(newSvg, "%s", svgTpl);

    struct Vector *a = newVector(atoi(argv[1]), 0);
    struct Vector *b = newVector(atoi(argv[2]), 0);

    origAlpha = atoi(argv[3]);
    sinAlpha = sin(origAlpha * rad);
    const unsigned int h = atoi(argv[4]);


    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long start = 1000000 * tv.tv_sec + tv.tv_usec;

    fractalPart(a, b, origAlpha, h, 1);

    gettimeofday(&tv, NULL);
    unsigned long end = 1000000 * tv.tv_sec + tv.tv_usec;
    printf("Done in %lums\n", (end - start));

    writeSvg();

}