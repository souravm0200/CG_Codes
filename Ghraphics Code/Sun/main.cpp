#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>




void Circle(GLfloat x, GLfloat y, GLfloat r){

    int i;
    int triangleAmount = 30;

    GLfloat twoPi = 2.0f * 3.1416;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,1,0);

        glVertex2f(x, y);

        for(i = 0; i <= triangleAmount;i++)
         {
            glVertex2f(
                    x + (r * cos(i *  twoPi / triangleAmount)),
                  y + (r * sin(i * twoPi / triangleAmount))
            );
        }

    glEnd();
}
void Cloud(GLfloat x, GLfloat y, GLfloat r){

    int i;
    int triangleAmount = 30;

    GLfloat twoPi = 2.0f * 3.1416;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,1,1);

        glVertex2f(x, y);

        for(i = 0; i <= triangleAmount;i++)
         {
            glVertex2f(
                    x + (r * cos(i *  twoPi / triangleAmount)),
                  y + (r * sin(i * twoPi / triangleAmount))
            );
        }

    glEnd();
}

void display(){
    glClearColor(0.5f, 1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_TRIANGLES);
    glColor3f(0.0,1.0,0.0);

    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,1.0);

    glVertex2f(1.0f,0.0f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(1.0f,-1.0f);

    glEnd();


    Circle(0.6,0.6,0.3);


    Cloud(-0.4,0.7,0.15);
    Cloud(-0.2,0.7,0.2);
    Cloud(0.0,0.7,0.15);


    glFlush();

}



int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("SUN");
   glutInitWindowSize(1000,1000);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
