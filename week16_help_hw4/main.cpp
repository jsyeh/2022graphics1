///week15_hw_gundam_parts
///修改自week15_angle_TRT_again
#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
float dx=0, dy=0, dz=0;
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

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
float angle[20], oldX=0, oldY=0;
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
    oldX = x; oldY = y;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    ///myWrite();
    dx += (x-oldX)/150.0;
    dy -= (y-oldY)/150.0;
    printf("glTranslatef(%.2f, %.2f, %.2f);\n", dx,dy,dz);
    oldX = x;
    oldY = y;
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
    glColor3f(1,0,0);
    glutSolidTeapot( 0.05 );

    glColor3f(1,1,1);///白色的
    glmDraw(body, GLM_SMOOTH);

    glPushMatrix();
        glTranslatef(-0.21, 0.03, 0.00);
        glRotatef(angle[1],0,0,1);
        glTranslatef(0.01, -0.07, 0.00);
        glmDraw(arm1, GLM_SMOOTH);
        glPushMatrix();
            glTranslatef(-0.03, -0.11, 0.00);;//glTranslatef(dx,dy,dz);
            glRotatef(angle[2], 0, 0, 1);
            glRotatef(angle[3], 1, 0, 0);
            glTranslatef(-0.01, -0.22, 0.00);
            glmDraw(hand1, GLM_SMOOTH);
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

    body = myReadOne("data/body.obj");
    arm1 = myReadOne("data/arm1.obj");
    hand1 = myReadOne("data/hand1.obj");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutMainLoop();
}
