#include <GL/glut.h>
#include<math.h>
#include<string.h>
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
void drawPlayer(int x, int y) {
  glPointSize(25);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}
void drawBall(int x,int y)
{
  glPointSize(150);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}
void bitmap_output(int x, int y, char *string, void *font)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

void display() 
{ 
  glClearColor(0.0, 1.0,1.0, 0.0); 
  glColor3f(1.0, 1.0, 1.0); 
  glClear(GL_COLOR_BUFFER_BIT);

  // teamA  player 1
  glColor3f(1.0, 0.0, 0.0);
  drawPlayer(200,300);//player 1
  glColor3f(1.0, 1.0, 1.0); 
  bitmap_output(190,290, "1",GLUT_BITMAP_TIMES_ROMAN_24);


  //teamA player 2
  glColor3f(1.0, 0.0, 0.0);
  drawPlayer(100,100);//player 1
  glColor3f(1.0, 1.0, 1.0); 
  bitmap_output(90,90, "2",GLUT_BITMAP_TIMES_ROMAN_24);


  //teamA player 3
  glColor3f(1.0, 0.0, 0.0);
  drawPlayer(300,500);//player 1
  glColor3f(1.0, 1.0, 1.0); 
  bitmap_output(290,490, "3",GLUT_BITMAP_TIMES_ROMAN_24);


  // teamB  player 1
  glColor3f(1.0, 1.0, 0.0);
  drawPlayer(500,300);//player 1
  glColor3f(1.0, 0.0, 0.0); 
  bitmap_output(490,290, "1",GLUT_BITMAP_TIMES_ROMAN_24);


  //teamB player 2
  glColor3f(1.0, 1.0, 0.0);
  drawPlayer(600,100);//player 2
  glColor3f(1.0, 0.0, 1.0); 
  bitmap_output(590,90, "2",GLUT_BITMAP_TIMES_ROMAN_24);


  //teamB player 3
  glColor3f(1.0, 1.0, 0.0);
  drawPlayer(600,700);//player 2
  glColor3f(1.0, 0.0, 1.0); 
  bitmap_output(590,690, "3",GLUT_BITMAP_TIMES_ROMAN_24);

  //Draw Ball
  glColor3f(0.0,0.0,0.0);
  drawBall(350,500);
  glColor3f(1.0,0.0,1.0);
  bitmap_output(340,490,"Ball",GLUT_BITMAP_TIMES_ROMAN_16);
  glFlush();
}


void myinit() 
{ 
  glViewport(0,0,width,height); 
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
  glPointSize(25.0);
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
