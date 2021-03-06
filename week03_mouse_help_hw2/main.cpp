///week03_mouse_help_hw2
#include <GL/glut.h>
#include <stdio.h>///printf()印東西用的
float mouseX=0, mouseY=0;///新加的
void myTeapot(float x, float y)
{
    glPushMatrix();///備份矩陣 (備份舊的位置)
        glTranslatef(x, y, 0);
        glColor3f(25/255.0 , 208/255.0 , 32/255.0);///0...1 要除/255.0
        glutSolidTeapot(0.1);///茶壼
    glPopMatrix();///還原矩陣 (還原舊的位置)
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///myTeapot(   (mouseX-150)/150.0, -(mouseY-150)/150.0 );///新加的
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y )
{
    ///printf("%d %d %d %d\n", button, state, x, y);
    printf("  glVertex2f( (%d-150)/150.0, -(%d-150)/150.0 );\n", x,y);
    mouseX=x; mouseY=y;///新加的
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新加的 滑鼠事件

    glutMainLoop();
}
