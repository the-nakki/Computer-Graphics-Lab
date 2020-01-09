// Date: 09 Jan, 2020
// Task: Draw a triangle, square and pentagon. Make them rotate

#include <GL/glut.h>


GLfloat angle = 0.0f;  // rotational angle of the shapes
int refreshMills = 30; // refresh interval in milliseconds

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
   glLoadIdentity();               // Reset the model-view matrix
}

void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer

   glPushMatrix();                     // Save model-view matrix setting
   glTranslatef(-0.7f, -0.5f, 0.0f);   // Translate
   glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
   glBegin(GL_QUADS);
      glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
      glVertex2f(-0.2f, -0.2f);
      glColor3f(1.0f, 1.0f, 1.0f); // White
      glVertex2f( 0.2f, -0.2f);
      glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
      glVertex2f( 0.2f,  0.2f);
      glColor3f(1.0f, 1.0f, 1.0f); // White
      glVertex2f(-0.2f,  0.2f);
   glEnd();
   glPopMatrix();                      // Restore the model-view matrix

   glPushMatrix();                     // Save model-view matrix setting
   glTranslatef(0.6f, -0.6f, 0.0f);    // Translate
   glRotatef(180.0f + angle, 0.0f, 0.0f, 1.0f); // Rotate 180+angle degree
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.3f, -0.2f);
      glColor3f(0.0f, 1.0f, 0.0f); // Green
      glVertex2f( 0.3f, -0.2f);
      glColor3f(0.0f, 0.0f, 1.0f); // Blue
      glVertex2f( 0.0f,  0.3f);
   glEnd();
   glPopMatrix();                      // Restore the model-view matrix

   glPushMatrix();                     // Save model-view matrix setting
   glTranslatef(0.5f, 0.4f, 0.0f);     // Translate
   glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
   glBegin(GL_POLYGON);
      glColor3f(1.0f, 1.0f, 0.0f); // Yellow
      glVertex2f(-0.1f, -0.2f);
      glVertex2f( 0.1f, -0.2f);
      glVertex2f( 0.2f,  0.0f);
      glVertex2f(-0.2f,  0.0f);
      glVertex2f( 0.0f,  0.15f);
      glVertex2f( 0.2f,  0.0f);
   glEnd();
   glPopMatrix();                      // Restore the model-view matrix

   glutSwapBuffers();   // Double buffered - swap the front and back buffers

   angle += 2.0f;
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE);  // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height - non-square
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Animation via Timer Function");  // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutTimerFunc(0, Timer, 0);     // First timer call immediately
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
