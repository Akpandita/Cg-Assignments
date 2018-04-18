#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include <iostream>
using namespace std;
void Midpointcircle() {
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);
    float radius = 100;
    float x = 0, y = radius;
    float decision = 1 - radius;
    glBegin(GL_POINTS);
    while (x != y)
    {
        x++;
        if (decision < 0) {
            decision += 2 * (x + 1) + 1;
        }
        else {
            y--;
        decision += 2 * (x + 1) + 1 - 2 * (y - 1);
    }
    glVertex2i(x, y);
    glVertex2i(-x, y);
    glVertex2i(x, -y);
    glVertex2i(-x, -y);

    glVertex2i(y, x);
    glVertex2i(-y, x);
    glVertex2i(y, -x);
    glVertex2i(-y, -x);
    }
    glEnd();
    glFlush();
}
int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Draw OpenGL");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-250, 250, -250, 250);
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, 500, 500);

    glutDisplayFunc(Midpointcircle);
    glutMainLoop();
    return 0;
}
