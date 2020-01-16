// Date: 16 Jan, 2020
// Task: Draw a pattern consisting of a square, suurounded by a diamond, suurounded by a square using Bresenham's algorithm



#include <GL/glut.h>
#include <stdio.h>

int xa, ya, xb, yb;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 600, 0, 600);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int xa, int xb, int ya, int yb) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x, y;

	dx = abs(xb - xa);
	dy = abs(yb - ya);

  incx = 1;
	if (xb < xa) incx = -1;

  incy = 1;
	if (yb < ya) incy = -1;

  x = xa; y = ya;
  draw_pixel(x, y);
  if (dx > dy)
  {

		e = 2*dy - dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++)
    {
			if (e >= 0)
      {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	}
  else
  {
		e = 2*dx - dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++)
    {
			if (e >= 0)
      {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}

void myDisplay() {
  //outer square
	draw_line(100, 100, 100, 500);
  draw_line(100, 500, 500, 500);
  draw_line(500, 500, 500, 100);
  draw_line(500, 100, 100, 100);
  //diamond
  draw_line(100, 300, 300, 500);
  draw_line(300, 500, 500, 300);
  draw_line(500, 300, 300, 100);
  draw_line(300, 100, 100, 300);
  //inner square
  draw_line(200, 200, 200, 400);
  draw_line(200, 400, 400, 400);
  draw_line(400, 400, 400, 200);
  draw_line(400, 200, 200, 200);

	glFlush();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Algorithm Pattern");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
