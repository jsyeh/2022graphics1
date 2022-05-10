#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot( 0.3 );///茶壼當身體
    glPushMatrix();
        glTranslatef(0.2, 0, 0);///(3)掛到右邊 (把整個往右移動)
        glRotatef( angle, 0, 0, 1);///(2)旋轉
        glTranslatef(0.2, 0, 0); ///(1)把旋轉中心,放到世界中心
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot( 0.2 );///小茶壼 想像它是手臂
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
