# 2022graphics1

# Week01
## 第一個 OpenGL 程式

0. CodeBlocks 17.12 mingw 裝好
1. File-New-Project, 選 OpenGL 專案
2. 在[點點點]的目錄,選「桌面」,Projects專案名存成 week01_OPENGL
3. 下一步下一步, 完成後, Build & Run
4. 可以看到彩色旋轉的三角形

## 第一個 GLUT 專案

1. Moodle 下載 freeglut ... zip
2. 解壓縮 桌面 freeglut目錄
3. 桌面 freeglut 的 lib 裡面有 libfreeglut.a 把它複製,改成 libglut32.a 才能讓我們的 CodeBlocks 的 GLUT專案連結使用

4. CodeBlocks: File-New-Project, 選 GLUT專案
5. 取名 week01_GLUT
6. 設定 GLUT 目錄 C:\Users\?????\Desktop\freeglut
7. Build & Run, 可看到 6個紅色的東西在轉動


## GitHub 備份程式
```
0. 登入 GitHub.com
1. New repo 新增專案倉庫
1.1. 取名 2022graphics
     (昨天乙班用掉了)
     或 2022graphics1
1.2. Public, Add README, 
     Add .gitignore 用C++
1.3. 綠色確認, 看到你的新的專案倉庫

2. 利用 Git指令
2.1. 安裝 Git for Windows

3. 開啟 Git Bash
3.1. cd desktop 進入桌面
3.2. git clone https://你的網址
3.3. cd 2022graphics1 

3.4. 把我們的2個程式目錄,放到2022graphics1
3.5. git status 看狀態(紅色2個目錄)
3.6. git add . 把它加進去
3.7. git status 再看狀態(變綠色)

4. 要推送上雲端
4.1. 要先有 commit 的動作, 第一次使用時,需

git config --global user.email "jsyeh@mail.mcu.edu.tw"
git config --global user.name "jsyeh"

git commit -m "訊息"

4.2. git push 推送上雲端
(Chrome 要登入才行)
```



# Week02
## step01-1 跑別人的範例

```
1. 下載範例 https://jsyeh.org/3dcg10
   data.zip windows.zip glut32.dll
2. windows.zip =解壓=> 下載\windows\Shapes.exe
   data.zip =解壓=> 下載\windows\data\模型
   glut32.dll =複製=> 下載\windows\glut32.dll
3. 跑 Shapes.exe 看範例, 試試看
   左可按右鍵選單: 大頂點、很多顏色
   右可按右鍵選單: POINT....POLYGON 
```

## step01-2 跑你上週的程式

```
1. 上週的安裝 Git for Windows
2. 上週的 Git Bash: cd desktop, git clone 你的網址
   cd 2022graphics1
3. 上週的安裝 freeglut, 記得改檔名 lib\libglut32.a
4. 在 CodeBlocks File-Open week01_GLUT專案,跑!
```

## step02-1 親手打造 GLUT的程式 (5-10行)

有了上週的 week01_GLUT 的專案
我們要寫出今天的 week02_color 新專案
1. File-New-Project,選GLUT專案
2. 設好freeglut後
3. 確定有上週的進度後, 大膽的把上週的程式刪掉
4. 寫下今天的10行程式碼,會秀出黃色的茶壼

```C++
///step02-1 10行最精簡的 GLUT程式
///先全刪, 目標: 5-10行,寫完
#include <GL/glut.h> ///使用GLUT外掛,簡化程式

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面

    glColor3f(1,1,0); ///設定色彩
    glutSolidTeapot(0.3); ///實心的茶壼

    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第02週的程式哦!"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
```


## step03-1 彩色三角形
接上一節的進度(黃色茶壼),我們想把今天的範例(彩色三角形)跑出來, 所以修改一下,將 glutSolidTeapot(0.3) 改成 glBegin(GL_POLYGON) ... glEnd() 在中間則用 glColor3f()及glVertex2()來標定色彩、頂點座標

```C++
///step02-1 10行最精簡的 GLUT程式
///先全刪, 目標: 5-10行,寫完
#include <GL/glut.h> ///使用GLUT外掛,簡化程式

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面

    glColor3f(1,1,0); ///設定色彩
    ///glutSolidTeapot(0.3); ///實心的茶壼
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);///紅色
        glVertex2f(-1, -1);

        glColor3f(0,1,0);///綠色
        glVertex2f(+1, -1);

        glColor3f(0,0,1);///藍色
        glVertex2f(0, +1);
    glEnd();

    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第02週的彩色三角形哦!"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
```

## step03-2 上傳到 GitHub
1. 把 README.md 說明檔,利用 Markdown MD語法編輯

```
# 一個井號,表示大標題
## 二個井號,表示小標題
```

```C++
會秀出C++的程式
 英文的 1234的左邊的撇

```

直接在 GitHub 上,登入後, 按 "筆" 修改

再按綠色的 Commit 確認你的修改


# Week03

0. 開啟 blogger 寫今天的課堂作業
   2022graphicsA.blogspot.com

1. 範例 https://jsyeh.org/3dcg10/
1.1. 下載 data, win32
windows.zip => 下載\windows\Transformation.exe
data.zip =>    下載\windows\data\模型.obj
1.2. 執行 Transformation.exe 
   (右上角)右鍵:換模型
   (下方)拖曳綠色的數值

2. step01-2 File-New-Project,GLUT, Project: week03_translate
2.1. ...桌面, 
2.2. freeglut要裝好: 解壓縮,改lib\libglut32.a


## step01-0 sin() cos() 畫圓
step01-0_早到的同學有福了, 老師為了讓同學可以寫出很棒的HW2,所以看了去年前年學長姐的作業,讓大家先有一個概念。但怎麼做的呢,老師馬上示範怎麼畫出小小兵給大家看,程式碼就只有一頁,利用 cos()及 sin() 來畫出圓形,利用for迴圈來控制角度,利用函式myCircle(float r) 來簡化程式, 利用 myCircle2(float x, float y, float r) 不同座標畫

```C++
///把上週的程式 copy進來
#include <GL/glut.h>
#include <math.h>///sin(), cos()
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f( 1,1,0 );
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( cos(a), sin(a) );
    }///要畫三角函數
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 作業2想加分");

    glutDisplayFunc( display );
    glutMainLoop();
}
```

```C++
///把上週的程式 copy進來
#include <GL/glut.h>
#include <math.h>///sin(), cos()
void myCircle( float r )
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( r*cos(a), r*sin(a) );
    }///要畫三角函數
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f( 1,1,0 );
    myCircle(2);

    glColor3f( 0.6 ,0.6 ,0.6 );
    myCircle(0.6);

    glColor3f( 1,1,1);
    myCircle(0.45);

    glColor3f( 0,0,0);
    myCircle(0.3);

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 作業2想加分");

    glutDisplayFunc( display );
    glutMainLoop();
}
```

```C++
///把上週的程式 copy進來
#include <GL/glut.h>
#include <math.h>///sin(), cos()
void myCircle( float x, float y, float r )
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a), y+r*sin(a) );
    }///要畫三角函數
    glEnd();
}
void myCircle2( float x, float y, float r )
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+2*r*cos(a), y+r*sin(a) );
    }///要畫三角函數
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f( 1,1,0 );
    myCircle(0, 0, 2);

    glColor3f( 0.6 ,0.6 ,0.6 );
    myCircle(0, 0, 0.6);

    glColor3f( 1,1,1);
    myCircle(0, 0, 0.45);

    glColor3f( 0,0,0);
    myCircle(0, 0, 0.3);

    glColor3f( 1,0,0);
    myCircle2(0.8, -0.6, 0.1);
    myCircle2(-0.8, -0.6, 0.1);

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 作業2想加分");

    glutDisplayFunc( display );
    glutMainLoop();
}
```

## step01-1 介紹 Translate
step01-1_今天上課的主題是移動Translate 這個英文單字 (上週教單字Vertex頂點), 接下來到老師的網頁下載 data.zip 及 windows.zip 並正確解壓縮後,可以跑今天的範例 Transformation.exe 可利用 mouse 來選模型, 利用drag來調整綠色的數值

## step01-2 黃色茶壼
step01-2_接下來想要實作今天Translate主題的程式,先把上週的黃色茶壼 程式碼拿來用
```C++
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///黃色
    glutSolidTeapot(0.3);///茶壼
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step02-1 移動黃色茶壼
step02-1_有了上週的黃色茶壼範例,加入今天教的glTranslatef(x,y,z) 便可以移動。不過,好像移動時,會像鬼故事一樣,越移越遠,因為移動會累積。所以要用glPushMatrix()備份矩陣, glPopMatrix()還原矩陣,備份起來,便能確認我們的移動不會殘留

```C++
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣 (備份舊的位置)
        ///移動會累積,因為它會修改矩陣
        glTranslatef(0.5, 0.5, 0);///右上角
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壼
    glPopMatrix();///還原矩陣 (還原舊的位置)
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step02-2 利用函式,做很多的移動
step02-2_有了剛剛的程式,便能畫出更多的茶壼。使用大一教過的「自訂函式」自己發明myTeapot(float x, float y) 可以在不同的地方畫茶壼。接下來便可以 myTeapot(0.5, 0.5); myTeapot(0.5, -0.5); myTeapot(-0.5, -0.5); myTeapot(-0.5, 0.5); 在不同地方畫很多個

```C++
#include <GL/glut.h>
void myTeapot(float x, float y)
{
    glPushMatrix();///備份矩陣 (備份舊的位置)
        ///移動會累積,因為它會修改矩陣
        //glTranslatef(0.5, 0.5, 0);///右上角
        glTranslatef(x, y, 0);
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壼
    glPopMatrix();///還原矩陣 (還原舊的位置)
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    myTeapot( 0.5, 0.5 );
    myTeapot( 0.5, -0.5 );
    myTeapot( -0.5, -0.5 );
    myTeapot( -0.5, 0.5 );
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step02-3 利用 mouse 移動黃色茶壼
step02-3_今天另一個主題,是利用mouse滑鼠來寫程式,可以使用glutMouseFunc(mouse)事件,註冊 void mouse(int button, int state, int x, int y) 函式,來讓mouse事件發生時,會叫用到我們的mouse()函式。這樣我們可以用某個座標換算公式,來算出-1到+1的座標,也能用在作業2中

```C++
#include <GL/glut.h>
float mouseX=0, mouseY=0;///新加的
void myTeapot(float x, float y)
{
    glPushMatrix();///備份矩陣 (備份舊的位置)
        glTranslatef(x, y, 0);
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壼
    glPopMatrix();///還原矩陣 (還原舊的位置)
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    myTeapot(   (mouseX-150)/150.0, -(mouseY-150)/150.0 );///新加的
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y )
{
    mouseX=x; mouseY=y;///新加的
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新加的 滑鼠事件

    glutMainLoop();
}
```

## step03-1 解釋 mouse()函式與座標換算
step03-1_剛剛mouse()的參數是什麼意思呢, 它的座標系統不是3D座標系統,而是window視窗的座標系統。老師教口訣「減一半、除一半。y要反過來」便可以換算到3D的世界。

```C++
///week03_mouse_help_hw2
#include <GL/glut.h>
#include <stdio.h>///printf()印東西用的
float mouseX=0, mouseY=0;///新加的
void myTeapot(float x, float y)
{
    glPushMatrix();///備份矩陣 (備份舊的位置)
        glTranslatef(x, y, 0);
        glColor3f(25/255.0 , 208/255.0 , 32/255.0);///0...1 要除/255.0
        glutSolidTeapot(0.1);///茶壼
    glPopMatrix();///還原矩陣 (還原舊的位置)
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    myTeapot(   (mouseX-150)/150.0, -(mouseY-150)/150.0 );///新加的
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y )
{
    printf("%d %d %d %d\n", button, state, x, y);
    mouseX=x; mouseY=y;///新加的
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新加的 滑鼠事件

    glutMainLoop();
}
```

## step03-2 利用 mouse 來印出程式(頂點座標)
step03-2_最後,可以利用mouse事件,配合 printf()來印出程式碼, 之後便能把座標換算的程式碼拿來畫圖囉

```C++
///week03_mouse_help_hw2
#include <GL/glut.h>
#include <stdio.h>///printf()印東西用的
float mouseX=0, mouseY=0;///新加的
void myTeapot(float x, float y)
{
    glPushMatrix();///備份矩陣 (備份舊的位置)
        glTranslatef(x, y, 0);
        glColor3f(25/255.0 , 208/255.0 , 32/255.0);///0...1 要除/255.0
        glutSolidTeapot(0.1);///茶壼
    glPopMatrix();///還原矩陣 (還原舊的位置)
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///myTeapot(   (mouseX-150)/150.0, -(mouseY-150)/150.0 );///新加的
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y )
{
    ///printf("%d %d %d %d\n", button, state, x, y);
    printf("  glVertex2f( (%d-150)/150.0, -(%d-150)/150.0 );\n", x,y);
    mouseX=x; mouseY=y;///新加的
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新加的 滑鼠事件

    glutMainLoop();
}
```
