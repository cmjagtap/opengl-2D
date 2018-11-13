//compile it as gcc Human_fet_3D.c -lglut -lGL -lGLU -lm -std=c99
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>
 
float points_part1[250][3];
float points_part2[250][3];
float points_part3[250][3];
float points_part4[250][3];
float points_part5[250][3];
float points_part6[250][3];

float curve_point1[250][250][3];
float curve_point2[250][250][3];
float curve_point3[250][250][3];

float rotate_y=0,rotate_x=0,rotate_z=0;

float cal_val_4_point(float p1,float p2,float p3,float p4,float t)
{
  return( p1*pow((1-t),3) + p2*3*pow((1-t),2)*t + p3*3*pow(t,2)*(1-t) + p4*pow(t,3));
}

float cal_val_3_point(float p1,float p2,float p3,float t)
{
  return(p1*pow((1-t),2) + p2*2*(1-t)*t + p3*pow(t,2));
}

void find_points_4(float a[3],float b[3],float c[3],float d[3],float point[250][3]){
  float t = 0.0, step = 0.004;
  int i;
  for(i=0;i<=250;i++){
    if(t>1)
      break;
    point[i][0] = cal_val_4_point(a[0],b[0],c[0],d[0],t);
    point[i][1] = cal_val_4_point(a[1],b[1],c[1],d[1],t);
    point[i][2] = cal_val_4_point(a[2],b[2],c[2],d[2],t);
    t += step;
  }
}

void plot_curve(float points_arr[250][250][3]){
  for(int j=0;j<=250;j++){
    glBegin(GL_POINTS);
    for(int i=0;i<=250;i++){
      glVertex3f(points_arr[j][i][0],points_arr[j][i][1],points_arr[j][i][2]);
    }
glEnd();
}
}

void display(){

  glClearColor(1.0,1.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  
  glMatrixMode(GL_PROJECTION);
  gluPerspective(30.0, 1.0, 1.0, 10.0);
  gluLookAt( 0.0, 0.0, 5.0,  0.0, 0.0, 0.0,  0.0,1.0, 0.0);

  glTranslatef(0.0, 0.0, 1.0);
  glRotatef(25, 1.0, 0.0, 0.0);
  glRotatef(70, 0.0, 0.0, 1.0);
 
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 1.0 );
  
  float p11[3]={0.0,0.1,-0.1},p12[3]={0.15,0.68,0.0},p13[3]={0.30,0.46,0.0},p14[3]={0.55,0.44,0.1};
  float p21[3]={0.0,0.55,0.03},p22[3]={0.17,0.55,0.05},p23[3]={0.35,0.55,0.05},p24[3]={0.55,0.55,0.04};
  float p31[3]={0.0,0.60,0.0},p32[3]={0.17,0.62,0.0},p33[3]={0.35,0.63,0.0},p34[3]={0.55,0.63,0.0};  
  float p41[3]={0.0,0.62,-0.02},p42[3]={0.17,0.64,-0.05},p43[3]={0.35,0.65,-0.05},p44[3]={0.55,0.64,-0.04};  
  float p51[3]={0.0,0.55,-0.03},p52[3]={0.17,0.55,-0.04},p53[3]={0.35,0.55,-0.04},p54[3]={0.55,0.55,-0.05};
  float p61[3]={0.2,0.4,-0.03},p62[3]={0.17,0.48,-0.04},p63[3]={0.35,0.46,-0.04},p64[3]={0.55,0.44,-0.05};

  glColor3f(0.8,0.7,0.3);

  find_points_4(p11,p12,p13,p14,points_part1);
  find_points_4(p21,p22,p23,p24,points_part2);
  find_points_4(p31,p32,p33,p34,points_part3);
  find_points_4(p41,p42,p43,p44,points_part4);
  find_points_4(p51,p52,p53,p54,points_part5);
  find_points_4(p61,p62,p63,p64,points_part6);

  for(int i=0;i<=250;i++)
  {
   float t = 0.0 ,step = 0.004;
   for(int j=0;j<250;j++)
   {
     for(int k=0;k<4;k++)
     {
       curve_point1[i][j][k]=cal_val_3_point(points_part1[i][k],points_part2[i][k],points_part3[i][k],t);
       curve_point2[i][j][k]=cal_val_3_point(points_part3[i][k],points_part4[i][k],points_part5[i][k],t);
       curve_point3[i][j][k]=cal_val_3_point(points_part5[i][k],points_part6[i][k],points_part1[i][k],t);
     }
     t+=step;
   }
  }

  plot_curve(curve_point1);
   plot_curve(curve_point2);
   plot_curve(curve_point3);

  glFlush();
  glutSwapBuffers();
 
}
 
void specialKeys( int key, int x, int y ) {
 
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 4;
 
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 4;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 4;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 4;
 
  glutPostRedisplay();
 
}
 
int main(int argc, char* argv[]){
 
  glutInit(&argc,argv);
 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition (100, 100);
  glutInitWindowSize (1000, 1000);
  glutCreateWindow("Feet");
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  glutMainLoop();
 
  return 0;
 
}
