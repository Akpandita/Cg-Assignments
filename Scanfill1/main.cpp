#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#define ht 500
#define wd 500
using namespace std;
float x1, x2, x3, x4, yy, y2, y3, y4, theta = 1 * (3.14 / 180);
void draw_pixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void edgedetect(float x1,float yy,float x2,float y2,int *le,int *re)
{
    float temp,x,mx;
    int i;

    if(yy>y2)
    {
        temp=x1,x1=x2,x2=temp;
        temp=yy,yy=y2,y2=temp;
    }

    if(yy==y2)
        mx=x2-x1;
    else
        mx=(x2-x1)/(y2-yy);

    x=x1;

    for(i=int(yy); i<=(int)y2; i++)
    {
        if(x<(float)le[i]) le[i]=(int)x;
        if(x>(float)re[i]) re[i]=(int)x;
        x+=mx;
    }
}

void scanfill(float x1,float yy,float x2,float y2,float x3,float y3,float x4,float y4)
{
    int le[500],re[500],i,j;

    for(i=0; i<500; i++)
        le[i]=500,re[i]=0;

    edgedetect(x1,yy,x2,y2,le,re);
    edgedetect(x2,y2,x3,y3,le,re);
    edgedetect(x3,y3,x4,y4,le,re);
    edgedetect(x4,y4,x1,yy,le,re);

    for(j=0; j<500; j++)
    {
        if(le[j]<=re[j])
            for(i=le[j]; i<re[j]; i++)
                draw_pixel(i,j);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,yy);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    scanfill(x1,yy,x2,y2,x3,y3,x4,y4);
    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    x1=0.0f;
    yy=0.0f;
    x2=1.0f;
    y2=1.0f;
    x3=1.0f;
    y3=9.0f;
    x4=0.5f;
    y4=10.0f;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);

    glutCreateWindow("Scan Line");
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-250, 250.0, -250.0, 250.0);
    glutMainLoop();
}
