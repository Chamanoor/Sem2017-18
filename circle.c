#include"header.h"
int radius;
void inputRadius()
{ 
        printf("In multiples of 10, give radius of the circle\n" );      
	scanf("%d",&radius);	
}

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInitCircle(void) {
glClearColor(1.0,1.0,1.0,0.0);		// set white background color
glColor3f(0.0f, 0.0f, 0.0f);		// set the drawing color
glPointSize(4.0);					// a ‘dot’ is 4 by 4 pixels
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500.0, 600.0,-500.0, 600.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplayCircle(void) { 

	glClear(GL_COLOR_BUFFER_BIT);
	// clear the screen
	glBegin(GL_POINTS);
	glVertex2i(0,0);

	int x=0;
	int y=radius;
	int d=1-radius;
	int deltaE=3;
	int deltaSE=-2*radius+5;
	glVertex2i(x,y);
	while(y>x){
	if(d<0){
		d+=deltaE;
		deltaE+=2;
		deltaSE+=2;
	}else{
		d+=deltaSE;
		deltaE+=2;
		deltaSE+=4;
		y--;
}
	glVertex2i(x,y);
	glVertex2i(-x,+y);
	glVertex2i(+x,-y);
	glVertex2i(-x,-y);
	glVertex2i(-y,-x);
	glVertex2i(y,x);
	glVertex2i(y,-x);
	glVertex2i(-y,+x);
	x++;
}
glEnd();
glFlush();										  // send all output to display
}

