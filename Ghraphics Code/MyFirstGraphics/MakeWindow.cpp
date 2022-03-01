#include<windows.h>
#include<GL/glut.h>

void display()
{
    glClearColor(0,0,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(30);
    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f(0,0);


    glEnd();

    glLineWidth(7.5);
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(0.5,0.5);
    glVertex2f(0.2,-0.2);

    glVertex2f(0.2,-0.2);
    glVertex2f(0.8,-0.2);

    glVertex2f(0.5,0.5);
    glVertex2f(0.8,-0.2);
    glEnd();





    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(300,300);
    glutCreateWindow("First Graphics");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
