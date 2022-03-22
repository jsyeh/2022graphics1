///接續剛剛的 week05_keyboard 變成 keyboard+mouse+motion
#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0, scale=1.0;
int oldX=0, oldY=0;
void display()
{
    glClearColor( 0.5, 0.5, 0.5, 1 );///R,G,B,A 其中A半透明功能,目前沒開
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 ,z);
        glScalef(scale, scale, scale);///都縮放成 scale倍
        glColor3f(1,1,0);///黃色的
        glutSolidTeapot( 0.3 );///茶壼
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
}
void mouse(int button, int state, int mouseX, int mouseY )
{///為了解決瞬間移動的錯誤,我們改用正確的方法
    oldX = mouseX; oldY = mouseY;
}
void motion(int mouseX, int mouseY)
{
    if( mouseX-oldX > 0 ) scale *= 1.01;
    if( mouseX-oldX < 0 ) scale *= 0.99;
    ///x += (mouseX-oldX);  y += (mouseY-oldY);
    oldX = mouseX;       oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///今天的主角
    glutMouseFunc(mouse);///上上週的主角
    glutMotionFunc(motion);///上週的主角
    glutMainLoop();
}
