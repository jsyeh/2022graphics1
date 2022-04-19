#include <opencv/highgui.h> ///成功了!!!
///樓上Compiler Include找到了
int main()
{///Ipl: Intel perfromance library
    IplImage * img = cvLoadImage("smile.png");
    cvShowImage( "week09", img );
    cvWaitKey( 0 );///等待按鍵,等到你按為止
}
