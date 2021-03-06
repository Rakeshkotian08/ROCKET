#include<windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include<math.h>



void expression(int x,int y,int r,int n,int l,int t)
{

    float m;
    glBegin(GL_LINE_STRIP);
    for( int angle = l; angle < t; angle ++ ){
        m=angle*3.142/180;
       glVertex2f( x+r*cos(m),y+n*sin(m));}
    glEnd();

}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    expression(280,300,23,50,0,360);
    expression(330,300,23,50,0,360);
    expression(300,300,210,250,166,376);
    expression(150,470,120,120,8,245);
    expression(450,470,120,120,-64,174);
    expression(300,489,30,5,-10,190);
    expression(300,180,55,35,0,360);
    expression(300,190,130,80,180,360);
    expression(170,170,30,20,50,130);
    expression(430,170,30,20,50,130);
    expression(300,187,95,110,215,325);
    expression(290,271,15,25,40,245);
    expression(320,271,15,25,-58,140);
    expression(237,290,90,150,45,200);
    expression(365,290,91,150,-21,137);
    expression(482,240,31,45,36,185);
    expression(120,240,31,45,10,155);
    glFlush();
}

void init(void)
{
   glClearColor(1,1,1,1);
   gluOrtho2D(0,600,0,600);
   glMatrixMode(GL_MODELVIEW);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
}
int main()
{
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("gasket");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

