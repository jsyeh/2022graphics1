# 資傳二甲電腦圖學 2022graphics1
銘傳大學資傳系的電腦圖學課（Computer Graphics），會帶大家利用 OpenGL (Open Graphics Language) 實作，來學習電腦圖學的相關觀念。

每週上課時，利用 Blog 寫課堂筆記的方式，來讓大家完成課堂作業。也會利用 Git 指令，帶大家將每週的程式上傳到 GitHub中。

課堂作業 寫blog 評分的原因，是因為在程式的實作時，如果有親手做記錄，比較能理解「做了什麼」「為什麼做」「出來的效果如何」，而且之後遺忘時，還能有自己的筆記，用自己能理解、曾經努力記錄的方式來回憶。

這樣之後上課時會比較順利，期末作品（整學期上課內容的整合）也會比較順利、不會負擔太大而放棄。

# Week01
介紹電腦圖學 OpenGL 的程式設計開發環境，用同學大一程式設計學過的 CodeBlocks 繼續延伸，了解如何利用 C/C++ 配合開發出 OpenGL 及 GLUT 的電腦圖學程式。之後同學也能在 Windows 的 Visual Studio 或是 Mac 的 Xcode 中，進行開發，程式碼都相同。

每週學一個新單字，今天學到的單字是 Graphics (圖學)。

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

每週學一個新單字，今天學到的單字是 Vertex (頂點)。

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

每週學一個新單字，今天學到的單字是 Translate (移動)。

```
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
```

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

# Week04

每週學一個新單字，今天學到的單字是 Rotate (旋轉)。


# Week05

本週的上課內容，是先介紹電腦圖學之父 Ivan Sutherland 的故事，並播放他博士畢業論文 Sketchpad 的展示影片（電視訪問的黑白畫面）。接下來便是利用這幾週上課教的移動、旋轉、縮放，配合這幾週教的 mouse, motion, keyboard等，讓大家看到整合在程式碼中的效果。下週將會照著繼續做。

每週學一個新單字，今天學到的單字是 Scale (縮放)。

0. 老師介紹 電腦圖學之父
Ivan Sutherland 的 Sketchpad影片
https://www.youtube.com/watch?v=6orsmFndx_o
介紹畢業時論文發表的小八卦

介紹他的老師 Shannon 的
Ultimate machine (useless machine)
https://www.youtube.com/watch?v=cZ34RDn34Ws

```
1. jsyeh.org/3dcg10
windows.zip => 下載\windows\Transformation.exe
data.zip    => 下載\windows\data\模型
下面區域,可以交換2行程式碼(移動、轉動)
會有自轉、公轉的效果。

2. 介紹完 移動、旋轉、縮放 對映 Maya qwer鍵
2.1. 先把 freeglut裝,改 lib\libglut32.a
2.2. File-New-Project, 新的GLUT專案
2.3. 把每次的 10行 copy 上來
```

## step01-0
介紹電腦圖學之父 Ivan Sutherland 及他的 Sketchpad 作品, 介紹他畢業論文發表的八卦, 介紹他的老師密碼學大師Shannon與他的Ultimate Machine (Useless Machine)。帶大家重新複習Transformation.exe裡面的內容,尤其是Translate及Rotate兩行相反時,分別有自轉、公轉的效果.zip

## step01-1
接下來為了模仿 Maya動畫軟體的keyboard+mouse操作,我們要寫今天的主角 glutKeyboardFunc(keyboard) 及對應的 void keyboard(unsigned char key, int x, int y)函式,印出來.zip

```C++
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///黃色的
    glutSolidTeapot( 0.3 );///茶壼
    glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y )
{
    printf("你按下了 %c 在 %d %d 座標\n", key, x, y );
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///今天的主角
    glutMainLoop();
}
```
## step02-1
接續剛剛的 week05_keyboard 我們新增一個專案,叫 week05_keyboard_mouse_motion 在裡面複習本週的keyboard(),上上週的mouse(),上週的motion()

```C++
///接續剛剛的 week05_keyboard 變成 keyboard+mouse+motion
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
150)/150.0 ,z);
    glColor3f(1,1,0);///黃色的
    glutSolidTeapot( 0.3 );///茶壼
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
}
void mouse(int button, int state, int mouseX, int mouseY )
{
}
void motion(int mouseX, int mouseY)
{
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///今天的主角
    glutMouseFunc(mouse);///上上週的主角
    glutMotionFunc(motion);///上週的主角
    glutMainLoop();
}
```

## step02-2
先做移動的部分,只利用motion裡面,配合 x += (mouseX-oldX) 及 y += (mouseY-oldY) 並更新 oldX=mouseX; oldY=mouseY; 來讓 x 及 y 可以正確增減。最後我們利用減一半、除一半、y要倒過來的公式,完成移動的任務,其中 display()裡還要有 glPushMatrix()備份矩陣 及 glPopMatrix()還原矩陣

```C++
#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0;
int oldX=0, oldY=0;
void display()
{
    glClearColor( 0.5, 0.5, 0.5, 1 );///R,G,B,A 其中A半透明功能,目前沒開
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 ,z);
        glColor3f(1,1,0);///黃色的
        glutSolidTeapot( 0.3 );///茶壼
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
}
void mouse(int button, int state, int mouseX, int mouseY )
{
}
void motion(int mouseX, int mouseY)
{
    x += (mouseX-oldX);  y += (mouseY-oldY);
    oldX = mouseX;       oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///今天的主角
    glutMouseFunc(mouse);///上上週的主角
    glutMotionFunc(motion);///上週的主角
    glutMainLoop();
}
```

## step02-3
剛剛只用motion其實有問題,有點不連續。因此,用上週教在 mouse()裡面設定 oldX=mouseX; oldY=mouseY; 去記錄下按下mouse時的位置,才能相對移動正確

```C++
#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0;
int oldX=0, oldY=0;
void display()
{
    glClearColor( 0.5, 0.5, 0.5, 1 );///R,G,B,A 其中A半透明功能,目前沒開
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 ,z);
        glColor3f(1,1,0);///黃色的
        glutSolidTeapot( 0.3 );///茶壼
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
}
void mouse(int button, int state, int mouseX, int mouseY )
{///為了解決瞬間移動的錯誤,我們改用正確的方法
    oldX = mouseX; oldY = mouseY;
}
void motion(int mouseX, int mouseY)
{
    x += (mouseX-oldX);  y += (mouseY-oldY);
    oldX = mouseX;       oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///今天的主角
    glutMouseFunc(mouse);///上上週的主角
    glutMotionFunc(motion);///上週的主角
    glutMainLoop();
}
```

## step03-1
把程式碼修改成只處理 glScalef(scale, scale, scale) 的部分,利用 float scale=1.0這個變數,往右拖會慢慢放大1%,往左拖會慢慢縮小1%, 每天多努力1%,成長看得見

```C++
#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0, scale=1.0;
int oldX=0, oldY=0;
void display()
{
    glClearColor( 0.5, 0.5, 0.5, 1 );///R,G,B,A 其中A半透明功能,目前沒開
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 ,z);
        glScalef(scale, scale, scale);///都縮放成 scale倍
        glColor3f(1,1,0);///黃色的
        glutSolidTeapot( 0.3 );///茶壼
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
}
void mouse(int button, int state, int mouseX, int mouseY )
{///為了解決瞬間移動的錯誤,我們改用正確的方法
    oldX = mouseX; oldY = mouseY;
}
void motion(int mouseX, int mouseY)
{
    if( mouseX-oldX > 0 ) scale *= 1.01;
    if( mouseX-oldX < 0 ) scale *= 0.99;
    ///x += (mouseX-oldX);  y += (mouseY-oldY);
    oldX = mouseX;       oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///今天的主角
    glutMouseFunc(mouse);///上上週的主角
    glutMotionFunc(motion);///上週的主角
    glutMainLoop();
}
```
