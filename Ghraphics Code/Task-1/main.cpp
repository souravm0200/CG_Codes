#include<windows.h>
#include<GL/glut.h>

void display()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	 glVertex2f(-0.5f, 0.5f);
     glVertex2f(-0.5f, -0.7f);
     glVertex2f(0.5f, -0.7f);
     glVertex2f(0.5f, 0.5f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,1.0f,0.0f);

    glVertex2f(-0.5f,0.5f);
    glVertex2f(0.5f,0.5f);
    glVertex2f(0.0f,1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,1.0f);

    glVertex2f(-0.2f,0.2f);
    glVertex2f(-0.2f,-0.7f);
    glVertex2f(0.2f,-0.7f);
    glVertex2f(0.2f,0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);

    glVertex2f(0.3f,0.1f);
    glVertex2f(0.3f,-0.1f);
    glVertex2f(0.45f,-0.1f);
    glVertex2f(0.45f,0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);

    glVertex2f(-0.3f,0.1f);
    glVertex2f(-0.3f,-0.1f);
    glVertex2f(-0.45f,-0.1f);
    glVertex2f(-0.45f,0.1f);
    glEnd();








    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(300,300);
    glutCreateWindow("HOUSE");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
