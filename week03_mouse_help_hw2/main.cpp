///week03_mouse_help_hw2
#include <GL/glut.h>
#include <stdio.h>///printf()�L�F��Ϊ�
float mouseX=0, mouseY=0;///�s�[��
void myTeapot(float x, float y)
{
    glPushMatrix();///�ƥ��x�} (�ƥ��ª���m)
        glTranslatef(x, y, 0);
        glColor3f(25/255.0 , 208/255.0 , 32/255.0);///0...1 �n��/255.0
        glutSolidTeapot(0.1);///����
    glPopMatrix();///�٭�x�} (�٭��ª���m)
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///myTeapot(   (mouseX-150)/150.0, -(mouseY-150)/150.0 );///�s�[��
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y )
{
    ///printf("%d %d %d %d\n", button, state, x, y);
    printf("  glVertex2f( (%d-150)/150.0, -(%d-150)/150.0 );\n", x,y);
    mouseX=x; mouseY=y;///�s�[��
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 ����");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///�s�[�� �ƹ��ƥ�

    glutMainLoop();
}
