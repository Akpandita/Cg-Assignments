#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

void display()
{ gluLookAt(0.5,0.5,0,1.73/2,1.73/2,1.73/2,0,0,1);
    glBegin(GL_QUADS);
                glColor3f(0.0,0.5,1.0);
               glVertex3f(0.0f, 0.0f,0.0); // vertex 1
               glVertex3f(0.5f, 0.0,0.0f); // vertex 2
               glVertex3f(0.5f,0.5f,0); // vertex 3
               glVertex3f(0.0f,0.5f,0); // vertex 4
       glEnd();
    glBegin(GL_QUADS);
                glColor3f(0.0,0.5,1.0);
               glVertex3f(0.0f, 0.0f,0.5); // vertex 1
               glVertex3f(0.5f, 0.0,0.5f); // vertex 2
               glVertex3f(0.5f,0.5f,0.5); // vertex 3
               glVertex3f(0.0f,0.5f,0.5); // vertex 4
       glEnd();
    glBegin(GL_QUADS);
                glColor3f(0.0,0.5,0);
               glVertex3f(0.0f, 0.0f,0.0);
               glVertex3f(0.0f,0.0f,0.5); // vertex 1
               glVertex3f(0.0f,0.5f,0.5); // vertex 3
               glVertex3f(0.0f, 0.5,0.0f);
       glEnd();
    glBegin(GL_QUADS);
                glColor3f(0.0,0.5,0);
               glVertex3f(0.5f, 0.0f,0.0);
               glVertex3f(0.5f,0.0f,0.5); // vertex 1
               glVertex3f(0.5f,0.5f,0.5); // vertex 3
               glVertex3f(0.5f, 0.5,0.0f);
       glEnd();
    glBegin(GL_QUADS);
                glColor3f(0.5,0,0);
               glVertex3f(0.0f, 0.0f,0.0);
               glVertex3f(0.0f,0.0f,0.5); // vertex 1
               glVertex3f(0.5f,0.0f,0.5); // vertex 3
               glVertex3f(0.5f, 0.0,0.0f);
       glEnd();

    glBegin(GL_QUADS);
                glColor3f(0.5,0,0);
               glVertex3f(0.0f, 0.5f,0.0);
               glVertex3f(0.0f,0.5f,0.5); // vertex 1
               glVertex3f(0.5f,0.5f,0.5); // vertex 3
               glVertex3f(0.5f, 0.5,0.0f);
       glEnd();

glutSwapBuffers();
}

void reshape(int w, int h)
{
glViewport(0.0, 0.0, w, h);
}
void intiopenGL()
{
glClearColor(1.0, 1.0, 1.0, 1.0);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
glutInitWindowSize(800, 600);
glutInitWindowPosition(300,50);
glutCreateWindow("OpenGL Test");

intiopenGL();

glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();


return 0;
}
