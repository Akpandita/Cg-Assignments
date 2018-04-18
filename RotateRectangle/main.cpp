
#include <windows.h>
#include <GL/glut.h>
float angle = 0.1f;
float x=0.5f;
float y=0.0f;
float dx=0.0001f;
float dy=0.00008f;

void initGL() {
   glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
}

void idle() {
   glutPostRedisplay();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(x, y, 0.0f);
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   float p1[]={-0.6f, -0.1f};
   float p2[]={0.6f, -0.1f};
   float p3[]={0.6f,  0.1f};
   float p4[]={-0.6f,  0.1f};
   glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2fv(p1);
      glVertex2fv(p2);
      glVertex2fv(p3);
      glVertex2fv(p4);
   glEnd();
   glPopMatrix();
   glutSwapBuffers();
   angle += 0.2f;
   x-=dy;
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Rotation of Polygon");
   glutDisplayFunc(display);
   glutIdleFunc(idle);
   initGL();
   glutMainLoop();
   return 0;
}
