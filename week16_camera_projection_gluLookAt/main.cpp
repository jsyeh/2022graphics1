#include <GL/glut.h>
void reshape(int w, int h){///不能 整數除
    float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);///3D變2D
    glLoadIdentity();
    gluPerspective(60, ar, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);///3D Model+View
    glLoadIdentity() ;
    gluLookAt(0, 0, 3, ///eye
              0, 0, 0, ///center看哪裡
              0, 1, 0);///up向量
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);
    glutSwapBuffers();
}
void motion(int x, int y){///新加的
    glMatrixMode(GL_MODELVIEW);///3D Model+View
    glLoadIdentity() ;
    gluLookAt((x-150)/150.0, (y-150)/150.0, 3, ///eye
              0, 0, 0, ///center看哪裡
              0, 1, 0);///up向量
    glutPostRedisplay();///請重畫畫面
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16 camera");
    glutMotionFunc(motion);///新加的
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);///範例是用resize
    glutMainLoop();
}
