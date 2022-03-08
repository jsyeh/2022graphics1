///把上週的程式 copy進來
#include <GL/glut.h>
#include <math.h>///sin(), cos()
void myCircle( float x, float y, float r )
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a), y+r*sin(a) );
    }///要畫三角函數
    glEnd();
}
void myCircle2( float x, float y, float r )
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+2*r*cos(a), y+r*sin(a) );
    }///要畫三角函數
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f( 1,1,0 );
    myCircle(0, 0, 2);

    glColor3f( 0.6 ,0.6 ,0.6 );
    myCircle(0, 0, 0.6);

    glColor3f( 1,1,1);
    myCircle(0, 0, 0.45);

    glColor3f( 0,0,0);
    myCircle(0, 0, 0.3);

    glColor3f( 1,0,0);
    myCircle2(0.8, -0.6, 0.1);
    myCircle2(-0.8, -0.6, 0.1);

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 作業2想加分");

    glutDisplayFunc( display );
    glutMainLoop();
}
