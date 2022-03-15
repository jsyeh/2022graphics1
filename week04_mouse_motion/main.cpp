#include <GL/glut.h>
float angle=0, oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�ƥ��x�}
        glRotatef(angle, 0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
}
void motion(int x, int y)
{
    angle += (x-oldX);
    oldX = x;
    display();///���e�e��
}
void mouse(int button, int state, int x, int y)
{
    oldX = x; ///�w��
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion);///mouse motion��
    glutMouseFunc(mouse);///�W�g��: mouse���U�h�B��}��
    glutMainLoop();
}
