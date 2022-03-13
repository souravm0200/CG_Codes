#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>




void display(){
    glClearColor(1.0f, 1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.0f,0.0f);

    glVertex2f(0.6f,0.6f);
    glVertex2f(-0.6f,0.6f);
    glVertex2f(-0.6f,-0.8f);
    glVertex2f(0.6f,-0.8f);
    glEnd();


    glLineWidth(7.5);

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(-0.59f, -0.3f);
	glVertex2f(0.59f, -0.3f);

	glVertex2f(0.0f,0.6f);
	glVertex2f(0.0f,-0.3f);

	glVertex2f(-0.6f,0.15f);
	glVertex2f(0.6f,0.15f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,69,0);

	glVertex2f(-0.3f,-0.8f);
	glVertex2f(-0.3f,-0.9f);

	glVertex2f(0.3f,-0.9f);
	glVertex2f(0.3f,-0.8f);
	glEnd();


    glLineWidth(6);
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);

	glVertex2f(0.3f,0.5f);
	glVertex2f(0.4f,0.4f);

	glVertex2f(0.3f,0.3f);
	glVertex2f(0.2f,0.4f);



	glVertex2f(0.3f,0.5f);
	glVertex2f(0.2f,0.4f);

	glVertex2f(0.4f,0.4f);
	glVertex2f(0.3f,0.3f);
	glEnd();

    glLineWidth(6);
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);

	glVertex2f(-0.3f,0.5f);
	glVertex2f(-0.4f,0.4f);

	glVertex2f(-0.3f,0.3f);
	glVertex2f(-0.2f,0.4f);



	glVertex2f(-0.3f,0.5f);
	glVertex2f(-0.2f,0.4f);

	glVertex2f(-0.4f,0.4f);
	glVertex2f(-0.3f,0.3f);
	glEnd();

    glLineWidth(6);
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);

	glVertex2f(0.3f,0.0f);
	glVertex2f(0.4f,-0.1f);

	glVertex2f(0.3f,0.0f);
	glVertex2f(0.2f,-0.1f);



	glVertex2f(0.4f,-0.1f);
	glVertex2f(0.3f,-0.2f);

	glVertex2f(0.3f,-0.2f);
	glVertex2f(0.2f,-0.1f);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);

	glVertex2f(-0.3f,0.0f);
	glVertex2f(-0.4f,-0.1f);

	glVertex2f(-0.3f,0.0f);
	glVertex2f(-0.2f,-0.1f);



	glVertex2f(-0.4f,-0.1f);
	glVertex2f(-0.3f,-0.2f);

	glVertex2f(-0.3f,-0.2f);
	glVertex2f(-0.2f,-0.1f);
	glEnd();



	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);

	glVertex2f(0.5f,-0.5f);
	glVertex2f(0.4f,-0.6f);

	glVertex2f(0.4f,-0.6f);
	glVertex2f(0.3f,-0.5f);



	glVertex2f(0.3f,-0.5f);
	glVertex2f(0.4f,-0.4f);

	glVertex2f(0.4f,-0.4f);
	glVertex2f(0.5f,-0.5f);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);

	glVertex2f(-0.5f,-0.5f);
	glVertex2f(-0.4f,-0.6f);

	glVertex2f(-0.4f,-0.6f);
	glVertex2f(-0.3f,-0.5f);



	glVertex2f(-0.3f,-0.5f);
	glVertex2f(-0.4f,-0.4f);

	glVertex2f(-0.4f,-0.4f);
	glVertex2f(-0.5f,-0.5f);
	glEnd();


	glLineWidth(7);
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);

	glVertex2f(-0.15f,-0.4f);
	glVertex2f(0.15f,-0.4f);

	glVertex2f(-0.15f,-0.75f);
	glVertex2f(0.15f,-0.75f);



	glVertex2f(-0.15f,-0.4f);
	glVertex2f(-0.15f,-0.75f);

	glVertex2f(0.15f,-0.4f);
	glVertex2f(0.15f,-0.75f);
	glEnd();


	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.0f,0.9f,0.0f);

	glVertex2f(-0.3f,0.6f);
	glVertex2f(-0.3f,0.7f);
	glVertex2f(0.3f,0.6f);
	glVertex2f(0.3f,0.7f);

    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.6f, 0.0f);

	glVertex2f(-0.5f, 0.67f);
	glVertex2f(-0.3f, 0.8f);
	glVertex2f(-0.1f,  0.67f);

	glEnd();



	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.6f, 0.0f);

	glVertex2f(-0.45f, 0.75f);
	glVertex2f(-0.3f, 0.85f);
	glVertex2f(-0.15f,  0.75f);

	glEnd();





	 glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.6f, 0.0f);

	glVertex2f(0.5f, 0.67f);
	glVertex2f(0.3f, 0.8f);
	glVertex2f(0.1f,  0.67f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.6f, 0.0f);

	glVertex2f(0.45f, 0.75f);
	glVertex2f(0.3f, 0.85f);
	glVertex2f(0.15f,  0.75f);

	glEnd();




    glFlush();

}



int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(500,600);
   glutInitWindowPosition(200,200);
   glutCreateWindow("House");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
