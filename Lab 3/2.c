// Date: 16 Jan, 2020
// Task: Implement Bresenham's Line Drawing Algorithm

#include <GL/glut.h>
#include <stdio.h>

int xa, ya, xb, yb;

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
	draw_line(xa, xb, ya, yb);
	glFlush();
}

void main(int argc, char **argv) {

	printf( "Enter coordinates of point 1\n");
	scanf("%d%d", &xa, &ya);
  printf( "Enter coordinates of point 2\n");
	scanf("%d%d", &xb, &yb);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Algorithm");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
