///�ΤW�@�ӵ{���ӧ�
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h" ///�ϥ�3D�ҫ�
GLMmodel * pmodel = NULL;///�ϥ�3D�ҫ�
///GLUquadric * sphere = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;///���ਤ��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle, 0,1,0);
        if(pmodel==NULL){ ///�ϥ�3D�ҫ�
            pmodel = glmReadOBJ( "data/Gundam.obj" ); ///�ϥ�3D�ҫ�
            glmUnitize(pmodel);///�ϥ�3D�ҫ�,�Y��� -1...+1��,�~�ݱo��
            glmFacetNormals(pmodel);///�ϥ�3D�ҫ�,�����k�V�q
            glmVertexNormals(pmodel, 90);///�ϥ�3D�ҫ�, ���I���k�V�q
        }
        glmDraw(pmodel, GLM_TEXTURE);
    glPopMatrix();

    glutSwapBuffers();
    angle+=1; ///�C������ display() �[ 1��
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glEnable(GL_DEPTH_TEST);///�}3D�`�״���,�~�|��3D���ĪG
    glutIdleFunc(display);///����idle �I�s display()
    glutDisplayFunc(display);
    myTexture( "data/Diffuse.jpg" );
    ///myTexture("earth.jpg");///�a�y���a��,�ϵ��@�U�|�ǳƦn
    ///sphere = gluNewQuadric();///�ǳƦn�G������

    glutMainLoop();
}
