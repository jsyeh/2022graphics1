///�W�g���Ʋ�
#include <GL/glut.h>
#include <stdio.h>
int mx[1000],my[1000];///�Ψӳƥ��A��mouse���y��
int N=0;///���X���I���n�F?
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){
        glVertex2f( (mx[i]-150)/150.0, -(my[i]-150)/150.0 );
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{//  printf("%d %d %d %d\n", button, state, x, y);
    if(state==GLUT_DOWN){///�p�Gstate�O���U�h0,�~�L�{���X
        printf("    glVertex2f( (%d-150)/150.0, -(%d-150)/150.0 );\n", x, y);
        N++;
        mx[N-1]=x; my[N-1]=y;
    }
    display();///���e
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///�W�g��: mouse���U�h�B��}��
    glutMainLoop();
}
