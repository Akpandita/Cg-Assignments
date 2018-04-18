#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

float angle=0.01f;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(angle,1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(0.3,0.6,0.0);
    glVertex3f(0.3,0.3,0.0);
    glVertex3f(0.6,0.6,0.0);
    glVertex3f(0.6,0.3,0.0);
    glEnd();
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0.0, 0.0, w, h);
}
void intiopenGL()
{
    glClearColor(0.8, 0.0, 0.0, 1.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Test");
    intiopenGL();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
