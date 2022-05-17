///week13_rect_many_TRT
#include <GL/glut.h>
float angle[20], oldX=0;
int angleID=0; ///0號關節, 1號關節, 2號關節, 3號關節
void keyboard(unsigned char key, int x, int y){
    if( key=='0' ) angleID=0;
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    oldX = x;
    glutPostRedisplay();///請GLUT重畫畫面 Re display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf( 0.3, 0.5,  -0.3, -0.5);///身體,四邊形

    glPushMatrix(); ///右半部
        glTranslatef( 0.3,  0.4, 0);///(3)把手臂掛回身體
        glRotatef(angle[0], 0,0,1);///(2)旋轉 對z軸轉
        glTranslatef(-0.3, -0.4, 0);///(1)把手臂旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf( 0.3, 0.5,  0.7, 0.3);///右上手臂

        glPushMatrix();
            glTranslatef( 0.7,  0.4, 0);///(3)把手肘掛回剛剛的位置
            glRotatef(angle[1], 0,0,1);///(2)旋轉
            glTranslatef(-0.7, -0.4, 0);///(1)把手肘旋轉中心,放中心
            glColor3f(0,1,0);///綠色的
            glRectf( 0.7, 0.5, 1.0, 0.3);///右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左半部
        glTranslatef(-0.3,  0.4, 0);///(3)把手臂掛回身體
        glRotatef(angle[2], 0,0,1);///(2)旋轉 對z軸轉
        glTranslatef(+0.3, -0.4, 0);///(1)把手臂旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3, 0.5, -0.7, 0.3);///左上手臂

        glPushMatrix();
            glTranslatef(-0.7,  0.4, 0);///(3)把手肘掛回剛剛的位置
            glRotatef(angle[3], 0,0,1);///(2)旋轉
            glTranslatef(+0.7, -0.4, 0);///(1)把手肘旋轉中心,放中心
            glColor3f(0,1,0);///綠色的
            glRectf(-0.7, 0.5,-1.0, 0.3);///左下手肘
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

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}
