#include <windows.h>
#include<GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

int xc, yc, r;

void plot(int x, int y)

{

	glBegin(GL_POINTS);

	glVertex2i(x+xc, y+yc);

	glVertex2i(xc+x, yc-y);

    glVertex2i(xc+y, yc+x);

    glVertex2i(xc+y, yc-x);

    glVertex2i(xc-x, yc-y);

    glVertex2i(xc-y, yc-x);

    glVertex2i(xc-x, yc+y);

    glVertex2i(xc-y, yc+x);

	glEnd();
}


void mid_Point_Circle()
{
	int x = 0;
	int y = r;
	float pk = 1 - r;

	plot(x, y);

	while (x < y)
	{
		if (pk < 0)
		{
			x++;
			y=y;
			pk = pk+2*x+1;
		}
		else
		{
			y--;
			x++;
			pk = pk+2*(x-y)+1;
		}

		plot(x, y);

	}

}

void Display(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 1.0);
	glPointSize(2.0);

	mid_Point_Circle();


	glFlush ();
}

int main(int argc, char** argv)
{
	cout << "Enter the coordinates of the center:\n\n" << endl;

	cout << "Enter Center: "; cin >> xc >>yc;

	cout << "\nEnter radius : "; cin >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Circle");
	glutDisplayFunc(Display);
	glutMainLoop();

}
