#include <GL/glut.h>
#include<math.h>
int width = 600, height = 400; 
int choice = 0; 
int xi, yi, xf, yf; 
void drawLine(int x1, int y1, int x2, int y2) 
{ 
  glClear(GL_COLOR_BUFFER_BIT); 
  glLineWidth(3);
  glBegin(GL_LINES); 
  glVertex2i(x1, y1); 
  glVertex2i(x2, y2); 
  glEnd(); 
  glFlush(); 
} 
void display() 
{ 
  glClearColor(0.0, 0.0,0.0, 0.0); 
  glColor3f(1.0, 1.0, 1.0); 
  glClear(GL_COLOR_BUFFER_BIT); 
  glFlush(); 
}


void mouse(int btn, int state, int x, int y) 
{ 
  if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    { 
      switch(choice) 
	{ 
	case 0: 
	  xi = x; 
	  yi = (height-y); 
	  choice = 1; 
	  break; 
	case 1: 
	  xf = x; 
	  yf = (height-y); 
	  drawLine(xi,yi,xf,yf); 
	  choice = 0; 
	  break; 
	} 
    } 
} 
void myinit() 
{ 
  glViewport(0,0,width,height); 
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
  gluOrtho2D(0.0,(GLdouble)width,0.0,(GLdouble)height); 
  glMatrixMode(GL_MODELVIEW); 
} 
int main(int argc, char** argv) 
{ 
  glutInit(&argc,argv); 
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
  glutInitWindowSize(width,height); 
  glutCreateWindow("DrawLine by Mouse"); 
  glutDisplayFunc(display); 
  myinit(); 
  glutMouseFunc(mouse);
  glutMainLoop(); 
  return 0; 
}
