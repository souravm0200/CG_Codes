#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
float CloudX = 0;
float CloudY = 0;

float CarX_R = 0;
float CarY_R = 0;

float CarX_L = 0;
float CarY_L = 0;

float sunX = 0;
float sunY = 0;

float moonX = 0;
float moonY = 0;
float rain = 0.0;
bool isDay = true;

bool makeItNight = false;
bool makeItDay = false;
bool sunSitThere = false;
bool moonSitThere = false;
bool rainday = false;
bool isRedlight = false;
void wheel(int x, int y, int outer, int inner);
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
void text(int x, int y, char *string)
{
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
    }
}
void Rain(int value)
{

    if (rainday)
    {

        rain += 0.01f;

        glBegin(GL_POINTS);
        for (int i = 1; i <= 10000; i++)
        {
            int x = rand(), y = rand();
            x %= 2000;
            y %= 2000;
            glBegin(GL_LINES);
            glColor3f(0.0, 1.0, 1.0);
            glVertex2d(x, y);
            glVertex2d(x + 5, y + 5);
            glEnd();
        }
    }
}
void Daysky()
{
    ///---------------------Ajran-----------------------///
    ///sky block
    glColor3ub(219, 223, 226);
    glBegin(GL_QUADS);
    glVertex2i(0, 600);
    glVertex2i(0, 145);
    glVertex2i(1200, 145);
    glVertex2i(1200, 600);
    glEnd();
}
void EveningSky()
{
    ///sky block
    glColor3ub(255, 137, 54);
    glBegin(GL_QUADS);
    glVertex2i(0, 145);
    glVertex2i(1200, 145);
    glColor3ub(219, 223, 226);
    glVertex2i(1200, 600);
    glVertex2i(0, 600);
    glEnd();
}
void Nightsky()
{

    ///sky block
    glColor3ub(0, 127, 179);
    glBegin(GL_QUADS);
    glVertex2i(0, 600);
    glVertex2i(0, 145);
    glVertex2i(1200, 145);
    glVertex2i(1200, 600);
    glEnd();
}
void sun()
{
    glPushMatrix();
    glTranslated(0, -300, 0);
    glColor3f(3.0, 1.0, 0.5);
    DrawCircle(805, 546, 50, 2000);
    glPopMatrix();
}
void moon()
{
    glPushMatrix();
    glTranslated(0, -200, 0);
    glColor3ub(251, 163, 31);
    DrawCircle(972, 402, 30, 2000);
    glColor3ub(0, 127, 179);
    DrawCircle(960, 405, 30, 2000);
    glPopMatrix();
}
void coverTheSun()
{
    glColor3ub(219, 223, 226);
    glBegin(GL_QUADS);
    glVertex2i(730, 590);
    glVertex2i(730, 130);
    glVertex2i(860, 130);
    glVertex2i(860, 590);
    glEnd();
}
void coverThemoon()
{
    glColor3ub(0, 127, 179);
    glBegin(GL_QUADS);
    glVertex2i(710, 530);
    glVertex2i(710, 130);
    glVertex2i(1010, 130);
    glVertex2i(1010, 530);
    glEnd();
}
struct cloud
{
    void drawDayCloud()
    {
        glColor3f(1.0, 1.0, 1.0);
        DrawCircle(246, 486, 23, 2000); //1
        DrawCircle(290, 509, 40, 2000); //2
        DrawCircle(350, 494, 36, 2000); //3
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex2i(246, 480);
        glVertex2i(246, 463);
        glVertex2i(350, 459);
        glVertex2i(350, 480);
        glEnd();
    }
    void drawNightCloud()
    {
        glColor3ub(36, 138, 197);
        DrawCircle(246, 486, 23, 2000); //1
        DrawCircle(290, 509, 40, 2000); //2
        DrawCircle(350, 494, 36, 2000); //3
        glColor3ub(36, 138, 197);
        glBegin(GL_QUADS);
        glVertex2i(246, 480);
        glVertex2i(246, 463);
        glVertex2i(350, 459);
        glVertex2i(350, 480);
        glEnd();
    }
};



struct LampPost
{
    void drawdayLampPost()
    {
        glColor3ub(103,154,169);
        glBegin(GL_TRIANGLES);
        glVertex2i(204,120);
        glVertex2i(215,120);
        glVertex2i(210,135);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_QUADS);
        glVertex2i(208,129);
        glVertex2i(212,129);
        glVertex2i(212,200);
        glVertex2i(208,200);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_TRIANGLES);
        glVertex2i(210,195);
        glVertex2i(215,205);
        glVertex2i(205,205);
        glEnd();

        glColor3ub(241,237,216);
        glBegin(GL_QUADS);
        glVertex2i(204,204);
        glVertex2i(215,204);
        glVertex2i(215,213);
        glVertex2i(204,213);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_QUADS);
        glVertex2i(208,214);
        glVertex2i(212,214);
        glVertex2i(212,222);
        glVertex2i(208,222);
        glEnd();

        glColor3ub(49,46,55);
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(204,215);
        glVertex2i(215,215);
        glVertex2i(204,120);
        glVertex2i(215,120);
        glVertex2i(208,204);
        glVertex2i(212,204);
        glEnd();
    }
    void drawnightLampPost()
    {
        glColor3ub(103,154,169);
        glBegin(GL_TRIANGLES);
        glVertex2i(204,120);
        glVertex2i(215,120);
        glVertex2i(210,135);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_QUADS);
        glVertex2i(208,129);
        glVertex2i(212,129);
        glVertex2i(212,200);
        glVertex2i(208,200);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_TRIANGLES);
        glVertex2i(210,195);
        glVertex2i(215,205);
        glVertex2i(205,205);
        glEnd();

        glColor3ub(255,207,88);
        glBegin(GL_QUADS);
        glVertex2i(204,204);
        glVertex2i(215,204);
        glVertex2i(215,213);
        glVertex2i(204,213);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_QUADS);
        glVertex2i(208,214);
        glVertex2i(212,214);
        glVertex2i(212,222);
        glVertex2i(208,222);
        glEnd();

        glColor3ub(49,46,55);
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(204,215);
        glVertex2i(215,215);
        glVertex2i(204,120);
        glVertex2i(215,120);
        glVertex2i(208,204);
        glVertex2i(212,204);
        glEnd();
    }

};

void dayLampPost()
{
    LampPost lp;

    glPushMatrix();
    glTranslated(20, 5, 0);
    lp.drawdayLampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslated(340,5, 0);
    lp.drawdayLampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslated(700, 5, 0);
    lp.drawdayLampPost();
    glPopMatrix();
}

void nightLampPost()
{
    LampPost lp;

    glPushMatrix();
    glTranslated(20, 5, 0);
    lp.drawnightLampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslated(340,5, 0);
    lp.drawnightLampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslated(700, 5, 0);
    lp.drawnightLampPost();
    glPopMatrix();
}

struct star
{
    void drawstars()
    {
        glColor3ub(251, 163, 31);
        glBegin(GL_TRIANGLE_FAN);

        glVertex2i(535, 608);
        glVertex2i(502, 597);
        glVertex2i(532, 592);

        glVertex2i(541, 560);
        glVertex2i(552, 590);

        glVertex2i(593, 599);
        glVertex2i(553, 607);

        glVertex2i(544, 647);
        glVertex2i(532, 592);

        glEnd();
    }
};
void stars()
{
    star s;
    //stars 1
    glPushMatrix();
    glScalef(0.3, 0.3, 0.0);
    glTranslated(2000, 1000, 0);
    s.drawstars();
    glPopMatrix();
    //stars 2
    glPushMatrix();
    glScalef(0.3, 0.3, 0.0);
    glTranslated(2200, 800, 0);
    s.drawstars();
    glPopMatrix();
    //stars 3
    glPushMatrix();
    glScalef(0.1, 0.1, 0.0);
    glTranslated(8000, 4200, 0);
    s.drawstars();
    glPopMatrix();
    //stars 4
    glPushMatrix();
    glScalef(0.1, 0.1, 0.0);
    glTranslated(9000, 4000, 0);
    s.drawstars();
    glPopMatrix();
    //stars 5
    glPushMatrix();
    glScalef(0.1, 0.1, 0.0);
    glTranslated(8700, 3850, 0);
    s.drawstars();
    glPopMatrix();
    //stars 6
    glPushMatrix();
    glScalef(0.1, 0.1, 0.0);
    glTranslated(8900, 3600, 0);
    s.drawstars();
    glPopMatrix();
    //point stars
    glPushMatrix();
    glBegin(GL_POINTS);
    glColor3ub(251, 163, 31);
    glVertex2i(947, 465);
    glVertex2i(901, 441);
    glVertex2i(912, 421);
    glEnd();
    glPopMatrix();
}
void DayCloud()
{
    cloud c;
    //cloud 1
    glPushMatrix();
    glTranslated(300, -50, 0);
    c.drawDayCloud();
    glPopMatrix();
    //cloud 2
    glPushMatrix();
    glTranslated(-150, 0, 0);
    c.drawDayCloud();
    glPopMatrix();
    //cloud 3
    glPushMatrix();
    glTranslated(200, 50, 0);
    c.drawDayCloud();
    glPopMatrix();
    //cloud 4
    glPushMatrix();
    glTranslated(600, -100, 0);
    c.drawDayCloud();
    glPopMatrix();
}

void NightCloud()
{
    cloud c;
    //cloud 1
    glPushMatrix();
    glTranslated(300, -50, 0);
    c.drawNightCloud();
    glPopMatrix();
    //cloud 2
    glPushMatrix();
    glTranslated(-150, 0, 0);
    c.drawNightCloud();
    glPopMatrix();
    //cloud 3
    glPushMatrix();
    glTranslated(200, 50, 0);
    c.drawNightCloud();
    glPopMatrix();
    //cloud 4
    glPushMatrix();
    glTranslated(600, -100, 0);
    c.drawNightCloud();
    glPopMatrix();
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
        glEnd();

        glColor3ub(180, 204, 201);
        glBegin(GL_POLYGON);
        glVertex2i(196, 26);
        glVertex2i(226, 26);
        glVertex2i(226, 50);
        glVertex2i(210, 65);
        glVertex2i(203, 80);
        glVertex2i(196, 85);
        glEnd();

        glColor3ub(240, 109, 35);
        glBegin(GL_QUADS);
        glVertex2i(104, 32);
        glVertex2i(196, 32);
        glVertex2i(196, 90);
        glVertex2i(104, 90);
        glEnd();

        //car 01 window
        glColor3ub(253, 231, 215);
        glBegin(GL_QUADS);
        glVertex2i(196, 76);
        glVertex2i(196, 61);
        glVertex2i(218, 57);
        glVertex2i(206, 72);
        glEnd();

        text(125, 53, "AMAZON");

        wheel(123, 31, 8, 5);
        wheel(175, 31, 8, 5);

        //car03
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
        glEnd();

        glColor3ub(153, 200, 209); //car3 window 01
        glBegin(GL_POLYGON);
        glVertex2i(746, 41);
        glVertex2i(741, 22);
        glVertex2i(761, 22);
        glVertex2i(761, 41);
        glEnd();

        glColor3ub(132, 172, 176); //car3 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(746, 41);
        glVertex2i(741, 22);
        glVertex2i(761, 41);
        glEnd();

        glColor3ub(153, 200, 209); //car2 window 02
        glBegin(GL_POLYGON);
        glVertex2i(765, 41);
        glVertex2i(765, 22);
        glVertex2i(784, 22);
        glVertex2i(779, 41);
        glEnd();

        glColor3ub(132, 172, 176); //car3 window 02 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(765, 41);
        glVertex2i(765, 22);
        glVertex2i(779, 41);
        glEnd();
        wheel(740, 14, 4, 2);
        wheel(788, 14, 4, 2);

        //car04
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
        glEnd();

        glColor3ub(219, 238, 243); //car4 window 01
        glBegin(GL_POLYGON);
        glVertex2i(906, 41);
        glVertex2i(901, 22);
        glVertex2i(921, 22);
        glVertex2i(921, 41);
        glEnd();

        glColor3ub(182, 190, 184); //car4 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(906, 41);
        glVertex2i(901, 22);
        glVertex2i(921, 41);
        glEnd();

        glColor3ub(219, 238, 243); //car4 window 02
        glBegin(GL_POLYGON);
        glVertex2i(925, 41);
        glVertex2i(925, 22);
        glVertex2i(944, 22);
        glVertex2i(939, 41);
        glEnd();

        glColor3ub(182, 190, 184); //car4 window 02 Glitch
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
        glEnd();

        glColor3ub(44, 136, 133); //car2 window 01
        glBegin(GL_POLYGON);
        glVertex2i(546, 101);
        glVertex2i(541, 84);
        glVertex2i(561, 84);
        glVertex2i(561, 101);
        glEnd();

        glColor3ub(23, 125, 117); //car2 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(546, 101);
        glVertex2i(561, 84);
        glVertex2i(561, 101);
        glEnd();

        glColor3ub(44, 136, 133); //car2 window 02
        glBegin(GL_POLYGON);
        glVertex2i(565, 101);
        glVertex2i(565, 84);
        glVertex2i(585, 84);
        glVertex2i(580, 101);
        glEnd();

        glColor3ub(23, 125, 117); //car2 window 02 Glitch
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
        //car01

        glColor3ub(108, 100, 110); //head light
        glBegin(GL_TRIANGLES);
        glVertex2i(300, 40);
        glVertex2i(300, 15);
        glColor3ub(204, 169, 48);
        glVertex2i(200, 40);
        glEnd();

        glColor3ub(121, 182, 231);
        glBegin(GL_QUADS);
        glVertex2i(104, 26);
        glVertex2i(196, 26);
        glVertex2i(196, 90);
        glVertex2i(104, 90);
        glEnd();

        glColor3ub(121, 182, 231);
        glBegin(GL_POLYGON);
        glVertex2i(196, 26);
        glVertex2i(226, 26);
        glVertex2i(226, 50);
        glVertex2i(210, 65);
        glVertex2i(203, 80);
        glVertex2i(196, 85);
        glEnd();

        glColor3ub(0, 137, 191);
        glBegin(GL_QUADS);
        glVertex2i(104, 32);
        glVertex2i(196, 32);
        glVertex2i(196, 90);
        glVertex2i(104, 90);
        glEnd();

        //car 01 window
        glColor3ub(253, 231, 215);
        glBegin(GL_QUADS);
        glVertex2i(196, 76);
        glVertex2i(196, 61);
        glVertex2i(218, 57);
        glVertex2i(206, 72);
        glEnd();

        text(125, 53, "AMAZON");

        wheel(123, 31, 8, 5);
        wheel(175, 31, 8, 5);

        //car03
        glColor3ub(108, 100, 110); //head light
        glBegin(GL_TRIANGLES);
        glVertex2i(860, 25);
        glVertex2i(860, 10);
        glColor3ub(204, 169, 48);
        glVertex2i(785, 20);
        glEnd();

        glColor3ub(6, 177, 213);
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
        glEnd();

        glColor3ub(0, 109, 157); //car3 window 01
        glBegin(GL_POLYGON);
        glVertex2i(746, 41);
        glVertex2i(741, 22);
        glVertex2i(761, 22);
        glVertex2i(761, 41);
        glEnd();

        glColor3ub(9, 36, 43); //car3 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(746, 41);
        glVertex2i(741, 22);
        glVertex2i(761, 41);
        glEnd();

        glColor3ub(0, 109, 157); //car3 window 02
        glBegin(GL_POLYGON);
        glVertex2i(765, 41);
        glVertex2i(765, 22);
        glVertex2i(784, 22);
        glVertex2i(779, 41);
        glEnd();

        glColor3ub(9, 36, 43); //car3 window 02 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(765, 41);
        glVertex2i(765, 22);
        glVertex2i(779, 41);
        glEnd();
        wheel(740, 14, 4, 2);
        wheel(788, 14, 4, 2);

        //car04
        glColor3ub(108, 100, 110); //head light
        glBegin(GL_TRIANGLES);
        glVertex2i(1020, 25);
        glVertex2i(1020, 10);
        glColor3ub(204, 169, 48);
        glVertex2i(950, 20);
        glEnd();

        glColor3ub(79, 183, 223);
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
        glEnd();

        glColor3ub(68, 112, 131); //car4 window 01
        glBegin(GL_POLYGON);
        glVertex2i(906, 41);
        glVertex2i(901, 22);
        glVertex2i(921, 22);
        glVertex2i(921, 41);
        glEnd();

        glColor3ub(7, 18, 14); //car4 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(906, 41);
        glVertex2i(901, 22);
        glVertex2i(921, 41);
        glEnd();

        glColor3ub(68, 112, 131); //car4 window 02
        glBegin(GL_POLYGON);
        glVertex2i(925, 41);
        glVertex2i(925, 22);
        glVertex2i(944, 22);
        glVertex2i(939, 41);
        glEnd();

        glColor3ub(7, 18, 14); //car4 window 02 Glitch
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
        glEnd();

        glColor3ub(4, 139, 182);
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
void moveCarRight()

{
    cars c;
    if (isRedlight)
    {
        CarX_R += 0;
    }
    else
    {
        CarX_R += .9;
    }

    if (CarX_R > 1200)
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
    }

    glPopMatrix();
}
void moveCarLeft()

{
    cars c;
    if (isRedlight)
    {
        CarX_L += 0;
    }
    else
    {
        CarX_L -= .9;
    }

    if (CarX_L < -650)
    {
        CarX_L = 650;
    }

    glPushMatrix();
    glTranslatef(CarX_L, CarY_L, 0);
    if (isDay)
    {
        c.dayCarLeft();
    }
    else
    {
        c.nightCarsLeft();
    }

    glPopMatrix();
}
void vehicle()
{
    moveCarLeft();
    moveCarRight();
}
void moveCloud()

{

    CloudX += .3;

    if (CloudX > 1200)
    {
        CloudX = -1200;
    }

    glPushMatrix();
    glTranslatef(CloudX, CloudY, 0);
    if (isDay)
    {
        DayCloud();
    }
    else
    {
        NightCloud();
    }

    glPopMatrix();
}
void sunRise()

{
    if (!sunSitThere)
    {
        sunY += .1;
        //std::cout << "  " << moonY;
    }
    if (sunY > 290)
    {
        //std::cout << "working!";
        text(50, 540, "Press N to make Night");
        sunSitThere = true;
    }
    glPushMatrix();
    glTranslatef(sunX, sunY, 0);
    sun();
    glPopMatrix();
}
void sunset()

{

    if (makeItNight)
    {
        sunY -= .1;
    }
    //std::cout << "  " << sunY ;
    if (sunY < -125)
    {
        isDay = false;
        sunY = 0;
    }

    glPushMatrix();
    glTranslatef(sunX, sunY, 0);
    sun();
    glPopMatrix();
}
void MoonRise()

{
    if (!moonSitThere)
    {
        moonY += .1;
        //std::cout << "  " << moonY;
    }
    if (moonY > 290)
    {
        //std::cout << "working!";
        text(50, 540, "Press D to make Day");
        moonSitThere = true;
    }
    glPushMatrix();
    glTranslatef(moonX, moonY, 0);
    moon();
    glPopMatrix();
}
void moonset()

{

    if (makeItDay)
    {
        //std::cout << " clicked ";
        moonY -= .1;
    }
    //std::cout << "  " << sunY ;
    if (moonY < -100)
    {
        isDay = true;
        moonY = 0;
    }

    glPushMatrix();
    glTranslatef(moonX, moonY, 0);
    moon();
    glPopMatrix();
}
void BgBuildingDayTime()
{
    ///bg building 1

    glColor3ub(195, 203, 200); //top_stick!
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(164, 350);
    glVertex2i(164, 340);

    glVertex2i(174, 360);
    glVertex2i(174, 340);
    glEnd();

    glColor3ub(195, 203, 200); //top
    glBegin(GL_QUADS);
    glVertex2i(138, 284);
    glVertex2i(179, 284);
    glVertex2i(178, 342);
    glVertex2i(138, 340);
    glEnd();

    glColor3ub(195, 203, 200); //bottom
    glBegin(GL_QUADS);
    glVertex2i(124, 170);
    glVertex2i(179, 170);
    glVertex2i(179, 284);
    glVertex2i(124, 284);
    glEnd();

    glColor3ub(195, 203, 200); //right_side
    glBegin(GL_QUADS);
    glVertex2i(179, 170);
    glVertex2i(186, 170);
    glVertex2i(186, 276);
    glVertex2i(179, 284);
    glEnd();

    glColor3ub(151, 163, 151); //bottom_shadow
    glBegin(GL_QUADS);
    glVertex2i(115, 170);
    glVertex2i(124, 170);
    glVertex2i(124, 284);
    glVertex2i(115, 284);
    glEnd();

    glColor3ub(151, 163, 151); //top_shadow
    glBegin(GL_QUADS);
    glVertex2i(129, 284);
    glVertex2i(138, 284);
    glVertex2i(138, 342);
    glVertex2i(129, 340);
    glEnd();
    ///end

    ///BG building 2
    glColor3ub(195, 203, 200); //top_stick!
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(229, 332);
    glVertex2i(229, 340);
    glEnd();
    glColor3ub(151, 163, 151); //top_stick_shadow
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(219, 336);
    glVertex2i(219, 330);
    glEnd();

    glColor3ub(195, 203, 200); //top_hat
    glBegin(GL_QUADS);
    glVertex2i(227, 330);
    glVertex2i(238, 330);
    glVertex2i(238, 332);
    glVertex2i(227, 332);
    glEnd();

    glColor3ub(195, 203, 200); //top
    glBegin(GL_QUADS);
    glVertex2i(227, 280);
    glVertex2i(248, 280);
    glVertex2i(248, 330);
    glVertex2i(227, 330);
    glEnd();

    glColor3ub(151, 163, 151); //top_shadow
    glBegin(GL_QUADS);
    glVertex2i(218, 280);
    glVertex2i(227, 280);
    glVertex2i(227, 330);
    glVertex2i(218, 330);
    glEnd();

    glColor3ub(195, 203, 200); //mid
    glBegin(GL_QUADS);
    glVertex2i(211, 254);
    glVertex2i(248, 254);
    glVertex2i(248, 280);
    glVertex2i(211, 280);
    glEnd();

    glColor3ub(151, 163, 151); //mid_shadow
    glBegin(GL_QUADS);
    glVertex2i(200, 254);
    glVertex2i(211, 254);
    glVertex2i(211, 280);
    glVertex2i(200, 280);
    glEnd();

    glColor3ub(195, 203, 200); //bottom
    glBegin(GL_QUADS);
    glVertex2i(204, 170);
    glVertex2i(248, 170);
    glVertex2i(248, 254);
    glVertex2i(204, 254);
    glEnd();

    glColor3ub(151, 163, 151); //bottom_shadow
    glBegin(GL_QUADS);
    glVertex2i(194, 170);
    glVertex2i(204, 170);
    glVertex2i(204, 254);
    glVertex2i(194, 254);
    glEnd();
    ///end

    ///BG Building 3
    glColor3ub(151, 163, 151); //top_box_shadow
    glBegin(GL_QUADS);
    glVertex2i(270, 355);
    glVertex2i(305, 355);
    glVertex2i(302, 365);
    glVertex2i(275, 365);
    glEnd();

    glColor3ub(195, 203, 200); //top_box
    glBegin(GL_QUADS);
    glVertex2i(280, 355);
    glVertex2i(305, 355);
    glVertex2i(302, 368);
    glVertex2i(285, 368);
    glEnd();

    glColor3ub(195, 203, 200); //top_tri1
    glBegin(GL_TRIANGLES);
    glVertex2i(305, 355);
    glVertex2i(315, 355);
    glVertex2i(310, 365);
    glEnd();

    glColor3ub(195, 203, 200); //top_tri2
    glBegin(GL_TRIANGLES);
    glVertex2i(320, 355);
    glVertex2i(325, 355);
    glVertex2i(325, 365);
    glEnd();

    glColor3ub(195, 203, 200); //top
    glBegin(GL_QUADS);
    glVertex2i(280, 170);
    glVertex2i(336, 170);
    glVertex2i(336, 355);
    glVertex2i(280, 355);
    glEnd();

    glColor3ub(151, 163, 151); //top_shadow
    glBegin(GL_QUADS);
    glVertex2i(270, 170);
    glVertex2i(280, 170);
    glVertex2i(280, 355);
    glVertex2i(270, 355);
    glEnd();

    ///end

    ///BG Building 4
    glColor3ub(151, 163, 151); //top_quad_shadow
    glBegin(GL_QUADS);
    glVertex2i(364, 380);
    glVertex2i(374, 380);
    glVertex2i(380, 398);
    glVertex2i(364, 408);
    glEnd();

    glColor3ub(195, 203, 200); //top_quad
    glBegin(GL_QUADS);
    glVertex2i(374, 380);
    glVertex2i(397, 380);
    glVertex2i(397, 401);
    glVertex2i(374, 411);
    glEnd();

    glColor3ub(195, 203, 200); //top
    glBegin(GL_QUADS);
    glVertex2i(354, 170);
    glVertex2i(397, 170);
    glVertex2i(397, 380);
    glVertex2i(354, 380);
    glEnd();

    glColor3ub(151, 163, 151); //top_shadow
    glBegin(GL_QUADS);
    glVertex2i(344, 170);
    glVertex2i(354, 170);
    glVertex2i(354, 380);
    glVertex2i(344, 380);
    glEnd();

    glColor3ub(195, 203, 200); //right_B3
    glBegin(GL_QUADS);
    glVertex2i(336, 170);
    glVertex2i(349, 170);
    glVertex2i(349, 270);
    glVertex2i(336, 270);
    glEnd();

    glColor3ub(195, 203, 200); //right
    glBegin(GL_QUADS);
    glVertex2i(401, 340);
    glVertex2i(397, 340);
    glVertex2i(397, 372);
    glVertex2i(401, 369);
    glEnd();
    glColor3ub(195, 203, 200); //right_2
    glBegin(GL_QUADS);
    glVertex2i(408, 170);
    glVertex2i(397, 170);
    glVertex2i(397, 353);
    glVertex2i(408, 345);
    glEnd();
    ///end

    ///BG Building 5
    glColor3ub(195, 203, 200); //top_1
    glBegin(GL_QUADS);
    glVertex2i(461, 400);
    glVertex2i(484, 400);
    glVertex2i(484, 387);
    glVertex2i(461, 387);
    glEnd();

    glColor3ub(151, 163, 151); //top_1_shadow
    glBegin(GL_QUADS);
    glVertex2i(451, 398);
    glVertex2i(461, 398);
    glVertex2i(461, 387);
    glVertex2i(451, 387);
    glEnd();

    glColor3ub(151, 163, 151); //top_2_curve_shadow
    glBegin(GL_QUADS);
    glVertex2i(451, 387);
    glVertex2i(474, 387);
    glVertex2i(474, 380);
    glVertex2i(448, 380);
    glEnd();

    glColor3ub(195, 203, 200); //top_2_curve
    glBegin(GL_QUADS);
    glVertex2i(461, 387);
    glVertex2i(484, 387);
    glVertex2i(487, 380);
    glVertex2i(458, 380);
    glEnd();

    glColor3ub(151, 163, 151); //top_2_shadow
    glBegin(GL_QUADS);
    glVertex2i(448, 380);
    glVertex2i(477, 380);
    glVertex2i(477, 350);
    glVertex2i(448, 350);
    glEnd();

    glColor3ub(195, 203, 200); //top_2
    glBegin(GL_QUADS);
    glVertex2i(458, 380);
    glVertex2i(487, 380);
    glVertex2i(487, 350);
    glVertex2i(458, 350);
    glEnd();

    glColor3ub(151, 163, 151); //top_curve
    glBegin(GL_QUADS);
    glVertex2i(445, 343);
    glVertex2i(480, 343);
    glVertex2i(477, 350);
    glVertex2i(448, 350);
    glEnd();

    glColor3ub(195, 203, 200); //top_curve
    glBegin(GL_QUADS);
    glVertex2i(455, 343);
    glVertex2i(490, 343);
    glVertex2i(487, 350);
    glVertex2i(458, 350);
    glEnd();

    glColor3ub(151, 163, 151); //main_shadow
    glBegin(GL_QUADS);
    glVertex2i(445, 170);
    glVertex2i(480, 170);
    glVertex2i(480, 343);
    glVertex2i(445, 343);
    glEnd();

    glColor3ub(195, 203, 200); //main
    glBegin(GL_QUADS);
    glVertex2i(455, 170);
    glVertex2i(490, 170);
    glVertex2i(490, 343);
    glVertex2i(455, 343);
    glEnd();

    glColor3ub(195, 203, 200); //righty
    glBegin(GL_QUADS);
    glVertex2i(490, 170);
    glVertex2i(513, 170);
    glVertex2i(513, 319);
    glVertex2i(490, 319);
    glEnd();

    ///end

    ///BG Building 6
    glColor3ub(195, 203, 200); //top_stick!
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2i(760, 380);
    glVertex2i(760, 346);
    glEnd();

    glColor3ub(195, 203, 200); //top_1
    glBegin(GL_QUADS);
    glVertex2i(748, 346);
    glVertex2i(762, 346);
    glVertex2i(762, 361);
    glVertex2i(748, 361);
    glEnd();

    glColor3ub(195, 203, 200); //top_2
    glBegin(GL_QUADS);
    glVertex2i(730, 340);
    glVertex2i(764, 340);
    glVertex2i(764, 346);
    glVertex2i(730, 346);
    glEnd();

    glColor3ub(195, 203, 200); //main
    glBegin(GL_QUADS);
    glVertex2i(723, 170);
    glVertex2i(762, 170);
    glVertex2i(762, 340);
    glVertex2i(723, 340);
    glEnd();

    glColor3ub(195, 203, 200); //right
    glBegin(GL_QUADS);
    glVertex2i(762, 170);
    glVertex2i(768, 170);
    glVertex2i(768, 345);
    glVertex2i(762, 350);
    glEnd();
    ///end

    ///BG Building 7
    glColor3ub(195, 203, 200); //stick
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(821, 380);
    glVertex2i(821, 340);
    glEnd();

    glColor3ub(195, 203, 200); //main
    glBegin(GL_QUADS);
    glVertex2i(779, 170);
    glVertex2i(828, 170);
    glVertex2i(828, 348);
    glVertex2i(776, 317);
    glEnd();

    glColor3ub(195, 203, 200); //right_1
    glBegin(GL_QUADS);
    glVertex2i(828, 170);
    glVertex2i(840, 170);
    glVertex2i(840, 306);
    glVertex2i(828, 306);
    glEnd();

    glColor3ub(195, 203, 200); //right_2
    glBegin(GL_QUADS);
    glVertex2i(840, 170);
    glVertex2i(853, 170);
    glVertex2i(853, 300);
    glVertex2i(840, 300);
    glEnd();
    ///end

    ///BG Building 8
    glColor3ub(195, 203, 200); //top_curve
    glBegin(GL_QUADS);
    glVertex2i(866, 367);
    glVertex2i(910, 367);
    glVertex2i(907, 380);
    glVertex2i(868, 380);
    glEnd();

    glColor3ub(195, 203, 200); //top
    glBegin(GL_QUADS);
    glVertex2i(866, 355);
    glVertex2i(910, 355);
    glVertex2i(910, 367);
    glVertex2i(866, 367);
    glEnd();

    glColor3ub(195, 203, 200); //main_curve
    glBegin(GL_QUADS);
    glVertex2i(862, 351);
    glVertex2i(913, 351);
    glVertex2i(910, 355);
    glVertex2i(866, 355);
    glEnd();

    glColor3ub(195, 203, 200); //main
    glBegin(GL_QUADS);
    glVertex2i(862, 170);
    glVertex2i(913, 170);
    glVertex2i(913, 351);
    glVertex2i(862, 351);
    glEnd();
    ///end

    ///BG Building 9
    glColor3ub(195, 203, 200); //main_curve
    glBegin(GL_QUADS);
    glVertex2i(945, 347);
    glVertex2i(990, 347);
    glVertex2i(985, 350);
    glVertex2i(949, 350);
    glEnd();

    glColor3ub(195, 203, 200); //main
    glBegin(GL_QUADS);
    glVertex2i(945, 170);
    glVertex2i(990, 170);
    glVertex2i(990, 347);
    glVertex2i(945, 347);
    glEnd();

    glColor3ub(195, 203, 200); //left
    glBegin(GL_QUADS);
    glVertex2i(942, 170);
    glVertex2i(945, 170);
    glVertex2i(945, 274);
    glVertex2i(942, 271);
    glEnd();

    glColor3ub(195, 203, 200); //right
    glBegin(GL_QUADS);
    glVertex2i(990, 170);
    glVertex2i(996, 170);
    glVertex2i(996, 285);
    glVertex2i(990, 290);
    glEnd();

    glColor3ub(195, 203, 200); //right_2
    glBegin(GL_QUADS);
    glVertex2i(996, 170);
    glVertex2i(1008, 170);
    glVertex2i(1008, 255);
    glVertex2i(996, 255);
    glEnd();
    ///end

    ///BG Building 10
    glColor3ub(195, 203, 200); //main_curve
    glBegin(GL_QUADS);
    glVertex2i(1060, 300);
    glVertex2i(1110, 300);
    glVertex2i(1105, 305);
    glVertex2i(1065, 305);
    glEnd();

    glColor3ub(195, 203, 200); //main
    glBegin(GL_QUADS);
    glVertex2i(1060, 170);
    glVertex2i(1110, 170);
    glVertex2i(1110, 300);
    glVertex2i(1060, 300);
    glEnd();
    ///end

    ///Front Building - 1
    glColor3ub(117, 152, 135); //right_side
    glBegin(GL_QUADS);
    glVertex2i(41, 170);
    glVertex2i(53, 170);
    glVertex2i(53, 314);
    glVertex2i(41, 314);
    glEnd();

    glColor3ub(148, 179, 163); //main
    glBegin(GL_QUADS);
    glVertex2i(53, 170);
    glVertex2i(94, 170);
    glVertex2i(94, 314);
    glVertex2i(53, 314);
    glEnd();

    glColor3ub(255, 255, 255); //main_window_white
    glBegin(GL_QUADS);
    glVertex2i(59, 175);
    glVertex2i(89, 175);
    glVertex2i(89, 309);
    glVertex2i(59, 309);
    glEnd();

    glLineWidth(3); //main_window_grill
    glColor3ub(148, 179, 163);
    glBegin(GL_LINES); //1V
    glVertex2i(66, 309);
    glVertex2i(66, 175);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(75, 309);
    glVertex2i(75, 175);
    glEnd();

    glBegin(GL_LINES); //3V
    glVertex2i(83, 309);
    glVertex2i(83, 175);
    glEnd();

    glBegin(GL_LINES); //1H
    glVertex2i(59, 292);
    glVertex2i(89, 292);
    glEnd();

    glBegin(GL_LINES); //2H
    glVertex2i(59, 273);
    glVertex2i(89, 273);
    glEnd();

    glBegin(GL_LINES); //3H
    glVertex2i(59, 253);
    glVertex2i(89, 253);
    glEnd();

    glBegin(GL_LINES); //4H
    glVertex2i(59, 233);
    glVertex2i(89, 233);
    glEnd();

    glBegin(GL_LINES); //5H
    glVertex2i(59, 213);
    glVertex2i(89, 213);
    glEnd();

    glBegin(GL_LINES); //5H
    glVertex2i(59, 193);
    glVertex2i(89, 193);
    glEnd();
    ///end

    ///Front Building 2
    glColor3ub(148, 179, 163); //main
    glBegin(GL_QUADS);
    glVertex2i(580, 170);
    glVertex2i(619, 170);
    glVertex2i(619, 344);
    glVertex2i(580, 344);
    glEnd();

    glColor3ub(117, 152, 135); //right_side
    glBegin(GL_QUADS);
    glVertex2i(619, 170);
    glVertex2i(629, 170);
    glVertex2i(629, 344);
    glVertex2i(619, 344);
    glEnd();

    glColor3ub(255, 255, 255); //main_window_white
    glBegin(GL_QUADS);
    glVertex2i(585, 221);
    glVertex2i(615, 221);
    glVertex2i(615, 340);
    glVertex2i(585, 340);
    glEnd();

    glColor3ub(148, 179, 163);
    glBegin(GL_LINES); //1V
    glVertex2i(592, 340);
    glVertex2i(592, 174);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(600, 340);
    glVertex2i(600, 174);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(608, 340);
    glVertex2i(608, 174);
    glEnd();

    glBegin(GL_LINES); //H1
    glVertex2i(585, 323);
    glVertex2i(615, 323);
    glEnd();

    glBegin(GL_LINES); //H2
    glVertex2i(585, 306);
    glVertex2i(615, 306);
    glEnd();

    glBegin(GL_LINES); //H3
    glVertex2i(585, 289);
    glVertex2i(615, 289);
    glEnd();

    glBegin(GL_LINES); //H4
    glVertex2i(585, 272);
    glVertex2i(615, 272);
    glEnd();

    glBegin(GL_LINES); //H5
    glVertex2i(585, 255);
    glVertex2i(615, 255);
    glEnd();

    glBegin(GL_LINES); //H6
    glVertex2i(585, 238);
    glVertex2i(615, 238);
    glEnd();

    glBegin(GL_LINES); //H7
    glVertex2i(585, 221);
    glVertex2i(615, 221);
    glEnd();

    ///end

    ///Front Building 3
    glColor3ub(148, 179, 163); //main
    glBegin(GL_QUADS);
    glVertex2i(1116, 170);
    glVertex2i(1172, 170);
    glVertex2i(1172, 426);
    glVertex2i(1116, 426);
    glEnd();

    glColor3ub(117, 152, 135); //right_side
    glBegin(GL_QUADS);
    glVertex2i(1168, 170);
    glVertex2i(1186, 170);
    glVertex2i(1186, 426);
    glVertex2i(1168, 426);
    glEnd();

    glColor3ub(255, 255, 255); //main_window_white
    glBegin(GL_QUADS);
    glVertex2i(1122, 278);
    glVertex2i(1163, 278);
    glVertex2i(1163, 418);
    glVertex2i(1122, 418);
    glEnd();

    glColor3ub(148, 179, 163);
    glBegin(GL_LINES); //1V
    glVertex2i(1131, 177);
    glVertex2i(1131, 418);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(1142, 177);
    glVertex2i(1142, 418);
    glEnd();

    glBegin(GL_LINES); //3V
    glVertex2i(1153, 177);
    glVertex2i(1153, 418);
    glEnd();

    glLineWidth(6.5);

    glBegin(GL_LINES); //1H
    glVertex2i(1122, 390);
    glVertex2i(1163, 390);
    glEnd();

    glBegin(GL_LINES); //2H
    glVertex2i(1122, 362);
    glVertex2i(1163, 362);
    glEnd();

    glBegin(GL_LINES); //3H
    glVertex2i(1122, 334);
    glVertex2i(1163, 334);
    glEnd();

    glBegin(GL_LINES); //4H
    glVertex2i(1122, 306);
    glVertex2i(1163, 306);
    glEnd();

    glBegin(GL_LINES); //4H
    glVertex2i(1122, 278);
    glVertex2i(1163, 278);
    glEnd();

    ///end
}

void BgBuildingNightTime()
{
    ///bg building 1
    glColor3ub(0, 114, 158);
    //top_stick!
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(164, 350);
    glVertex2i(164, 340);

    glVertex2i(174, 360);
    glVertex2i(174, 340);
    glEnd();

    //top
    glBegin(GL_QUADS);
    glVertex2i(138, 284);
    glVertex2i(179, 284);
    glVertex2i(178, 342);
    glVertex2i(138, 340);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
    glVertex2i(124, 170);
    glVertex2i(179, 170);
    glVertex2i(179, 284);
    glVertex2i(124, 284);
    glEnd();

    //right_side
    glBegin(GL_QUADS);
    glVertex2i(179, 170);
    glVertex2i(186, 170);
    glVertex2i(186, 276);
    glVertex2i(179, 284);
    glEnd();

    ///BG building 2
    glColor3ub(5, 145, 193);
    //top_stick!
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(229, 332);
    glVertex2i(229, 340);
    glEnd();

    //top_hat
    glBegin(GL_QUADS);
    glVertex2i(227, 330);
    glVertex2i(238, 330);
    glVertex2i(238, 332);
    glVertex2i(227, 332);
    glEnd();

    //top
    glBegin(GL_QUADS);
    glVertex2i(227, 280);
    glVertex2i(248, 280);
    glVertex2i(248, 330);
    glVertex2i(227, 330);
    glEnd();

    //mid
    glBegin(GL_QUADS);
    glVertex2i(211, 254);
    glVertex2i(248, 254);
    glVertex2i(248, 280);
    glVertex2i(211, 280);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
    glVertex2i(204, 170);
    glVertex2i(248, 170);
    glVertex2i(248, 254);
    glVertex2i(204, 254);
    glEnd();
    ///end

    ///BG Building 3
    glColor3ub(0, 91, 133);
    //top_box
    glBegin(GL_QUADS);
    glVertex2i(280, 355);
    glVertex2i(305, 355);
    glVertex2i(302, 368);
    glVertex2i(285, 368);
    glEnd();

    //top_tri1
    glBegin(GL_TRIANGLES);
    glVertex2i(305, 355);
    glVertex2i(315, 355);
    glVertex2i(310, 365);
    glEnd();

    //top_tri2
    glBegin(GL_TRIANGLES);
    glVertex2i(320, 355);
    glVertex2i(325, 355);
    glVertex2i(325, 365);
    glEnd();

    //top
    glBegin(GL_QUADS);
    glVertex2i(280, 170);
    glVertex2i(336, 170);
    glVertex2i(336, 355);
    glVertex2i(280, 355);
    glEnd();

    ///end

    ///BG Building 4
    glColor3ub(0, 114, 158);
    //top_quad
    glBegin(GL_QUADS);
    glVertex2i(374, 380);
    glVertex2i(397, 380);
    glVertex2i(397, 401);
    glVertex2i(374, 411);
    glEnd();

    //top
    glBegin(GL_QUADS);
    glVertex2i(354, 170);
    glVertex2i(397, 170);
    glVertex2i(397, 380);
    glVertex2i(354, 380);
    glEnd();

    //right_B3
    glBegin(GL_QUADS);
    glVertex2i(336, 170);
    glVertex2i(349, 170);
    glVertex2i(349, 270);
    glVertex2i(336, 270);
    glEnd();

    //right
    glBegin(GL_QUADS);
    glVertex2i(401, 340);
    glVertex2i(397, 340);
    glVertex2i(397, 372);
    glVertex2i(401, 369);
    glEnd();

    //right_2
    glBegin(GL_QUADS);
    glVertex2i(408, 170);
    glVertex2i(397, 170);
    glVertex2i(397, 353);
    glVertex2i(408, 345);
    glEnd();
    ///end

    ///BG Building 5
    glColor3ub(0, 91, 133);
    //top_1
    glBegin(GL_QUADS);
    glVertex2i(461, 400);
    glVertex2i(484, 400);
    glVertex2i(484, 387);
    glVertex2i(461, 387);
    glEnd();

    //top_2_curve
    glBegin(GL_QUADS);
    glVertex2i(461, 387);
    glVertex2i(484, 387);
    glVertex2i(487, 380);
    glVertex2i(458, 380);
    glEnd();

    //top_2
    glBegin(GL_QUADS);
    glVertex2i(458, 380);
    glVertex2i(487, 380);
    glVertex2i(487, 350);
    glVertex2i(458, 350);
    glEnd();

    //top_curve
    glBegin(GL_QUADS);
    glVertex2i(455, 343);
    glVertex2i(490, 343);
    glVertex2i(487, 350);
    glVertex2i(458, 350);
    glEnd();

    //main
    glBegin(GL_QUADS);
    glVertex2i(455, 170);
    glVertex2i(490, 170);
    glVertex2i(490, 343);
    glVertex2i(455, 343);
    glEnd();

    //righty
    glBegin(GL_QUADS);
    glVertex2i(490, 170);
    glVertex2i(513, 170);
    glVertex2i(513, 319);
    glVertex2i(490, 319);
    glEnd();

    ///end

    ///BG Building 6
    glColor3ub(0, 91, 133);
    //top_stick!
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2i(760, 380);
    glVertex2i(760, 346);
    glEnd();

    //top_1
    glBegin(GL_QUADS);
    glVertex2i(748, 346);
    glVertex2i(762, 346);
    glVertex2i(762, 361);
    glVertex2i(748, 361);
    glEnd();

    //top_2
    glBegin(GL_QUADS);
    glVertex2i(730, 340);
    glVertex2i(764, 340);
    glVertex2i(764, 346);
    glVertex2i(730, 346);
    glEnd();

    //main
    glBegin(GL_QUADS);
    glVertex2i(723, 170);
    glVertex2i(762, 170);
    glVertex2i(762, 340);
    glVertex2i(723, 340);
    glEnd();

    //right
    glBegin(GL_QUADS);
    glVertex2i(762, 170);
    glVertex2i(768, 170);
    glVertex2i(768, 345);
    glVertex2i(762, 350);
    glEnd();
    ///end

    ///BG Building 7
    glColor3ub(0, 114, 158); //stick
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(821, 380);
    glVertex2i(821, 340);
    glEnd();

    //main
    glBegin(GL_QUADS);
    glVertex2i(779, 170);
    glVertex2i(828, 170);
    glVertex2i(828, 348);
    glVertex2i(776, 317);
    glEnd();

    //right_1
    glBegin(GL_QUADS);
    glVertex2i(828, 170);
    glVertex2i(840, 170);
    glVertex2i(840, 306);
    glVertex2i(828, 306);
    glEnd();

    //right_2
    glBegin(GL_QUADS);
    glVertex2i(840, 170);
    glVertex2i(853, 170);
    glVertex2i(853, 300);
    glVertex2i(840, 300);
    glEnd();
    ///end

    ///BG Building 8
    glColor3ub(0, 114, 158); //top_curve
    glBegin(GL_QUADS);
    glVertex2i(866, 367);
    glVertex2i(910, 367);
    glVertex2i(907, 380);
    glVertex2i(868, 380);
    glEnd();

    //top
    glBegin(GL_QUADS);
    glVertex2i(866, 355);
    glVertex2i(910, 355);
    glVertex2i(910, 367);
    glVertex2i(866, 367);
    glEnd();

    //main_curve
    glBegin(GL_QUADS);
    glVertex2i(862, 351);
    glVertex2i(913, 351);
    glVertex2i(910, 355);
    glVertex2i(866, 355);
    glEnd();

    //main
    glBegin(GL_QUADS);
    glVertex2i(862, 170);
    glVertex2i(913, 170);
    glVertex2i(913, 351);
    glVertex2i(862, 351);
    glEnd();
    ///end

    ///BG Building 9
    glColor3ub(0, 114, 158); //main_curve
    glBegin(GL_QUADS);
    glVertex2i(945, 347);
    glVertex2i(990, 347);
    glVertex2i(985, 350);
    glVertex2i(949, 350);
    glEnd();

    //main
    glBegin(GL_QUADS);
    glVertex2i(945, 170);
    glVertex2i(990, 170);
    glVertex2i(990, 347);
    glVertex2i(945, 347);
    glEnd();

    //left
    glBegin(GL_QUADS);
    glVertex2i(942, 170);
    glVertex2i(945, 170);
    glVertex2i(945, 274);
    glVertex2i(942, 271);
    glEnd();

    //right
    glBegin(GL_QUADS);
    glVertex2i(990, 170);
    glVertex2i(996, 170);
    glVertex2i(996, 285);
    glVertex2i(990, 290);
    glEnd();

    //right_2
    glBegin(GL_QUADS);
    glVertex2i(996, 170);
    glVertex2i(1008, 170);
    glVertex2i(1008, 255);
    glVertex2i(996, 255);
    glEnd();
    ///end

    ///BG Building 10
    glColor3ub(0, 114, 158); //main_curve
    glBegin(GL_QUADS);
    glVertex2i(1060, 300);
    glVertex2i(1110, 300);
    glVertex2i(1105, 305);
    glVertex2i(1065, 305);
    glEnd();

    //main
    glBegin(GL_QUADS);
    glVertex2i(1060, 170);
    glVertex2i(1110, 170);
    glVertex2i(1110, 300);
    glVertex2i(1060, 300);
    glEnd();
    ///end

    ///Front Building - 1
    glColor3ub(10, 7, 8); //right_side
    glBegin(GL_QUADS);
    glVertex2i(41, 170);
    glVertex2i(53, 170);
    glVertex2i(53, 314);
    glVertex2i(41, 314);
    glEnd();

    glColor3ub(0, 113, 168); //main
    glBegin(GL_QUADS);
    glVertex2i(53, 170);
    glVertex2i(94, 170);
    glVertex2i(94, 314);
    glVertex2i(53, 314);
    glEnd();

    glColor3ub(177, 101, 46); //main_window_white
    glBegin(GL_QUADS);
    glVertex2i(59, 175);
    glVertex2i(89, 175);
    glVertex2i(89, 309);
    glVertex2i(59, 309);
    glEnd();

    glColor3ub(10, 7, 8); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(67, 274);
    glVertex2i(89, 274);
    glVertex2i(89, 290);
    glVertex2i(67, 290);
    glEnd();

    glColor3ub(10, 7, 8); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(67, 232);
    glVertex2i(89, 232);
    glVertex2i(89, 253);
    glVertex2i(67, 253);
    glEnd();

    glColor3ub(177, 101, 46);
    glLineWidth(3); //main_window_grill
    glColor3ub(0, 113, 168);
    glBegin(GL_LINES); //1V
    glVertex2i(66, 309);
    glVertex2i(66, 175);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(75, 309);
    glVertex2i(75, 175);
    glEnd();

    glBegin(GL_LINES); //3V
    glVertex2i(83, 309);
    glVertex2i(83, 175);
    glEnd();

    glBegin(GL_LINES); //1H
    glVertex2i(59, 292);
    glVertex2i(89, 292);
    glEnd();

    glBegin(GL_LINES); //2H
    glVertex2i(59, 273);
    glVertex2i(89, 273);
    glEnd();

    glBegin(GL_LINES); //3H
    glVertex2i(59, 253);
    glVertex2i(89, 253);
    glEnd();

    glBegin(GL_LINES); //4H
    glVertex2i(59, 233);
    glVertex2i(89, 233);
    glEnd();

    glBegin(GL_LINES); //5H
    glVertex2i(59, 213);
    glVertex2i(89, 213);
    glEnd();

    glBegin(GL_LINES); //5H
    glVertex2i(59, 193);
    glVertex2i(89, 193);
    glEnd();
    ///end

    ///Front Building 2
    glColor3ub(19, 116, 153); //main
    glBegin(GL_QUADS);
    glVertex2i(580, 170);
    glVertex2i(619, 170);
    glVertex2i(619, 344);
    glVertex2i(580, 344);
    glEnd();

    glColor3ub(7, 43, 72); //right_side
    glBegin(GL_QUADS);
    glVertex2i(619, 170);
    glVertex2i(629, 170);
    glVertex2i(629, 344);
    glVertex2i(619, 344);
    glEnd();

    glColor3ub(35, 181, 221); //main_window_white
    glBegin(GL_QUADS);
    glVertex2i(585, 221);
    glVertex2i(615, 221);
    glVertex2i(615, 340);
    glVertex2i(585, 340);
    glEnd();

    glColor3ub(177, 101, 46); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(600, 324);
    glVertex2i(607, 324);
    glVertex2i(607, 340);
    glVertex2i(600, 340);
    glEnd();
    glColor3ub(177, 101, 46); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(592, 272);
    glVertex2i(600, 272);
    glVertex2i(600, 287);
    glVertex2i(592, 287);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(592, 238);
    glVertex2i(608, 238);
    glVertex2i(608, 253);
    glVertex2i(592, 253);
    glEnd();

    glColor3ub(9, 118, 163);
    glBegin(GL_LINES); //1V
    glVertex2i(592, 340);
    glVertex2i(592, 174);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(600, 340);
    glVertex2i(600, 174);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(608, 340);
    glVertex2i(608, 174);
    glEnd();

    glBegin(GL_LINES); //H1
    glVertex2i(585, 323);
    glVertex2i(615, 323);
    glEnd();

    glBegin(GL_LINES); //H2
    glVertex2i(585, 306);
    glVertex2i(615, 306);
    glEnd();

    glBegin(GL_LINES); //H3
    glVertex2i(585, 289);
    glVertex2i(615, 289);
    glEnd();

    glBegin(GL_LINES); //H4
    glVertex2i(585, 272);
    glVertex2i(615, 272);
    glEnd();

    glBegin(GL_LINES); //H5
    glVertex2i(585, 255);
    glVertex2i(615, 255);
    glEnd();

    glBegin(GL_LINES); //H6
    glVertex2i(585, 238);
    glVertex2i(615, 238);
    glEnd();

    glBegin(GL_LINES); //H7
    glVertex2i(585, 221);
    glVertex2i(615, 221);
    glEnd();

    ///end

    ///Front Building 3
    glColor3ub(23, 107, 156); //main
    glBegin(GL_QUADS);
    glVertex2i(1116, 170);
    glVertex2i(1172, 170);
    glVertex2i(1172, 426);
    glVertex2i(1116, 426);
    glEnd();

    glColor3ub(5, 52, 81); //right_side
    glBegin(GL_QUADS);
    glVertex2i(1168, 170);
    glVertex2i(1186, 170);
    glVertex2i(1186, 426);
    glVertex2i(1168, 426);
    glEnd();

    glColor3ub(4, 22, 21); //main_window_white
    glBegin(GL_QUADS);
    glVertex2i(1122, 278);
    glVertex2i(1163, 278);
    glVertex2i(1163, 418);
    glVertex2i(1122, 418);
    glEnd();

    glColor3ub(175, 111, 64); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(1120, 387);
    glVertex2i(1164, 387);
    glVertex2i(1164, 365);
    glVertex2i(1120, 365);
    glEnd();
    glColor3ub(175, 111, 64); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(1142, 392);
    glVertex2i(1153, 392);
    glVertex2i(1153, 418);
    glVertex2i(1142, 418);
    glEnd();
    glColor3ub(175, 111, 64); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(1142, 336);
    glVertex2i(1153, 336);
    glVertex2i(1153, 359);
    glVertex2i(1142, 359);
    glEnd();

    glColor3ub(23, 107, 156);
    glBegin(GL_LINES); //1V
    glVertex2i(1131, 177);
    glVertex2i(1131, 418);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(1142, 177);
    glVertex2i(1142, 418);
    glEnd();

    glBegin(GL_LINES); //3V
    glVertex2i(1153, 177);
    glVertex2i(1153, 418);
    glEnd();

    glLineWidth(6.5);

    glBegin(GL_LINES); //1H
    glVertex2i(1122, 390);
    glVertex2i(1163, 390);
    glEnd();

    glBegin(GL_LINES); //2H
    glVertex2i(1122, 362);
    glVertex2i(1163, 362);
    glEnd();

    glBegin(GL_LINES); //3H
    glVertex2i(1122, 334);
    glVertex2i(1163, 334);
    glEnd();

    glBegin(GL_LINES); //4H
    glVertex2i(1122, 306);
    glVertex2i(1163, 306);
    glEnd();

    glBegin(GL_LINES); //4H
    glVertex2i(1122, 278);
    glVertex2i(1163, 278);
    glEnd();

    ///end
}

struct Tree
{
    void drawdayTree()
    {
        glColor3ub(78,148,45);
        glBegin(GL_TRIANGLES);
        glVertex2i(370,250);
        glVertex2i(440,255);
        glVertex2i(400,290);
        glEnd();

        glColor3ub(39,118,37);
        glBegin(GL_TRIANGLES);
        glVertex2i(375,272);
        glVertex2i(432,268);
        glVertex2i(405,297);
        glEnd();

        glColor3ub(78,148,45);
        glBegin(GL_TRIANGLES);
        glVertex2i(380,290);
        glVertex2i(425,290);
        glVertex2i(405,315);
        glEnd();

        glColor3ub(119,68,34);
        glBegin(GL_QUADS);
        glVertex2i(400,235);
        glVertex2i(410,235);
        glVertex2i(410,253);
        glVertex2i(400,253);
        glEnd();

    }

    void drawnightTree()
    {
        glColor3ub(26,77,132);
        glBegin(GL_TRIANGLES);
        glVertex2i(370,250);
        glVertex2i(440,255);
        glVertex2i(400,290);
        glEnd();

        glColor3ub(26,77,132);
        glBegin(GL_TRIANGLES);
        glVertex2i(375,272);
        glVertex2i(432,268);
        glVertex2i(405,297);
        glEnd();

        glColor3ub(26,77,132);
        glBegin(GL_TRIANGLES);
        glVertex2i(380,290);
        glVertex2i(425,290);
        glVertex2i(405,315);
        glEnd();

        glColor3ub(26,77,132);
        glBegin(GL_QUADS);
        glVertex2i(400,235);
        glVertex2i(410,235);
        glVertex2i(410,253);
        glVertex2i(400,253);
        glEnd();

        glPointSize(2);
        glColor3ub(rand()%255,rand()%255,rand()%255);
        glBegin(GL_POINTS);
        glVertex2i(394,300);
        glVertex2i(406,297);
        glVertex2i(396,271);
        glVertex2i(426,261);
        glVertex2i(415,279);
        glVertex2i(400,279);
        glVertex2i(380,255);
        glEnd();
    }
};

void dayTree()
{
    Tree t;
    glPushMatrix();
    glTranslated(-100, -100, 0);
    t.drawdayTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(60, -95, 0);
    t.drawdayTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(80, -95, 0);
    t.drawdayTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(170, -110, 0);
    t.drawdayTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(270, -100, 0);
    t.drawdayTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-300, -110, 0);
    t.drawdayTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(380, -100, 0);
    t.drawdayTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(400, -110, 0);
    t.drawdayTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(600, -100, 0);
    t.drawdayTree();
    glPopMatrix();

}

void nightTree()
{

    Tree t;
    glPushMatrix();
    glTranslated(-100, -100, 0);
    t.drawnightTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(60, -95, 0);
    t.drawnightTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(80, -95, 0);
    t.drawnightTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(170, -110, 0);
    t.drawnightTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(270, -100, 0);
    t.drawnightTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-300, -110, 0);
    t.drawnightTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(380, -100, 0);
    t.drawnightTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(400, -110, 0);
    t.drawnightTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(600, -100, 0);
    t.drawnightTree();
    glPopMatrix();
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
void trafficlights(int x, int y)
{
    glPushMatrix();
    DrawCircle(x, y, 5, 2000);
    glPopMatrix();
}
void trfficText()
{
    if (isRedlight)
    {
        text(50, 560, "Press G for Green Light");
    }
    else
    {
        text(50, 560, "Press S for Red Light");
    }
}
void trafficlightStand()
{
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(600, 122);
    glVertex2i(605, 122);
    glVertex2i(605, 160);
    glVertex2i(600, 160);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(595, 160);
    glVertex2i(610, 160);
    glVertex2i(610, 190);
    glVertex2i(595, 190);
    glEnd();

    if (isRedlight)
    {
        glColor3ub(255, 0, 0);
        trafficlights(602, 181);
        glColor3ub(0, 80, 0);
        trafficlights(602, 168);
    }
    else
    {
        glColor3ub(80, 0, 0);
        trafficlights(602, 181);
        glColor3ub(0, 255, 0);
        trafficlights(602, 168);
    }
}
void RoadFieldDay()
{
    ///Green Field
    glColor3ub(169, 188, 60);
    glBegin(GL_QUADS);
    glVertex2i(0, 170);
    glVertex2i(0, 122);
    glVertex2i(1200, 122);
    glVertex2i(1200, 170);
    glEnd();
    ///end

    ///Road
    glColor3ub(254, 206, 8);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(1200, 0);
    glVertex2i(1200, 122);
    glVertex2i(0, 122);
    glEnd();

    glPushAttrib(GL_ENABLE_BIT);
    glLineWidth(5); // road_strip
    glLineStipple(10, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2i(0, 58);
    glVertex2i(1190, 58);
    glEnd();
    glPopAttrib();

    ///end
}
void RoadFielNight()
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

    glPushAttrib(GL_ENABLE_BIT);
    glLineWidth(5); // road_strip
    glLineStipple(10, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    glColor3ub(6, 95, 138);
    glBegin(GL_LINES);
    glVertex2i(0, 58);
    glVertex2i(1190, 58);
    glEnd();
    glPopAttrib();

    ///end
}
void DayTime()
{
    ///---------------------Mahjabin-----------------------///

    //1st building

    glBegin(GL_POLYGON);
    glPointSize(10.0);
    glColor3ub(106, 135, 109);
    glVertex2i(310, 250);
    glVertex2i(395, 250);
    glVertex2i(387, 262);
    glVertex2i(318, 262);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(305, 245);
    glVertex2i(400, 245);
    glVertex2i(397, 250);
    glVertex2i(306, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);

    glColor3ub(239, 124, 33);
    glVertex2i(310, 145);
    glVertex2i(395, 145);
    glVertex2i(395, 245);
    glVertex2i(310, 245);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(214, 195, 144);
    glVertex2i(310, 212);
    glVertex2i(395, 212);
    glVertex2i(395, 217);
    glVertex2i(310, 217);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(322, 217);
    glVertex2i(336, 217);
    glVertex2i(336, 238);
    glVertex2i(322, 238);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(322, 232);
    glVertex2i(336, 232);
    glVertex2i(322, 222);
    glVertex2i(336, 222);
    glVertex2i(330, 238);
    glVertex2i(330, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(345, 217);
    glVertex2i(357, 217);
    glVertex2i(357, 238);
    glVertex2i(345, 238);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(345, 232);
    glVertex2i(358, 232);
    glVertex2i(345, 222);
    glVertex2i(358, 222);
    glVertex2i(352, 238);
    glVertex2i(352, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(368, 217);
    glVertex2i(381, 217);
    glVertex2i(381, 238);
    glVertex2i(368, 238);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(368, 232);
    glVertex2i(382, 232);
    glVertex2i(368, 222);
    glVertex2i(382, 222);
    glVertex2i(375, 238);
    glVertex2i(375, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(335, 185);
    glVertex2i(345, 185);
    glVertex2i(345, 205);
    glVertex2i(335, 205);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(335, 200);
    glVertex2i(345, 200);
    glVertex2i(335, 191);
    glVertex2i(345, 191);
    glVertex2i(340, 205);
    glVertex2i(340, 185);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(355, 185);
    glVertex2i(370, 185);
    glVertex2i(370, 205);
    glVertex2i(355, 205);
    glEnd();
    ///---------------------Asraf-----------------------///
    //yellow building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(251, 185, 23);
    glVertex2i(0, 145);
    glVertex2i(20, 145);
    glVertex2i(20, 260);
    glVertex2i(0, 260);
    glEnd();

    glBegin(GL_QUADS); //1st Building Top bar
    glColor3ub(65, 51, 0);
    glVertex2i(0, 260);
    glVertex2i(20, 260);
    glVertex2i(20, 266);
    glVertex2i(0, 266);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(245, 225, 164);
    glVertex2i(20, 145);
    glVertex2i(64, 145);
    glVertex2i(64, 260);
    glVertex2i(20, 260);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(65, 51, 0);
    glVertex2i(20, 260);
    glVertex2i(64, 260);
    glVertex2i(64, 266);
    glVertex2i(20, 266);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(25, 237);
    glVertex2i(33, 237);
    glVertex2i(33, 250);
    glVertex2i(25, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(25, 250);
    glVertex2i(33, 250);
    glVertex2i(33, 253);
    glVertex2i(25, 253);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(37, 237);
    glVertex2i(45, 237);
    glVertex2i(45, 250);
    glVertex2i(37, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(37, 250);
    glVertex2i(45, 250);
    glVertex2i(45, 253);
    glVertex2i(37, 253);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(50, 237);
    glVertex2i(58, 237);
    glVertex2i(58, 250);
    glVertex2i(50, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(50, 250);
    glVertex2i(58, 250);
    glVertex2i(58, 253);
    glVertex2i(50, 253);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(25, 215);
    glVertex2i(33, 215);
    glVertex2i(33, 228);
    glVertex2i(25, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(25, 228);
    glVertex2i(33, 228);
    glVertex2i(33, 231);
    glVertex2i(25, 231);
    glEnd();

    //window 5

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(37, 215);
    glVertex2i(45, 215);
    glVertex2i(45, 228);
    glVertex2i(37, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(37, 228);
    glVertex2i(45, 228);
    glVertex2i(45, 231);
    glVertex2i(37, 231);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(50, 215);
    glVertex2i(58, 215);
    glVertex2i(58, 228);
    glVertex2i(50, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(50, 228);
    glVertex2i(58, 228);
    glVertex2i(58, 231);
    glVertex2i(50, 231);
    glEnd();

    //window 7
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(25, 195);
    glVertex2i(33, 195);
    glVertex2i(33, 208);
    glVertex2i(25, 208);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(25, 207);
    glVertex2i(33, 207);
    glVertex2i(33, 210);
    glVertex2i(25, 210);
    glEnd();

    //window 8

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(37, 195);
    glVertex2i(45, 195);
    glVertex2i(45, 208);
    glVertex2i(37, 208);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(37, 207);
    glVertex2i(45, 207);
    glVertex2i(45, 210);
    glVertex2i(37, 210);
    glEnd();

    //window 9

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(50, 195);
    glVertex2i(58, 195);
    glVertex2i(58, 208);
    glVertex2i(50, 208);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(50, 207);
    glVertex2i(58, 207);
    glVertex2i(58, 210);
    glVertex2i(50, 210);
    glEnd();

    //window 10
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 252);
    glVertex2i(25, 175);
    glVertex2i(33, 175);
    glVertex2i(33, 188);
    glVertex2i(25, 188);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(252, 194, 40);
    glVertex2i(25, 188);
    glVertex2i(33, 188);
    glVertex2i(33, 191);
    glVertex2i(25, 191);
    glEnd();

    //green building

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(201, 78, 44);
    glVertex2i(90, 150);
    glVertex2i(100, 150);
    glVertex2i(100, 275);
    glVertex2i(90, 275);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(201, 78, 44);
    glVertex2i(85, 270);
    glVertex2i(95, 270);
    glVertex2i(95, 280);
    glVertex2i(85, 280);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(36, 71, 66);
    glVertex2i(100, 150);
    glVertex2i(160, 150);
    glVertex2i(160, 275);
    glVertex2i(100, 275);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(36, 71, 66);
    glVertex2i(90, 275);
    glVertex2i(165, 275);
    glVertex2i(165, 280);
    glVertex2i(90, 280);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(104, 245);
    glVertex2i(118, 245);
    glVertex2i(118, 265);
    glVertex2i(104, 265);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(104, 255);
    glVertex2i(118, 255);
    glVertex2i(111, 245);
    glVertex2i(111, 265);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(124, 245);
    glVertex2i(138, 245);
    glVertex2i(138, 265);
    glVertex2i(124, 265);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(124, 255);
    glVertex2i(138, 255);
    glVertex2i(131, 245);
    glVertex2i(131, 265);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(142, 245);
    glVertex2i(156, 245);
    glVertex2i(156, 265);
    glVertex2i(142, 265);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(142, 255);
    glVertex2i(156, 255);
    glVertex2i(149, 245);
    glVertex2i(149, 265);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(107, 131, 125);
    glVertex2i(100, 237);
    glVertex2i(160, 237);
    glVertex2i(160, 240);
    glVertex2i(100, 240);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(104, 215);
    glVertex2i(118, 215);
    glVertex2i(118, 235);
    glVertex2i(104, 235);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(104, 225);
    glVertex2i(118, 225);
    glVertex2i(111, 215);
    glVertex2i(111, 235);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(124, 215);
    glVertex2i(138, 215);
    glVertex2i(138, 235);
    glVertex2i(124, 235);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(124, 135, 118);
    glVertex2i(124, 225);
    glVertex2i(138, 225);
    glVertex2i(131, 215);
    glVertex2i(131, 235);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(142, 215);
    glVertex2i(156, 215);
    glVertex2i(156, 235);
    glVertex2i(142, 235);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(142, 225);
    glVertex2i(156, 225);
    glVertex2i(149, 215);
    glVertex2i(149, 235);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(107, 131, 125);
    glVertex2i(100, 207);
    glVertex2i(160, 207);
    glVertex2i(160, 210);
    glVertex2i(100, 210);
    glEnd();

    //window 7
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(104, 185);
    glVertex2i(118, 185);
    glVertex2i(118, 205);
    glVertex2i(104, 205);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(104, 195);
    glVertex2i(118, 195);
    glVertex2i(111, 185);
    glVertex2i(111, 205);
    glEnd();

    //window 8
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(124, 185);
    glVertex2i(138, 185);
    glVertex2i(138, 205);
    glVertex2i(124, 205);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(124, 195);
    glVertex2i(138, 195);
    glVertex2i(131, 185);
    glVertex2i(131, 205);
    glEnd();

    //window 9
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(142, 185);
    glVertex2i(156, 185);
    glVertex2i(156, 205);
    glVertex2i(142, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(107, 131, 125);
    glVertex2i(100, 177);
    glVertex2i(160, 177);
    glVertex2i(160, 180);
    glVertex2i(100, 180);
    glEnd();

    //red building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(146, 44, 27);
    glVertex2i(228, 145);
    glVertex2i(237, 145);
    glVertex2i(237, 310);
    glVertex2i(228, 310);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(146, 44, 27);
    glVertex2i(227, 305);
    glVertex2i(232, 305);
    glVertex2i(232, 315);
    glVertex2i(227, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(209, 70, 42);
    glVertex2i(237, 145);
    glVertex2i(300, 145);
    glVertex2i(300, 310);
    glVertex2i(237, 310);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(209, 70, 42);
    glVertex2i(232, 310);
    glVertex2i(305, 310);
    glVertex2i(305, 315);
    glVertex2i(232, 315);
    glEnd();

    //window 1

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(131, 180, 160);
    glVertex2i(250, 270);
    glVertex2i(262, 270);
    glVertex2i(262, 295);
    glVertex2i(250, 295);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(250, 285);
    glVertex2i(262, 285);
    glVertex2i(256, 270);
    glVertex2i(256, 295);
    glEnd();
    //window 2

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(131, 180, 160);
    glVertex2i(267, 270);
    glVertex2i(279, 270);
    glVertex2i(279, 295);
    glVertex2i(267, 295);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(267, 285);
    glVertex2i(279, 285);
    glVertex2i(273, 270);
    glVertex2i(273, 295);
    glEnd();

    //window 3

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(131, 180, 160);
    glVertex2i(284, 270);
    glVertex2i(296, 270);
    glVertex2i(296, 295);
    glVertex2i(284, 295);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(284, 285);
    glVertex2i(296, 285);
    glVertex2i(290, 270);
    glVertex2i(290, 295);
    glEnd();

    //window 4

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(131, 180, 160);
    glVertex2i(250, 235);
    glVertex2i(262, 235);
    glVertex2i(262, 260);
    glVertex2i(250, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(250, 250);
    glVertex2i(262, 250);
    glVertex2i(256, 235);
    glVertex2i(256, 260);
    glEnd();

    //window 5

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(131, 180, 160);
    glVertex2i(267, 235);
    glVertex2i(279, 235);
    glVertex2i(279, 260);
    glVertex2i(267, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(267, 250);
    glVertex2i(279, 250);
    glVertex2i(273, 235);
    glVertex2i(273, 260);
    glEnd();

    //window 6

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(131, 180, 160);
    glVertex2i(284, 235);
    glVertex2i(296, 235);
    glVertex2i(296, 260);
    glVertex2i(284, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(284, 250);
    glVertex2i(296, 250);
    glVertex2i(290, 235);
    glVertex2i(290, 260);
    glEnd();

    //window 7

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(131, 180, 160);
    glVertex2i(250, 195);
    glVertex2i(262, 195);
    glVertex2i(262, 220);
    glVertex2i(250, 220);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(250, 210);
    glVertex2i(262, 210);
    glVertex2i(256, 195);
    glVertex2i(256, 220);
    glEnd();

    //window 8

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(131, 180, 160);
    glVertex2i(267, 195);
    glVertex2i(279, 195);
    glVertex2i(279, 220);
    glVertex2i(267, 220);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(267, 210);
    glVertex2i(279, 210);
    glVertex2i(273, 195);
    glVertex2i(273, 220);
    glEnd();

    //window 9

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(131, 180, 160);
    glVertex2i(284, 195);
    glVertex2i(296, 195);
    glVertex2i(296, 220);
    glVertex2i(284, 220);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(284, 210);
    glVertex2i(296, 210);
    glVertex2i(290, 195);
    glVertex2i(290, 220);
    glEnd();

    //yellow building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(235, 197, 73);
    glVertex2i(130, 145);
    glVertex2i(180, 145);
    glVertex2i(180, 210);
    glVertex2i(130, 210);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(222, 147, 51);
    glVertex2i(127, 210);
    glVertex2i(180, 210);
    glVertex2i(180, 218);
    glVertex2i(127, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(249, 243, 222);
    glVertex2i(180, 145);
    glVertex2i(230, 145);
    glVertex2i(230, 210);
    glVertex2i(180, 210);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(243, 165, 75);
    glVertex2i(180, 210);
    glVertex2i(232, 210);
    glVertex2i(232, 218);
    glVertex2i(180, 218);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(132, 195);
    glVertex2i(137, 195);
    glVertex2i(137, 203);
    glVertex2i(132, 203);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(139, 195);
    glVertex2i(144, 195);
    glVertex2i(144, 203);
    glVertex2i(139, 203);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(146, 195);
    glVertex2i(151, 195);
    glVertex2i(151, 203);
    glVertex2i(146, 203);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(153, 195);
    glVertex2i(158, 195);
    glVertex2i(158, 203);
    glVertex2i(153, 203);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(160, 195);
    glVertex2i(165, 195);
    glVertex2i(165, 203);
    glVertex2i(160, 203);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(167, 195);
    glVertex2i(172, 195);
    glVertex2i(172, 203);
    glVertex2i(167, 203);
    glEnd();

    //window 7
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(132, 180);
    glVertex2i(137, 180);
    glVertex2i(137, 188);
    glVertex2i(132, 188);
    glEnd();

    //window 8
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(139, 180);
    glVertex2i(144, 180);
    glVertex2i(144, 188);
    glVertex2i(139, 188);
    glEnd();

    //window 9
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(146, 180);
    glVertex2i(151, 180);
    glVertex2i(151, 188);
    glVertex2i(146, 188);
    glEnd();

    //window 10
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(153, 180);
    glVertex2i(158, 180);
    glVertex2i(158, 188);
    glVertex2i(153, 188);
    glEnd();

    //window 11
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(160, 180);
    glVertex2i(165, 180);
    glVertex2i(165, 188);
    glVertex2i(160, 188);
    glEnd();

    //window 12
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(167, 180);
    glVertex2i(172, 180);
    glVertex2i(172, 188);
    glVertex2i(167, 188);
    glEnd();

    //window 13
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(132, 165);
    glVertex2i(137, 165);
    glVertex2i(137, 173);
    glVertex2i(132, 173);
    glEnd();

    //window 14
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(139, 165);
    glVertex2i(144, 165);
    glVertex2i(144, 173);
    glVertex2i(139, 173);
    glEnd();

    //window 15
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(146, 165);
    glVertex2i(151, 165);
    glVertex2i(151, 173);
    glVertex2i(146, 173);
    glEnd();

    //window 16
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(153, 165);
    glVertex2i(158, 165);
    glVertex2i(158, 173);
    glVertex2i(153, 173);
    glEnd();

    //window 17
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(160, 165);
    glVertex2i(165, 165);
    glVertex2i(165, 173);
    glVertex2i(160, 173);
    glEnd();

    //window 18
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(167, 165);
    glVertex2i(172, 165);
    glVertex2i(172, 173);
    glVertex2i(167, 173);
    glEnd();

    //window 19
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(132, 150);
    glVertex2i(137, 150);
    glVertex2i(137, 158);
    glVertex2i(132, 158);
    glEnd();

    //window 20
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(139, 150);
    glVertex2i(144, 150);
    glVertex2i(144, 158);
    glVertex2i(139, 158);
    glEnd();

    //window 21
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(146, 150);
    glVertex2i(151, 150);
    glVertex2i(151, 158);
    glVertex2i(146, 158);
    glEnd();

    //window 22
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(153, 150);
    glVertex2i(158, 150);
    glVertex2i(158, 158);
    glVertex2i(153, 158);
    glEnd();

    //window 23
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(160, 150);
    glVertex2i(165, 150);
    glVertex2i(165, 158);
    glVertex2i(160, 158);
    glEnd();

    //window 24
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 246, 221);
    glVertex2i(167, 150);
    glVertex2i(172, 150);
    glVertex2i(172, 158);
    glVertex2i(167, 158);
    glEnd();

    //pink building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(185, 32, 116);
    glVertex2i(35, 140);
    glVertex2i(125, 140);
    glVertex2i(125, 185);
    glVertex2i(35, 185);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(49, 13, 84);
    glVertex2i(30, 140);
    glVertex2i(40, 140);
    glVertex2i(40, 205);
    glVertex2i(30, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(49, 13, 84);
    glVertex2i(65, 185);
    glVertex2i(80, 185);
    glVertex2i(80, 205);
    glVertex2i(65, 205);
    glEnd();

    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(185, 32, 116);
    glVertex2i(40, 185);
    glVertex2i(75, 185);
    glVertex2i(40, 205);
    glEnd();

    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(185, 32, 116);
    glVertex2i(78, 185);
    glVertex2i(120, 185);
    glVertex2i(78, 205);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 255);
    glVertex2i(50, 152);
    glVertex2i(65, 152);
    glVertex2i(65, 170);
    glVertex2i(50, 170);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(85, 19, 85);
    glVertex2i(50, 170);
    glVertex2i(65, 170);
    glVertex2i(65, 174);
    glVertex2i(50, 174);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 255);
    glVertex2i(75, 172);
    glVertex2i(80, 172);
    glVertex2i(80, 178);
    glVertex2i(75, 178);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(85, 19, 85);
    glVertex2i(75, 178);
    glVertex2i(80, 178);
    glVertex2i(80, 180);
    glVertex2i(75, 180);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 255);
    glVertex2i(83, 172);
    glVertex2i(88, 172);
    glVertex2i(88, 178);
    glVertex2i(83, 178);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(85, 19, 85);
    glVertex2i(83, 178);
    glVertex2i(88, 178);
    glVertex2i(88, 180);
    glVertex2i(83, 180);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 255);
    glVertex2i(83, 162);
    glVertex2i(88, 162);
    glVertex2i(88, 168);
    glVertex2i(83, 168);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(85, 19, 85);
    glVertex2i(83, 168);
    glVertex2i(88, 168);
    glVertex2i(88, 170);
    glVertex2i(83, 170);
    glEnd();

    //window 5

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 255);
    glVertex2i(91, 162);
    glVertex2i(96, 162);
    glVertex2i(96, 168);
    glVertex2i(91, 168);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(85, 19, 85);
    glVertex2i(91, 168);
    glVertex2i(96, 168);
    glVertex2i(96, 170);
    glVertex2i(91, 170);

    glEnd();
    ///---------------------Mahjabin-----------------------///
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(355, 200);
    glVertex2i(370, 200);
    glVertex2i(355, 191);
    glVertex2i(370, 191);
    glVertex2i(363, 205);
    glVertex2i(363, 185);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(113, 140, 120);
    glVertex2i(328, 152);
    glVertex2i(376, 152);
    glVertex2i(376, 170);
    glVertex2i(328, 170);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(245, 234, 188);
    glVertex2i(328, 144);
    glVertex2i(376, 144);
    glVertex2i(376, 146);
    glVertex2i(328, 146);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(245, 234, 188);
    glVertex2i(328, 146);
    glVertex2i(376, 146);
    glVertex2i(376, 152);
    glVertex2i(328, 152);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(376, 152);
    glVertex2i(376, 170);
    glVertex2i(376, 170);
    glVertex2i(328, 170);
    glVertex2i(328, 170);
    glVertex2i(328, 152);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(376, 144);
    glVertex2i(376, 152);
    glVertex2i(328, 152);
    glVertex2i(328, 144);
    glVertex2i(350, 170);
    glVertex2i(350, 144);
    glEnd();

    //2nd building

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(145, 55, 50);
    glVertex2i(405, 145);
    glVertex2i(430, 145);
    glVertex2i(430, 330);
    glVertex2i(405, 330);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(247, 165, 63);
    glVertex2i(430, 145);
    glVertex2i(485, 145);
    glVertex2i(485, 330);
    glVertex2i(430, 330);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(16, 17, 8);
    glVertex2i(405, 330);
    glVertex2i(430, 330);
    glVertex2i(430, 336);
    glVertex2i(405, 336);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(241, 205, 54);
    glVertex2i(430, 330);
    glVertex2i(485, 330);
    glVertex2i(485, 336);
    glVertex2i(430, 336);
    glEnd();

    glBegin(GL_QUADS); ///1st window
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(436, 305);
    glVertex2i(446, 305);
    glVertex2i(446, 315);
    glVertex2i(436, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(436, 316);
    glVertex2i(446, 316);
    glVertex2i(446, 318);
    glVertex2i(436, 318);
    glEnd();

    glBegin(GL_QUADS); ///2nd
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(450, 305);
    glVertex2i(460, 305);
    glVertex2i(460, 315);
    glVertex2i(450, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(450, 316);
    glVertex2i(460, 316);
    glVertex2i(460, 318);
    glVertex2i(450, 318);
    glEnd();

    glBegin(GL_QUADS); ///3rd
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(465, 305);
    glVertex2i(475, 305);
    glVertex2i(475, 315);
    glVertex2i(465, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(465, 316);
    glVertex2i(475, 316);
    glVertex2i(475, 318);
    glVertex2i(465, 318);
    glEnd();

    glBegin(GL_QUADS); ///1st bar
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 299);
    glVertex2i(475, 299);
    glVertex2i(475, 302);
    glVertex2i(435, 302);
    glEnd();

    glBegin(GL_QUADS); ///4th
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(435, 265);
    glVertex2i(445, 265);
    glVertex2i(445, 275);
    glVertex2i(435, 275);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 275);
    glVertex2i(445, 275);
    glVertex2i(445, 277);
    glVertex2i(435, 277);
    glEnd();

    glBegin(GL_QUADS); ///5th
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(465, 265);
    glVertex2i(475, 265);
    glVertex2i(475, 275);
    glVertex2i(465, 275);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(465, 275);
    glVertex2i(475, 275);
    glVertex2i(475, 277);
    glVertex2i(465, 277);
    glEnd();

    glBegin(GL_QUADS); ///6th
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(450, 265);
    glVertex2i(460, 265);
    glVertex2i(460, 275);
    glVertex2i(450, 275);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(450, 275);
    glVertex2i(460, 275);
    glVertex2i(460, 277);
    glVertex2i(450, 277);
    glEnd();

    glBegin(GL_QUADS); ///2nd bar
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 262);
    glVertex2i(475, 262);
    glVertex2i(475, 259);
    glVertex2i(435, 259);
    glEnd();

    glBegin(GL_QUADS); ///7th
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(435, 220);
    glVertex2i(445, 220);
    glVertex2i(445, 230);
    glVertex2i(435, 230);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 231);
    glVertex2i(445, 231);
    glVertex2i(445, 233);
    glVertex2i(435, 233);
    glEnd();

    glBegin(GL_QUADS); ///8th
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(450, 220);
    glVertex2i(460, 220);
    glVertex2i(460, 230);
    glVertex2i(450, 230);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(450, 231);
    glVertex2i(460, 231);
    glVertex2i(460, 233);
    glVertex2i(450, 233);
    glEnd();

    glBegin(GL_QUADS); ///9th
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(465, 220);
    glVertex2i(475, 220);
    glVertex2i(475, 230);
    glVertex2i(465, 230);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(465, 231);
    glVertex2i(475, 231);
    glVertex2i(475, 233);
    glVertex2i(465, 233);
    glEnd();

    glBegin(GL_QUADS); ///3rd bar
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 214);
    glVertex2i(475, 214);
    glVertex2i(475, 217);
    glVertex2i(435, 217);
    glEnd();

    glBegin(GL_QUADS); ///10th
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(465, 175);
    glVertex2i(475, 175);
    glVertex2i(475, 185);
    glVertex2i(465, 185);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(465, 186);
    glVertex2i(475, 186);
    glVertex2i(475, 188);
    glVertex2i(465, 188);
    glEnd();

    glBegin(GL_QUADS); ///11th
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(435, 175);
    glVertex2i(445, 175);
    glVertex2i(445, 185);
    glVertex2i(435, 185);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 186);
    glVertex2i(445, 186);
    glVertex2i(445, 188);
    glVertex2i(435, 188);
    glEnd();

    glBegin(GL_QUADS); ///12th
    glPointSize(10.0);
    glColor3ub(255, 253, 241);
    glVertex2i(450, 175);
    glVertex2i(460, 175);
    glVertex2i(460, 185);
    glVertex2i(450, 185);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(450, 186);
    glVertex2i(460, 186);
    glVertex2i(460, 188);
    glVertex2i(450, 188);
    glEnd();

    glBegin(GL_QUADS); ///last bar
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 170);
    glVertex2i(475, 170);
    glVertex2i(475, 173);
    glVertex2i(435, 173);
    glEnd();

    //3rd building

    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(79, 143, 128);
    glVertex2i(492, 280);
    glVertex2i(540, 280);
    glVertex2i(535, 312);
    glEnd();

    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(137, 180, 170);
    glVertex2i(540, 280);
    glVertex2i(580, 280);
    glVertex2i(535, 312);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(43, 141, 128);
    glVertex2i(495, 145);
    glVertex2i(540, 145);
    glVertex2i(540, 280);
    glVertex2i(495, 280);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(184, 217, 212);
    glVertex2i(540, 145);
    glVertex2i(580, 145);
    glVertex2i(580, 280);
    glVertex2i(540, 280);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(196, 231, 210);
    glVertex2i(500, 170);
    glVertex2i(535, 170);
    glVertex2i(535, 275);
    glVertex2i(500, 275);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES); //1
    glColor3ub(46, 142, 130);
    glVertex2i(495, 270);
    glVertex2i(535, 270);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 260);
    glVertex2i(535, 260);
    glEnd(); //2

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 250);
    glVertex2i(535, 250);
    glEnd(); //3

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 240);
    glVertex2i(535, 240);
    glEnd(); //4

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 230);
    glVertex2i(535, 230);
    glEnd(); //5

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 220);
    glVertex2i(535, 220);
    glEnd(); //6

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 210);
    glVertex2i(535, 210);
    glEnd(); //7

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 200);
    glVertex2i(535, 200);
    glEnd(); //8

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 190);
    glVertex2i(535, 190);
    glEnd(); //9

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 180);
    glVertex2i(535, 180);
    glEnd(); //10

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 170);
    glVertex2i(535, 170);
    glEnd(); //11

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(495, 160);
    glVertex2i(535, 160);
    glEnd(); //12

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(500, 275);
    glVertex2i(500, 170);
    glEnd(); //1

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(505, 275);
    glVertex2i(505, 170);
    glEnd(); //2

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(510, 275);
    glVertex2i(510, 170);
    glEnd(); //3

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(515, 275);
    glVertex2i(515, 170);
    glEnd(); //4

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(520, 275);
    glVertex2i(520, 170);
    glEnd(); //5

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(525, 275);
    glVertex2i(525, 170);
    glEnd(); //6

    glBegin(GL_LINES);
    glColor3ub(46, 142, 130);
    glVertex2i(530, 275);
    glVertex2i(530, 170);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(233, 248, 219);
    glVertex2i(545, 150);
    glVertex2i(575, 150);
    glVertex2i(575, 275);
    glVertex2i(545, 275);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 270);
    glVertex2i(575, 270);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 265);
    glVertex2i(575, 265);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 260);
    glVertex2i(575, 260);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 255);
    glVertex2i(575, 255);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 250);
    glVertex2i(575, 250);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 245);
    glVertex2i(575, 245);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 240);
    glVertex2i(575, 240);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 235);
    glVertex2i(575, 235);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 230);
    glVertex2i(575, 230);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 225);
    glVertex2i(575, 225);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 220);
    glVertex2i(575, 220);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 215);
    glVertex2i(575, 215);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 210);
    glVertex2i(575, 210);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 205);
    glVertex2i(575, 205);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 200);
    glVertex2i(575, 200);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 195);
    glVertex2i(575, 195);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 190);
    glVertex2i(575, 190);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 185);
    glVertex2i(575, 185);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 180);
    glVertex2i(575, 180);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 175);
    glVertex2i(575, 175);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 170);
    glVertex2i(575, 170);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 165);
    glVertex2i(575, 165);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 160);
    glVertex2i(575, 160);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(184, 217, 212);
    glVertex2i(545, 155);
    glVertex2i(575, 155);
    glEnd();
    //5th building

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 255, 51);
    glVertex2i(645, 165);
    glVertex2i(705, 165);
    glVertex2i(705, 330);
    glVertex2i(645, 330);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(244, 188, 22);
    glVertex2i(705, 270);
    glVertex2i(725, 270);
    glVertex2i(725, 330);
    glVertex2i(705, 330);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(705, 330);
    glVertex2i(726, 330);
    glVertex2i(726, 335);
    glVertex2i(705, 335);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(77, 78, 23);
    glVertex2i(642, 330);
    glVertex2i(705, 330);
    glVertex2i(705, 335);
    glVertex2i(642, 335);
    glEnd();

    //1st
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(650, 300);
    glVertex2i(660, 300);
    glVertex2i(660, 315);
    glVertex2i(650, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(650, 315);
    glVertex2i(660, 315);
    glVertex2i(660, 318);
    glVertex2i(650, 318);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(650, 270);
    glVertex2i(660, 270);
    glVertex2i(660, 285);
    glVertex2i(650, 285);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(650, 285);
    glVertex2i(660, 285);
    glVertex2i(660, 288);
    glVertex2i(650, 288);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(650, 240);
    glVertex2i(660, 240);
    glVertex2i(660, 255);
    glVertex2i(650, 255);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(650, 255);
    glVertex2i(660, 255);
    glVertex2i(660, 258);
    glVertex2i(650, 258);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(650, 210);
    glVertex2i(660, 210);
    glVertex2i(660, 225);
    glVertex2i(650, 225);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(650, 225);
    glVertex2i(660, 225);
    glVertex2i(660, 228);
    glVertex2i(650, 228);
    glEnd();

    //2nd
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(670, 300);
    glVertex2i(680, 300);
    glVertex2i(680, 315);
    glVertex2i(670, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(670, 315);
    glVertex2i(680, 315);
    glVertex2i(680, 318);
    glVertex2i(670, 318);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(670, 270);
    glVertex2i(680, 270);
    glVertex2i(680, 285);
    glVertex2i(670, 285);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(670, 285);
    glVertex2i(680, 285);
    glVertex2i(680, 288);
    glVertex2i(670, 288);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(670, 240);
    glVertex2i(680, 240);
    glVertex2i(680, 255);
    glVertex2i(670, 255);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(670, 255);
    glVertex2i(680, 255);
    glVertex2i(680, 258);
    glVertex2i(670, 258);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(670, 210);
    glVertex2i(680, 210);
    glVertex2i(680, 225);
    glVertex2i(670, 225);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(670, 225);
    glVertex2i(680, 225);
    glVertex2i(680, 228);
    glVertex2i(670, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(670, 180);
    glVertex2i(680, 180);
    glVertex2i(680, 195);
    glVertex2i(670, 195);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(670, 195);
    glVertex2i(680, 195);
    glVertex2i(680, 198);
    glVertex2i(670, 198);
    glEnd();

    //3rd

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(685, 300);
    glVertex2i(695, 300);
    glVertex2i(695, 315);
    glVertex2i(685, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(685, 315);
    glVertex2i(695, 315);
    glVertex2i(695, 318);
    glVertex2i(685, 318);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(685, 270);
    glVertex2i(695, 270);
    glVertex2i(695, 285);
    glVertex2i(685, 285);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(685, 285);
    glVertex2i(695, 285);
    glVertex2i(695, 288);
    glVertex2i(685, 288);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(685, 240);
    glVertex2i(695, 240);
    glVertex2i(695, 255);
    glVertex2i(685, 255);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(685, 255);
    glVertex2i(695, 255);
    glVertex2i(695, 258);
    glVertex2i(685, 258);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(685, 210);
    glVertex2i(695, 210);
    glVertex2i(695, 225);
    glVertex2i(685, 225);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(685, 225);
    glVertex2i(695, 225);
    glVertex2i(695, 228);
    glVertex2i(685, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 254, 254);
    glVertex2i(685, 180);
    glVertex2i(695, 180);
    glVertex2i(695, 195);
    glVertex2i(685, 195);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(239, 181, 38);
    glVertex2i(685, 195);
    glVertex2i(695, 195);
    glVertex2i(695, 198);
    glVertex2i(685, 198);
    glEnd();

    //4th building

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(254, 207, 7);
    glVertex2i(590, 145);
    glVertex2i(635, 145);
    glVertex2i(635, 200);
    glVertex2i(590, 200);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(245, 225, 164);
    glVertex2i(635, 145);
    glVertex2i(685, 145);
    glVertex2i(685, 200);
    glVertex2i(635, 200);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(254, 207, 7);
    glVertex2i(590, 145);
    glVertex2i(635, 145);
    glVertex2i(635, 200);
    glVertex2i(590, 200);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(245, 225, 164);
    glVertex2i(635, 145);
    glVertex2i(685, 145);
    glVertex2i(685, 200);
    glVertex2i(635, 200);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(595, 190);
    glVertex2i(600, 190);
    glVertex2i(600, 185);
    glVertex2i(595, 185);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(602, 190);
    glVertex2i(607, 190);
    glVertex2i(607, 185);
    glVertex2i(602, 185);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(609, 190);
    glVertex2i(614, 190);
    glVertex2i(614, 185);
    glVertex2i(609, 185);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(616, 190);
    glVertex2i(621, 190);
    glVertex2i(621, 185);
    glVertex2i(616, 185);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(623, 190);
    glVertex2i(628, 190);
    glVertex2i(628, 185);
    glVertex2i(623, 185);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(595, 175);
    glVertex2i(600, 175);
    glVertex2i(600, 180);
    glVertex2i(595, 180);
    glEnd();

    //window 7
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(602, 175);
    glVertex2i(607, 175);
    glVertex2i(607, 180);
    glVertex2i(602, 180);
    glEnd();

    //window 8
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(609, 175);
    glVertex2i(614, 175);
    glVertex2i(614, 180);
    glVertex2i(609, 180);
    glEnd();

    //window 9
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(616, 175);
    glVertex2i(621, 175);
    glVertex2i(621, 180);
    glVertex2i(616, 180);
    glEnd();

    //window 10
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(623, 175);
    glVertex2i(628, 175);
    glVertex2i(628, 180);
    glVertex2i(623, 180);
    glEnd();

    //window 11
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(595, 165);
    glVertex2i(600, 165);
    glVertex2i(600, 170);
    glVertex2i(595, 170);
    glEnd();

    //window 12
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(602, 165);
    glVertex2i(607, 165);
    glVertex2i(607, 170);
    glVertex2i(602, 170);
    glEnd();

    //window 13
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(609, 165);
    glVertex2i(614, 165);
    glVertex2i(614, 170);
    glVertex2i(609, 170);
    glEnd();

    //window 14
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(616, 165);
    glVertex2i(621, 165);
    glVertex2i(621, 170);
    glVertex2i(616, 170);
    glEnd();

    //window 15
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(623, 165);
    glVertex2i(628, 165);
    glVertex2i(628, 170);
    glVertex2i(623, 170);
    glEnd();

    //window 16
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(595, 155);
    glVertex2i(600, 155);
    glVertex2i(600, 160);
    glVertex2i(595, 160);
    glEnd();

    //window 17
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(602, 155);
    glVertex2i(607, 155);
    glVertex2i(607, 160);
    glVertex2i(602, 160);
    glEnd();

    //window 18
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(609, 155);
    glVertex2i(614, 155);
    glVertex2i(614, 160);
    glVertex2i(609, 160);
    glEnd();

    //window 19
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(616, 155);
    glVertex2i(621, 155);
    glVertex2i(621, 160);
    glVertex2i(616, 160);
    glEnd();

    //window 20
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 251, 254);
    glVertex2i(623, 155);
    glVertex2i(628, 155);
    glVertex2i(628, 160);
    glVertex2i(623, 160);
    glEnd();

    //6th building

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(245, 94, 55);
    glVertex2i(705, 145);
    glVertex2i(765, 145);
    glVertex2i(765, 270);
    glVertex2i(705, 270);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(58, 81, 76);
    glVertex2i(695, 145);
    glVertex2i(705, 145);
    glVertex2i(705, 270);
    glVertex2i(695, 270);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(720, 250);
    glVertex2i(730, 250);
    glVertex2i(730, 260);
    glVertex2i(720, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(720, 255);
    glVertex2i(730, 255);
    glVertex2i(725, 260);
    glVertex2i(725, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(733, 250);
    glVertex2i(743, 250);
    glVertex2i(743, 260);
    glVertex2i(733, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(733, 255);
    glVertex2i(743, 255);
    glVertex2i(738, 260);
    glVertex2i(738, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(745, 250);
    glVertex2i(755, 250);
    glVertex2i(755, 260);
    glVertex2i(745, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(745, 255);
    glVertex2i(755, 255);
    glVertex2i(750, 260);
    glVertex2i(750, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(720, 235);
    glVertex2i(730, 235);
    glVertex2i(730, 245);
    glVertex2i(720, 245);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(720, 240);
    glVertex2i(730, 240);
    glVertex2i(725, 245);
    glVertex2i(725, 235);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(720, 220);
    glVertex2i(730, 220);
    glVertex2i(730, 230);
    glVertex2i(720, 230);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(720, 225);
    glVertex2i(730, 225);
    glVertex2i(725, 230);
    glVertex2i(725, 220);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(720, 205);
    glVertex2i(730, 205);
    glVertex2i(730, 215);
    glVertex2i(720, 215);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(720, 210);
    glVertex2i(730, 210);
    glVertex2i(725, 215);
    glVertex2i(725, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(720, 190);
    glVertex2i(730, 190);
    glVertex2i(730, 200);
    glVertex2i(720, 200);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(720, 195);
    glVertex2i(730, 195);
    glVertex2i(725, 200);
    glVertex2i(725, 190);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(720, 175);
    glVertex2i(730, 175);
    glVertex2i(730, 185);
    glVertex2i(720, 185);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(720, 180);
    glVertex2i(730, 180);
    glVertex2i(725, 185);
    glVertex2i(725, 175);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(720, 160);
    glVertex2i(730, 160);
    glVertex2i(730, 170);
    glVertex2i(720, 170);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(720, 165);
    glVertex2i(730, 165);
    glVertex2i(725, 170);
    glVertex2i(725, 160);
    glEnd();

    //2nd
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(733, 235);
    glVertex2i(743, 235);
    glVertex2i(743, 245);
    glVertex2i(733, 245);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(733, 240);
    glVertex2i(743, 240);
    glVertex2i(738, 245);
    glVertex2i(738, 235);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(733, 220);
    glVertex2i(743, 220);
    glVertex2i(743, 230);
    glVertex2i(733, 230);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(733, 225);
    glVertex2i(743, 225);
    glVertex2i(738, 230);
    glVertex2i(738, 220);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(733, 205);
    glVertex2i(743, 205);
    glVertex2i(743, 215);
    glVertex2i(733, 215);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(733, 210);
    glVertex2i(743, 210);
    glVertex2i(738, 215);
    glVertex2i(738, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(733, 190);
    glVertex2i(743, 190);
    glVertex2i(743, 200);
    glVertex2i(733, 200);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(733, 195);
    glVertex2i(743, 195);
    glVertex2i(738, 200);
    glVertex2i(738, 190);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(733, 175);
    glVertex2i(743, 175);
    glVertex2i(743, 185);
    glVertex2i(733, 185);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(733, 180);
    glVertex2i(743, 180);
    glVertex2i(738, 185);
    glVertex2i(738, 175);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(733, 160);
    glVertex2i(743, 160);
    glVertex2i(743, 170);
    glVertex2i(733, 170);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(733, 165);
    glVertex2i(743, 165);
    glVertex2i(738, 170);
    glVertex2i(738, 160);
    glEnd();

    //3rd
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(745, 235);
    glVertex2i(755, 235);
    glVertex2i(755, 245);
    glVertex2i(745, 245);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(745, 240);
    glVertex2i(755, 240);
    glVertex2i(750, 245);
    glVertex2i(750, 235);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(745, 220);
    glVertex2i(755, 220);
    glVertex2i(755, 230);
    glVertex2i(745, 230);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(745, 225);
    glVertex2i(755, 225);
    glVertex2i(750, 230);
    glVertex2i(750, 220);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(745, 205);
    glVertex2i(755, 205);
    glVertex2i(755, 215);
    glVertex2i(745, 215);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(745, 210);
    glVertex2i(755, 210);
    glVertex2i(750, 215);
    glVertex2i(750, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(745, 190);
    glVertex2i(755, 190);
    glVertex2i(755, 200);
    glVertex2i(745, 200);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(745, 195);
    glVertex2i(755, 195);
    glVertex2i(750, 200);
    glVertex2i(750, 190);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(745, 175);
    glVertex2i(755, 175);
    glVertex2i(755, 185);
    glVertex2i(745, 185);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(745, 180);
    glVertex2i(755, 180);
    glVertex2i(750, 185);
    glVertex2i(750, 175);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(157, 203, 178);
    glVertex2i(745, 160);
    glVertex2i(755, 160);
    glVertex2i(755, 170);
    glVertex2i(745, 170);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(104, 135, 118);
    glVertex2i(745, 165);
    glVertex2i(755, 165);
    glVertex2i(750, 170);
    glVertex2i(750, 160);
    glEnd();
    ///---------------------Fariha-----------------------///
    //2nd building
    glBegin(GL_QUADS); //red1 b2
    glPointSize(10.0);
    glColor3ub(208, 75, 36);
    glVertex2i(855, 155);
    glVertex2i(865, 155);
    glVertex2i(865, 330);
    glVertex2i(855, 330);
    glEnd();

    glBegin(GL_QUADS); //red2 b2 border
    glPointSize(10.0);
    glColor3ub(208, 75, 36);
    glVertex2i(850, 325);
    glVertex2i(865, 325);
    glVertex2i(865, 335);
    glVertex2i(850, 335);
    glEnd();
    glBegin(GL_QUADS); //green1 b2
    glPointSize(10.0);
    glColor3ub(29, 68, 59);
    glVertex2i(865, 155);
    glVertex2i(925, 155);
    glVertex2i(925, 330);
    glVertex2i(865, 330);
    glEnd();
    glBegin(GL_QUADS); //green2 b2 border
    glPointSize(10.0);
    glColor3ub(29, 68, 59);
    glVertex2i(860, 325);
    glVertex2i(930, 325);
    glVertex2i(930, 335);
    glVertex2i(860, 335);
    glEnd();
    glBegin(GL_QUADS); //w1 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(870, 290);
    glVertex2i(885, 290);
    glVertex2i(885, 310);
    glVertex2i(870, 310);
    glEnd();
    glBegin(GL_QUADS); //w2 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(890, 290);
    glVertex2i(905, 290);
    glVertex2i(905, 310);
    glVertex2i(890, 310);
    glEnd();
    glBegin(GL_QUADS); //w3 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(910, 290);
    glVertex2i(925, 290);
    glVertex2i(925, 310);
    glVertex2i(910, 310);
    glEnd();
    //line border1

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(184, 218, 194);
    glVertex2i(867, 282);
    glVertex2i(923, 282);
    glEnd();

    glBegin(GL_QUADS); //w4 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(870, 255);
    glVertex2i(885, 255);
    glVertex2i(885, 275);
    glVertex2i(870, 275);
    glEnd();
    glBegin(GL_QUADS); //w5 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(890, 255);
    glVertex2i(905, 255);
    glVertex2i(905, 275);
    glVertex2i(890, 275);
    glEnd();

    glBegin(GL_QUADS); //w6 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(910, 255);
    glVertex2i(925, 255);
    glVertex2i(925, 275);
    glVertex2i(910, 275);
    glEnd();
    //line border2
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(184, 218, 194);
    glVertex2i(867, 244);
    glVertex2i(923, 244);
    glEnd();

    glBegin(GL_QUADS); //w7 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(870, 220);
    glVertex2i(885, 220);
    glVertex2i(885, 240);
    glVertex2i(870, 240);
    glEnd();

    glBegin(GL_QUADS); //w8 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(890, 220);
    glVertex2i(905, 220);
    glVertex2i(905, 240);
    glVertex2i(890, 240);
    glEnd();

    glBegin(GL_QUADS); //w9 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(910, 220);
    glVertex2i(925, 220);
    glVertex2i(925, 240);
    glVertex2i(910, 240);
    glEnd();

    //line border3
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(184, 218, 194);
    glVertex2i(867, 204);
    glVertex2i(923, 204);
    glEnd();

    //1st building.
    glBegin(GL_QUADS); //red part b1
    glPointSize(10.0);
    glColor3ub(163, 76, 63);
    glVertex2i(774, 147);
    glVertex2i(790, 147);
    glVertex2i(790, 242);
    glVertex2i(774, 242);
    glEnd();
    // border
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(114, 149, 125);
    glVertex2i(777, 146);
    glVertex2i(777, 242);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(04);
    glColor3ub(114, 149, 125);
    glVertex2i(782, 146);
    glVertex2i(782, 242);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(04);
    glColor3ub(114, 149, 125);
    glVertex2i(789, 146);
    glVertex2i(789, 242);
    glEnd();

    glBegin(GL_QUADS); //white part b1
    glPointSize(10.0);
    glColor3ub(244, 237, 215);
    glVertex2i(790, 147);
    glVertex2i(863, 147);
    glVertex2i(863, 242);
    glVertex2i(790, 242);
    glEnd();
    glBegin(GL_QUADS); //w1 b1
    glPointSize(10.0);
    glColor3ub(187, 211, 188);
    glVertex2i(800, 217);
    glVertex2i(813, 217);
    glVertex2i(813, 232);
    glVertex2i(800, 232);
    glEnd();

    glBegin(GL_QUADS); //w2 b1
    glPointSize(10.0);
    glColor3ub(187, 211, 188);
    glVertex2i(820, 217);
    glVertex2i(833, 217);
    glVertex2i(833, 232);
    glVertex2i(820, 232);
    glEnd();
    glBegin(GL_QUADS); //w3 b1
    glPointSize(10.0);
    glColor3ub(187, 211, 188);
    glVertex2i(840, 217);
    glVertex2i(853, 217);
    glVertex2i(853, 232);
    glVertex2i(840, 232);
    glEnd();
    glBegin(GL_QUADS); //w4 b1
    glPointSize(10.0);
    glColor3ub(187, 211, 188);
    glVertex2i(800, 188);
    glVertex2i(813, 188);
    glVertex2i(813, 203);
    glVertex2i(800, 203);
    glEnd();
    glBegin(GL_QUADS); //w5 b1
    glPointSize(10.0);
    glColor3ub(187, 211, 188);
    glVertex2i(820, 188);
    glVertex2i(833, 188);
    glVertex2i(833, 203);
    glVertex2i(820, 203);
    glEnd();
    glBegin(GL_QUADS); //w6 b1
    glPointSize(10.0);
    glColor3ub(187, 211, 188);
    glVertex2i(840, 188);
    glVertex2i(853, 188);
    glVertex2i(853, 203);
    glVertex2i(840, 203);
    glEnd();

    glBegin(GL_QUADS); //w7 b1
    glPointSize(10.0);
    glColor3ub(187, 211, 188);
    glVertex2i(800, 159);
    glVertex2i(813, 159);
    glVertex2i(813, 174);
    glVertex2i(800, 174);
    glEnd();
    glBegin(GL_QUADS); //w8 b1
    glPointSize(10.0);
    glColor3ub(187, 211, 188);
    glVertex2i(820, 159);
    glVertex2i(833, 159);
    glVertex2i(833, 174);
    glVertex2i(820, 174);
    glEnd();
    glBegin(GL_QUADS); //w9 b1
    glPointSize(10.0);
    glColor3ub(187, 211, 188);
    glVertex2i(840, 159);
    glVertex2i(853, 159);
    glVertex2i(853, 174);
    glVertex2i(840, 174);
    glEnd();

    //3rd building
    glBegin(GL_QUADS); //b3 border
    glPointSize(10.0);
    glColor3ub(82, 78, 55);
    glVertex2i(924, 145);
    glVertex2i(934, 145);
    glVertex2i(934, 252);
    glVertex2i(924, 252);
    glEnd();
    //Red part b3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(201, 79, 43);
    glVertex2i(934, 145);
    glVertex2i(995, 145);
    glVertex2i(995, 252);
    glVertex2i(934, 252);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w1 b3
    glVertex2i(952, 235);
    glVertex2i(960, 235);
    glVertex2i(960, 245);
    glVertex2i(952, 245);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w2 b3
    glVertex2i(975, 235);
    glVertex2i(984, 235);
    glVertex2i(984, 245);
    glVertex2i(975, 245);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w3 b3
    glVertex2i(940, 220);
    glVertex2i(950, 220);
    glVertex2i(950, 230);
    glVertex2i(940, 230);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w4 b3
    glVertex2i(963, 220);
    glVertex2i(973, 220);
    glVertex2i(973, 232);
    glVertex2i(963, 232);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w5 b3
    glVertex2i(952, 205);
    glVertex2i(960, 205);
    glVertex2i(960, 215);
    glVertex2i(952, 215);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w6 b3
    glVertex2i(975, 205);
    glVertex2i(984, 205);
    glVertex2i(984, 215);
    glVertex2i(975, 215);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w7 b3
    glVertex2i(940, 190);
    glVertex2i(950, 190);
    glVertex2i(950, 200);
    glVertex2i(940, 200);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w8 b3
    glVertex2i(963, 190);
    glVertex2i(973, 190);
    glVertex2i(973, 200);
    glVertex2i(963, 200);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w9 b3
    glVertex2i(952, 180);
    glVertex2i(960, 180);
    glVertex2i(960, 190);
    glVertex2i(952, 190);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w10 b3
    glVertex2i(975, 180);
    glVertex2i(984, 180);
    glVertex2i(984, 190);
    glVertex2i(975, 190);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w11 b3
    glVertex2i(940, 165);
    glVertex2i(950, 165);
    glVertex2i(950, 175);
    glVertex2i(940, 175);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w12 b3
    glVertex2i(963, 165);
    glVertex2i(973, 165);
    glVertex2i(973, 175);
    glVertex2i(963, 175);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w13 b3
    glVertex2i(952, 150);
    glVertex2i(960, 150);
    glVertex2i(960, 160);
    glVertex2i(952, 160);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(198, 242, 237); //w14 b3
    glVertex2i(975, 150);
    glVertex2i(984, 150);
    glVertex2i(984, 160);
    glVertex2i(975, 160);
    glEnd();

    //4th building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(241, 219, 168);
    glVertex2i(1010, 147);
    glVertex2i(1025, 147);
    glVertex2i(1025, 208);
    glVertex2i(1010, 208);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(191, 83, 22); //deep oranger part b4
    glVertex2i(1025, 147);
    glVertex2i(1030, 147);
    glVertex2i(1030, 208);
    glVertex2i(1025, 208);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(232, 107, 37); //light oranger part b4
    glVertex2i(1030, 147);
    glVertex2i(1060, 147);
    glVertex2i(1060, 208);
    glVertex2i(1030, 208);
    glEnd();
    glBegin(GL_QUADS); //light brik 1
    glPointSize(10.0);
    glColor3ub(241, 219, 168);
    glVertex2i(1060, 147);
    glVertex2i(1074, 147);
    glVertex2i(1074, 208);
    glVertex2i(1060, 208);
    glEnd();
    glBegin(GL_QUADS); //light brik 2
    glPointSize(10.0);
    glColor3ub(241, 219, 168);
    glVertex2i(1060, 147);
    glVertex2i(1074, 147);
    glVertex2i(1074, 208);
    glVertex2i(1060, 208);
    glEnd();
    glBegin(GL_QUADS); //light brik square
    glPointSize(10.0);
    glColor3ub(241, 219, 168);
    glVertex2i(1010, 208);
    glVertex2i(1074, 208);
    glVertex2i(1074, 233);
    glVertex2i(1010, 233);
    glEnd();
    glBegin(GL_QUADS); //white border
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1010, 233);
    glVertex2i(1074, 233);
    glVertex2i(1074, 239);
    glVertex2i(1010, 239);
    glEnd();
    glBegin(GL_QUADS); //upper brik
    glPointSize(10.0);
    glColor3ub(241, 219, 168);
    glVertex2i(1010, 239);
    glVertex2i(1074, 239);
    glVertex2i(1074, 282);
    glVertex2i(1010, 282);
    glEnd();
    glBegin(GL_QUADS); //W1
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1018, 260);
    glVertex2i(1024, 260);
    glVertex2i(1024, 270);
    glVertex2i(1018, 270);
    glEnd();
    glBegin(GL_QUADS); //W2
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1028, 260);
    glVertex2i(1035, 260);
    glVertex2i(1035, 270);
    glVertex2i(1028, 270);
    glEnd();
    glBegin(GL_QUADS); //W3
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1038, 260);
    glVertex2i(1045, 260);
    glVertex2i(1045, 270);
    glVertex2i(1038, 270);
    glEnd();
    glBegin(GL_QUADS); //W4
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1048, 260);
    glVertex2i(1055, 260);
    glVertex2i(1055, 270);
    glVertex2i(1048, 270);
    glEnd();
    glBegin(GL_QUADS); //W5
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1018, 249);
    glVertex2i(1024, 249);
    glVertex2i(1024, 258);
    glVertex2i(1018, 258);
    glEnd();
    glBegin(GL_QUADS); //W6
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1028, 249);
    glVertex2i(1035, 249);
    glVertex2i(1035, 258);
    glVertex2i(1028, 258);
    glEnd();
    glBegin(GL_QUADS); //W6
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1038, 249);
    glVertex2i(1045, 249);
    glVertex2i(1045, 258);
    glVertex2i(1038, 258);
    glEnd();
    glBegin(GL_QUADS); //W7
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1038, 249);
    glVertex2i(1045, 249);
    glVertex2i(1045, 258);
    glVertex2i(1038, 258);
    glEnd();
    glBegin(GL_QUADS); //W8
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1048, 249);
    glVertex2i(1055, 249);
    glVertex2i(1055, 258);
    glVertex2i(1048, 258);
    glEnd();
    //uppper triangle
    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(121, 137, 109);
    glVertex2i(1010, 282);
    glVertex2i(1073, 282);
    glVertex2i(1053, 315);
    glEnd();
    glBegin(GL_QUADS); //deep border
    glPointSize(10.0);
    glColor3ub(44, 76, 63);
    glVertex2i(1010, 282);
    glVertex2i(1072, 282);
    glVertex2i(1072, 288);
    glVertex2i(1014, 288);
    glEnd();

    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(56, 83, 58);
    glVertex2i(1073, 282);
    glVertex2i(1097, 282);
    glVertex2i(1053, 315);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(203, 175, 98);
    glVertex2i(1074, 147);
    glVertex2i(1097, 147);
    glVertex2i(1097, 282);
    glVertex2i(1074, 282);
    glEnd();
    glBegin(GL_QUADS); //w1
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1080, 262);
    glVertex2i(1085, 262);
    glVertex2i(1085, 273);
    glVertex2i(1080, 273);
    glEnd();
    glBegin(GL_QUADS); //w2
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1088, 263);
    glVertex2i(1093, 263);
    glVertex2i(1093, 273);
    glVertex2i(1088, 273);
    glEnd();
    glBegin(GL_QUADS); //w3
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1080, 249);
    glVertex2i(1085, 249);
    glVertex2i(1085, 258);
    glVertex2i(1080, 258);
    glEnd();
    glBegin(GL_QUADS); //w4
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1088, 249);
    glVertex2i(1093, 249);
    glVertex2i(1093, 258);
    glVertex2i(1088, 258);
    glEnd();
    glBegin(GL_QUADS); //w5
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1080, 232);
    glVertex2i(1085, 232);
    glVertex2i(1085, 244);
    glVertex2i(1080, 244);
    glEnd();
    glBegin(GL_QUADS); //w6
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1088, 232);
    glVertex2i(1093, 232);
    glVertex2i(1093, 244);
    glVertex2i(1088, 244);
    glEnd();

    glBegin(GL_QUADS); //w7
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1080, 216);
    glVertex2i(1085, 216);
    glVertex2i(1085, 228);
    glVertex2i(1080, 228);
    glEnd();
    glBegin(GL_QUADS); //w8
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1088, 216);
    glVertex2i(1093, 216);
    glVertex2i(1093, 228);
    glVertex2i(1088, 228);
    glEnd();
    glBegin(GL_QUADS); //w9
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1080, 204);
    glVertex2i(1085, 204);
    glVertex2i(1085, 213);
    glVertex2i(1080, 213);
    glEnd();
    glBegin(GL_QUADS); //w10
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1088, 204);
    glVertex2i(1093, 204);
    glVertex2i(1093, 213);
    glVertex2i(1088, 213);
    glEnd();
    glBegin(GL_QUADS); //w11
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1080, 188);
    glVertex2i(1085, 188);
    glVertex2i(1085, 198);
    glVertex2i(1080, 198);
    glEnd();
    glBegin(GL_QUADS); //w12
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1088, 188);
    glVertex2i(1093, 188);
    glVertex2i(1093, 198);
    glVertex2i(1088, 198);
    glEnd();

    glBegin(GL_QUADS); //w13
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1080, 173);
    glVertex2i(1085, 173);
    glVertex2i(1085, 182);
    glVertex2i(1080, 182);
    glEnd();
    glBegin(GL_QUADS); //w14
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1088, 173);
    glVertex2i(1093, 173);
    glVertex2i(1093, 182);
    glVertex2i(1088, 182);
    glEnd();
    glBegin(GL_QUADS); //w15
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1080, 157);
    glVertex2i(1085, 157);
    glVertex2i(1085, 169);
    glVertex2i(1080, 169);
    glEnd();
    glBegin(GL_QUADS); //w16
    glPointSize(10.0);
    glColor3ub(255, 255, 255);
    glVertex2i(1088, 157);
    glVertex2i(1093, 157);
    glVertex2i(1093, 169);
    glVertex2i(1088, 169);
    glEnd();
    //5th building
    glBegin(GL_QUADS); //light part
    glPointSize(10.0);
    glColor3ub(159, 158, 58);
    glVertex2i(1108, 147);
    glVertex2i(1158, 147);
    glVertex2i(1158, 267);
    glVertex2i(1108, 267);
    glEnd();
    glBegin(GL_QUADS); //deep part
    glPointSize(10.0);
    glColor3ub(129, 130, 53);
    glVertex2i(1158, 147);
    glVertex2i(1186, 147);
    glVertex2i(1186, 300);
    glVertex2i(1158, 268);
    glEnd();
    glBegin(GL_QUADS); //deep blue
    glPointSize(10.0);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 267);
    glVertex2i(1158, 267);
    glVertex2i(1186, 300);
    glVertex2i(1136, 300);
    glEnd();
    //shade
    glBegin(GL_LINES); //1
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 255);
    glVertex2i(1158, 255);
    glVertex2i(1117, 147);
    glVertex2i(1117, 267);
    glEnd();

    glBegin(GL_LINES); //2
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 245);
    glVertex2i(1158, 245);
    glVertex2i(1125, 147);
    glVertex2i(1125, 266);
    glEnd();

    glBegin(GL_LINES); //3
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 233);
    glVertex2i(1158, 233);
    glVertex2i(1135, 147);
    glVertex2i(1135, 266);
    glEnd();

    glBegin(GL_LINES); //4
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 222);
    glVertex2i(1158, 222);
    glVertex2i(1145, 147);
    glVertex2i(1145, 266);
    glEnd();
    glBegin(GL_LINES); //5
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 212);
    glVertex2i(1158, 212);
    glVertex2i(1135, 147);
    glVertex2i(1135, 266);
    glEnd();
    glBegin(GL_LINES); //6
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 202);
    glVertex2i(1158, 202);
    glEnd();
    glBegin(GL_LINES); //7
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 192);
    glVertex2i(1158, 192);
    glEnd();
    glBegin(GL_LINES); //8
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 182);
    glVertex2i(1158, 182);
    glEnd();
    glBegin(GL_LINES); //9
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 172);
    glVertex2i(1158, 172);
    glEnd();
    glBegin(GL_LINES); //10
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 162);
    glVertex2i(1158, 162);
    glEnd();
    glBegin(GL_LINES); //11
    glLineWidth(10);
    glColor3ub(199, 192, 49);
    glVertex2i(1108, 152);
    glVertex2i(1158, 152);
    glEnd();
}
void NightTime()
{
    ///---------------------Mahjabin-----------------------///

    //1st building

    glBegin(GL_POLYGON); ///tarrace
    glPointSize(10.0);
    glColor3ub(9, 26, 34);
    glVertex2i(310, 250);
    glVertex2i(395, 250);
    glVertex2i(387, 262);
    glVertex2i(318, 262);
    glEnd();

    glBegin(GL_QUADS); ///bar
    glPointSize(10.0);
    glColor3ub(0, 82, 132);
    glVertex2i(305, 245);
    glVertex2i(400, 245);
    glVertex2i(397, 250);
    glVertex2i(306, 250);

    glBegin(GL_QUADS); ///body
    glPointSize(10.0);
    glColor3ub(0, 125, 163);
    glVertex2i(310, 145);
    glVertex2i(395, 145);
    glVertex2i(395, 245);
    glVertex2i(310, 245);
    glEnd();

    glBegin(GL_QUADS); ///middle bar
    glPointSize(10.0);
    glColor3ub(38, 41, 22);
    glVertex2i(310, 212);
    glVertex2i(395, 212);
    glVertex2i(395, 217);
    glVertex2i(310, 217);
    glEnd();

    glBegin(GL_QUADS); ///1st window
    glPointSize(10.0);
    glColor3ub(204, 149, 60);
    glVertex2i(322, 217);
    glVertex2i(336, 217);
    glVertex2i(336, 238);
    glVertex2i(322, 238);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(322, 232);
    glVertex2i(336, 232);
    glVertex2i(322, 222);
    glVertex2i(336, 222);
    glVertex2i(330, 238);
    glVertex2i(330, 218);
    glEnd();

    glBegin(GL_QUADS); ///2nd window
    glPointSize(10.0);
    glColor3ub(204, 149, 60);
    glVertex2i(345, 217);
    glVertex2i(357, 217);
    glVertex2i(357, 238);
    glVertex2i(345, 238);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(345, 232);
    glVertex2i(358, 232);
    glVertex2i(345, 222);
    glVertex2i(358, 222);
    glVertex2i(352, 238);
    glVertex2i(352, 218);
    glEnd();

    glBegin(GL_QUADS); ///3rd window
    glPointSize(10.0);
    glColor3ub(204, 149, 60);
    glVertex2i(368, 217);
    glVertex2i(381, 217);
    glVertex2i(381, 238);
    glVertex2i(368, 238);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(368, 232);
    glVertex2i(382, 232);
    glVertex2i(368, 222);
    glVertex2i(382, 222);
    glVertex2i(375, 238);
    glVertex2i(375, 218);
    glEnd();

    glBegin(GL_QUADS); ///4th window
    glPointSize(10.0);
    glColor3ub(2, 20, 30);
    glVertex2i(335, 185);
    glVertex2i(345, 185);
    glVertex2i(345, 205);
    glVertex2i(335, 205);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(335, 200);
    glVertex2i(345, 200);
    glVertex2i(335, 191);
    glVertex2i(345, 191);
    glVertex2i(340, 205);
    glVertex2i(340, 185);
    glEnd();

    glBegin(GL_QUADS); ///5th window
    glPointSize(10.0);
    glColor3ub(2, 20, 30);
    glVertex2i(355, 185);
    glVertex2i(370, 185);
    glVertex2i(370, 205);
    glVertex2i(355, 205);
    glEnd();
    ///---------------------Asraf-----------------------///
    //yellow building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(10, 44, 76);
    glVertex2i(0, 145);
    glVertex2i(20, 145);
    glVertex2i(20, 260);
    glVertex2i(0, 260);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 12, 27);
    glVertex2i(0, 260);
    glVertex2i(20, 260);
    glVertex2i(20, 266);
    glVertex2i(0, 266);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(11, 132, 157);
    glVertex2i(20, 145);
    glVertex2i(64, 145);
    glVertex2i(64, 260);
    glVertex2i(20, 260);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(74, 160, 206);
    glVertex2i(20, 260);
    glVertex2i(64, 260);
    glVertex2i(64, 266);
    glVertex2i(20, 266);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(25, 237);
    glVertex2i(33, 237);
    glVertex2i(33, 250);
    glVertex2i(25, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(25, 250);
    glVertex2i(33, 250);
    glVertex2i(33, 253);
    glVertex2i(25, 253);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(37, 237);
    glVertex2i(45, 237);
    glVertex2i(45, 250);
    glVertex2i(37, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(37, 250);
    glVertex2i(45, 250);
    glVertex2i(45, 253);
    glVertex2i(37, 253);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(50, 237);
    glVertex2i(58, 237);
    glVertex2i(58, 250);
    glVertex2i(50, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(50, 250);
    glVertex2i(58, 250);
    glVertex2i(58, 253);
    glVertex2i(50, 253);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(25, 215);
    glVertex2i(33, 215);
    glVertex2i(33, 228);
    glVertex2i(25, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(25, 228);
    glVertex2i(33, 228);
    glVertex2i(33, 231);
    glVertex2i(25, 231);
    glEnd();

    //window 5

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(37, 215);
    glVertex2i(45, 215);
    glVertex2i(45, 228);
    glVertex2i(37, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(37, 228);
    glVertex2i(45, 228);
    glVertex2i(45, 231);
    glVertex2i(37, 231);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(50, 215);
    glVertex2i(58, 215);
    glVertex2i(58, 228);
    glVertex2i(50, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(50, 228);
    glVertex2i(58, 228);
    glVertex2i(58, 231);
    glVertex2i(50, 231);
    glEnd();

    //window 7
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(25, 195);
    glVertex2i(33, 195);
    glVertex2i(33, 208);
    glVertex2i(25, 208);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(25, 207);
    glVertex2i(33, 207);
    glVertex2i(33, 210);
    glVertex2i(25, 210);
    glEnd();

    //window 8

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(37, 195);
    glVertex2i(45, 195);
    glVertex2i(45, 208);
    glVertex2i(37, 208);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(37, 207);
    glVertex2i(45, 207);
    glVertex2i(45, 210);
    glVertex2i(37, 210);
    glEnd();

    //window 9

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(50, 195);
    glVertex2i(58, 195);
    glVertex2i(58, 208);
    glVertex2i(50, 208);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(50, 207);
    glVertex2i(58, 207);
    glVertex2i(58, 210);
    glVertex2i(50, 210);
    glEnd();

    //window 10
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(25, 175);
    glVertex2i(33, 175);
    glVertex2i(33, 188);
    glVertex2i(25, 188);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(25, 188);
    glVertex2i(33, 188);
    glVertex2i(33, 191);
    glVertex2i(25, 191);
    glEnd();

    //green building

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(14, 12, 11);
    glVertex2i(90, 150);
    glVertex2i(100, 150);
    glVertex2i(100, 275);
    glVertex2i(90, 275);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(14, 12, 11);
    glVertex2i(85, 270);
    glVertex2i(95, 270);
    glVertex2i(95, 280);
    glVertex2i(85, 280);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(18, 73, 139);
    glVertex2i(100, 150);
    glVertex2i(160, 150);
    glVertex2i(160, 275);
    glVertex2i(100, 275);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(18, 73, 139);
    glVertex2i(90, 275);
    glVertex2i(165, 275);
    glVertex2i(165, 280);
    glVertex2i(90, 280);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(104, 245);
    glVertex2i(118, 245);
    glVertex2i(118, 265);
    glVertex2i(104, 265);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(0, 5, 5);
    glVertex2i(104, 255);
    glVertex2i(118, 255);
    glVertex2i(111, 245);
    glVertex2i(111, 265);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(124, 245);
    glVertex2i(138, 245);
    glVertex2i(138, 265);
    glVertex2i(124, 265);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(0, 5, 5);
    glVertex2i(124, 255);
    glVertex2i(138, 255);
    glVertex2i(131, 245);
    glVertex2i(131, 265);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(142, 245);
    glVertex2i(156, 245);
    glVertex2i(156, 265);
    glVertex2i(142, 265);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(0, 5, 5);
    glVertex2i(142, 255);
    glVertex2i(156, 255);
    glVertex2i(149, 245);
    glVertex2i(149, 265);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(8, 59, 135);
    glVertex2i(100, 237);
    glVertex2i(160, 237);
    glVertex2i(160, 240);
    glVertex2i(100, 240);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(104, 215);
    glVertex2i(118, 215);
    glVertex2i(118, 235);
    glVertex2i(104, 235);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(0, 5, 5);
    glVertex2i(104, 225);
    glVertex2i(118, 225);
    glVertex2i(111, 215);
    glVertex2i(111, 235);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(124, 215);
    glVertex2i(138, 215);
    glVertex2i(138, 235);
    glVertex2i(124, 235);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(124, 225);
    glVertex2i(138, 225);
    glVertex2i(131, 215);
    glVertex2i(131, 235);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 5, 5);
    glVertex2i(142, 215);
    glVertex2i(156, 215);
    glVertex2i(156, 235);
    glVertex2i(142, 235);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(0, 5, 5);
    glVertex2i(142, 225);
    glVertex2i(156, 225);
    glVertex2i(149, 215);
    glVertex2i(149, 235);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(8, 59, 135);
    glVertex2i(100, 207);
    glVertex2i(160, 207);
    glVertex2i(160, 210);
    glVertex2i(100, 210);
    glEnd();

    //window 7
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(104, 185);
    glVertex2i(118, 185);
    glVertex2i(118, 205);
    glVertex2i(104, 205);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(104, 195);
    glVertex2i(118, 195);
    glVertex2i(111, 185);
    glVertex2i(111, 205);
    glEnd();

    //window 8
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(124, 185);
    glVertex2i(138, 185);
    glVertex2i(138, 205);
    glVertex2i(124, 205);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(124, 195);
    glVertex2i(138, 195);
    glVertex2i(131, 185);
    glVertex2i(131, 205);
    glEnd();

    //window 9
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(135, 173, 149);
    glVertex2i(142, 185);
    glVertex2i(156, 185);
    glVertex2i(156, 205);
    glVertex2i(142, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(107, 131, 125);
    glVertex2i(100, 177);
    glVertex2i(160, 177);
    glVertex2i(160, 180);
    glVertex2i(100, 180);
    glEnd();

    //red building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(17, 44, 76);
    glVertex2i(228, 145);
    glVertex2i(237, 145);
    glVertex2i(237, 310);
    glVertex2i(228, 310);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(17, 44, 76);
    glVertex2i(227, 305);
    glVertex2i(232, 305);
    glVertex2i(232, 315);
    glVertex2i(227, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 112, 166);
    glVertex2i(237, 145);
    glVertex2i(300, 145);
    glVertex2i(300, 310);
    glVertex2i(237, 310);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 112, 166);
    glVertex2i(232, 310);
    glVertex2i(305, 310);
    glVertex2i(305, 315);
    glVertex2i(232, 315);
    glEnd();

    //window 1

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(250, 270);
    glVertex2i(262, 270);
    glVertex2i(262, 295);
    glVertex2i(250, 295);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(250, 285);
    glVertex2i(262, 285);
    glVertex2i(256, 270);
    glVertex2i(256, 295);
    glEnd();
    //window 2

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(267, 270);
    glVertex2i(279, 270);
    glVertex2i(279, 295);
    glVertex2i(267, 295);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(267, 285);
    glVertex2i(279, 285);
    glVertex2i(273, 270);
    glVertex2i(273, 295);
    glEnd();

    //window 3

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(284, 270);
    glVertex2i(296, 270);
    glVertex2i(296, 295);
    glVertex2i(284, 295);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(284, 285);
    glVertex2i(296, 285);
    glVertex2i(290, 270);
    glVertex2i(290, 295);
    glEnd();

    //window 4

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(250, 235);
    glVertex2i(262, 235);
    glVertex2i(262, 260);
    glVertex2i(250, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(250, 250);
    glVertex2i(262, 250);
    glVertex2i(256, 235);
    glVertex2i(256, 260);
    glEnd();

    //window 5

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(267, 235);
    glVertex2i(279, 235);
    glVertex2i(279, 260);
    glVertex2i(267, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(267, 250);
    glVertex2i(279, 250);
    glVertex2i(273, 235);
    glVertex2i(273, 260);
    glEnd();

    //window 6

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(284, 235);
    glVertex2i(296, 235);
    glVertex2i(296, 260);
    glVertex2i(284, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(284, 250);
    glVertex2i(296, 250);
    glVertex2i(290, 235);
    glVertex2i(290, 260);
    glEnd();

    //window 7

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(250, 195);
    glVertex2i(262, 195);
    glVertex2i(262, 220);
    glVertex2i(250, 220);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(250, 210);
    glVertex2i(262, 210);
    glVertex2i(256, 195);
    glVertex2i(256, 220);
    glEnd();

    //window 8

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(267, 195);
    glVertex2i(279, 195);
    glVertex2i(279, 220);
    glVertex2i(267, 220);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(267, 210);
    glVertex2i(279, 210);
    glVertex2i(273, 195);
    glVertex2i(273, 220);
    glEnd();

    //window 9

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(284, 195);
    glVertex2i(296, 195);
    glVertex2i(296, 220);
    glVertex2i(284, 220);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(151, 93, 17);
    glVertex2i(284, 210);
    glVertex2i(296, 210);
    glVertex2i(290, 195);
    glVertex2i(290, 220);
    glEnd();

    //yellow building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(15, 48, 82);
    glVertex2i(130, 145);
    glVertex2i(180, 145);
    glVertex2i(180, 210);
    glVertex2i(130, 210);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(17, 13, 21);
    glVertex2i(127, 210);
    glVertex2i(180, 210);
    glVertex2i(180, 218);
    glVertex2i(127, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(4, 92, 126);
    glVertex2i(180, 145);
    glVertex2i(230, 145);
    glVertex2i(230, 210);
    glVertex2i(180, 210);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(113, 194, 228);
    glVertex2i(180, 210);
    glVertex2i(232, 210);
    glVertex2i(232, 218);
    glVertex2i(180, 218);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(132, 195);
    glVertex2i(137, 195);
    glVertex2i(137, 203);
    glVertex2i(132, 203);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(139, 195);
    glVertex2i(144, 195);
    glVertex2i(144, 203);
    glVertex2i(139, 203);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(146, 195);
    glVertex2i(151, 195);
    glVertex2i(151, 203);
    glVertex2i(146, 203);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(153, 195);
    glVertex2i(158, 195);
    glVertex2i(158, 203);
    glVertex2i(153, 203);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(160, 195);
    glVertex2i(165, 195);
    glVertex2i(165, 203);
    glVertex2i(160, 203);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(167, 195);
    glVertex2i(172, 195);
    glVertex2i(172, 203);
    glVertex2i(167, 203);
    glEnd();

    //window 7
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(132, 180);
    glVertex2i(137, 180);
    glVertex2i(137, 188);
    glVertex2i(132, 188);
    glEnd();

    //window 8
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(139, 180);
    glVertex2i(144, 180);
    glVertex2i(144, 188);
    glVertex2i(139, 188);
    glEnd();

    //window 9
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(146, 180);
    glVertex2i(151, 180);
    glVertex2i(151, 188);
    glVertex2i(146, 188);
    glEnd();

    //window 10
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(153, 180);
    glVertex2i(158, 180);
    glVertex2i(158, 188);
    glVertex2i(153, 188);
    glEnd();

    //window 11
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(160, 180);
    glVertex2i(165, 180);
    glVertex2i(165, 188);
    glVertex2i(160, 188);
    glEnd();

    //window 12
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(167, 180);
    glVertex2i(172, 180);
    glVertex2i(172, 188);
    glVertex2i(167, 188);
    glEnd();

    //window 13
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(132, 165);
    glVertex2i(137, 165);
    glVertex2i(137, 173);
    glVertex2i(132, 173);
    glEnd();

    //window 14
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(139, 165);
    glVertex2i(144, 165);
    glVertex2i(144, 173);
    glVertex2i(139, 173);
    glEnd();

    //window 15
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(146, 165);
    glVertex2i(151, 165);
    glVertex2i(151, 173);
    glVertex2i(146, 173);
    glEnd();

    //window 16
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(153, 165);
    glVertex2i(158, 165);
    glVertex2i(158, 173);
    glVertex2i(153, 173);
    glEnd();

    //window 17
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(160, 165);
    glVertex2i(165, 165);
    glVertex2i(165, 173);
    glVertex2i(160, 173);
    glEnd();

    //window 18
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 17, 14);
    glVertex2i(167, 165);
    glVertex2i(172, 165);
    glVertex2i(172, 173);
    glVertex2i(167, 173);
    glEnd();

    //window 19
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(132, 150);
    glVertex2i(137, 150);
    glVertex2i(137, 158);
    glVertex2i(132, 158);
    glEnd();

    //window 20
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(139, 150);
    glVertex2i(144, 150);
    glVertex2i(144, 158);
    glVertex2i(139, 158);
    glEnd();

    //window 21
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(146, 150);
    glVertex2i(151, 150);
    glVertex2i(151, 158);
    glVertex2i(146, 158);
    glEnd();

    //window 22
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(153, 150);
    glVertex2i(158, 150);
    glVertex2i(158, 158);
    glVertex2i(153, 158);
    glEnd();

    //window 23
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(160, 150);
    glVertex2i(165, 150);
    glVertex2i(165, 158);
    glVertex2i(160, 158);
    glEnd();

    //window 24
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 168, 49);
    glVertex2i(167, 150);
    glVertex2i(172, 150);
    glVertex2i(172, 158);
    glVertex2i(167, 158);
    glEnd();

    //pink building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 105, 157);
    glVertex2i(35, 140);
    glVertex2i(125, 140);
    glVertex2i(125, 185);
    glVertex2i(35, 185);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(50, 27, 87);
    glVertex2i(30, 140);
    glVertex2i(40, 140);
    glVertex2i(40, 205);
    glVertex2i(30, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(50, 27, 87);
    glVertex2i(65, 185);
    glVertex2i(80, 185);
    glVertex2i(80, 205);
    glVertex2i(65, 205);
    glEnd();

    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(0, 105, 157);
    glVertex2i(40, 185);
    glVertex2i(75, 185);
    glVertex2i(40, 205);
    glEnd();

    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(0, 105, 157);
    glVertex2i(78, 185);
    glVertex2i(120, 185);
    glVertex2i(78, 205);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(50, 27, 87);
    glVertex2i(50, 152);
    glVertex2i(65, 152);
    glVertex2i(65, 170);
    glVertex2i(50, 170);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(234, 157, 60);
    glVertex2i(50, 170);
    glVertex2i(65, 170);
    glVertex2i(65, 174);
    glVertex2i(50, 174);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(50, 27, 87);
    glVertex2i(75, 172);
    glVertex2i(80, 172);
    glVertex2i(80, 178);
    glVertex2i(75, 178);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(234, 157, 60);
    glVertex2i(75, 178);
    glVertex2i(80, 178);
    glVertex2i(80, 180);
    glVertex2i(75, 180);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(50, 27, 87);
    glVertex2i(83, 172);
    glVertex2i(88, 172);
    glVertex2i(88, 178);
    glVertex2i(83, 178);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(234, 157, 60);
    glVertex2i(83, 178);
    glVertex2i(88, 178);
    glVertex2i(88, 180);
    glVertex2i(83, 180);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(50, 27, 87);
    glVertex2i(83, 162);
    glVertex2i(88, 162);
    glVertex2i(88, 168);
    glVertex2i(83, 168);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(234, 157, 60);
    glVertex2i(83, 168);
    glVertex2i(88, 168);
    glVertex2i(88, 170);
    glVertex2i(83, 170);
    glEnd();

    //window 5

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(50, 27, 87);
    glVertex2i(91, 162);
    glVertex2i(96, 162);
    glVertex2i(96, 168);
    glVertex2i(91, 168);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(234, 157, 60);
    glVertex2i(91, 168);
    glVertex2i(96, 168);
    glVertex2i(96, 170);
    glVertex2i(91, 170);

    glEnd();
    ///---------------------Mahjabin-----------------------///
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(355, 200);
    glVertex2i(370, 200);
    glVertex2i(355, 191);
    glVertex2i(370, 191);
    glVertex2i(363, 205);
    glVertex2i(363, 185);
    glEnd();

    glBegin(GL_QUADS); ///door
    glPointSize(10.0);
    glColor3ub(13, 42, 84);
    glVertex2i(328, 152);
    glVertex2i(376, 152);
    glVertex2i(376, 170);
    glVertex2i(328, 170);
    glEnd();

    glBegin(GL_QUADS); ///door
    glPointSize(10.0);
    glColor3ub(0, 87, 112);
    glVertex2i(328, 144);
    glVertex2i(376, 144);
    glVertex2i(376, 146);
    glVertex2i(328, 146);
    glEnd();

    glBegin(GL_QUADS); ///door
    glPointSize(10.0);
    glColor3ub(0, 87, 112);
    glVertex2i(328, 146);
    glVertex2i(376, 146);
    glVertex2i(376, 152);
    glVertex2i(328, 152);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(376, 152);
    glVertex2i(376, 170);
    glVertex2i(376, 170);
    glVertex2i(328, 170);
    glVertex2i(328, 170);
    glVertex2i(328, 152);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(376, 144);
    glVertex2i(376, 152);
    glVertex2i(328, 152);
    glVertex2i(328, 144);
    glVertex2i(350, 170);
    glVertex2i(350, 144);
    glEnd();

    //2nd building

    glBegin(GL_QUADS); ///side bar
    glPointSize(10.0);
    glColor3ub(7, 26, 33);
    glVertex2i(405, 145);
    glVertex2i(430, 145);
    glVertex2i(430, 330);
    glVertex2i(405, 330);
    glEnd();

    glBegin(GL_QUADS); ///main
    glPointSize(10.0);
    glColor3ub(34, 135, 197);
    glVertex2i(430, 145);
    glVertex2i(485, 145);
    glVertex2i(485, 330);
    glVertex2i(430, 330);
    glEnd();

    glBegin(GL_QUADS); ///top_side bar
    glPointSize(10.0);
    glColor3ub(16, 17, 8);
    glVertex2i(405, 330);
    glVertex2i(430, 330);
    glVertex2i(430, 336);
    glVertex2i(405, 336);
    glEnd();

    glBegin(GL_QUADS); ///top bottom bar
    glPointSize(10.0);
    glColor3ub(37, 142, 196);
    glVertex2i(430, 330);
    glVertex2i(485, 330);
    glVertex2i(485, 336);
    glVertex2i(430, 336);
    glEnd();

    glBegin(GL_QUADS); ///1st window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(436, 305);
    glVertex2i(446, 305);
    glVertex2i(446, 315);
    glVertex2i(436, 315);
    glEnd();

    glBegin(GL_QUADS); ///1st window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(436, 316);
    glVertex2i(446, 316);
    glVertex2i(446, 318);
    glVertex2i(436, 318);
    glEnd();

    glBegin(GL_QUADS); ///2nd window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(450, 305);
    glVertex2i(460, 305);
    glVertex2i(460, 315);
    glVertex2i(450, 315);
    glEnd();

    glBegin(GL_QUADS); ///2nd window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(450, 316);
    glVertex2i(460, 316);
    glVertex2i(460, 318);
    glVertex2i(450, 318);
    glEnd();

    glBegin(GL_QUADS); ///3rd window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(465, 305);
    glVertex2i(475, 305);
    glVertex2i(475, 315);
    glVertex2i(465, 315);
    glEnd();

    glBegin(GL_QUADS); ///3rd window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(465, 316);
    glVertex2i(475, 316);
    glVertex2i(475, 318);
    glVertex2i(465, 318);
    glEnd();

    glBegin(GL_QUADS); ///bottom bar
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 299);
    glVertex2i(475, 299);
    glVertex2i(475, 302);
    glVertex2i(435, 302);
    glEnd();

    glBegin(GL_QUADS); ///4th window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(435, 265);
    glVertex2i(445, 265);
    glVertex2i(445, 275);
    glVertex2i(435, 275);
    glEnd();

    glBegin(GL_QUADS); ///4th window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(435, 275);
    glVertex2i(445, 275);
    glVertex2i(445, 277);
    glVertex2i(435, 277);
    glEnd();

    glBegin(GL_QUADS); ///6th window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(465, 265);
    glVertex2i(475, 265);
    glVertex2i(475, 275);
    glVertex2i(465, 275);
    glEnd();

    glBegin(GL_QUADS); ///6th window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(465, 275);
    glVertex2i(475, 275);
    glVertex2i(475, 277);
    glVertex2i(465, 277);
    glEnd();

    glBegin(GL_QUADS); ///5th window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(450, 265);
    glVertex2i(460, 265);
    glVertex2i(460, 275);
    glVertex2i(450, 275);
    glEnd();

    glBegin(GL_QUADS); ///5th window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(450, 275);
    glVertex2i(460, 275);
    glVertex2i(460, 277);
    glVertex2i(450, 277);
    glEnd();

    glBegin(GL_QUADS); ///2nd bottom bar
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 262);
    glVertex2i(475, 262);
    glVertex2i(475, 259);
    glVertex2i(435, 259);
    glEnd();

    glBegin(GL_QUADS); ///7th window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(435, 220);
    glVertex2i(445, 220);
    glVertex2i(445, 230);
    glVertex2i(435, 230);
    glEnd();

    glBegin(GL_QUADS); ///7th window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(435, 231);
    glVertex2i(445, 231);
    glVertex2i(445, 233);
    glVertex2i(435, 233);
    glEnd();

    glBegin(GL_QUADS); ///8th window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(450, 220);
    glVertex2i(460, 220);
    glVertex2i(460, 230);
    glVertex2i(450, 230);
    glEnd();

    glBegin(GL_QUADS); ///8th window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(450, 231);
    glVertex2i(460, 231);
    glVertex2i(460, 233);
    glVertex2i(450, 233);
    glEnd();

    glBegin(GL_QUADS); ///9th window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(465, 220);
    glVertex2i(475, 220);
    glVertex2i(475, 230);
    glVertex2i(465, 230);
    glEnd();

    glBegin(GL_QUADS); ///9th window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(465, 231);
    glVertex2i(475, 231);
    glVertex2i(475, 233);
    glVertex2i(465, 233);
    glEnd();

    glBegin(GL_QUADS); ///3rd bottom bar
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 214);
    glVertex2i(475, 214);
    glVertex2i(475, 217);
    glVertex2i(435, 217);
    glEnd();

    glBegin(GL_QUADS); ///10th window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(465, 175);
    glVertex2i(475, 175);
    glVertex2i(475, 185);
    glVertex2i(465, 185);
    glEnd();

    glBegin(GL_QUADS); ///10th window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(465, 186);
    glVertex2i(475, 186);
    glVertex2i(475, 188);
    glVertex2i(465, 188);
    glEnd();

    glBegin(GL_QUADS); ///11th window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(435, 175);
    glVertex2i(445, 175);
    glVertex2i(445, 185);
    glVertex2i(435, 185);
    glEnd();

    glBegin(GL_QUADS); ///11th window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(435, 186);
    glVertex2i(445, 186);
    glVertex2i(445, 188);
    glVertex2i(435, 188);
    glEnd();

    glBegin(GL_QUADS); ///12th window
    glPointSize(10.0);
    glColor3ub(5, 45, 74);
    glVertex2i(450, 175);
    glVertex2i(460, 175);
    glVertex2i(460, 185);
    glVertex2i(450, 185);
    glEnd();

    glBegin(GL_QUADS); ///12th window bar
    glPointSize(10.0);
    glColor3ub(206, 140, 77);
    glVertex2i(450, 186);
    glVertex2i(460, 186);
    glVertex2i(460, 188);
    glVertex2i(450, 188);
    glEnd();

    glBegin(GL_QUADS); ///last bottom bar
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(435, 170);
    glVertex2i(475, 170);
    glVertex2i(475, 173);
    glVertex2i(435, 173);
    glEnd();

    //3rd building

    glBegin(GL_TRIANGLES); ///left triangle
    glPointSize(10.0);
    glColor3ub(9, 43, 72);
    glVertex2i(492, 280);
    glVertex2i(540, 280);
    glVertex2i(535, 312);
    glEnd();

    glBegin(GL_TRIANGLES); ///right trio
    glPointSize(10.0);
    glColor3ub(108, 181, 224);
    glVertex2i(540, 280);
    glVertex2i(580, 280);
    glVertex2i(535, 312);
    glEnd();

    glBegin(GL_QUADS); ///left body
    glPointSize(10.0);
    glColor3ub(12, 46, 80);
    glVertex2i(495, 145);
    glVertex2i(540, 145);
    glVertex2i(540, 280);
    glVertex2i(495, 280);
    glEnd();

    glBegin(GL_QUADS); ///right body
    glPointSize(10.0);
    glColor3ub(7, 134, 181);
    glVertex2i(540, 145);
    glVertex2i(580, 145);
    glVertex2i(580, 280);
    glVertex2i(540, 280);
    glEnd();

    glBegin(GL_QUADS); ///left inB
    glPointSize(10.0);
    glColor3ub(12, 46, 80);
    glVertex2i(500, 170);
    glVertex2i(535, 170);
    glVertex2i(535, 275);
    glVertex2i(500, 275);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 270);
    glVertex2i(535, 270);
    glEnd();

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 260);
    glVertex2i(535, 260);
    glEnd(); //2

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 250);
    glVertex2i(535, 250);
    glEnd(); //3

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 240);
    glVertex2i(535, 240);
    glEnd(); //4

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 230);
    glVertex2i(535, 230);
    glEnd(); //5

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 220);
    glVertex2i(535, 220);
    glEnd(); //6

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 210);
    glVertex2i(535, 210);
    glEnd(); //7

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 200);
    glVertex2i(535, 200);
    glEnd(); //8

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 190);
    glVertex2i(535, 190);
    glEnd(); //9

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 180);
    glVertex2i(535, 180);
    glEnd(); //10

    glBegin(GL_LINES); ///row
    glColor3ub(0, 0, 0);
    glVertex2i(495, 170);
    glVertex2i(535, 170);
    glEnd(); //11

    glBegin(GL_LINES); ///column
    glColor3ub(0, 0, 0);
    glVertex2i(500, 275);
    glVertex2i(500, 170);
    glEnd(); //1

    glBegin(GL_LINES); ///column
    glColor3ub(0, 0, 0);
    glVertex2i(505, 275);
    glVertex2i(505, 170);
    glEnd(); //2

    glBegin(GL_LINES); ///column
    glColor3ub(0, 0, 0);
    glVertex2i(510, 275);
    glVertex2i(510, 170);
    glEnd(); //3

    glBegin(GL_LINES); ///column
    glColor3ub(0, 0, 0);
    glVertex2i(515, 275);
    glVertex2i(515, 170);
    glEnd(); //4

    glBegin(GL_LINES); ///column
    glColor3ub(0, 0, 0);
    glVertex2i(520, 275);
    glVertex2i(520, 170);
    glEnd(); //5

    glBegin(GL_LINES); ///column
    glColor3ub(0, 0, 0);
    glVertex2i(525, 275);
    glVertex2i(525, 170);
    glEnd(); //6

    glBegin(GL_LINES); ///column
    glColor3ub(0, 0, 0);
    glVertex2i(530, 275);
    glVertex2i(530, 170);
    glEnd();

    glBegin(GL_LINES); ///column
    glColor3ub(0, 0, 0);
    glVertex2i(535, 275);
    glVertex2i(535, 170);
    glEnd();

    glBegin(GL_QUADS); ///right inB
    glPointSize(10.0);
    glColor3ub(7, 134, 181);
    glVertex2i(545, 150);
    glVertex2i(575, 150);
    glVertex2i(575, 275);
    glVertex2i(545, 275);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 270);
    glVertex2i(575, 270);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 265);
    glVertex2i(575, 265);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 260);
    glVertex2i(575, 260);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 255);
    glVertex2i(575, 255);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 250);
    glVertex2i(575, 250);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 245);
    glVertex2i(575, 245);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 240);
    glVertex2i(575, 240);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 235);
    glVertex2i(575, 235);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 230);
    glVertex2i(575, 230);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 225);
    glVertex2i(575, 225);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 220);
    glVertex2i(575, 220);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 215);
    glVertex2i(575, 215);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 210);
    glVertex2i(575, 210);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 205);
    glVertex2i(575, 205);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 200);
    glVertex2i(575, 200);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 195);
    glVertex2i(575, 195);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 190);
    glVertex2i(575, 190);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 185);
    glVertex2i(575, 185);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 180);
    glVertex2i(575, 180);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 175);
    glVertex2i(575, 175);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 170);
    glVertex2i(575, 170);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 165);
    glVertex2i(575, 165);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 160);
    glVertex2i(575, 160);
    glEnd();

    glBegin(GL_LINES); //1
    glColor3ub(21, 69, 89);
    glVertex2i(545, 155);
    glVertex2i(575, 155);
    glEnd();

    //5th building

    glBegin(GL_QUADS); ///front
    glPointSize(10.0);
    glColor3ub(4, 110, 150);
    glVertex2i(645, 165);
    glVertex2i(705, 165);
    glVertex2i(705, 330);
    glVertex2i(645, 330);
    glEnd();

    glBegin(GL_QUADS); ///back
    glPointSize(10.0);
    glColor3ub(6, 45, 69);
    glVertex2i(705, 270);
    glVertex2i(725, 270);
    glVertex2i(725, 330);
    glVertex2i(705, 330);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(705, 330);
    glVertex2i(726, 330);
    glVertex2i(726, 335);
    glVertex2i(705, 335);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(2, 111, 154);
    glVertex2i(642, 330);
    glVertex2i(705, 330);
    glVertex2i(705, 335);
    glVertex2i(642, 335);
    glEnd();

    //1st
    glBegin(GL_QUADS); ///window1
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(650, 300);
    glVertex2i(660, 300);
    glVertex2i(660, 315);
    glVertex2i(650, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(650, 315);
    glVertex2i(660, 315);
    glVertex2i(660, 318);
    glVertex2i(650, 318);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(650, 270);
    glVertex2i(660, 270);
    glVertex2i(660, 285);
    glVertex2i(650, 285);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(650, 285);
    glVertex2i(660, 285);
    glVertex2i(660, 288);
    glVertex2i(650, 288);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(650, 240);
    glVertex2i(660, 240);
    glVertex2i(660, 255);
    glVertex2i(650, 255);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(650, 255);
    glVertex2i(660, 255);
    glVertex2i(660, 258);
    glVertex2i(650, 258);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(650, 210);
    glVertex2i(660, 210);
    glVertex2i(660, 225);
    glVertex2i(650, 225);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(650, 225);
    glVertex2i(660, 225);
    glVertex2i(660, 228);
    glVertex2i(650, 228);
    glEnd();

    //2nd
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(670, 300);
    glVertex2i(680, 300);
    glVertex2i(680, 315);
    glVertex2i(670, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(670, 315);
    glVertex2i(680, 315);
    glVertex2i(680, 318);
    glVertex2i(670, 318);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(670, 270);
    glVertex2i(680, 270);
    glVertex2i(680, 285);
    glVertex2i(670, 285);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(670, 285);
    glVertex2i(680, 285);
    glVertex2i(680, 288);
    glVertex2i(670, 288);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(670, 240);
    glVertex2i(680, 240);
    glVertex2i(680, 255);
    glVertex2i(670, 255);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(670, 255);
    glVertex2i(680, 255);
    glVertex2i(680, 258);
    glVertex2i(670, 258);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(670, 210);
    glVertex2i(680, 210);
    glVertex2i(680, 225);
    glVertex2i(670, 225);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(670, 225);
    glVertex2i(680, 225);
    glVertex2i(680, 228);
    glVertex2i(670, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(670, 180);
    glVertex2i(680, 180);
    glVertex2i(680, 195);
    glVertex2i(670, 195);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(670, 195);
    glVertex2i(680, 195);
    glVertex2i(680, 198);
    glVertex2i(670, 198);
    glEnd();

    //3rd

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(685, 300);
    glVertex2i(695, 300);
    glVertex2i(695, 315);
    glVertex2i(685, 315);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(685, 315);
    glVertex2i(695, 315);
    glVertex2i(695, 318);
    glVertex2i(685, 318);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(685, 270);
    glVertex2i(695, 270);
    glVertex2i(695, 285);
    glVertex2i(685, 285);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(685, 285);
    glVertex2i(695, 285);
    glVertex2i(695, 288);
    glVertex2i(685, 288);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(685, 240);
    glVertex2i(695, 240);
    glVertex2i(695, 255);
    glVertex2i(685, 255);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(685, 255);
    glVertex2i(695, 255);
    glVertex2i(695, 258);
    glVertex2i(685, 258);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(685, 210);
    glVertex2i(695, 210);
    glVertex2i(695, 225);
    glVertex2i(685, 225);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(160, 117, 50);
    glVertex2i(685, 225);
    glVertex2i(695, 225);
    glVertex2i(695, 228);
    glVertex2i(685, 228);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(685, 180);
    glVertex2i(695, 180);
    glVertex2i(695, 195);
    glVertex2i(685, 195);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(27, 174, 223);
    glVertex2i(685, 195);
    glVertex2i(695, 195);
    glVertex2i(695, 198);
    glVertex2i(685, 198);
    glEnd();

    //4th building

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(12, 46, 80);
    glVertex2i(590, 145);
    glVertex2i(635, 145);
    glVertex2i(635, 200);
    glVertex2i(590, 200);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(26, 155, 197);
    glVertex2i(635, 145);
    glVertex2i(685, 145);
    glVertex2i(685, 200);
    glVertex2i(635, 200);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(595, 190);
    glVertex2i(600, 190);
    glVertex2i(600, 185);
    glVertex2i(595, 185);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(602, 190);
    glVertex2i(607, 190);
    glVertex2i(607, 185);
    glVertex2i(602, 185);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(609, 190);
    glVertex2i(614, 190);
    glVertex2i(614, 185);
    glVertex2i(609, 185);
    glEnd();

    //window 4
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(616, 190);
    glVertex2i(621, 190);
    glVertex2i(621, 185);
    glVertex2i(616, 185);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(623, 190);
    glVertex2i(628, 190);
    glVertex2i(628, 185);
    glVertex2i(623, 185);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(595, 175);
    glVertex2i(600, 175);
    glVertex2i(600, 180);
    glVertex2i(595, 180);
    glEnd();

    //window 7
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(602, 175);
    glVertex2i(607, 175);
    glVertex2i(607, 180);
    glVertex2i(602, 180);
    glEnd();

    //window 8
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(609, 175);
    glVertex2i(614, 175);
    glVertex2i(614, 180);
    glVertex2i(609, 180);
    glEnd();

    //window 9
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(616, 175);
    glVertex2i(621, 175);
    glVertex2i(621, 180);
    glVertex2i(616, 180);
    glEnd();

    //window 10
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(623, 175);
    glVertex2i(628, 175);
    glVertex2i(628, 180);
    glVertex2i(623, 180);
    glEnd();

    //window 11
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(595, 165);
    glVertex2i(600, 165);
    glVertex2i(600, 170);
    glVertex2i(595, 170);
    glEnd();

    //window 12
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(602, 165);
    glVertex2i(607, 165);
    glVertex2i(607, 170);
    glVertex2i(602, 170);
    glEnd();

    //window 13
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(609, 165);
    glVertex2i(614, 165);
    glVertex2i(614, 170);
    glVertex2i(609, 170);
    glEnd();

    //window 14
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(616, 165);
    glVertex2i(621, 165);
    glVertex2i(621, 170);
    glVertex2i(616, 170);
    glEnd();

    //window 15
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(623, 165);
    glVertex2i(628, 165);
    glVertex2i(628, 170);
    glVertex2i(623, 170);
    glEnd();

    //window 16
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(595, 155);
    glVertex2i(600, 155);
    glVertex2i(600, 160);
    glVertex2i(595, 160);
    glEnd();

    //window 17
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(602, 155);
    glVertex2i(607, 155);
    glVertex2i(607, 160);
    glVertex2i(602, 160);
    glEnd();

    //window 18
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(609, 155);
    glVertex2i(614, 155);
    glVertex2i(614, 160);
    glVertex2i(609, 160);
    glEnd();

    //window 19
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(616, 155);
    glVertex2i(621, 155);
    glVertex2i(621, 160);
    glVertex2i(616, 160);
    glEnd();

    //window 20
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(40, 102, 158);
    glVertex2i(623, 155);
    glVertex2i(628, 155);
    glVertex2i(628, 160);
    glVertex2i(623, 160);
    glEnd();

    //6th building

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(6, 92, 119);
    glVertex2i(705, 145);
    glVertex2i(765, 145);
    glVertex2i(765, 270);
    glVertex2i(705, 270);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(16, 15, 16);
    glVertex2i(695, 145);
    glVertex2i(705, 145);
    glVertex2i(705, 270);
    glVertex2i(695, 270);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(246, 184, 10);
    glVertex2i(720, 250);
    glVertex2i(730, 250);
    glVertex2i(730, 260);
    glVertex2i(720, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(246, 184, 10);
    glVertex2i(720, 255);
    glVertex2i(730, 255);
    glVertex2i(725, 260);
    glVertex2i(725, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 250);
    glVertex2i(743, 250);
    glVertex2i(743, 260);
    glVertex2i(733, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 255);
    glVertex2i(743, 255);
    glVertex2i(738, 260);
    glVertex2i(738, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(745, 250);
    glVertex2i(755, 250);
    glVertex2i(755, 260);
    glVertex2i(745, 260);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(745, 255);
    glVertex2i(755, 255);
    glVertex2i(750, 260);
    glVertex2i(750, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(246, 184, 10);
    glVertex2i(720, 235);
    glVertex2i(730, 235);
    glVertex2i(730, 245);
    glVertex2i(720, 245);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(246, 184, 10);
    glVertex2i(720, 240);
    glVertex2i(730, 240);
    glVertex2i(725, 245);
    glVertex2i(725, 235);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(720, 220);
    glVertex2i(730, 220);
    glVertex2i(730, 230);
    glVertex2i(720, 230);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(720, 225);
    glVertex2i(730, 225);
    glVertex2i(725, 230);
    glVertex2i(725, 220);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(720, 205);
    glVertex2i(730, 205);
    glVertex2i(730, 215);
    glVertex2i(720, 215);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(720, 210);
    glVertex2i(730, 210);
    glVertex2i(725, 215);
    glVertex2i(725, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(720, 190);
    glVertex2i(730, 190);
    glVertex2i(730, 200);
    glVertex2i(720, 200);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(720, 195);
    glVertex2i(730, 195);
    glVertex2i(725, 200);
    glVertex2i(725, 190);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(246, 184, 10);
    glVertex2i(720, 175);
    glVertex2i(730, 175);
    glVertex2i(730, 185);
    glVertex2i(720, 185);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(246, 184, 10);
    glVertex2i(720, 180);
    glVertex2i(730, 180);
    glVertex2i(725, 185);
    glVertex2i(725, 175);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(246, 184, 10);
    glVertex2i(720, 160);
    glVertex2i(730, 160);
    glVertex2i(730, 170);
    glVertex2i(720, 170);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(246, 184, 10);
    glVertex2i(720, 165);
    glVertex2i(730, 165);
    glVertex2i(725, 170);
    glVertex2i(725, 160);
    glEnd();

    //2nd
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 235);
    glVertex2i(743, 235);
    glVertex2i(743, 245);
    glVertex2i(733, 245);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 240);
    glVertex2i(743, 240);
    glVertex2i(738, 245);
    glVertex2i(738, 235);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 220);
    glVertex2i(743, 220);
    glVertex2i(743, 230);
    glVertex2i(733, 230);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 225);
    glVertex2i(743, 225);
    glVertex2i(738, 230);
    glVertex2i(738, 220);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(246, 184, 10);
    glVertex2i(733, 205);
    glVertex2i(743, 205);
    glVertex2i(743, 215);
    glVertex2i(733, 215);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(246, 184, 10);
    glVertex2i(733, 210);
    glVertex2i(743, 210);
    glVertex2i(738, 215);
    glVertex2i(738, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 190);
    glVertex2i(743, 190);
    glVertex2i(743, 200);
    glVertex2i(733, 200);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 195);
    glVertex2i(743, 195);
    glVertex2i(738, 200);
    glVertex2i(738, 190);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(246, 184, 10);
    glVertex2i(733, 175);
    glVertex2i(743, 175);
    glVertex2i(743, 185);
    glVertex2i(733, 185);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(246, 184, 10);
    glVertex2i(733, 180);
    glVertex2i(743, 180);
    glVertex2i(738, 185);
    glVertex2i(738, 175);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 160);
    glVertex2i(743, 160);
    glVertex2i(743, 170);
    glVertex2i(733, 170);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(733, 165);
    glVertex2i(743, 165);
    glVertex2i(738, 170);
    glVertex2i(738, 160);
    glEnd();

    //3rd
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(745, 235);
    glVertex2i(755, 235);
    glVertex2i(755, 245);
    glVertex2i(745, 245);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(745, 240);
    glVertex2i(755, 240);
    glVertex2i(750, 245);
    glVertex2i(750, 235);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(246, 184, 10);
    glVertex2i(745, 220);
    glVertex2i(755, 220);
    glVertex2i(755, 230);
    glVertex2i(745, 230);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(246, 184, 10);
    glVertex2i(745, 225);
    glVertex2i(755, 225);
    glVertex2i(750, 230);
    glVertex2i(750, 220);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(745, 205);
    glVertex2i(755, 205);
    glVertex2i(755, 215);
    glVertex2i(745, 215);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(745, 210);
    glVertex2i(755, 210);
    glVertex2i(750, 215);
    glVertex2i(750, 205);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(246, 184, 10);
    glVertex2i(745, 190);
    glVertex2i(755, 190);
    glVertex2i(755, 200);
    glVertex2i(745, 200);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(246, 184, 10);
    glVertex2i(745, 195);
    glVertex2i(755, 195);
    glVertex2i(750, 200);
    glVertex2i(750, 190);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(246, 184, 10);
    glVertex2i(745, 175);
    glVertex2i(755, 175);
    glVertex2i(755, 185);
    glVertex2i(745, 185);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(246, 184, 10);
    glVertex2i(745, 180);
    glVertex2i(755, 180);
    glVertex2i(750, 185);
    glVertex2i(750, 175);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(9, 38, 58);
    glVertex2i(745, 160);
    glVertex2i(755, 160);
    glVertex2i(755, 170);
    glVertex2i(745, 170);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(9, 38, 58);
    glVertex2i(745, 165);
    glVertex2i(755, 165);
    glVertex2i(750, 170);
    glVertex2i(750, 160);
    glEnd();
    ///---------------------Fariha-----------------------///
    //2nd building
    glBegin(GL_QUADS); //red1 b2
    glPointSize(10.0);
    glColor3ub(6, 41, 50);
    glVertex2i(855, 155);
    glVertex2i(865, 155);
    glVertex2i(865, 330);
    glVertex2i(855, 330);
    glEnd();

    glBegin(GL_QUADS); //red2 b2 border
    glPointSize(10.0);
    glColor3ub(6, 41, 50);
    glVertex2i(850, 325);
    glVertex2i(865, 325);
    glVertex2i(865, 335);
    glVertex2i(850, 335);
    glEnd();
    glBegin(GL_QUADS); //green1 b2
    glPointSize(10.0);
    glColor3ub(3, 125, 164);
    glVertex2i(865, 155);
    glVertex2i(925, 155);
    glVertex2i(925, 330);
    glVertex2i(865, 330);
    glEnd();
    glBegin(GL_QUADS); //green2 b2 border
    glPointSize(10.0);
    glColor3ub(3, 125, 164);
    glVertex2i(860, 325);
    glVertex2i(930, 325);
    glVertex2i(930, 335);
    glVertex2i(860, 335);
    glEnd();
    glBegin(GL_QUADS); //w1 b2
    glPointSize(10.0);
    glColor3ub(204, 160, 65);
    glVertex2i(870, 290);
    glVertex2i(885, 290);
    glVertex2i(885, 310);
    glVertex2i(870, 310);
    glEnd();
    glBegin(GL_QUADS); //w2 b2
    glPointSize(10.0);
    glColor3ub(2, 52, 75);
    glVertex2i(890, 290);
    glVertex2i(905, 290);
    glVertex2i(905, 310);
    glVertex2i(890, 310);
    glEnd();
    glBegin(GL_QUADS); //w3 b2
    glPointSize(10.0);
    glColor3ub(2, 52, 75);
    glVertex2i(910, 290);
    glVertex2i(925, 290);
    glVertex2i(925, 310);
    glVertex2i(910, 310);
    glEnd();
    //line border1

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(2, 52, 75);
    glVertex2i(867, 282);
    glVertex2i(923, 282);
    glEnd();

    glBegin(GL_QUADS); //w4 b2
    glPointSize(10.0);
    glColor3ub(2, 52, 75);
    glVertex2i(870, 255);
    glVertex2i(885, 255);
    glVertex2i(885, 275);
    glVertex2i(870, 275);
    glEnd();
    glBegin(GL_QUADS); //w5 b2
    glPointSize(10.0);
    glColor3ub(204, 160, 65);
    glVertex2i(890, 255);
    glVertex2i(905, 255);
    glVertex2i(905, 275);
    glVertex2i(890, 275);
    glEnd();

    glBegin(GL_QUADS); //w6 b2
    glPointSize(10.0);
    glColor3ub(204, 160, 65);
    glVertex2i(910, 255);
    glVertex2i(925, 255);
    glVertex2i(925, 275);
    glVertex2i(910, 275);
    glEnd();
    //line border2
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(2, 52, 75);
    glVertex2i(867, 244);
    glVertex2i(923, 244);
    glEnd();

    glBegin(GL_QUADS); //w7 b2
    glPointSize(10.0);
    glColor3ub(2, 52, 75);
    glVertex2i(870, 220);
    glVertex2i(885, 220);
    glVertex2i(885, 240);
    glVertex2i(870, 240);
    glEnd();

    glBegin(GL_QUADS); //w8 b2
    glPointSize(10.0);
    glColor3ub(204, 160, 65);
    glVertex2i(890, 220);
    glVertex2i(905, 220);
    glVertex2i(905, 240);
    glVertex2i(890, 240);
    glEnd();

    glBegin(GL_QUADS); //w9 b2
    glPointSize(10.0);
    glColor3ub(2, 52, 75);
    glVertex2i(910, 220);
    glVertex2i(925, 220);
    glVertex2i(925, 240);
    glVertex2i(910, 240);
    glEnd();

    //line border3
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(2, 52, 75);
    glVertex2i(867, 204);
    glVertex2i(923, 204);
    glEnd();

    //1st building.
    glBegin(GL_QUADS); //red part b1
    glPointSize(10.0);
    glColor3ub(14, 48, 60);
    glVertex2i(774, 147);
    glVertex2i(790, 147);
    glVertex2i(790, 242);
    glVertex2i(774, 242);
    glEnd();
    // border
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(8, 32, 60);
    glVertex2i(777, 146);
    glVertex2i(777, 242);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(04);
    glColor3ub(8, 32, 60);
    glVertex2i(782, 146);
    glVertex2i(782, 242);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(04);
    glColor3ub(8, 32, 60);
    glVertex2i(789, 146);
    glVertex2i(789, 242);
    glEnd();

    glBegin(GL_QUADS); //white part b1
    glPointSize(10.0);
    glColor3ub(30, 61, 113);
    glVertex2i(790, 147);
    glVertex2i(863, 147);
    glVertex2i(863, 242);
    glVertex2i(790, 242);
    glEnd();
    glBegin(GL_QUADS); //w1 b1
    glPointSize(10.0);
    glColor3ub(6, 101, 150);
    glVertex2i(800, 217);
    glVertex2i(813, 217);
    glVertex2i(813, 232);
    glVertex2i(800, 232);
    glEnd();

    glBegin(GL_QUADS); //w2 b1
    glPointSize(10.0);
    glColor3ub(204, 165, 51);
    glVertex2i(820, 217);
    glVertex2i(833, 217);
    glVertex2i(833, 232);
    glVertex2i(820, 232);
    glEnd();
    glBegin(GL_QUADS); //w3 b1
    glPointSize(10.0);
    glColor3ub(6, 101, 150);
    glVertex2i(840, 217);
    glVertex2i(853, 217);
    glVertex2i(853, 232);
    glVertex2i(840, 232);
    glEnd();
    glBegin(GL_QUADS); //w4 b1
    glPointSize(10.0);
    glColor3ub(6, 101, 150);
    glVertex2i(800, 188);
    glVertex2i(813, 188);
    glVertex2i(813, 203);
    glVertex2i(800, 203);
    glEnd();
    glBegin(GL_QUADS); //w5 b1
    glPointSize(10.0);
    glColor3ub(204, 165, 51);
    glVertex2i(820, 188);
    glVertex2i(833, 188);
    glVertex2i(833, 203);
    glVertex2i(820, 203);
    glEnd();
    glBegin(GL_QUADS); //w6 b1
    glPointSize(10.0);
    glColor3ub(204, 165, 51);
    glVertex2i(840, 188);
    glVertex2i(853, 188);
    glVertex2i(853, 203);
    glVertex2i(840, 203);
    glEnd();

    glBegin(GL_QUADS); //w7 b1
    glPointSize(10.0);
    glColor3ub(204, 165, 51);
    glVertex2i(800, 159);
    glVertex2i(813, 159);
    glVertex2i(813, 174);
    glVertex2i(800, 174);
    glEnd();
    glBegin(GL_QUADS); //w8 b1
    glPointSize(10.0);
    glColor3ub(6, 101, 150);
    glVertex2i(820, 159);
    glVertex2i(833, 159);
    glVertex2i(833, 174);
    glVertex2i(820, 174);
    glEnd();
    glBegin(GL_QUADS); //w9 b1
    glPointSize(10.0);
    glColor3ub(6, 101, 150);
    glVertex2i(840, 159);
    glVertex2i(853, 159);
    glVertex2i(853, 174);
    glVertex2i(840, 174);
    glEnd();

    //3rd building
    glBegin(GL_QUADS); //b3 border
    glPointSize(10.0);
    glColor3ub(8, 90, 117);
    glVertex2i(924, 145);
    glVertex2i(934, 145);
    glVertex2i(934, 252);
    glVertex2i(924, 252);
    glEnd();
    //Red part b3
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(98, 161, 199);
    glVertex2i(934, 145);
    glVertex2i(995, 145);
    glVertex2i(995, 252);
    glVertex2i(934, 252);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(2, 30, 49); //w1 b3
    glVertex2i(952, 235);
    glVertex2i(960, 235);
    glVertex2i(960, 245);
    glVertex2i(952, 245);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(2, 30, 49); //w2 b3
    glVertex2i(975, 235);
    glVertex2i(984, 235);
    glVertex2i(984, 245);
    glVertex2i(975, 245);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 184, 0); //w3 b3
    glVertex2i(940, 220);
    glVertex2i(950, 220);
    glVertex2i(950, 230);
    glVertex2i(940, 230);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 184, 0); //w4 b3
    glVertex2i(963, 220);
    glVertex2i(973, 220);
    glVertex2i(973, 232);
    glVertex2i(963, 232);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(2, 30, 49); //w5 b3
    glVertex2i(952, 205);
    glVertex2i(960, 205);
    glVertex2i(960, 215);
    glVertex2i(952, 215);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(2, 30, 49); //w6 b3
    glVertex2i(975, 205);
    glVertex2i(984, 205);
    glVertex2i(984, 215);
    glVertex2i(975, 215);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(2, 30, 49); //w7 b3
    glVertex2i(940, 190);
    glVertex2i(950, 190);
    glVertex2i(950, 200);
    glVertex2i(940, 200);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 184, 0); //w8 b3
    glVertex2i(963, 190);
    glVertex2i(973, 190);
    glVertex2i(973, 200);
    glVertex2i(963, 200);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 184, 0); //w9 b3
    glVertex2i(952, 180);
    glVertex2i(960, 180);
    glVertex2i(960, 190);
    glVertex2i(952, 190);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(2, 30, 49); //w10 b3
    glVertex2i(975, 180);
    glVertex2i(984, 180);
    glVertex2i(984, 190);
    glVertex2i(975, 190);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(2, 30, 49); //w11 b3
    glVertex2i(940, 165);
    glVertex2i(950, 165);
    glVertex2i(950, 175);
    glVertex2i(940, 175);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 184, 0); //w12 b3
    glVertex2i(963, 165);
    glVertex2i(973, 165);
    glVertex2i(973, 175);
    glVertex2i(963, 175);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(2, 30, 49); //w13 b3
    glVertex2i(952, 150);
    glVertex2i(960, 150);
    glVertex2i(960, 160);
    glVertex2i(952, 160);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(255, 184, 0); //w14 b3
    glVertex2i(975, 150);
    glVertex2i(984, 150);
    glVertex2i(984, 160);
    glVertex2i(975, 160);
    glEnd();

    //4th building
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 136, 173);
    glVertex2i(1010, 147);
    glVertex2i(1025, 147);
    glVertex2i(1025, 208);
    glVertex2i(1010, 208);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(1, 20, 29); //deep oranger part b4
    glVertex2i(1025, 147);
    glVertex2i(1030, 147);
    glVertex2i(1030, 208);
    glVertex2i(1025, 208);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(11, 46, 84); //light oranger part b4
    glVertex2i(1030, 147);
    glVertex2i(1060, 147);
    glVertex2i(1060, 208);
    glVertex2i(1030, 208);
    glEnd();
    glBegin(GL_QUADS); //light brik 1
    glPointSize(10.0);
    glColor3ub(0, 136, 173);
    glVertex2i(1060, 147);
    glVertex2i(1074, 147);
    glVertex2i(1074, 208);
    glVertex2i(1060, 208);
    glEnd();
    glBegin(GL_QUADS); //light brik 2
    glPointSize(10.0);
    glColor3ub(0, 136, 173);
    glVertex2i(1060, 147);
    glVertex2i(1074, 147);
    glVertex2i(1074, 208);
    glVertex2i(1060, 208);
    glEnd();
    glBegin(GL_QUADS); //light brik square
    glPointSize(10.0);
    glColor3ub(0, 136, 173);
    glVertex2i(1010, 208);
    glVertex2i(1074, 208);
    glVertex2i(1074, 233);
    glVertex2i(1010, 233);
    glEnd();
    glBegin(GL_QUADS); //white border
    glPointSize(10.0);
    glColor3ub(0, 22, 32);
    glVertex2i(1010, 233);
    glVertex2i(1074, 233);
    glVertex2i(1074, 239);
    glVertex2i(1010, 239);
    glEnd();
    glBegin(GL_QUADS); //upper brik
    glPointSize(10.0);
    glColor3ub(0, 136, 173);
    glVertex2i(1010, 239);
    glVertex2i(1074, 239);
    glVertex2i(1074, 282);
    glVertex2i(1010, 282);
    glEnd();
    glBegin(GL_QUADS); //W1
    glPointSize(10.0);
    glColor3ub(4, 27, 40);
    glVertex2i(1018, 260);
    glVertex2i(1024, 260);
    glVertex2i(1024, 270);
    glVertex2i(1018, 270);
    glEnd();
    glBegin(GL_QUADS); //W2
    glPointSize(10.0);
    glColor3ub(4, 27, 40);
    glVertex2i(1028, 260);
    glVertex2i(1035, 260);
    glVertex2i(1035, 270);
    glVertex2i(1028, 270);
    glEnd();
    glBegin(GL_QUADS); //W3
    glPointSize(10.0);
    glColor3ub(248, 190, 25);
    glVertex2i(1038, 260);
    glVertex2i(1045, 260);
    glVertex2i(1045, 270);
    glVertex2i(1038, 270);
    glEnd();
    glBegin(GL_QUADS); //W4
    glPointSize(10.0);
    glColor3ub(4, 27, 40);
    glVertex2i(1048, 260);
    glVertex2i(1055, 260);
    glVertex2i(1055, 270);
    glVertex2i(1048, 270);
    glEnd();
    glBegin(GL_QUADS); //W5
    glPointSize(10.0);
    glColor3ub(4, 27, 40);
    glVertex2i(1018, 249);
    glVertex2i(1024, 249);
    glVertex2i(1024, 258);
    glVertex2i(1018, 258);
    glEnd();
    glBegin(GL_QUADS); //W6
    glPointSize(10.0);
    glColor3ub(248, 190, 25);
    glVertex2i(1028, 249);
    glVertex2i(1035, 249);
    glVertex2i(1035, 258);
    glVertex2i(1028, 258);
    glEnd();
    glBegin(GL_QUADS); //W6
    glPointSize(10.0);
    glColor3ub(4, 27, 40);
    glVertex2i(1038, 249);
    glVertex2i(1045, 249);
    glVertex2i(1045, 258);
    glVertex2i(1038, 258);
    glEnd();
    glBegin(GL_QUADS); //W7
    glPointSize(10.0);
    glColor3ub(4, 27, 40);
    glVertex2i(1038, 249);
    glVertex2i(1045, 249);
    glVertex2i(1045, 258);
    glVertex2i(1038, 258);
    glEnd();
    glBegin(GL_QUADS); //W8
    glPointSize(10.0);
    glColor3ub(248, 190, 25);
    glVertex2i(1048, 249);
    glVertex2i(1055, 249);
    glVertex2i(1055, 258);
    glVertex2i(1048, 258);
    glEnd();
    //uppper triangle
    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(112, 182, 228);
    glVertex2i(1010, 282);
    glVertex2i(1073, 282);
    glVertex2i(1053, 315);
    glEnd();
    glBegin(GL_QUADS); //deep border
    glPointSize(10.0);
    glColor3ub(112, 182, 228);
    glVertex2i(1010, 282);
    glVertex2i(1072, 282);
    glVertex2i(1072, 288);
    glVertex2i(1014, 288);
    glEnd();

    glBegin(GL_TRIANGLES);
    glPointSize(10.0);
    glColor3ub(5, 47, 72);
    glVertex2i(1073, 282);
    glVertex2i(1097, 282);
    glVertex2i(1053, 315);
    glEnd();
    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(5, 47, 72);
    glVertex2i(1074, 147);
    glVertex2i(1097, 147);
    glVertex2i(1097, 282);
    glVertex2i(1074, 282);
    glEnd();
    glBegin(GL_QUADS); //w1
    glPointSize(10.0);
    glColor3ub(5, 28, 38);
    glVertex2i(1080, 262);
    glVertex2i(1085, 262);
    glVertex2i(1085, 273);
    glVertex2i(1080, 273);
    glEnd();
    glBegin(GL_QUADS); //w2
    glPointSize(10.0);
    glColor3ub(244, 190, 32);
    glVertex2i(1088, 263);
    glVertex2i(1093, 263);
    glVertex2i(1093, 273);
    glVertex2i(1088, 273);
    glEnd();
    glBegin(GL_QUADS); //w3
    glPointSize(10.0);
    glColor3ub(244, 190, 32);
    glVertex2i(1080, 249);
    glVertex2i(1085, 249);
    glVertex2i(1085, 258);
    glVertex2i(1080, 258);
    glEnd();
    glBegin(GL_QUADS); //w4
    glPointSize(10.0);
    glColor3ub(5, 28, 38);
    glVertex2i(1088, 249);
    glVertex2i(1093, 249);
    glVertex2i(1093, 258);
    glVertex2i(1088, 258);
    glEnd();
    glBegin(GL_QUADS); //w5
    glPointSize(10.0);
    glColor3ub(244, 190, 32);
    glVertex2i(1080, 232);
    glVertex2i(1085, 232);
    glVertex2i(1085, 244);
    glVertex2i(1080, 244);
    glEnd();
    glBegin(GL_QUADS); //w6
    glPointSize(10.0);
    glColor3ub(5, 28, 38);
    glVertex2i(1088, 232);
    glVertex2i(1093, 232);
    glVertex2i(1093, 244);
    glVertex2i(1088, 244);
    glEnd();

    glBegin(GL_QUADS); //w7
    glPointSize(10.0);
    glColor3ub(244, 190, 32);
    glVertex2i(1080, 216);
    glVertex2i(1085, 216);
    glVertex2i(1085, 228);
    glVertex2i(1080, 228);
    glEnd();
    glBegin(GL_QUADS); //w8
    glPointSize(10.0);
    glColor3ub(244, 190, 32);
    glVertex2i(1088, 216);
    glVertex2i(1093, 216);
    glVertex2i(1093, 228);
    glVertex2i(1088, 228);
    glEnd();
    glBegin(GL_QUADS); //w9
    glPointSize(10.0);
    glColor3ub(5, 28, 38);
    glVertex2i(1080, 204);
    glVertex2i(1085, 204);
    glVertex2i(1085, 213);
    glVertex2i(1080, 213);
    glEnd();
    glBegin(GL_QUADS); //w10
    glPointSize(10.0);
    glColor3ub(5, 28, 38);
    glVertex2i(1088, 204);
    glVertex2i(1093, 204);
    glVertex2i(1093, 213);
    glVertex2i(1088, 213);
    glEnd();
    glBegin(GL_QUADS); //w11
    glPointSize(10.0);
    glColor3ub(5, 28, 38);
    glVertex2i(1080, 188);
    glVertex2i(1085, 188);
    glVertex2i(1085, 198);
    glVertex2i(1080, 198);
    glEnd();
    glBegin(GL_QUADS); //w12
    glPointSize(10.0);
    glColor3ub(244, 190, 32);
    glVertex2i(1088, 188);
    glVertex2i(1093, 188);
    glVertex2i(1093, 198);
    glVertex2i(1088, 198);
    glEnd();

    glBegin(GL_QUADS); //w13
    glPointSize(10.0);
    glColor3ub(244, 190, 32);
    glVertex2i(1080, 173);
    glVertex2i(1085, 173);
    glVertex2i(1085, 182);
    glVertex2i(1080, 182);
    glEnd();
    glBegin(GL_QUADS); //w14
    glPointSize(10.0);
    glColor3ub(5, 28, 38);
    glVertex2i(1088, 173);
    glVertex2i(1093, 173);
    glVertex2i(1093, 182);
    glVertex2i(1088, 182);
    glEnd();
    glBegin(GL_QUADS); //w15
    glPointSize(10.0);
    glColor3ub(5, 28, 38);
    glVertex2i(1080, 157);
    glVertex2i(1085, 157);
    glVertex2i(1085, 169);
    glVertex2i(1080, 169);
    glEnd();
    glBegin(GL_QUADS); //w16
    glPointSize(10.0);
    glColor3ub(5, 28, 38);
    glVertex2i(1088, 157);
    glVertex2i(1093, 157);
    glVertex2i(1093, 169);
    glVertex2i(1088, 169);
    glEnd();
    //5th building
    glBegin(GL_QUADS); //light part
    glPointSize(10.0);
    glColor3ub(11, 104, 156);
    glVertex2i(1108, 147);
    glVertex2i(1158, 147);
    glVertex2i(1158, 267);
    glVertex2i(1108, 267);
    glEnd();
    glBegin(GL_QUADS); //deep part
    glPointSize(10.0);
    glColor3ub(8, 25, 33);
    glVertex2i(1158, 147);
    glVertex2i(1186, 147);
    glVertex2i(1186, 300);
    glVertex2i(1158, 268);
    glEnd();
    glBegin(GL_QUADS); //deep blue
    glPointSize(10.0);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 267);
    glVertex2i(1158, 267);
    glVertex2i(1186, 300);
    glVertex2i(1136, 300);
    glEnd();
    //shade
    glBegin(GL_LINES); //1
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 255);
    glVertex2i(1158, 255);
    glVertex2i(1117, 147);
    glVertex2i(1117, 267);
    glEnd();

    glBegin(GL_LINES); //2
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 245);
    glVertex2i(1158, 245);
    glVertex2i(1125, 147);
    glVertex2i(1125, 266);
    glEnd();

    glBegin(GL_LINES); //3
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 233);
    glVertex2i(1158, 233);
    glVertex2i(1135, 147);
    glVertex2i(1135, 266);
    glEnd();

    glBegin(GL_LINES); //4
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 222);
    glVertex2i(1158, 222);
    glVertex2i(1145, 147);
    glVertex2i(1145, 266);
    glEnd();
    glBegin(GL_LINES); //5
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 212);
    glVertex2i(1158, 212);
    glVertex2i(1135, 147);
    glVertex2i(1135, 266);
    glEnd();
    glBegin(GL_LINES); //6
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 202);
    glVertex2i(1158, 202);
    glEnd();
    glBegin(GL_LINES); //7
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 192);
    glVertex2i(1158, 192);
    glEnd();
    glBegin(GL_LINES); //8
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 182);
    glVertex2i(1158, 182);
    glEnd();
    glBegin(GL_LINES); //9
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 172);
    glVertex2i(1158, 172);
    glEnd();
    glBegin(GL_LINES); //10
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 162);
    glVertex2i(1158, 162);
    glEnd();
    glBegin(GL_LINES); //11
    glLineWidth(10);
    glColor3ub(55, 25, 85);
    glVertex2i(1108, 152);
    glVertex2i(1158, 152);
    glEnd();
}

void keyboard(unsigned char key, int x, int y)

{
    switch (key)
    {
    case 'd':
        if (moonSitThere)
        {
            makeItDay = true;
            makeItNight = false;
            sunSitThere = false;
        }
        break;
    case 'n':
        if (sunSitThere)
        {
            makeItNight = true;
            makeItDay = false;
            moonSitThere = false;
        }
        break;
    case 'r':
        rainday = true;
        break;
    case 'f':
        rainday = false;
        break;
    case 's':
        isRedlight = true;
        break;
    case 'g':
        isRedlight = false;
        break;
    default:
        break;
    }
}

void Day()
{
    Daysky();
    if (sunY < -60)
        if (!rainday)
            EveningSky();
    sunRise();
    sunset();
    if (rainday)
    {
        coverTheSun();
        text(50, 580, "Press F to stop Rain");
    }
    else
        text(50, 580, "Press R to start Rain");
    trfficText();
    moveCloud();
    BgBuildingDayTime();
    RoadFieldDay();
    DayTime();
    dayTree();
    trafficlightStand();
    vehicle();
    dayLampPost();
}

void Night()
{
    Nightsky();
    trfficText();
    MoonRise();
    moonset();
    stars();
    if (rainday)
    {
        coverThemoon();
        text(50, 580, "Press F to stop Rain");
    }
    else
        text(50, 580, "Press R to start Rain");
    moveCloud();
    BgBuildingNightTime();
    RoadFielNight();
    NightTime();
    nightTree();
    trafficlightStand();
    vehicle();
    nightLampPost();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (isDay)
    {
        Day();
    }
    else
    {
        Night();
    }
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();

    glPushMatrix();
    Rain(rain);
    glutPostRedisplay();
    glutTimerFunc(1, Rain, 0);
    glFlush();
    glPopMatrix();
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
    glutCreateWindow("OpenGL_Project_Group_2");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    myInit();
    glutMainLoop();
}
