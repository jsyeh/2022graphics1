///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=0, oldX=0;
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();///請GLUT重畫畫面 Re display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf( 0.3, 0.5,  -0.3, -0.5);///身體,四邊形

    glPushMatrix();
        glTranslatef( 0.3,  0.4, 0);///(3)把手臂掛回身體
        glRotatef(angle, 0,0,1);///(2)旋轉 對z軸轉
        glTranslatef(-0.3, -0.4, 0);///(1)把手臂旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf( 0.3, 0.5,  0.7, 0.3);///上手臂

        glPushMatrix();
            glTranslatef( 0.7,  0.4, 0);///(3)把手肘掛回剛剛的位置
            glRotatef(angle, 0,0,1);///(2)旋轉
            glTranslatef(-0.7, -0.4, 0);///(1)把手肘旋轉中心,放中心
            glColor3f(0,1,0);///綠色的
            glRectf( 0.7, 0.5, 1.0, 0.3);///下手肘
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}
