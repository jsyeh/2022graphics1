#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
float dx=0, dy=0, dz=0, oldX=0, oldY=0;
GLuint tex1, tex2;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
GLMmodel * pmodel = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * arm1 = NULL,  * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * bot = NULL;
GLMmodel * leg1 = NULL,  * leg2 = NULL;
GLMmodel * knee1 = NULL, * knee2 = NULL;
GLMmodel * foot1 = NULL, * foot2 = NULL;
GLMmodel * myReadOne(char * filename){///改寫
    GLMmodel * one = NULL;
    if( one == NULL){
        one = glmReadOBJ(filename);
        ///glmUnitize(one);///我們的模型,原來 Y 是 0~26. 好高哦
        glmScale(one, 1/26.0 );
        glmFacetNormals(one);
        glmVertexNormals(one, 90);
    }
    return one;
}
void myReadAll(){
    pmodel = myReadOne("data/Gundam.obj");
    head = myReadOne("data/head.obj");
    body = myReadOne("data/body.obj");
    arm1 = myReadOne("data/arm1.obj");
    arm2 = myReadOne("data/arm2.obj");
    hand1 = myReadOne("data/hand1.obj");
    hand2 = myReadOne("data/hand2.obj");
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void myLight(){
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
}
void reshape(int w, int h){
    float ar = (float)w/(float)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, ar, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( 0, 0, 2,   0, 0, 0,  0, 1, 0);
}
float angleX[20], angleY[20];
int angleID=0;
void keyboard(unsigned char key, int x, int y){
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, tex1);
    ///glmDraw(pmodel, GLM_TEXTURE | GLM_SMOOTH);

    glmDraw(body, GLM_TEXTURE | GLM_SMOOTH);///身體
    glPushMatrix();
        glTranslatef( 0.00, +0.85, 0);
        glRotatef(angleX[0], 0, 1, 0);
        glRotatef(angleY[0], 1, 0, 0);
        glTranslatef( 0.00 , -0.85 , 0.00 );///glTranslatef( dx, dy, dz);
        glmDraw(head, GLM_TEXTURE | GLM_SMOOTH);///頭
    glPopMatrix();

    glPushMatrix();///左邊
        glTranslatef(-0.15 , +0.81 , 0.00 );///glTranslatef()
        glRotatef(angleY[1], 0, 0, 1);
        glRotatef(angleX[1], 0, 1, 0);
        glTranslatef( 0.15 , -0.81 , 0.00 );///glTranslatef( dx, dy, dz);
        glmDraw(arm1, GLM_TEXTURE | GLM_SMOOTH);///上手臂

        glPushMatrix();
            glTranslatef(-0.17 , +0.70 , 0.00 );
            glRotatef(angleY[2], 1, 0, 0);
            glRotatef(angleX[2], 0, 1, 0);
            glTranslatef( 0.17 , -0.70 , 0.00 );///glTranslatef( dx, dy, dz);
            glmDraw(hand1, GLM_TEXTURE | GLM_SMOOTH);///手肘
        glPopMatrix();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, tex2);
    glutSolidTeapot( 0.03 );

    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y){
    oldX=x; oldY=y;
}
void motion(int x, int y){
    dx += (x-oldX)/150.0;  dy -= (y-oldY)/150.0;
    angleX[angleID] += (x-oldX);
    angleY[angleID] += (y-oldY);
    printf("glTranslatef( %.2f , %.2f , %.2f );\n", dx, dy, dz);
    oldX = x;        oldY = y;
    glutPostRedisplay();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week17 demo");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    myLight();
    tex1 = myTexture("data/Diffuse.jpg");///要記得放在工作目錄
    tex2 = myTexture("data/wood.png");

    ///glClearColor(1, 1, 0, 0);///換一下位置,因為只要讀一次
    myReadAll();///換一下位置,因為只要讀一次

    glutMainLoop();
}
