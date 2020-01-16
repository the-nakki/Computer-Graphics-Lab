// Date: 16 Jan, 2020
// Task: Implement DDA Line Drawing Algorithm

#include <GL/glut.h>
#include <stdio.h>

float xa, ya, xb, yb;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(float xa, float xb, float ya, float yb) {
	float dy, dx, step, i;
	float incx, incy;
	float x, y;

	dx = abs(xb - xa);
	dy = abs(yb - ya);

  step = dx > dy ? dx : dy;

  incx = dx / step;
  incy = dy / step;

  x = xa; y = ya;
  draw_pixel(x, y);

  for (i = 0; i < step; i++)
  {
    x += incx;
    y += incy;
    draw_pixel(x, y);
  }
}

void myDisplay() {
	draw_line(xa, xb, ya, yb);
	glFlush();
}

void main(int argc, char **argv) {

	printf( "Enter coordinates of point 1\n");
	scanf("%f%f", &xa, &ya);
  printf( "Enter coordinates of point 2\n");
	scanf("%f%f", &xb, &yb);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DDA Algorithm");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
