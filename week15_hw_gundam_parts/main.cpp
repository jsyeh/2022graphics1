///week15_hw_gundam_parts
///修改自week15_angle_TRT_again
#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
GLMmodel * pmodel = NULL;///全部的
GLMmodel * body = NULL;///分塊的模型,作業用分塊的模型
GLMmodel * head = NULL;
GLMmodel * arm1 = NULL;
GLMmodel * arm2 = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;
GLMmodel * bot = NULL;
GLMmodel * leg1 = NULL;
GLMmodel * leg2 = NULL;
GLMmodel * knee1 = NULL;
GLMmodel * knee2 = NULL;
GLMmodel * foot1 = NULL;
GLMmodel * foot2 = NULL;
float angle[20], oldX=0;
int angleID=0;
FILE * fout = NULL, * fin = NULL;
void myWrite(){///每呼叫一次myWrite()
    if( fout == NULL ) fout = fopen("file.txt", "w+");

    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i] );///小黑印出來
        fprintf(fout, "%.1f ", angle[i] );///檔案印出來
    }///印出20個數字
    printf("\n");///每呼叫一次, 小黑跳行
    fprintf(fout, "\n");///每呼叫一次, 檔案也跳行
}///這裡老師沒有fclose
void myRead(){
    if( fout != NULL ) { fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f", &angle[i] );
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key, int x, int y){
    if( key=='s' ) myWrite();///調好動作,才Save存檔
    if( key=='r' ) myRead();
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
    ///myWrite();
    oldX = x;
    glutPostRedisplay();
}
GLMmodel * myReadOne(char * filename){
    GLMmodel * one=NULL;
    if(one==NULL){
        one = glmReadOBJ(filename);
        glmUnitize(one);
        glmFacetNormals(one);
        glmVertexNormals(one, 90);
    }
    return one;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///glColor3f(1,1,1);
    ///glRectf( 0.3, 0.5,  -0.3, -0.5);
    if(body==NULL) body = myReadOne("data/body.obj");
    glmDraw(body, GLM_TEXTURE | GLM_SMOOTH );

    glPushMatrix();
        glTranslatef( 0.3,  0.4, 0);
        glRotatef(angle[0], 0,0,1);
        glTranslatef(-0.3, -0.4, 0);
        ///glColor3f(1,0,0);
        ///glRectf( 0.3, 0.5,  0.7, 0.3);
        if(arm1==NULL) arm1 = myReadOne("data/arm1.obj");
        glmDraw(arm1, GLM_TEXTURE | GLM_SMOOTH);

        glPushMatrix();
            glTranslatef( 0.7,  0.4, 0);
            glRotatef(angle[1], 0,0,1);///(2)����
            glTranslatef(-0.7, -0.4, 0);///(1)���y���त��,�񤤤�
            ///glColor3f(0,1,0);///��⪺
            ///glRectf( 0.7, 0.5, 1.0, 0.3);///�k�U��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///���b��
        glTranslatef(-0.3,  0.4, 0);///(3)����u���^����
        glRotatef(angle[2], 0,0,1);///(2)���� ��z�b��
        glTranslatef(+0.3, -0.4, 0);///(1)����u���त��,�񤤤�
        glColor3f(1,0,0);///���⪺
        glRectf(-0.3, 0.5, -0.7, 0.3);///���W���u

        glPushMatrix();
            glTranslatef(-0.7,  0.4, 0);///(3)���y���^��誺��m
            glRotatef(angle[3], 0,0,1);///(2)����
            glTranslatef(+0.7, -0.4, 0);///(1)���y���त��,�񤤤�
            glColor3f(0,1,0);///��⪺
            glRectf(-0.7, 0.5,-1.0, 0.3);///���U��y
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week15 angles TRT again");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}
