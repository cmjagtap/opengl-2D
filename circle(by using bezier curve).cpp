#include<GL/glut.h>
#include<math.h>

class Point
{
public:
  float x, y;
  void setxy(float x2, float y2)
  {
    x = x2; y = y2;
  }
  const Point & operator=(const Point &rPoint)
  {
    x = rPoint.x;
    y = rPoint.y;
    return *this;
  }
  
};

Point abc[8];

void myInit() {
  glClearColor(0.0,0.0,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glPointSize(10.0);
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
  glLineWidth(3);
  glBegin(GL_LINES);
  glVertex2f(p1.x, p1.y);
  glVertex2f(p2.x, p2.y);
  glEnd();
  glFlush();
}

// Calculate the next bezier point.
Point drawBezier(Point A, Point B, Point C, Point D,Point E,Point F,Point G,Point H,double t) {
  Point P;
  P.x = pow((1 - t), 7) * A.x + 7 * t * pow((1 -t), 6) * B.x + 21 *pow((1-t) ,5)*pow(t, 2)* C.x + 35 * pow((1-t), 4)*pow (t, 3)* D.x+35 * pow((1-t),3) * pow(t,4) * E.x+21 * pow((1-t) ,2) * pow(t,5) *F.x+ 7 * (1-t) * pow(t,6) * G.x + pow(t,7) * H.x;

  P.y = pow((1 - t), 7) * A.y + 7 * t * pow((1 -t), 6) * B.y + 21 *pow((1-t) ,5)* pow(t, 2)* C.y + 35 * pow((1-t) ,4)* pow (t, 3)* D.y+35*pow((1-t) ,3) * pow(t,4)*E.y + 21*pow((1-t),2)*pow(t,5)*F.y+7 *(1-t) * pow(t,6)*G.y + pow(t,7)*H.y;
  return P;
}

void myDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  Point POld=abc[0];
 
  abc[0].x=23,abc[0].y=30;
  abc[1].x=24,abc[1].y=38;
  abc[2].x=30,abc[2].y=40;
  abc[3].x=37,abc[3].y=37;
  abc[4].x=39,abc[4].y=29;
  abc[5].x=35,abc[5].y=24;
  abc[6].x=25,abc[6].y=22;
  abc[7].x=23,abc[7].y=30; 
  glColor3f(1.0,0.0,0.0);

  for(int i=0;i<8;i++)
    drawDot(abc[i].x, abc[i].y);
  glColor3f(1.0,1.0,1.0);
  
  for(double t = 0.0;t <= 1.0; t += 0.1) {
    Point P = drawBezier(abc[0], abc[1], abc[2], abc[3],abc[4],abc[5],abc[6],abc[7],t);
    drawLine(POld, P);
    POld = P;
  }

  glFlush();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(640,480);
  glutInitWindowPosition(100,150);
  glutCreateWindow("Bezier Curve circle");
  glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();
  return 0;
}
