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

State states[10000000];

void inputLineCoordinates();
void Line1infinite();
void Line01();
void Line_10();
void Line_1infinite();
void LineDraw();
void myInitLine(void);
void myDisplayLine(void);

void inputRadius();
void myInitCircle(void);
void myDisplayCircle(void);
void myTreeDisplay2();
void drawTreeLine2(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
void tree2Draw();

void repeat(char *t);
void myTreeDisplay(void);
void myTreeInit(void);
void treeDraw() ;
void drawTreeLine(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2); 

/*void repeatNoBranch(char *t);*/

/*void myTreeInit2(void)*/;

   

