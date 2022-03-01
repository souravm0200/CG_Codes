#include<windows.h>
#include<GL/glut.h>

void display()
{
    glClearColor(0,0,1,1);
    glClear(GL_COLOR_BUFFER_BIT);


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
