#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include<iostream>
#include <time.h>
using namespace std;


void drawPoint(int x, int y)
{
    glPointSize(7.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
float x[]={-250,0,250},y[]={-250,250,-250}, X[3],Y[3];;
float angle,theta;
void rotateCustom()
{

    glClear(GL_COLOR_BUFFER_BIT);

    theta=angle* 3.14 / 180;

    int i=0;

    for(i=0;i<3;i++){
        X[i] =  ((float)(x[i]) * cos(theta))
             - ((float)(y[i]) * sin(theta));
        Y[i] =  ((float)(x[i]) * sin(theta))
             + ((float)(y[i]) * cos(theta));
    }
    glBegin(GL_POLYGON);
        for(i=0;i<3;i++){
            glVertex2d(X[i],Y[i]);
        }
    glEnd();
    glPointSize(3);
    glColor3f(0,0,0);
    glBegin(GL_POINTS);
    glVertex2d(0,0);
    glEnd();
    glFlush();

}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0,500.0,-500.0,500.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,1.0,1.0);
    rotateCustom();
    angle-=0.01;

}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Rotation");
    glutDisplayFunc(display);
    glutIdleFunc(display);

    init();
    glutMainLoop();
}
