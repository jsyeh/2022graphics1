#include <opencv/highgui.h> ///���\�F!!!
///�ӤWCompiler Include���F
int main()
{///Ipl: Intel perfromance library
    IplImage * img = cvLoadImage("smile.png");
    cvShowImage( "week09", img );
    cvWaitKey( 0 );///���ݫ���,����A������
}
