#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///���⪺
    glutSolidTeapot( 0.3 );///����
    glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y )
{
    printf("�A���U�F %c �b %d %d �y��\n", key, x, y );
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///���Ѫ��D��
    glutMainLoop();
}
