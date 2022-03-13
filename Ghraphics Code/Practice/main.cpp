#include<windows.h>
#include<GL/glut.h>

void display(){
    glClearColor(0,0,1,1);
    glClear(GL_COLOR_BUFFER_BIT);



	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red

	glVertex2f(0.0f, 0.0f);    // x, y
	glVertex2f(0.5f, 0.0f);    // x, y

	glVertex2f(0.5f, 0.5f);    // x, y
	glVertex2f(0.0f, 0.5f);    // x, y
	glEnd();

	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(0.4f, 0.2f);
	glVertex2f(0.6f, 0.2f);
	glVertex2f(0.7f, 0.4f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.3f, 0.4f);
	glEnd();

	glBegin(GL_TRIANGLES);//
    glColor3ub(232, 133, 20);//rgb color picker

    glVertex2f(+.5f, -.8f);    // x, y
	glVertex2f(+0.7f,-.8f);
	glVertex2f(+.6f, -0.4f);
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
