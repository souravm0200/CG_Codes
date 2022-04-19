#include<windows.h>
#include<GL/glut.h>



static GLfloat spin = 0.0;
static GLfloat spin_speed = 0.2;
float spin_x = 1;
float spin_y = 1;
float spin_z = 1;



float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;



// assuming work-window width=50unit, height=25unit;
void init()
{
    //glClearColor(0,0,0,0);
    //glShadeModel(GL_SMOOTH);// Enable Smooth Shading
   // glClearDepth(1.0f);// Depth Buffer Setup
    //glEnable(GL_DEPTH_TEST);// Enables Depth Testing
    glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
void drawFan()
{
     glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

     glLineWidth(2);
     glBegin(GL_LINES);

     glColor3f(1.0f,1.0f,1.0f);

     glVertex2f(0.0f,0.0f);
     glVertex2f(0.6f,0.0f);

     glVertex2f(0.0f,0.0f);
     glVertex2f(0.1f,-0.15f);

     glVertex2f(0.6f,0.0f);
     glVertex2f(0.5f,-0.15f);

     glVertex2f(0.1f,-0.15f);
     glVertex2f(-0.04f,-0.15f);
     glVertex2f(0.5f,-0.15f);
     glVertex2f(0.64f,-0.15f);

     glVertex2f(-0.04f,-0.15f);
     glVertex2f(0.02f,-0.25f);
     glVertex2f(0.64f,-0.15f);
     glVertex2f(0.59f,-0.26f);

     glVertex2f(0.02f,-0.25f);
     glVertex2f(0.07f,-0.25f);
     glVertex2f(0.59f,-0.26f);
     glVertex2f(0.53f,-0.26f);

     glVertex2f(0.07f,-0.25f);
     glVertex2f(0.13f,-0.40f);
     glVertex2f(0.53f,-0.26f);
     glVertex2f(0.48f,-0.41f);

     glVertex2f(0.13f,-0.40f);
     glVertex2f(0.06f,-0.40f);
     glVertex2f(0.48f,-0.41f);
     glVertex2f(0.55f,-0.41f);

     glVertex2f(0.06f,-0.40f);
     glVertex2f(0.09f,-0.54f);
     glVertex2f(0.55f,-0.41f);
     glVertex2f(0.52f,-0.55f);

     glVertex2f(0.09f,-0.54f);
     glVertex2f(0.13f,-0.54f);
     glVertex2f(0.52f,-0.55f);
     glVertex2f(0.49f,-0.55f);

     glVertex2f(0.13f,-0.54f);
     glVertex2f(0.3f,-0.84f);
     glVertex2f(0.49f,-0.55f);
     glVertex2f(0.3f,-0.84f);

     glEnd();



    glFlush();
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(translate_x, translate_y, translate_z);
    glRotatef(spin,spin_x,spin_y,spin_z);
    //******************************************//
    //------- custom code starts -------


     drawFan();

    //drawFanStand();
    //------- custom code ends   -------
    //******************************************//
    glutSwapBuffers();
}
//------- custom functions starts -------



void setSpin(float x, float y, float z)
{
    spin_x = x;
    spin_y = y;
    spin_z = z;
}



void reset()
{
    spin_x = 0;
    spin_y = 1;
    spin_z = 0;
    translate_x = 0.0;
    translate_y = 0.0;
    translate_z = -30.0;
}
//------- custom functions ends   -------


void reshape(int w,int h)
{
    glViewport(0,0, (GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}




void spinDisplay(void)
{
    spin=spin+spin_speed;
    if(spin>360.0)
    {
        spin=spin-360.0;
    }
    glutPostRedisplay();
}



void spinDisplayReverse(void)
{
    spin=spin-spin_speed;
    if(spin<360.0)
    {
        spin=spin+360.0;
    }
    glutPostRedisplay();
}



void mouse(int button,int state,int x,int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(spinDisplay);
            break;



        case GLUT_MIDDLE_BUTTON:
            if(state==GLUT_DOWN)
            {
                glutIdleFunc(NULL);
            }
            break;



        case GLUT_RIGHT_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(spinDisplayReverse);
            break;



        default:
            break;



    }
}



void keyboard(unsigned char key, int x, int y)
{
//-------- spin --------
    if(key=='x')
    {
        setSpin(1.0,0.0,0.0);
        glutPostRedisplay();
    }
    else if(key=='y')
    {
        setSpin(0.0,1.0,0.0);
        glutPostRedisplay();
    }
    else if(key=='z')
    {
        setSpin(0.0,0.0,1.0);
        glutPostRedisplay();
    }
    else if(key=='a')
    {
        setSpin(1.0,1.0,1.0);
        glutPostRedisplay();
    }
    //-------- spin --------
    //-------- zoom --------
    else if(key=='i')
    {
        translate_z++;
        glutPostRedisplay();
    }
    else if(key=='o')
    {
        translate_z--;
        glutPostRedisplay();
    }
    //-------- zoom --------
    //-------- reset -------
    else if(key=='r')
    {
        reset();
        glutPostRedisplay();
    }
}
//-------- reset -------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Keyboard and Mouse Interaction");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
}
