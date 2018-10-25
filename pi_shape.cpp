#include<GL/glut.h>
#include<math.h>
class Point
{
public:
  float x, y;
  void setxy(float x2, float y2)
  {
    x = x2;
    y = y2;
  }
  const Point & operator=(const Point &rPoint) {
    x = rPoint.x;
    y = rPoint.y;
    return *this;
  }
  
};
Point abc[4];
Point xyz[4];
Point pqr[4];

void myInit() {
  glClearColor(0.0,0.0,0.0,0.0);
  glColor3f(1.0,0.0,0.0);
  glPointSize(8.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,64.0,0.0,48.0);
}

void drawDot(int x, int y) {
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
void myDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  Point POld=abc[0];
  
  //left side
  abc[0].x=5,abc[0].y=8;
  abc[1].x=8,abc[1].y=15;
  abc[2].x=10,abc[2].y=20;
  abc[3].x=12,abc[3].y=30;
  
  glColor3f(1.0,0.0,0.0);
 for(int i=0;i<4;i++)
    drawDot(abc[i].x, abc[i].y);
  glColor3f(1.0,1.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(abc[0], abc[1], abc[2], abc[3],  t);
      drawLine(POld, P);
      POld = P;
    }

  Point POd=xyz[0];
  
  //horizontal line
  xyz[0].x=10,xyz[0].y=30;
  xyz[1].x=15,xyz[1].y=30;
  xyz[2].x=20,xyz[2].y=30;
  xyz[3].x=27,xyz[3].y=30;
   
  
  glColor3f(1.0,1.0,1.0);
 for(int i=0;i<4;i++)
    drawDot(xyz[i].x, xyz[i].y);
  glColor3f(1.0,0.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(xyz[0], xyz[1], xyz[2], xyz[3],  t);
      drawLine(POd, P);
      POd = P;
    }

  
  Point PO=pqr[0];
  
  //right side line
  pqr[0].x=25,pqr[0].y=30;
  pqr[1].x=25,pqr[1].y=20;
  pqr[2].x=27,pqr[2].y=15;
  pqr[3].x=32,pqr[3].y=8;
   
  
  glColor3f(1.0,0.0,0.0);
 for(int i=0;i<4;i++)
    drawDot(pqr[i].x, pqr[i].y);
  glColor3f(1.0,1.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(pqr[0], pqr[1], pqr[2], pqr[3],  t);
      drawLine(PO, P);
      PO = P;
    }
    glFlush();
}
int main(int argc,char *argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(640,480);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Pi Using Bezier curve");
  
  glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();
  return 0;
}
