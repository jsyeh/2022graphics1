///Week14_timer_one_by_one 每天早晨, 老師 05:50 鬧鐘響
///起床,閉著眼,再設定 05:53鬧鐘,再睡
///起床,閉著眼,再設定 05:56鬧鐘,再睡
///...
///起床,閉著眼,再設定 07:50鬧鐘...嚇死了..
#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){
	printf("我起床囉! %d\n", t);
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

    glutTimerFunc(5000, timer, 0);///設定: 5秒後, 第0個timer
    glutDisplayFunc(display);
    glutMainLoop();
}
