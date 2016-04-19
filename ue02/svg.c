#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "svg.h"

char svgTpl[1079] = "<svg xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink' width='100%' viewBox='{{minX}} {{minY}} {{width}} {{height}}'><style>svg { transform: translateZ(0) translate3d(0, 0, 0); backface-visibility: hidden; perspective: 1000; } path { fill: #fff; animation: rainbow 20s ease infinite; } .path-2 { animation-delay: 0.05s; } .path-3 { animation-delay: 0.15s; } .path-4 { animation-delay: 0.3s; } .path-5 { animation-delay: 0.5s; } .path-6 { animation-delay: 0.75s; } .path-7 { animation-delay: 1.15s; } .path-8 { animation-delay: 1.5s; } .path-9 { animation-delay: 1.9s; } .path-10 { animation-delay: 2.35s; } .path-11 { animation-delay: 2.85s; } .path-12 { animation-delay: 3.4s; } .path-13 { animation-delay: 4s; } .path-14 { animation-delay: 4.65s; } .path-15 { animation-delay: 5.35s; } @keyframes rainbow { 0% { fill: #DC001B; } 12.5% { fill: #FFEA2E; } 25% { fill: #228D1B; } 37.5% { fill: #1397F1; } 50% { fill: #5321A8; } 62.5% { fill: #1397F1; } 75% { fill: #228D1B; } 87.5% { fill: #FFEA2E; } 100% { fill: #DC001B; } } </style>\n\t{{path}}\n</svg>";

char path[172] = "<path d='M {{a_x}} {{a_y}} L {{c_x}} {{c_y}} L {{e_x}} {{e_y}} L {{d_x}} {{d_y}} L {{b_x}} {{b_y}} z' class='path-{{depth}}' fill='#fff' stroke='#fff' stroke-width='1' />\n\t";


int replaceStr (char *orig, char *rep, char *after) {
    // printf("replace %s with %s\n", orig, rep);

    char buffer[2048000];
    char *p;

    if(!(p = strstr(newSvg, orig)))
        return 0;

    strncpy(buffer, newSvg, p - newSvg);
    buffer[p - newSvg] = '\0';

    sprintf(buffer + (p - newSvg), "%s%s%s", rep, after, p + strlen(orig));

    newSvg = realloc(newSvg, strlen(buffer) + 1);
    sprintf(newSvg, "%s", buffer);
    return 1;
}

void replacePathStuff (struct Vector *v, char *name) {

    char rep[30];
    char orig[34];

    if (v->x < smallestX) smallestX = v->x;
    if (v->x > biggestX) biggestX = v->x;
    if (v->y < smallestY) smallestY = v->y;
    if (v->y > biggestY) biggestY = v->y;

    sprintf(rep, "%f", v->x);
    sprintf(orig, "{{%s_x}}", name);
    replaceStr(orig, rep, "");

    sprintf(rep, "%f", v->y);
    sprintf(orig, "{{%s_y}}", name);
    replaceStr(orig, rep, "");

}

void insertPath (struct Vector *a, struct Vector *b, struct Vector *c, struct Vector *d, struct Vector *e, int depth) {

    char rep[30];
    char orig[34];
    sprintf(orig, "%s", "{{path}}");
    replaceStr(orig, path, "{{path}}");

    sprintf(rep, "%d", depth);
    sprintf(orig, "{{depth}}");
    replaceStr(orig, rep, "");

    replacePathStuff(a, "a");
    replacePathStuff(b, "b");
    replacePathStuff(c, "c");
    replacePathStuff(d, "d");
    replacePathStuff(e, "e");

}

void writeSvg () {
    char rep[30];
    char orig[34];

    smallestX -= 10;
    smallestY -= 10;
    biggestX += 10;
    biggestY += 10;

    sprintf(rep, "%f", smallestX);
    sprintf(orig, "%s", "{{minX}}");
    replaceStr(orig, rep, "");

    sprintf(rep, "%f", smallestY);
    sprintf(orig, "%s", "{{minY}}");
    replaceStr(orig, rep, "");

    sprintf(rep, "%f", -smallestX + biggestX);
    sprintf(orig, "%s", "{{width}}");
    replaceStr(orig, rep, "");

    sprintf(rep, "%f", -smallestY + biggestY);
    sprintf(orig, "%s", "{{height}}");
    replaceStr(orig, rep, "");

    sprintf(orig, "%s", "\n\t{{path}}");
    replaceStr(orig, "", "");

    FILE *fp = fopen("fractal.svg", "w");
    fputs(newSvg, fp);
    fclose(fp);
}