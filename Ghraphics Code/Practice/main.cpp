#include<windows.h>
#include<GL/glut.h>

void display(){
    glClearColor(0,0,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f(0,0);
    glEnd();


    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(0.1,0);
    glVertex2f(0.5,0);
    glEnd();


    glFlush();

}

int main (int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(300,300);
    glutCreateWindow("Practice Window");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}
