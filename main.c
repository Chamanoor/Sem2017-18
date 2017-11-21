#include"header.h"


/*Function to drawLine*/

void drawLine()
{
	inputLineCoordinates();
	// initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 480);
	// set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Straight Line"); // open the screen window
	glutDisplayFunc(myDisplayLine);
	
	myInitLine();
	glutMainLoop();

} 

/*Function to drawCircle*/

void drawCircle()
{       
        inputRadius();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640,640);				// set window size
	glutInitWindowPosition(100, 150); 		   // set window position on screen
	glutCreateWindow("Circle"); 	  		  // open the screen window
	glutDisplayFunc(myDisplayCircle);
	myInitCircle();
	glutMainLoop();
}
/* Function to Draw Tree*/

void drawTree1()
{
  
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // set display mode
	glutInitWindowSize(800, 700);				 // set window size
	glutInitWindowPosition(500, 350); 			// set window position on screen
	glutCreateWindow("Tree"); 	               // open the screen window
	glutDisplayFunc(myTreeDisplay);
	
	myTreeInit();
	glutMainLoop();
}

int main(int argc,char **argv)
{
	int options;
	glutInit(&argc, argv);
	
	while(1)
	{	printf("Pick one of the following!\n");
		printf("1.Straight Line\n2.Circle\n3.Tree \n");
		scanf("%d",&options);
		
		switch(options)
		{
			case 1:
			drawLine();
			break;
			case 2: 
			drawCircle();
			break;
			case 3:
			drawTree1();
			break;
			
			return 0;
		}
	}
}
