
#include <windows.h>
#include <GL/glut.h>


void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(0.0f,1.0f,0.0f);

	glVertex2f(-1.0f,1.0f);
	glVertex2f(-0.3f,1.0f);
	glVertex2f(-0.3f,-1.0f);
	glVertex2f(-1.0f,-1.0);
	glEnd();


	glBegin(GL_QUADS);

	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(-0.7f,0.3f);
	glVertex2f(-0.6f,0.3f);
	glVertex2f(-0.6f,-0.3f);
	glVertex2f(-0.7f,-0.3f);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(-0.62f,0.3f);
	glVertex2f(-0.62f,0.4f);

	glVertex2f(-0.64f,0.3f);
	glVertex2f(-0.64f,0.4f);

	glVertex2f(-0.66f,0.3f);
	glVertex2f(-0.66f,0.4f);

	glVertex2f(-0.62f,-0.3f);
	glVertex2f(-0.62f,-0.4f);

	glVertex2f(-0.64f,-0.3f);
	glVertex2f(-0.64f,-0.4f);

	glVertex2f(-0.66f,-0.3f);
	glVertex2f(-0.66f,-0.4f);

	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.0f,0.0f,0.0f);

	glVertex2f(-0.3f,0.28f);
	glVertex2f(1.0f,0.28f);
	glVertex2f(1.0f,0.02f);
	glVertex2f(-0.3f,0.02f);

	glEnd();


	glBegin(GL_QUADS);

	glColor3f(0.0f,0.0f,0.0f);

	glVertex2f(-0.3f,-0.28f);
	glVertex2f(1.0f,-0.28f);
	glVertex2f(1.0f,-0.02f);
	glVertex2f(-0.3f,-0.02f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f,0.9f,1.0f);
	glVertex2f(-0.3f,1.0f);
	glVertex2f(1.0f,1.0f);
	glVertex2f(1.0f,0.28f);
	glVertex2f(-0.3f,0.28f);
	glEnd();

    glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex2f(-0.3f,0.31f);
	glVertex2f(1.0f,0.31f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.0f,0.0f,0.6f);
	glVertex2f(-0.3f,-1.0f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(1.0f,-0.28f);
	glVertex2f(-0.3f,-0.28f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(-0.3f,-0.28f);
	glVertex2f(0.0f,-0.5f);
	glVertex2f(0.2f,-0.28f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(0.2f,-0.28f);
	glVertex2f(0.4f,-0.5f);
	glVertex2f(0.6f,-0.28f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(0.6f,-0.28f);
	glVertex2f(0.9f,-0.5f);
	glVertex2f(1.0f,-0.28f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6f,0.0f,0.0f);
	glVertex2f(0.0f,0.95f);
	glVertex2f(0.3f,0.95f);
	glVertex2f(0.3f,0.28f);
	glVertex2f(0.0f,0.28f);
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.05f,0.9f);
    glVertex2f(0.1f,0.9f);
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.05f,0.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.05f,0.7f);
    glVertex2f(0.1f,0.7f);
    glVertex2f(0.1f,0.6f);
    glVertex2f(0.05f,0.6f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.05f,0.5f);
    glVertex2f(0.1f,0.5f);
    glVertex2f(0.1f,0.4f);
    glVertex2f(0.05f,0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.2f,0.9f);
    glVertex2f(0.25f,0.9f);
    glVertex2f(0.25f,0.8f);
    glVertex2f(0.2f,0.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.2f,0.7f);
    glVertex2f(0.25f,0.7f);
    glVertex2f(0.25f,0.6f);
    glVertex2f(0.2f,0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.2f,0.5f);
    glVertex2f(0.25f,0.5f);
    glVertex2f(0.25f,0.4f);
    glVertex2f(0.2f,0.4f);
    glEnd();






	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 400);
	glutCreateWindow("Scenario");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
