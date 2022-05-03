#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h" ///���b�M�ץؿ���
GLMmodel * pmodel = NULL; ///����,����ҫ�,�w�]�ONULL�ū���
GLMmodel * head=NULL;
GLMmodel * body=NULL;

GLMmodel * arm1=NULL;
GLMmodel * arm2=NULL;
GLMmodel * hand1=NULL;
GLMmodel * hand2=NULL;

GLMmodel * leg1=NULL;
GLMmodel * knee1=NULL;
GLMmodel * foot1=NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    if( pmodel == NULL ){ ///�p�G�O �ū���, ��ܼҫ��S�ǳƦn
        pmodel = glmReadOBJ("data/head.obj"); ///�NŪ�ҫ�
        glmUnitize( pmodel ); ///���⦨Unit���j�p -1...+1
        glmFacetNormals( pmodel ); ///���s�p��ҫ��������k�V�q
        glmVertexNormals( pmodel , 90 ); ///���s�p��ҫ������I���k�V�q
    }

    glPushMatrix();
        glRotatef(angle, 0,1,0);
        glmDraw( pmodel, GLM_TEXTURE ); ///���ҫ���, �e��,�n�O�o�e�K��
    glPopMatrix();

    glutSwapBuffers();
    angle += 1;
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 gundam");

    glutIdleFunc( display );
    glutDisplayFunc( display );
    myTexture("data/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
