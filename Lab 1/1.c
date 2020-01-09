// Date: 02 Jan, 2020
// Task: Draw a house with mountains and Sun



#include <stdio.h>
#include <GL/glut.h>
#include<math.h>
#define pi 3.142857

void myInit (void){
     glClearColor(0.0,0.0,0.0,0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, 500.0, 0.0, 400.0);
}

void myDisplay(void){
  glClear(GL_COLOR_BUFFER_BIT);
//Sun
  glColor3f(7.0f,7.0f, 0.0f);
  glBegin(GL_POINTS);
  float x, y, i;
  for ( i = 0; i < (2 * pi); i += 0.001)
  {
      x = 20 * cos(i);
      y = 20 * sin(i);
      glVertex2i(x+170, y+350);
  }
  glEnd();

//Mountains
  //M1
  glColor3f(5.0f,4.0f, 6.0f);
  glBegin(GL_POLYGON);
  //bottom
  glVertex2i(0, 200);
  glVertex2i(100, 200);
  //Left
  glVertex2i(0, 200);
  glVertex2i(50, 300);
  //Right
  glVertex2i(50, 300);
  glVertex2i(100, 200);

  glEnd();
  //M2
  glColor3f(5.0f,4.0f, 6.0f);
  glBegin(GL_POLYGON);
  //bottom
  glVertex2i(100, 200);
  glVertex2i(200, 200);
  //Left
  glVertex2i(200, 200);
  glVertex2i(150, 300);
  //Right
  glVertex2i(150, 300);
  glVertex2i(200, 200);

  glEnd();
  //M3
  glColor3f(5.0f,4.0f, 6.0f);
  glBegin(GL_POLYGON);
  //bottom
  glVertex2i(200, 200);
  glVertex2i(300, 200);
  //Left
  glVertex2i(200, 200);
  glVertex2i(250, 300);
  //Right
  glVertex2i(250, 300);
  glVertex2i(300, 200);

  glEnd();
  //M4
  glColor3f(5.0f,4.0f, 6.0f);
  glBegin(GL_POLYGON);
  //bottom
  glVertex2i(300, 200);
  glVertex2i(400, 200);
  //Left
  glVertex2i(300, 200);
  glVertex2i(350, 300);
  //Right
  glVertex2i(350, 300);
  glVertex2i(400, 200);

  glEnd();
  //M5
  glColor3f(5.0f,4.0f, 6.0f);
  glBegin(GL_POLYGON);
  //bottom
  glVertex2i(400, 200);
  glVertex2i(500, 200);
  //Left
  glVertex2i(400, 200);
  glVertex2i(450, 300);
  //Right
  glVertex2i(450, 300);
  glVertex2i(500, 200);

  glEnd();

  //House Body
    glColor3f(0.5f,0.5f,0.5f);
    glPointSize(4.0);
    glRectf(120,100,310,270);

  //Left Window
   glColor3f(1.0f,0.0f,0.0f) ;
   glPointSize(4.0);
   glRectf(130,200,180,250);

  //Right Window
    glColor3f(1.0f,0.0f,0.0f) ;
    glPointSize(4.0);
    glRectf(250,200,300,250);

  //Door
    glColor3f(0.0f,0.0f,1.0f) ;
    glPointSize(4.0);
    glRectf(200,100,230,180);

  //Steps
    glColor3f(0.0f,1.0f,1.0f) ;
    glPointSize(4.0);
    glRectf(175,80,255,100);
    glRectf(185,60,245,78);
    glRectf(195,40,235,58);

  //Roof
    glColor3f(1.0f,0.0f,1.0f) ;
    glBegin(GL_POLYGON);
    //bottom
    glVertex2i(120, 270);
    glVertex2i(310, 270);
    //Left
    glVertex2i(120, 270);
    glVertex2i(215, 320);
    //Right
    glVertex2i(215, 320);
    glVertex2i(310, 270);
    glEnd();


  glFlush();

}
int main (int argc, char **argv)
{

     glutInit (&argc, argv);
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize (640, 480);
     glutInitWindowPosition (10, 10);
     glutCreateWindow ("Lab 1 - 02 Jan 2020");
     glutDisplayFunc (myDisplay);
     myInit();
     glutMainLoop();
     return 0;
}
