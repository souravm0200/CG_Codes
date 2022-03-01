
#include <windows.h>
#include <GL/glut.h>


void display() {
	glClearColor(0.50f, 0.0f, 0.50f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);



	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(175, 175);
	glutCreateWindow("Visual Studio Logo");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
