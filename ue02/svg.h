#ifndef SVG_H_   /* Include guard */
#define SVG_H_

char svgTpl[1295];
char pathTpl[172];
char *newSvg;

double smallestX;
double smallestY;
double biggestX;
double biggestY;

int replaceStr (char *orig, char *rep, char *after);
void replacePathStuff (struct Vector *v, char *name);
void insertPath (struct Vector *a, struct Vector *b, struct Vector *c, struct Vector *d, struct Vector *e, int depth);
void writeSvg ();

#endif // SVG_H_