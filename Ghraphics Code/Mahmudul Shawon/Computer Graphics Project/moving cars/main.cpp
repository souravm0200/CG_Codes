
#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<windows.h>
#include <bits/stdc++.h>

float CarX_R = 0;
float CarY_R = 0;



float CarX_L = 0;
float CarY_L = 0;
bool isRedlight = false;
bool isDay = true;

//void wheel(int x, int y, int outer, int inner);
void DrawCircle(float cx, float cy, float r, int num_segments)
{ glBegin(GL_TRIANGLE_FAN);
for (int i = 0; i < num_segments; i++)
{
float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); float x = r * cosf(theta);
float y = r * sinf(theta); glVertex2f(x + cx, y + cy);
}
glEnd();
}

void wheel(int x, int y, int outer, int inner)
{
glPushMatrix();



glColor3ub(0, 22, 51);
DrawCircle(x, y, outer, 2000);
glColor3ub(164, 199, 178);
DrawCircle(x, y, inner, 2000);
glPopMatrix();
}

void RoadFieldDay()
{
///Green Field
glColor3ub(86, 125, 70);
glBegin(GL_QUADS);
glVertex2i(0, 170);
glVertex2i(0, 122);
glVertex2i(1200, 122);
glVertex2i(1200, 170);
glEnd();
///end



///Road
glColor3ub(60, 60, 60);
glBegin(GL_QUADS);
glVertex2i(0, 0);
glVertex2i(1200, 0);
glVertex2i(1200, 122);
glVertex2i(0, 122);
glEnd();




glLineWidth(5); // road_strip
glLineStipple(30, 0xAAAA);
glEnable(GL_LINE_STIPPLE);
glColor3ub(255, 255, 255);
glBegin(GL_LINES);
glVertex2i(0, 58);
glVertex2i(1190, 58);
glEnd();






///end
}
void RoadFieldNight()
{
///Green Field
glColor3ub(9, 27, 32);
glBegin(GL_QUADS);
glVertex2i(0, 170);
glVertex2i(0, 122);
glVertex2i(1200, 122);
glVertex2i(1200, 170);
glEnd();
///end



///Road
glColor3ub(27, 66, 121);
glBegin(GL_QUADS);
glVertex2i(0, 0);
glVertex2i(1200, 0);
glVertex2i(1200, 122);
glVertex2i(0, 122);
glEnd();




glLineWidth(5); // road_strip
glLineStipple(10, 0xAAAA);
glEnable(GL_LINE_STIPPLE);
glColor3ub(6, 95, 138);
glBegin(GL_LINES);
glVertex2i(0, 58);
glVertex2i(1190, 58);
glEnd();




///end
}



struct cars
{
void dayCarsRight()
{
//car01
glColor3ub(199, 199, 193);
glBegin(GL_QUADS);
glVertex2i(104, 26);
glVertex2i(196, 26);
glVertex2i(196, 90);
glVertex2i(104, 90);
glEnd(); glColor3ub(180, 204, 201);
glBegin(GL_POLYGON);
glVertex2i(196, 26);
glVertex2i(226, 26);
glVertex2i(226, 50);
glVertex2i(210, 65);
glVertex2i(203, 80);
glVertex2i(196, 85);
glEnd(); glColor3ub(240, 109, 35);
glBegin(GL_QUADS);
glVertex2i(104, 32);
glVertex2i(196, 32);
glVertex2i(196, 90);
glVertex2i(104, 90);
glEnd(); //car 01 window
glColor3ub(253, 231, 215);
glBegin(GL_QUADS);
glVertex2i(196, 76);
glVertex2i(196, 61);
glVertex2i(218, 57);
glVertex2i(206, 72);
glEnd();
wheel(123, 31, 8, 5);
wheel(175, 31, 8, 5); //car03
glColor3ub(28, 138, 141);
glBegin(GL_POLYGON);
glVertex2i(735, 22);
glVertex2i(725, 22);
glVertex2i(718, 18);
glVertex2i(718, 14);
glVertex2i(718, 14);
glVertex2i(804, 14);
glVertex2i(804, 18);
glVertex2i(799, 22);
glVertex2i(790, 22);
glVertex2i(784, 46);
glVertex2i(741, 46);
glEnd(); glColor3ub(153, 200, 209); //car3 window 01
glBegin(GL_POLYGON);
glVertex2i(746, 41);
glVertex2i(741, 22);
glVertex2i(761, 22);
glVertex2i(761, 41);
glEnd(); glColor3ub(132, 172, 176); //car3 window 01 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(746, 41);
glVertex2i(741, 22);
glVertex2i(761, 41);
glEnd(); glColor3ub(153, 200, 209); //car2 window 02
glBegin(GL_POLYGON);
glVertex2i(765, 41);
glVertex2i(765, 22);
glVertex2i(784, 22);
glVertex2i(779, 41);
glEnd(); glColor3ub(132, 172, 176); //car3 window 02 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(765, 41);
glVertex2i(765, 22);
glVertex2i(779, 41);
glEnd();
wheel(740, 14, 4, 2);
wheel(788, 14, 4, 2); //car04
glColor3ub(238, 84, 59);
glBegin(GL_POLYGON);
glVertex2i(895, 22);
glVertex2i(885, 22);
glVertex2i(878, 18);
glVertex2i(878, 14);
glVertex2i(878, 14);
glVertex2i(964, 14);
glVertex2i(964, 18);
glVertex2i(959, 22);
glVertex2i(950, 22);
glVertex2i(944, 46);
glVertex2i(901, 46);
glEnd(); glColor3ub(219, 238, 243); //car4 window 01
glBegin(GL_POLYGON);
glVertex2i(906, 41);
glVertex2i(901, 22);
glVertex2i(921, 22);
glVertex2i(921, 41);
glEnd(); glColor3ub(182, 190, 184); //car4 window 01 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(906, 41);
glVertex2i(901, 22);
glVertex2i(921, 41);
glEnd(); glColor3ub(219, 238, 243); //car4 window 02
glBegin(GL_POLYGON);
glVertex2i(925, 41);
glVertex2i(925, 22);
glVertex2i(944, 22);
glVertex2i(939, 41);
glEnd(); glColor3ub(182, 190, 184); //car4 window 02 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(925, 41);
glVertex2i(925, 22);
glVertex2i(939, 41);
glEnd();
wheel(895, 16, 4, 2);
wheel(950, 16, 4, 2);
}
void dayCarLeft()
{
//car02
glColor3ub(215, 236, 240);
glBegin(GL_POLYGON);
glVertex2i(535, 82);
glVertex2i(525, 82);
glVertex2i(518, 78);
glVertex2i(518, 74);
glVertex2i(518, 74);
glVertex2i(604, 74);
glVertex2i(604, 78);
glVertex2i(599, 82);
glVertex2i(590, 82);
glVertex2i(584, 106);
glVertex2i(541, 106);
glEnd(); glColor3ub(44, 136, 133); //car2 window 01
glBegin(GL_POLYGON);
glVertex2i(546, 101);
glVertex2i(541, 84);
glVertex2i(561, 84);
glVertex2i(561, 101);
glEnd(); glColor3ub(23, 125, 117); //car2 window 01 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(546, 101);
glVertex2i(561, 84);
glVertex2i(561, 101);
glEnd(); glColor3ub(44, 136, 133); //car2 window 02
glBegin(GL_POLYGON);
glVertex2i(565, 101);
glVertex2i(565, 84);
glVertex2i(585, 84);
glVertex2i(580, 101);
glEnd(); glColor3ub(23, 125, 117); //car2 window 02 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(565, 101);
glVertex2i(585, 84);
glVertex2i(580, 101);
glEnd();
wheel(540, 74, 4, 2);
wheel(578, 74, 4, 2);
}
void nightCarsRight()
{
//car01 glColor3ub(108, 100, 110); //head light
glBegin(GL_TRIANGLES);
glVertex2i(300, 40);
glVertex2i(300, 15);
glColor3ub(204, 169, 48);
glVertex2i(200, 40);
glEnd(); glColor3ub(121, 182, 231);
glBegin(GL_QUADS);
glVertex2i(104, 26);
glVertex2i(196, 26);
glVertex2i(196, 90);
glVertex2i(104, 90);
glEnd(); glColor3ub(121, 182, 231);
glBegin(GL_POLYGON);
glVertex2i(196, 26);
glVertex2i(226, 26);
glVertex2i(226, 50);
glVertex2i(210, 65);
glVertex2i(203, 80);
glVertex2i(196, 85);
glEnd(); glColor3ub(0, 137, 191);
glBegin(GL_QUADS);
glVertex2i(104, 32);
glVertex2i(196, 32);
glVertex2i(196, 90);
glVertex2i(104, 90);
glEnd(); //car 01 window
glColor3ub(253, 231, 215);
glBegin(GL_QUADS);
glVertex2i(196, 76);
glVertex2i(196, 61);
glVertex2i(218, 57);
glVertex2i(206, 72);
glEnd(); wheel(123, 31, 8, 5);
wheel(175, 31, 8, 5); //car03
glColor3ub(108, 100, 110); //head light
glBegin(GL_TRIANGLES);
glVertex2i(860, 25);
glVertex2i(860, 10);
glColor3ub(204, 169, 48);
glVertex2i(785, 20);
glEnd(); glColor3ub(6, 177, 213);
glBegin(GL_POLYGON);
glVertex2i(735, 22);
glVertex2i(725, 22);
glVertex2i(718, 18);
glVertex2i(718, 14);
glVertex2i(718, 14);
glVertex2i(804, 14);
glVertex2i(804, 18);
glVertex2i(799, 22);
glVertex2i(790, 22);
glVertex2i(784, 46);
glVertex2i(741, 46);
glEnd(); glColor3ub(0, 109, 157); //car3 window 01
glBegin(GL_POLYGON);
glVertex2i(746, 41);
glVertex2i(741, 22);
glVertex2i(761, 22);
glVertex2i(761, 41);
glEnd(); glColor3ub(9, 36, 43); //car3 window 01 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(746, 41);
glVertex2i(741, 22);
glVertex2i(761, 41);
glEnd(); glColor3ub(0, 109, 157); //car3 window 02
glBegin(GL_POLYGON);
glVertex2i(765, 41);
glVertex2i(765, 22);
glVertex2i(784, 22);
glVertex2i(779, 41);
glEnd(); glColor3ub(9, 36, 43); //car3 window 02 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(765, 41);
glVertex2i(765, 22);
glVertex2i(779, 41);
glEnd();
wheel(740, 14, 4, 2);
wheel(788, 14, 4, 2); //car04
glColor3ub(108, 100, 110); //head light
glBegin(GL_TRIANGLES);
glVertex2i(1020, 25);
glVertex2i(1020, 10);
glColor3ub(204, 169, 48);
glVertex2i(950, 20);
glEnd(); glColor3ub(79, 183, 223);
glBegin(GL_POLYGON);
glVertex2i(895, 22);
glVertex2i(885, 22);
glVertex2i(878, 18);
glVertex2i(878, 14);
glVertex2i(878, 14);
glVertex2i(964, 14);
glVertex2i(964, 18);
glVertex2i(959, 22);
glVertex2i(950, 22);
glVertex2i(944, 46);
glVertex2i(901, 46);
glEnd(); glColor3ub(68, 112, 131); //car4 window 01
glBegin(GL_POLYGON);
glVertex2i(906, 41);
glVertex2i(901, 22);
glVertex2i(921, 22);
glVertex2i(921, 41);
glEnd(); glColor3ub(7, 18, 14); //car4 window 01 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(906, 41);
glVertex2i(901, 22);
glVertex2i(921, 41);
glEnd(); glColor3ub(68, 112, 131); //car4 window 02
glBegin(GL_POLYGON);
glVertex2i(925, 41);
glVertex2i(925, 22);
glVertex2i(944, 22);
glVertex2i(939, 41);
glEnd(); glColor3ub(7, 18, 14); //car4 window 02 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(925, 41);
glVertex2i(925, 22);
glVertex2i(939, 41);
glEnd();
wheel(895, 16, 4, 2);
wheel(950, 16, 4, 2);
}
void nightCarsLeft()
{
//car02
glColor3ub(108, 100, 110); //head light
glBegin(GL_TRIANGLES);
glVertex2i(472, 85);
glVertex2i(472, 70);
glColor3ub(204, 169, 48);
glVertex2i(540, 79);
glEnd(); glColor3ub(4, 139, 182);
glBegin(GL_POLYGON);
glVertex2i(535, 82);
glVertex2i(525, 82);
glVertex2i(518, 78);
glVertex2i(518, 74);
glVertex2i(518, 74);
glVertex2i(604, 74);
glVertex2i(604, 78);
glVertex2i(599, 82);
glVertex2i(590, 82);
glVertex2i(584, 106);
glVertex2i(541, 106);
glEnd();
glColor3ub(6, 99, 157); //car2 window 01
glBegin(GL_POLYGON);
glVertex2i(546, 101);
glVertex2i(541, 84);
glVertex2i(561, 84);
glVertex2i(561, 101);
glEnd();
glColor3ub(0, 30, 45); //car2 window 01 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(546, 101);
glVertex2i(561, 84);
glVertex2i(561, 101);
glEnd();
glColor3ub(6, 99, 157); //car2 window 02
glBegin(GL_POLYGON);
glVertex2i(565, 101);
glVertex2i(565, 84);
glVertex2i(585, 84);
glVertex2i(580, 101);
glEnd();
glColor3ub(0, 30, 45); //car2 window 02 Glitch
glBegin(GL_TRIANGLES);
glVertex2i(565, 101);
glVertex2i(585, 84);
glVertex2i(580, 101);
glEnd();
wheel(540, 74, 4, 2);
wheel(578, 74, 4, 2);
}
};



void moveCarRight(){
cars c;
if (isRedlight)
{
CarX_R += 0;
}
else
{
CarX_R += .9;
} if (CarX_R > 1200)
{
CarX_R = -800;
}

glPushMatrix();
glTranslatef(CarX_R, CarY_R, 0);
if (isDay)
{
c.dayCarsRight();
}
else
{
c.nightCarsRight();
} glPopMatrix();
}

void moveCarLeft(){
cars c;
if (isRedlight)
{
CarX_L += 0;
}
else
{
CarX_L -= .9;
} if (CarX_L < -650)
{
CarX_L = 650;
} glPushMatrix();
glTranslatef(CarX_L, CarY_L, 0);
if (isDay)
{
c.dayCarLeft();
}
else
{
c.nightCarsLeft();
} glPopMatrix();
}
void vehicle()
{
moveCarLeft();
moveCarRight();
}



void Display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
RoadFieldDay();
//RoadFieldNight();

vehicle();

glFlush();
glutPostRedisplay();
glutSwapBuffers();
}



void myInit(void)
{
glClearColor(255, 255, 255, 0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1200.0, 0.0, 600.0);
}



int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1200, 600);
glutInitWindowPosition(100, 150);
glutCreateWindow("A HIGHWAY VIEW");
glutDisplayFunc(Display);







myInit();
glutMainLoop();
}
