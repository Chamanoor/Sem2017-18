#include "header.h"

int pos=0,counter = 0, color = 0;
State states[10000000];
//char str[10000000];
char *str=NULL;
void push(State a) {
	states[pos++] = a;
}

State pop() {
	return states[--pos];
}

void drawTreeLine(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    int c;
    float r,g,b;
    c = color % 3;
    switch(c) {
        case 0:
            r = 1.0, g = 0.55, b = 0.0;
            break;
        case 1:
            r = 1.0, g = 0.0, b = 0.0;
            break;
        case 2:
            r = 0.9411, g = 0.5, b = 0.5;
            break;
       
    }
	glBegin(GL_LINES);
        glColor3f(r, g, b);
		glVertex2d(x1, y1);
		glVertex2d(x2, y2);
	glEnd();
}

/*This method changes the
 direction with respect to point (x,y)*/ 

State rotate(double x,double y, State st,double angle) { 
    State t;
    t.x=(x-st.x)*cos(angle*PI/180)-(y-st.y)*sin(angle*PI/180)+st.x;     
    t.y=(x-st.x)*sin(angle*PI/180)+(y-st.y)*cos(angle*PI/180)+st.y;
  return t;
}

/*This function draws tree*/
    
void treeDraw() { 
    double x=10,y=-395;
    double slope=0.0;
    State current;
    current.x=10;
    current.y=-400;
    current.angle=0.0;
    State temp;
    char *t ="F[+X][-X]FX";
    repeat(t); 				//Sequence generation
   str=(char*)malloc(sizeof(char)*5000);
   FILE* fp;
   fp=fopen("string.txt","r"); 
   while(fgets(str,5000,fp)!=NULL);    //Reading the tree sequence from file and storing it in array str 

   	
 for(long i=0;i<strlen(str);i++) {
        switch(str[i]) {      
            case 'F':                                 
                drawTreeLine(current.x,current.y,x,y);
                current.x=x;
                current.y=y;
                x=x+5*sin(current.angle);
                y=y+5*cos(current.angle);
                break;    
            case '+':
                temp=rotate(x,y,current,15.0);
                x=temp.x;
                y=temp.y;
                current.angle=atan((x-current.x)/(y-current.y));
                break;
            case '-':
                temp=rotate(x,y,current,-15.0);
                x=temp.x;
                y=temp.y;
                current.angle=atan((x-current.x)/(y-current.y));
                break;
             case '[':
                push(current);
                color++;
                break;
            case ']':
                current=pop();
                x=current.x+5*sin(current.angle);
                y=current.y+5*cos(current.angle);
                color++;
                break;
     }
  }
}

void myTreeInit(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);				// set white background color
	glColor3f(0.0f, 0.0f, 0.0f);					// set the drawing color
	glPointSize(4.0);								// a ‘dot’ is 4 by 4 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250.0, 250.0, -480.0, 480.0);
    //treeDraw();
}

    
void tree2Draw() { 
    double x=10,y=-380;
    double length=20.0;
    State current;
    current.x=10;
    current.y=-400;
    current.angle=0.0;
    str=(char*)malloc(sizeof(char)*5000);
   FILE* fp;
   fp=fopen("string2.txt","r");
   while(fgets(str,10000,fp)!=NULL); 
    State temp;
    for(int i=0;i<strlen(str);i++) {
        switch(str[i]) {      
            case 'F':                                 
                drawTreeLine(current.x,current.y,x,y);
                current.x=x;
                current.y=y;
                x=x+length*sin(current.angle);
                y=y+length*cos(current.angle);
                break;
           case '+':
                temp=rotate(x,y,current,22.5);
                x=temp.x;
                y=temp.y;
                current.angle=atan((x-current.x)/(y-current.y));
                
                break;
            case '-':
                temp=rotate(x,y,current,-22.5);
                x=temp.x;
                y=temp.y;
                
                current.angle=atan((x-current.x)/(y-current.y));
                break;
             case '[':
                
                push(current);
                color++;
                break;
            case ']':
                current=pop();
                x=current.x+length*sin(current.angle);
                y=current.y+length*cos(current.angle);
                color++;               
                break;
     }
  }
}

void myTreeDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    clock_t start, end;
    double cpu_time_used;
    start = clock();                                    // To measure the time taken to build the tree
    treeDraw();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to build the tree: %lf\n",cpu_time_used );
    glEnd();
    glFlush();      
   }



