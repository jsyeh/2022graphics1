#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ�
    glutSolidTeapot( 0.3 );///�������
    glPushMatrix();
        glTranslatef(0.2, 0, 0);///(3)����k�� (���ө��k����)
        glRotatef( angle, 0, 0, 1);///(2)����
        glTranslatef(0.2, 0, 0); ///(1)����त��,���@�ɤ���
        glColor3f(1,0,0);///���⪺
        glutSolidTeapot( 0.2 );///�p���� �Q�����O���u
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main( int argc, char** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE|GLUT_DEPTH );
    glutCreateWindow("week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
