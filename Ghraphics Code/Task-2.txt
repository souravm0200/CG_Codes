#include<windows.h>
#include<GL/glut.h>

void display()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(3.0);

    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.9f,0.5f);
    glVertex2f(-0.7f,0.5);

    glVertex2f(-0.9f,0.5f);
    glVertex2f(-0.9f,0.3f);

    glVertex2f(-0.9f,0.3f);
    glVertex2f(-0.7f,0.3f);

    glVertex2f(-0.7f,0.3f);
    glVertex2f(-0.7f,0.1f);


    glVertex2f(-0.9f,0.1f);
    glVertex2f(-0.7f,0.1f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.6f,0.5f);
    glVertex2f(-0.4f,0.5f);

    glVertex2f(-0.6f,0.5f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.6f,0.1f);
    glVertex2f(-0.4f,0.1f);

    glVertex2f(-0.4f,0.1f);
    glVertex2f(-0.4f,0.5f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(-0.3f,0.5f);
    glVertex2f(-0.3f,0.1f);

    glVertex2f(-0.3f,0.1f);
    glVertex2f(-0.1f,0.1f);

    glVertex2f(-0.1,0.1f);
    glVertex2f(-0.1f,0.5f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);

    glVertex2f(0.0f,0.5f);
    glVertex2f(0.0f,0.1f);

    glVertex2f(0.0f,0.5f);
    glVertex2f(0.2f,0.5f);

    glVertex2f(0.2f,0.5f);
    glVertex2f(0.2f,0.25f);

    glVertex2f(0.2f,0.25f);
    glVertex2f(0.0f,0.25f);

    glVertex2f(0.0f,0.25f);
    glVertex2f(0.1f,0.1f);

    glEnd();




    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(300,300);
    glutCreateWindow("My Name");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

