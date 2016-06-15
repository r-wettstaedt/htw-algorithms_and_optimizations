#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "vector.h"

struct Vector *newVector (double x, double y) {
    struct Vector *v = malloc(sizeof(struct Vector));
    assert(v != NULL);

    v->x = x;
    v->y = y;

    return v;
}

double vectorLength (struct Vector *v) {
    return sqrt(v->x * v->x + v->y * v->y);
}