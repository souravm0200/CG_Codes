#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<bits/stdc++.h>

GLfloat RocketPosition= 0.0f;
GLfloat CloudPosition1 = 0.0f;
GLfloat CloudPosition2 = 0.0f;
GLfloat SunPosition = 0.0f;


GLfloat CloudSpeed1 = 15.0;
GLfloat CloudSpeed2 = 12.0;
GLfloat RocketSpeed = 20.0f;
GLfloat SunSpeed = 9.0f;

void update(int value)
{

    if(CloudPosition1 >1000.0)
    {
        CloudPosition1 =-1000.0f;
    }

    else if(CloudPosition2 >1000.0)
    {
        CloudPosition2 =-1000.0f;
    }

    else if(RocketPosition>1000.0)
    {
        RocketPosition=-1000.0f;
    }

    else if(SunPosition>1000.0)
    {
        SunPosition =-1000.0f;
    }

    RocketPosition += RocketSpeed;
    CloudPosition1 += CloudSpeed1;
    CloudPosition2 +=CloudSpeed2;
    SunPosition += SunSpeed;

glutPostRedisplay();
glutTimerFunc(100, update, 0);
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); //get the current angle

        float x = r * cosf(theta); //calculate the x component
        float y = r * sinf(theta); //calculate the y component

        glVertex2f(x + cx, y + cy); //output vertex
    }
    glEnd();
}

void Cloud()
{

        glPushMatrix();
        glTranslatef(CloudPosition1,0.0f, 0.0f);
        glColor3ub(225, 225, 225);
        DrawCircle(246, 386, 23, 2000);
        DrawCircle(290, 409, 40, 2000);
        DrawCircle(350, 394, 36, 2000);
        glColor3ub(225, 225, 225);
        glBegin(GL_QUADS);
        glVertex2i(246, 380);
        glVertex2i(246, 363);
        glVertex2i(350, 359);
        glVertex2i(350, 380);
        glEnd();
        glPopMatrix();



        glPushMatrix();
        glTranslatef(CloudPosition2,0.0f, 0.0f);
        glColor3ub(225, 225, 225);
        DrawCircle(450, 486, 23, 2000);
        DrawCircle(490, 509, 40, 2000);
        DrawCircle(550, 494, 36, 2000);
        glColor3ub(225, 225, 225);
        glBegin(GL_QUADS);
        glVertex2i(450, 480);
        glVertex2i(450, 463);
        glVertex2i(550, 459);
        glVertex2i(550, 480);
        glEnd();
        glPopMatrix();

        glFlush();


}

void Sun()
{
    glPushMatrix();
    glTranslatef(0.0f,-SunPosition, 0.0f);
    glColor3ub(253, 184, 19);
    DrawCircle(700,500,60,2000);
    glPopMatrix();


    glFlush();
}

void Rocket()
{
glPushMatrix();
glTranslatef(-RocketPosition,RocketPosition,0);
    glColor3ub(255,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(420,400);
    glVertex2i(450,250);
    glVertex2i(550,350);
    glEnd();

    glColor3ub(100,0,0);
    glBegin(GL_QUADS);
    glVertex2i(450,250);
    glVertex2i(550,350);
    glVertex2i(650,190);
    glVertex2i(550,100);
    glEnd();

    glColor3ub(255,255,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(570,120);
    glVertex2i(620,110);
    glVertex2i(560,70);
    glEnd();

    glColor3ub(255,255,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(630,175);
    glVertex2i(630,120);
    glVertex2i(680,150);
    glEnd();
    glPopMatrix();

    glFlush();

}

void handleMouse(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON)
{
    	RocketSpeed += 10.0f;
}
if (button == GLUT_RIGHT_BUTTON)
    {
    RocketSpeed -= 10.0f;
    }
glutPostRedisplay();
}



void handleKeypress(unsigned char key, int x, int y)
{
switch (key) {
case 's':
    SunSpeed = 0.0f;
    break;
case 'c':
    CloudSpeed1 = 0.0f;
    break;
case 'C':
    CloudSpeed2 += 5.0f;
    break;
case 'w':
    RocketSpeed = 20.0f;
    CloudSpeed1 = 15.0f;
    CloudSpeed2 = 12.0f;
    SunSpeed = 9.0f;
    break;
glutPostRedisplay();
}
}




void display()
{

    glClearColor(0.0f, 1.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 600.0);


    Cloud();
    Sun();
    Rocket();

}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1200, 600);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Translation Rocket");
   glutDisplayFunc(display);
   glutTimerFunc(100, update, 0);
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutMainLoop();
   return 0;
}
