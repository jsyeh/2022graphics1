///Week14_timer_one_by_one �C�Ѧ���, �Ѯv 05:50 �x���T
///�_��,���۲�,�A�]�w 05:53�x��,�A��
///�_��,���۲�,�A�]�w 05:56�x��,�A��
///...
///�_��,���۲�,�A�]�w 07:50�x��...�~���F..
#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){
	printf("�ڰ_���o! %d\n", t);
	PlaySound("do.wav", NULL, SND_ASYNC);
	glutTimerFunc(2000, timer, t+1 );
}
void display(){
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutTimerFunc(5000, timer, 0);///�]�w: 5���, ��0��timer
    glutDisplayFunc(display);
    glutMainLoop();
}
