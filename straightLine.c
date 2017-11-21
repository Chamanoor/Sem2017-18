
#include "header.h"

int a,b,c,d; //global variables defined to represent coordinate values 

/* this function takes 
coordinates of points
 of line from user*/

void inputLineCoordinates() {  
    printf("Please give the coordinates of points : \n");
    printf("Point 1 :\nx1 : \n");
    scanf("%d",&a);
    printf("y1: \n");
    scanf("%d",&b);

    printf("Point 2 : \nx2 : \n");
    scanf("%d",&c);
    printf("y2: \n");
    scanf("%d",&d);
    if(a>c)
    {int temp=a;
     a=c;
      c=temp;
      temp=b;
      b=d;
      d=temp;
    }
}


/* this function is used to 
draw line which has slope
 between 1 and infinite*/

void Line1infinite() {
  printf("Your line has slope between 1 and infinite\n");
  int x0 = a;
  int y0 =  b;
  int  x1 = c;
  int y1 = d;
  glClear(GL_COLOR_BUFFER_BIT); //clears Screen
  glBegin(GL_POINTS);
  int dx = x1 - x0;
  int dy = y1 - y0;
  int d = 2 * dx - dy;
  int incrE = 2 * dx;
  int incrNE = 2 * (dx - dy);
  int x = x0;
  int y = y0;
  glVertex2i(x, y);				//The loop runs util y coordinate of the point is less than or equal to y1
 
 /*Since the slope is greater than one,
  loop runs on variable y*/

  while(y < y1) {
    if(d <= 0){
       d += incrE;
       y++;
     }
    else { d += incrNE;
       x++;
       y++;
     }
    glVertex2i(x, y);
 }
}

/*
*this function draws 
*a line whose slope
*is between 0 and 1
*/

void Line01()
{ 
  printf("Your line has slope between 0 and 1\n");
  int x0 = a;
  int y0 = b;
  int  x1 = c;
  int y1 = d;
  glClear(GL_COLOR_BUFFER_BIT); //clears Screen
  glBegin(GL_POINTS);
  int dx  = x1 - x0;
  int dy = y1 - y0;
  int d = 2 * dy - dx;
  int incrE = 2 * dy;
  int incrNE = 2 *(dy - dx);
  int x = x0;
  int y = y0; 
  glVertex2i(x, y);
  while(x < x1)
  {
    if(d <= 0){
       d += incrE;
       x++;
     }
    else
     { d += incrNE;
       x++;
       y++;
     }
    glVertex2i(x, y);
 }
}

/*this function draws a line whose slope is between -1 and 0 i.e -1<=m<=0 which also means 0<=-m<1
  by first finding the points on the line whose slope is -m and while illuminating it,
 the corresponding reflected point about the line x= x0 ( starting x coordinate) is calculated and illuminated.
*/
 
void Line_10()
{
  printf("Your line has slope between 0 and -1\n");
  int x0 = c;
  int y0 = d;
  int x1 = 2 * c - a;
  int y1 = b;
  glClear(GL_COLOR_BUFFER_BIT); //clears Screen
  glBegin(GL_POINTS);
  int dx = x1 - x0;
  int dy = y1 - y0;
  int d = 2 * (dy) - dx; 
  int incrE = 2 * (dy);
  int incrNE = 2 * (dy - dx);
  int x = x0;
  int y = y0;
  glVertex2i(x,y);
  while(x < x1)
  { 
    if(d <= 0){
       d += incrE;
       x++;
     }
    else
     { d += incrNE;
       x++;
       y++;
     }
    glVertex2i(2 * c- x, y);
 }
}

/*this function draws a line whose slope is between -infinite and -1 i.e -infinite < m <-1 which also means 1<=-m<infinite
  by first finding the points on the line whose slope is -m and while illuminating it,
 the corresponding reflected point about the line x= x0 ( starting x coordinate) is calculated and illuminated.
*/

void Line_1infinite()
{
  
  printf("Your line has slope between -1 and infinite\n");
  int x0 = c;
  int y0 = d;
  int x1 = 2 * c - a;
  int y1 = b;
  glClear(GL_COLOR_BUFFER_BIT); //clears Screen
  glBegin(GL_POINTS);
  int dx = x1 - x0;
  int dy = y1 - y0;
  int d = 2 * (dx) - dy;
  int incrE = 2 * (dx);
  int incrNE = 2 * (dx - dy);
  int x = x0;
  int y = y0;
  glVertex2i(x, y);
  while(y < y1)
  {
    if(d <= 0){
       d += incrE;
       x++;
     }
    else
     { d += incrNE;
       x++;
       y++;
     }
    glVertex2i(2 * c - x, y);
 }
}


/*this function invokes any of the above functions 
i.e. Line01 or Line1infinite or Line_10 or Line_1infinite
based on the input coordinates*/


void LineDraw()
{
 
 double m = ((double)(d - b) / (double)(c - a));
  printf("%f is your line slope\n",m);
 if(a < c)
 {  if(b <= d)
    {  if(0 <= m &&  m <= 1)
       Line01();
       else
       Line1infinite(); 
    }
    else
    { if(-1 <= m && m <= 0)
      Line_10();
      else
      Line_1infinite();
    }
 
 }
 if(a == c)
 { Line1infinite();
 }
}


void myInitLine(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
// set white background color
glColor3f(0.0f, 0.0f, 0.0f);
// set the drawing color
glPointSize(4.0);
// a ‘dot’ is 4 by 4 pixels
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-250.0, 250.0, -480.0, 480.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>

void myDisplayLine(void)
{ 

LineDraw();
glEnd();
glFlush();
// send all output to display
}



