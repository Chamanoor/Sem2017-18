#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14

typedef struct State{
 double x,y;
 double angle;
 char color[20];
}State;
void repeat(char *t);

