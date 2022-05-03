#include <GL/glut.h>
void hand(){
    glColor3f(0,1,0);
    glutSolidTeapot( 0.2 );
}
void body(){
    glColor3f(1,1,0);
    glutSolidTeapot( 0.3 );
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    body();
    glPushMatrix();
        glTranslatef(0.5, 0.2, 0);
        glRotatef(angle, 0,0,1);
        glTranslatef(0.3, 0, 0);
        hand();
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 TRT");

    glutIdleFunc( display );
    glutDisplayFunc( display );

    glutMainLoop();
}
