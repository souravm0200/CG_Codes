#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

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


void DayTime()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    ///Hill 1
    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 170);
    glVertex2i(200, 300);
    glVertex2i(300, 170);
    glEnd();

    ///Hill 2

    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(270, 170);
    glVertex2i(370, 270);
    glVertex2i(470, 170);
    glEnd();

    ///Hill 3

    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(1050, 170);
    glVertex2i(1150, 300);
    glVertex2i(1300, 170);
    glEnd();

   ///station

    glColor3ub(150,150,150);
    glBegin(GL_QUADS);
    glVertex2i(700,220);
    glVertex2i(700,140);
    glVertex2i(850,140);
    glVertex2i(850,220);
    glEnd();
    text(750, 200, "Bus station");

    glColor3ub(100,100,100);
    glBegin(GL_QUADS);
    glVertex2i(720,240);
    glVertex2i(700,220);
    glVertex2i(850,220);
    glVertex2i(870,240);
    glEnd();

    glColor3ub(0,128,128);
    glBegin(GL_TRIANGLES);
    glVertex2i(700,160);
    glVertex2i(720,239);
    glVertex2i(700,220);
    glEnd();

    glColor3ub(0,128,128);
    glBegin(GL_TRIANGLES);
    glVertex2i(850,160);
    glVertex2i(870,240);
    glVertex2i(850,220);
    glEnd();

    glColor3ub(100,100,100);
    glBegin(GL_QUADS);
    glVertex2i(690,139);
    glVertex2i(690,130);
    glVertex2i(860,130);
    glVertex2i(860,139);
    glEnd();

    glColor3ub(50,50,50);
    glDisable(GL_LINE_STIPPLE);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(720,155);
    glVertex2i(840,155);

    glVertex2i(730,155);
    glVertex2i(730,140);
    glVertex2i(750,155);
    glVertex2i(750,140);
    glVertex2i(770,155);
    glVertex2i(770,140);
    glVertex2i(790,155);
    glVertex2i(790,140);
    glVertex2i(810,155);
    glVertex2i(810,140);
    glVertex2i(830,155);
    glVertex2i(830,140);
    glEnd();

    ///Mall
 glBegin(GL_QUADS);


    glColor3ub(30,144,255);

    glVertex2i(450,150);
    glVertex2i(600,150);

    glVertex2i(600,300);
    glVertex2i(450,300);
    glEnd();

text(475, 275, "Shopping Mall");
    glLineWidth(7.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2i(450,200);
    glVertex2i(600, 200);

     glVertex2i(450,250);
    glVertex2i(600, 250);

     glVertex2i(450,300);
    glVertex2i(600, 300);

   glEnd();




    glBegin(GL_QUADS);
    glColor3ub(30,144,255);
    glVertex2i(600,150);
    glVertex2i(630,160);
    glVertex2i(630,310);
    glVertex2i(600,300);

    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(600,200);
    glVertex2i(630,210);

    glVertex2i(600,250);
    glVertex2i(630,260);

    glVertex2i(600,300);
    glVertex2i(630,310);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2i(600,150);
    glVertex2i(600, 300);

    glEnd();

   glBegin(GL_QUADS);
    glColor3ub(30,144,255);

     glVertex2i(450,304);
    glVertex2i(460,315);
    glVertex2i(632,315);
    glVertex2i(600,304);

    glEnd();

  glBegin(GL_QUADS);
    glColor3ub(175,238,238);

     glVertex2i(500,150);
    glVertex2i(550,150);
    glVertex2i(550,190);
    glVertex2i(500,190);

    glEnd();


  ///billboard
glColor3ub(47,79,79);


  glBegin(GL_QUADS);
    glColor3ub(47,79,79);

     glVertex2i(200,200);
    glVertex2i(350,200);
    glVertex2i(350,290);
    glVertex2i(200,290);


glEnd();

text(250, 245, "Close Up");

glLineWidth(7.5);
     glBegin(GL_LINES);
    glColor3ub(47,79,79);

     glVertex2i(275,150);
    glVertex2i(275,200);

   glEnd();

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



}
void NightTime()
{
     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
     glClear(GL_COLOR_BUFFER_BIT);

///Hill 1
    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 170);
    glVertex2i(200, 300);
    glVertex2i(300, 170);
    glEnd();

    ///Hill 2

    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(270, 170);
    glVertex2i(370, 270);
    glVertex2i(470, 170);
    glEnd();

    ///Hill 3

    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(1050, 170);
    glVertex2i(1150, 300);
    glVertex2i(1300, 170);
    glEnd();

   ///station

    glColor3ub(150,150,150);
    glBegin(GL_QUADS);
    glVertex2i(700,220);
    glVertex2i(700,140);
    glVertex2i(850,140);
    glVertex2i(850,220);
    glEnd();

    glColor3ub(100,100,100);
    glBegin(GL_QUADS);
    glVertex2i(720,240);
    glVertex2i(700,220);
    glVertex2i(850,220);
    glVertex2i(870,240);
    glEnd();

    glColor3ub(0,128,128);
    glBegin(GL_TRIANGLES);
    glVertex2i(700,160);
    glVertex2i(720,239);
    glVertex2i(700,220);
    glEnd();

    glColor3ub(0,128,128);
    glBegin(GL_TRIANGLES);
    glVertex2i(850,160);
    glVertex2i(870,240);
    glVertex2i(850,220);
    glEnd();

    glColor3ub(100,100,100);
    glBegin(GL_QUADS);
    glVertex2i(690,139);
    glVertex2i(690,130);
    glVertex2i(860,130);
    glVertex2i(860,139);
    glEnd();

    glColor3ub(50,50,50);
    glDisable(GL_LINE_STIPPLE);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(720,155);
    glVertex2i(840,155);

    glVertex2i(730,155);
    glVertex2i(730,140);
    glVertex2i(750,155);
    glVertex2i(750,140);
    glVertex2i(770,155);
    glVertex2i(770,140);
    glVertex2i(790,155);
    glVertex2i(790,140);
    glVertex2i(810,155);
    glVertex2i(810,140);
    glVertex2i(830,155);
    glVertex2i(830,140);
    glEnd();

    ///Mall
 glBegin(GL_QUADS);
    glColor3ub(30,144,255);

    glVertex2i(450,150);
    glVertex2i(600,150);

    glVertex2i(600,300);
    glVertex2i(450,300);
    glEnd();


    glLineWidth(7.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2i(450,200);
    glVertex2i(600, 200);

     glVertex2i(450,250);
    glVertex2i(600, 250);

     glVertex2i(450,300);
    glVertex2i(600, 300);

   glEnd();




    glBegin(GL_QUADS);
    glColor3ub(30,144,255);
    glVertex2i(600,150);
    glVertex2i(630,160);
    glVertex2i(630,310);
    glVertex2i(600,300);

    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(600,200);
    glVertex2i(630,210);

    glVertex2i(600,250);
    glVertex2i(630,260);

    glVertex2i(600,300);
    glVertex2i(630,310);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2i(600,150);
    glVertex2i(600, 300);

    glEnd();

   glBegin(GL_QUADS);
    glColor3ub(30,144,255);

     glVertex2i(450,304);
    glVertex2i(460,315);
    glVertex2i(632,315);
    glVertex2i(600,304);

    glEnd();

  glBegin(GL_QUADS);
    glColor3ub(175,238,238);

     glVertex2i(500,150);
    glVertex2i(550,150);
    glVertex2i(550,190);
    glVertex2i(500,190);

    glEnd();


  ///billboard
glColor3ub(47,79,79);


  glBegin(GL_QUADS);
    glColor3ub(47,79,79);

     glVertex2i(200,200);
    glVertex2i(350,200);
    glVertex2i(350,290);
    glVertex2i(200,290);


glEnd();

text(250, 245, "Close Up");

glLineWidth(7.5);
     glBegin(GL_LINES);
    glColor3ub(47,79,79);

     glVertex2i(275,150);
    glVertex2i(275,200);

   glEnd();

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
}


void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


   DayTime();
   //NightTime();


    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();

    glPushMatrix();

    glutPostRedisplay();

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
    glutCreateWindow("A HIGHWAY VIEW");
    glutDisplayFunc(Display);

    myInit();
    glutMainLoop();
}

