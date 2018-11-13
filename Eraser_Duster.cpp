#include <GL/glut.h>
GLfloat xRotated,yRotated,zRotated;
void DrawDuster(void)
{

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(0.0,0.0,-10.5);

  glRotatef(xRotated,1.0,0.0,0.0);
  glRotatef(yRotated,0.0,1.0,0.0);
  glRotatef(zRotated,0.0,0.0,1.0);
  
  glBegin(GL_QUADS);
  
    glColor3f(1.0f,0.0f,0.0f);    // Color Red Back side 
    glVertex3f( 4.0f, 1.0f, 1.0f);    
    glVertex3f(-1.5f, 1.0f, 1.0f);    
    glVertex3f(-1.5f,-1.0f, 1.0f);    
    glVertex3f( 4.0f,-1.0f, 1.0f);
    
    glColor3f(1.0f,0.5f,1.0f);    // Color orange up side
    glVertex3f( 4.0f, 1.0f,-1.0f);    
    glVertex3f(-1.0f, 1.0f,-1.0f);    
    glVertex3f(-1.5f, 1.0f, 1.0f);    
    glVertex3f( 4.0f, 1.0f, 1.0f);    
   
    glColor3f(1.0f,0.5f,1.0f);    // Color Orange down side
    glVertex3f( 4.0f,-1.0f, 1.0f);
    glVertex3f(-1.5f,-1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);    
    glVertex3f( 4.0f,-1.0f,-1.0f);       
   
    glColor3f(0.0f,0.0f,1.0f);   // Color Blue Front
    glVertex3f( 4.0f,-1.0f,-1.0f);    
    glVertex3f(-1.0f,-1.0f,-1.0f);    
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f( 4.0f, 1.0f,-1.0f);    
   
    glColor3f(1.0f,0.5f,0.0f);    // Color violet Left side
    glVertex3f(-1.5f, 1.0f, 1.0f);     
    glVertex3f(-1.0f, 1.0f,-1.0f);     
    glVertex3f(-1.0f,-1.0f,-1.0f);     
    glVertex3f(-1.5f,-1.0f, 1.0f);     
   
    glColor3f(1.0f,0.5f,0.0f);    // Color Violet Right side
    glVertex3f( 4.0f, 1.0f,-1.0f);     
    glVertex3f( 4.0f, 1.0f, 1.0f);     
    glVertex3f( 4.0f,-1.0f, 1.0f);     
    glVertex3f( 4.0f,-1.0f,-1.0f);    
    
  glEnd();         
  glFlush();
}

void rotate(void)
{
  //yRotated +=0.05;
  //xRotated +=0.01;
  zRotated +=0.01;
  DrawDuster();
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) 
	return;

    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();     
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  
}

int main(int argc, char** argv){

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(700,900); 
glutCreateWindow("Duster "); 
glutDisplayFunc(DrawDuster);
glutReshapeFunc(reshape);
glutIdleFunc(rotate);
glutMainLoop();
return 0;
}
