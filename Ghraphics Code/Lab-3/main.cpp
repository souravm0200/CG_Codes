#include <windows.h>  // for MS Windows

#include <GL/glut.h>  // GLUT, include glu.h and gl.h



void display() {

// Set background color to black and opaque

glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)



// Draw a Red 1x1 Square centered at origin


    int bw = 0;
    for (float i = 1.0f; i>= -0.75f; i-= 0.25f)
    {
       for (float j = -1.0f; j<= 0.75f; j+= 0.25f)
       {
           glBegin(GL_POLYGON);
           if (bw%2==0)
                glColor3f(0.0f, 0.0f, 0.0f);
           else
                glColor3f(1.0f, 1.0f, 1.0f);
           glVertex2f(j, i);   //-0.75,1
           glVertex2f(j, i-0.25f); //-0.75, 0.75   //
           glVertex2f(j+0.25f, i-0.25f);  //-0.50,0.75
           glVertex2f(j+0.25f, i);//-0.50,1
           glEnd();
           bw++;
       }
        bw--;
    }

glFlush();  // Render now

}



/* Main function: GLUT runs as a console application starting at main()  */

int main(int argc, char** argv) {

glutInit(&argc, argv);                 // Initialize GLUT

glutCreateWindow("OpenGL Setup"); // Create a window with the given title

glutInitWindowSize(320, 320);   // Set the window's initial width & height

glutDisplayFunc(display); // Register display callback handler for window re-paint

glutMainLoop();           // Enter the event-processing loop

return 0;

}

