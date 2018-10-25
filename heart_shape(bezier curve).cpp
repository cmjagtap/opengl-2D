#include<GL/glut.h>
#include<math.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

class Point
{
public:
  float x, y;
  void setxy(float x2, float y2)
  {
    x = x2;
    y = y2;
  }
  const Point & operator=(const Point &rPoint)
  {
    x = rPoint.x;
    y = rPoint.y;
    return *this;
  }
  
};

Point abc[4];
Point xyz[4];

void Init() {
  glClearColor(0.0,0.0,0.0,0.0);
  glColor3f(1.0,0.0,0.0);
  glPointSize(8.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,64.0,0.0,48.0);
}

void printDot(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

void drawLine(Point p1, Point p2) {
  glLineWidth(5);
  glBegin(GL_LINES);
  glVertex2f(p1.x, p1.y);
  glVertex2f(p2.x, p2.y);
  glEnd();
  glFlush();
}

// Calculate the next bezier point.
Point drawBezier(Point A, Point B, Point C, Point D, double t) {
  Point P;
  P.x = pow((1 - t), 3) * A.x + 3 * t * pow((1 -t), 2) * B.x + 3 * (1-t) * pow(t, 2)* C.x + pow (t, 3)* D.x;
  P.y = pow((1 - t), 3) * A.y + 3 * t * pow((1 -t), 2) * B.y + 3 * (1-t) * pow(t, 2)* C.y + pow (t, 3)* D.y;
  return P;
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
  for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
}

void myDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  Point POld=abc[0];
  
  //left side
  abc[0].x=30,abc[0].y=13;
  abc[1].x=23,abc[1].y=20;
  abc[2].x=28,abc[2].y=25;
  abc[3].x=30,abc[3].y=20;
   
  
  glColor3f(1.0,0.0,0.0);
 for(int i=0;i<4;i++)
    printDot(abc[i].x, abc[i].y);
  glColor3f(1.0,1.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(abc[0], abc[1], abc[2], abc[3],  t);
      drawLine(POld, P);
      POld = P;
    }

  Point POd=xyz[0];
  
  //right side
  xyz[0].x=30,xyz[0].y=20;
  xyz[1].x=33,xyz[1].y=25;
  xyz[2].x=36,xyz[2].y=20;
  xyz[3].x=30,xyz[3].y=13;
   
  
  glColor3f(1.0,0.0,0.0);
 for(int i=0;i<4;i++)
   printDot(xyz[i].x, xyz[i].y);
  glColor3f(1.0,1.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(xyz[0], xyz[1], xyz[2], xyz[3],  t);
      drawLine(POd, P);
      POd = P;
    }
    glColor3f(1.0,0.0,0.0);

    bitmap_output(29,18, "Heart",GLUT_BITMAP_TIMES_ROMAN_24);
  glFlush();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(640,480);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Bezier Curve");
  glutDisplayFunc(myDisplay);
  Init();
  glutMainLoop();
  return 0;
}
