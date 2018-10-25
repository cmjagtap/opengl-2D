#include <GL/glut.h>
#include<math.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
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

void printButton(int x, int y) {
  glPointSize(7);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
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

void stroke_output(GLfloat x, GLfloat y, char *format,...)
{
  va_list args;
  char buffer[200], *p;

  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(0.005, 0.005, 0.005);
  for (p = buffer; *p; p++)  glColor3f(1.0, 1.0, 1.0); 

    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
}
void display() 
{ 
  glClearColor(0.0, 0.0,0.0, 0.0); 
  glColor3f(1.0, 1.0, 1.0); 
  glClear(GL_COLOR_BUFFER_BIT);
  //Monitor
  drawLine(150,600,330,600);//up
  drawLine(150,500,330,500);//down
  drawLine(150,500,150,600);//left
  drawLine(330,500,330,600);//right
  drawLine(240,500,180,460);// stand left
  drawLine(240,500,290,460);// stand right
  drawLine(180,460,290,460);//stand down

  glColor3f(1.0,0.0,0.0);
  printButton(270, 500); //onscreen
  printButton(290, 500); //onscreen
  printButton(310, 500); //onscreen

  glColor3f(1.0, 1.0, 1.0); 

  //CPU
  drawLine(420,600,420,400);//left
  drawLine(500,600,500,400);//right
  drawLine(420,600,500,600);//up
  drawLine(420,400,500,400);//left/
  drawLine(420,500,500,500);//left/
  drawLine(420,525,500,525);//left/

  //Keyboard
  drawLine(180,400,300,400);//up
  drawLine(160,350,320,350);//down
  drawLine(300,400,320,350);//right
  drawLine(180,400,160,350);//left
  printButton(200, 385);
  printButton(220, 385);
  printButton(240, 385);
  printButton(260, 385);
  printButton(280, 385);
  printButton(180, 368);
  printButton(200, 368);
  printButton(220, 368);
  printButton(240, 368);
  printButton(260, 368);
  printButton(280, 368);
  printButton(300, 368);

  //button cpu
    glColor3f(1.0,0.0,0.0);
    printButton(457, 513);
  
  glColor3f(1.0,0.0,0.0);
  bitmap_output(200,550, "PUCSD",GLUT_BITMAP_TIMES_ROMAN_24);
  bitmap_output(430,540, "CPU",GLUT_BITMAP_TIMES_ROMAN_24);

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
