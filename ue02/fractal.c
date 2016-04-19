// fractal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "vector.h"

char svg[] = "<svg xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink' width='{{width}}px' height='{{height}}px' viewBox='{{minX}} {{minY}} {{width}} {{height}}' zoomAndPan='disable' preserveAspectRatio='none'>\n\t{{path}}\n</svg>";
char path[] = "<path d='M {{a_x}} {{a_y}} L {{c_x}} {{c_y}} L {{e_x}} {{e_y}} L {{d_x}} {{d_y}} L {{b_x}} {{b_y}} z' fill='orange' stroke='black' stroke-width='3' />\n\t";

char *newSvg;

double smallestX;
double smallestY;
double biggestX;
double biggestY;

int replace_str(char *orig, char *rep, char *after) {
    // printf("replace %s with %s\n", orig, rep);

    static char buffer[4096];
    char *p;

    if(!(p = strstr(newSvg, orig)))
        return 0;

    strncpy(buffer, newSvg, p - newSvg);
    buffer[p - newSvg] = '\0';

    sprintf(buffer + (p - newSvg), "%s%s%s", rep, after, p + strlen(orig));
    newSvg = malloc(strlen(buffer) + 1);
    sprintf(newSvg, "%s", buffer);
    return 1;
}

void replace (struct Vector *v, char *name) {

    char rep[15];
    char orig[19];

    if (v->x < smallestX) smallestX = v->x;
    if (v->x > biggestX) biggestX = v->x;
    if (v->y < smallestY) smallestY = v->y;
    if (v->y > biggestY) biggestY = v->y;

    sprintf(rep, "%f", v->x);
    sprintf(orig, "{{%s_x}}", name);
    replace_str(orig, rep, "");

    sprintf(rep, "%f", v->y);
    sprintf(orig, "{{%s_y}}", name);
    replace_str(orig, rep, "");

}


int fractalPart (struct Vector *a, struct Vector *b, int alpha, double h, int cycles) {

    if (cycles > 100 || h < 1) return cycles;
    int alphaNormalized = alpha * cycles;

    struct Vector *ab = newVector(b->x - a->x, b->y - a->y);

    struct Vector *c = newVector(ab->y + a->x, -(ab->x - a->y));
    struct Vector *d = newVector((b->x + c->x) - a->x, (b->y + c->y) - a->y);



    double si = sin(-alphaNormalized * M_PI / 180);
    double co = cos(-alphaNormalized * M_PI / 180);

    double length_ce = fabs(h / sin(-alphaNormalized / cycles * M_PI / 180));
    struct Vector *e;

    double e_x = length_ce;
    double e_y = 0;
    e = newVector(e_x, e_y);

    double _e_x = e_x * co - e_y * si;
    double _e_y = e_x * si + e_y * co;
    e = newVector(_e_x, _e_y);
    e = newVector(c->x + _e_x, c->y + _e_y);



    printf("\n\nNew Fractal Part\n");
    printf("alpha: %d\t| %d\n", alpha, alphaNormalized);
    printf("cycle: %d\n", cycles);
    printf("h: %.0f\n\n", h);
    printf("a: %.0f\t| %.0f\n", a->x, a->y);
    printf("b: %.0f\t| %.0f\n", b->x, b->y);
    printf("ab: %.0f\t| %.0f\n", ab->x, ab->y);
    printf("c: %.0f\t| %.0f\n", c->x, c->y);
    printf("d: %.0f\t| %.0f\n", d->x, d->y);
    printf("e: %.0f\t| %.0f\n", e->x, e->y);
    printf("|ce|: %.0f\n", length_ce);


    char orig[19];
    sprintf(orig, "%s", "{{path}}");
    replace_str(orig, path, "{{path}}");

    replace(a, "a");
    replace(b, "b");
    replace(c, "c");
    replace(d, "d");
    replace(e, "e");
    e = newVector(c->x + _e_x, c->y + _e_y);

    struct Vector *ce = newVector(c->x - e->x, c->y - e->y);
    printf("|ce|: %.0f\n", vectorLength(ce));

    double length_ab = vectorLength(ab);
    printf("|ab|: %.0f\n", length_ab);

    double factor = length_ce / length_ab;
    return fractalPart(c, e, alpha, h * factor, ++cycles);

}


int main (int argc, char *argv[]) {

    if (argc != 5) {
        printf("Wrong number of parameters\n");
        printf("Passed arguments: %d\tRequired arguments: 4\n", argc - 1);
        printf("Usage: fractal [A] [B] [alpha] [h]\n");
        return 1;
    }

    newSvg = malloc(strlen(svg) + 1);
    sprintf(newSvg, "%s", svg);

    struct Vector *a = newVector(atoi(argv[1]), 0);
    struct Vector *b = newVector(atoi(argv[2]), 0);

    unsigned int alpha = atoi(argv[3]);
    unsigned int h = atoi(argv[4]);


    fractalPart(a, b, alpha, h, 1);


    char rep[15];
    char orig[19];

    smallestX -= 10;
    smallestY -= 10;
    biggestX += 10;
    biggestY += 10;

    sprintf(rep, "%f", smallestX);
    sprintf(orig, "%s", "{{minX}}");
    replace_str(orig, rep, "");

    sprintf(rep, "%f", smallestY);
    sprintf(orig, "%s", "{{minY}}");
    replace_str(orig, rep, "");

    sprintf(rep, "%f", -smallestX + biggestX);
    sprintf(orig, "%s", "{{width}}");
    replace_str(orig, rep, "");

    sprintf(rep, "%f", -smallestX + biggestX);
    sprintf(orig, "%s", "{{width}}");
    replace_str(orig, rep, "");

    sprintf(rep, "%f", -smallestY + biggestY);
    sprintf(orig, "%s", "{{height}}");
    replace_str(orig, rep, "");

    sprintf(rep, "%f", -smallestY + biggestY);
    sprintf(orig, "%s", "{{height}}");
    replace_str(orig, rep, "");

    sprintf(orig, "%s", "\n\t{{path}}");
    replace_str(orig, "", "");

    FILE *fp = fopen("fractal.svg", "w");
    fputs(newSvg, fp);
    fclose(fp);

}