#include<windows.h>
#include<GL/glut.h>

void display()
{
    glClearColor(0,0,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(7.5);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.80f, 0.80f);
	glVertex2f(-0.8f, -0.80f);
	glVertex2f(-0.8f, -0.80f);
	glVertex2f(0.80f, -0.80f);
	glVertex2f(0.80f, -0.80f);
	glVertex2f(0.80f, 0.80f);
	glVertex2f(0.80f, 0.80f);
	glVertex2f(-0.80f, 0.80f);

	glEnd();


    glFlush();
}

int main (int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(300,300);
    glutCreateWindow("First Graphics");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
