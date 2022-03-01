#include<windows.h>
#include<GL/glut.h>
#include <bits/stdc++.h>


using namespace std;

int xa,xb,ya,yb;

void display (void)
{

    int dx=xb-xa;
    int dy=yb-ya;
    int pk0= (2*dy)-dx;
    float x=xa,y=ya;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 1.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    int pk =pk0;
    int k;
    int n;
    if(dx == dy)
    {
      n=dx;
    }
    else
    {
        n= dx > dy? dx : dy;


    }

    for(k=0;k<n;k++)
    {
        if(pk>0)

        {
            x = x+1;
            y=y+1;
            pk=pk+(2*dy)-(2*dx);
            glVertex2i(x,y);
        }

        else if(pk<=0)
        {
            x = x+1;
            y=y;
            pk=pk+(2*dy);
            glVertex2i(x,y);


        }


    }

    glEnd();
    glFlush();

}

void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}



int main(int argc, char** argv)
{
    cout<<("Enter the points\n(X1,Y1,X2,Y2):-\n");
    cin>>xa>>ya>>xb>>yb;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Bresenham Line Algorithm ");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}

