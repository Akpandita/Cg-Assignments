#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define pi 3.1416
int r,t,a;
float x1,Y1,z1,x2,y2,z2;
double ang;
int n,i,j;
void idle() {
   glutPostRedisplay();
}
float** makeM(int rows,int col){
    float** m=NULL;
    m=(float**)malloc(rows*sizeof(float*));
    for(int i=0;i<rows;i++){
        m[i]=(float*)malloc(col*sizeof(float));
    }
    return m;
}
float** m[100];

float** translateM(float x,float y,float z){
float** m=makeM(4,4);
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        if(i==j){
            m[i][i]=1;
        }
        else{
            m[i][j]=0;
        }
    }}
    m[0][3]=x;
    m[1][3]=y;
    m[2][3]=z;
    return m;
}
float** scaleM(float x,float y,float z){
float** m=makeM(4,4);
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        if(i==j){
            m[i][j]=1;
        }
        else{
            m[i][j]=0;
        }
    }}
    m[0][0]=x;
    m[1][1]=y;
    m[2][2]=z;
    return m;
}
float** rotateM(double angle,int axis){
    float** m=makeM(4,4);
    double c=cos(angle);
    double s=sin(angle);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j){
                m[i][i]=1;
            }
            else{
                m[i][j]=0;
        }
    }
    }
    if(axis==1){
        m[1][1]=c;
        m[1][2]=-s;
        m[2][1]=s;
        m[2][2]=c;
    }
    if(axis==2){
        m[0][0]=c;
        m[0][2]=s;
        m[2][0]=-s;
        m[2][2]=c;
    }
    if(axis==3){
        m[0][0]=c;
        m[0][1]=-s;
        m[1][0]=s;
        m[1][1]=c;
    }
    return m;
}
float** vectorM(float x,float y,float z){
    float** m=makeM(4,1);
    m[0][0]=x;
    m[1][0]=y;
    m[2][0]=z;
    m[3][0]=1;
    return m;
}
float** mulM(float** a,float** b,int n1,int c1,int n2,int c2){
    float** m=makeM(n1,c2);
    for(int i=0;i<n1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<n2;k++){
                m[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return m;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    printf("%d\n",n);
    for(i=0;i<n;i++){
        printf("%f %f %f\n",m[i][0][0],m[i][1][0],m[i][2][0]);
    }
    float** trans=translateM(x1,Y1,z1);
    float** scale=scaleM(x2,y2,z2);
    float** rot=rotateM(ang,a);
    float** mul=mulM(rot,mulM(scale,trans,4,4,4,4),4,4,4,4);
    float** p[n];
    for(i=0;i<n;i++){
        p[i]=mulM(mul,m[i],4,4,4,1);
    }
    glBegin(GL_POLYGON);
    for(i=0;i<n;i++){
        glColor3f(1.0,0.0,0.0);
        glVertex3f(p[i][0][0],p[i][1][0],p[i][2][0]);
    }
    glEnd();
    glFlush();
}
void reshape(int w, int h)
{
glViewport(0.0, 0.0, w, h);
glLoadIdentity();
gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void intiopenGL()
{
glClearColor(1.0,1 ,1.0 , 1.0);
glColor3f(0.0,0.0,0.0);
}
int main(int argc, char** argv)
{
float x,y,z;
printf("Enter number of vertices of polygon");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("Point %d: ",i);
    scanf("%f %f %f",&x,&y,&z);
    m[i]=vectorM(x,y,z);
}
printf("Enter x,y,z for translation\n");
scanf("%f %f %f",&x1,&Y1,&z1);
printf("Enter x,y,z for scaling\n");
scanf("%f %f %f",&x2,&y2,&z2);
printf("Enter angle of rotation and axis");
scanf("%lf %d",&ang,&a);

glutInit(&argc, argv);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("Polygon");
intiopenGL();
gluOrtho2D(-250 , 250, -250 , 250);
glutDisplayFunc(display);
glutIdleFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}

