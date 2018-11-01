#include <GL/glut.h>
#include<math.h>
#include<math.h>
int width = 600, height = 400;  

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
Point mno[4];
Point def[4];
void drawLine(int x1, int y1, int x2, int y2) 
{ 
  glLineWidth(3);
  glBegin(GL_LINES); 
  glVertex2i(x1, y1); 
  glVertex2i(x2, y2); 
  glEnd(); 
 } 

void printDot(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void drawCurve(Point p1, Point p2) {
  glLineWidth(5);
  glBegin(GL_LINES);
  glVertex2f(p1.x, p1.y);
  glVertex2f(p2.x, p2.y);
  glEnd();
}
// Calculate the next bezier point.
Point drawBezier(Point A, Point B, Point C, Point D, double t) {
  Point P;
  P.x = pow((1 - t), 3) * A.x + 3 * t * pow((1 -t), 2) * B.x + 3 * (1-t) * pow(t, 2)* C.x + pow (t, 3)* D.x;
  P.y = pow((1 - t), 3) * A.y + 3 * t * pow((1 -t), 2) * B.y + 3 * (1-t) * pow(t, 2)* C.y + pow (t, 3)* D.y;
  return P;
}

void display() 
{ 
  glClearColor(0.0, 0.0,0.0, 0.0); 
  glClear(GL_COLOR_BUFFER_BIT); 
  drawLine(100,150,100,300); //left side
  drawLine(200,150,200,300); //right right
  drawLine(100,120,200,120); //stand down side
  drawLine(100,150,200,150); //stand up side

  Point POld=abc[0];
  
  //left curve stand
  abc[0].x=100,abc[0].y=150;
  abc[1].x=80,abc[1].y=140;
  abc[2].x=80,abc[2].y=130;
  abc[3].x=100,abc[3].y=120;
   
  
  glColor3f(1.0,0.0,0.0);
 for(int i=0;i<4;i++)
    printDot(abc[i].x, abc[i].y);
  glColor3f(1.0,1.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(abc[0], abc[1], abc[2], abc[3],  t);
      drawCurve(POld, P);
      POld = P;
    }

  Point POd=xyz[0];
  
  //right curve stand
  xyz[0].x=200,xyz[0].y=150;
  xyz[1].x=220,xyz[1].y=140;
  xyz[2].x=220,xyz[2].y=130;
  xyz[3].x=200,xyz[3].y=120;
   
  
  glColor3f(1.0,0.0,0.0);
 for(int i=0;i<4;i++)
    printDot(xyz[i].x, xyz[i].y);
  glColor3f(1.0,1.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(xyz[0], xyz[1], xyz[2], xyz[3],  t);
      drawCurve(POd, P);
      POd = P;
    }


  Point PO=pqr[0];
  
  //down curve up part
  pqr[0].x=100,pqr[0].y=300;
  pqr[1].x=130,pqr[1].y=320;
  pqr[2].x=170,pqr[2].y=320;
  pqr[3].x=200,pqr[3].y=300;
   
  
  glColor3f(1.0,0.0,0.0);
 for(int i=0;i<4;i++)
    printDot(pqr[i].x, pqr[i].y);
  glColor3f(1.0,1.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(pqr[0], pqr[1], pqr[2], pqr[3],  t);
      drawCurve(PO, P);
      PO = P;
    }


  Point PX=mno[0];
  
  //Up curve up part
  mno[0].x=100,mno[0].y=300;
  mno[1].x=130,mno[1].y=270;
  mno[2].x=170,mno[2].y=270;
  mno[3].x=200,mno[3].y=300;
   
  
  glColor3f(1.0,0.0,0.0);
 for(int i=0;i<4;i++)
    printDot(mno[i].x, mno[i].y);
  glColor3f(1.0,1.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(mno[0], mno[1], mno[2], mno[3],  t);
      drawCurve(PX, P);
      PX = P;
    }

  Point PY=def[0];
  
  //Flame curve
  def[0].x=150,def[0].y=300;
  def[1].x=120,def[1].y=370;
  def[2].x=180,def[2].y=370;
  def[3].x=150,def[3].y=300;
   
  
  glColor3f(1.0,0.0,0.0);
 for(int i=0;i<4;i++)
    printDot(def[i].x, def[i].y);
  glColor3f(1.0,1.0,1.0);

  for(double t = 0.0;t <= 1.0; t += 0.1)
    {
      Point P = drawBezier(def[0], def[1], def[2], def[3],  t);
      drawCurve(PY, P);
      PY = P;
    }

  glFlush(); 
}


void myinit() 
{ 
  glViewport(0,0,width,height); 
  glColor3f(1.0,0.0,0.0);
  glPointSize(3.0);
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
  glutCreateWindow("Candel "); 
  glutDisplayFunc(display); 
  myinit(); 
  glutMainLoop(); 
  return 0; 
}
