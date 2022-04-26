///ノ祘Αㄓэ
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h" ///ㄏノ3D家
GLMmodel * pmodel = NULL;///ㄏノ3D家
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
float angle=0;///臂锣à
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle, 0,1,0);
        if(pmodel==NULL){ ///ㄏノ3D家
            pmodel = glmReadOBJ( "data/Gundam.obj" ); ///ㄏノ3D家
            glmUnitize(pmodel);///ㄏノ3D家,罽 -1...+1丁,眔
            glmFacetNormals(pmodel);///ㄏノ3D家,猭秖
            glmVertexNormals(pmodel, 90);///ㄏノ3D家, 郴翴猭秖
        }
        glmDraw(pmodel, GLM_TEXTURE);
    glPopMatrix();

    glutSwapBuffers();
    angle+=1; ///–Ω磅︽ display()  1
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glEnable(GL_DEPTH_TEST);///秨3D瞏代刚,穦Τ3D狦
    glutIdleFunc(display);///Τidle ㊣ display()
    glutDisplayFunc(display);
    myTexture( "data/Diffuse.jpg" );
    ///myTexture("earth.jpg");///瞴瓜,瓜单穦非称
    ///sphere = gluNewQuadric();///非称ΩΡ

    glutMainLoop();
}
