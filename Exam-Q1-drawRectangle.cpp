#include <GL/glut.h>
#include<math.h>
int width = 800, height = 800; 
void drawLine(int x1, int y1, int x2, int y2) 
{ 
  glLineWidth(5);
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
  drawLine(150,600,280,600); //upline
  drawLine(150,500,280,500);//down line
  drawLine(150,500,150,600);//left
  drawLine(280,500,280,600);//right line
  glLineWidth(2);
  glColor3f(1.0, 1.0, 0.0); 
  drawLine(150,700,150,600);//left up line y
  drawLine(280,500,400,500);//down line x
  drawLine(150,700,400,700);//up line a
  drawLine(400,500,400,700);//upline b
  drawLine(370,500,370,670);//line p
  drawLine(330,500,330,630);//line q
  drawLine(150,630,330,630);//line m
  drawLine(150,670,370,670);//left n



  glFlush(); 
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
  glutCreateWindow("Desktop"); 
  glutDisplayFunc(display); 
  myinit(); 
  glutMainLoop(); 
  return 0; 
}
