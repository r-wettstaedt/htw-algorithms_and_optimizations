#ifndef VECTOR_H_   /* Include guard */
#define VECTOR_H_

struct Vector {
    double x;
    double y;
};

struct Vector *newVector (double x, double y);
double vectorLength (struct Vector *v);

#endif // VECTOR_H_