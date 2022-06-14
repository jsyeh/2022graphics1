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
本週的上課範圍，是介紹Translate移動，也教大家如何利用 mouse 來操作、寫出能利用mouse的程式。
另外在座標換算的部分，在HW2會需要將 Windows 的座標系統，換算成 OpenGL的座標系統，這樣便能在 mouse()函式裡，進行座標換算，方便製作我們的HW2 。

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
本週的上課範圍，是介紹Rotate旋轉，並且利用 mouse motion 函式，讓大家可以利用mouse的操作來控制物體的轉動，就像 Maya 課及 Unity課時使用的方式來轉動。

每週學一個新單字，今天學到的單字是 Rotate (旋轉)。

```
1. 主題: Rotate旋轉
jsyeh.org/3dcg10 下載
data.zip   =>下載\windows\data\一堆3D模型
windows.zip=>下載\windows\Transformation.exe
2. 測試 角度
   glRotatef(角度, x, y, z);
3. 最難的, 是不同的旋轉軸。
```

## step01-1
介紹今天的主題「旋轉Rotate」先帶大家看課本的範例,解壓縮windows.zip並把 data.zip 正確放好,便能執行Transformation.exe 並試著改裡面的glRotatef(角度,....)

## step01-2
接下來要介紹各種不同的旋轉軸,像是如果旋轉軸是0,1,0向上的Y軸,那它怎麼轉呢。如果旋轉軸是1,0,0向右的X軸,它的轉法,是頭往前倒。如果旋轉軸是1,1,0向右上斜,那轉動時,右肩往前倒。最難理解的是0,0,1向著前面的Z軸,如果你有右手比讚,便容易想像它怎麼轉動。

## step02-1
我們再利用課本範例Transformation.exe測了最難理解的0,0,1的Z軸,如果改成0,0,-1的反方向,大家也要能知道它往哪裡轉。接下來我們承接上週的程式碼,改成用glRotatef(角度,x,y,z)來看茶壼轉動的狀況

```C++
///全刪,再從blog抄你的精簡10行程式
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(90, 0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step_02-1b
如何偽造時間。在Blog裡,其實可以設定你的時間。在GitHub裡,也可以設定你的時間。老師分享之前交作業時曾經修改email的時間, 去年在修英文課時,發現如果有缺交作業時,就會想放棄。如果能補交、保持完美,就會有動力繼續保持下去。大家可以試試,有問題可以問我。



## step02-2
剛剛的程式裡, glRotatef(90,0,0,1) 的角度是寫死固定。想要有互動的變化時, 可以使用 mouse motion 功能,要在 main() 裡註冊 glutMotionFunc(motion), 再寫你的 void motion(int x, int y) 裡面去修改 angle值,再用 display()重畫畫面, 其中glRotatef(angle, 0,0,1)


```C++
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle, 0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x, int y)
{
    angle = x;
    display();///重畫畫面
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion);///mouse motion動
    glutMainLoop();
}
```

備份、改GitHub時間
```
git clone https://github.com/jsyeh/2022graphics1

git status (看到有紅色)
git add .
git status (確認變綠色)

git config --global user.name jsyeh
git config --global user.email jsyeh@mail.mcu.edu.tw


git commit -m "add week04"   --date "2022-03-09 12:00:00"

git push
```


## step03-1
剛剛的 angle=x 的作法,會讓轉動很奇怪、不太連續, 原因是 angle設成x座標。老師使用一個很舊的笑話「大象放到冰箱裡」接下來,便利用這樣的觀念,把滑鼠按下去定錨oldX=x,之後移動時,angle+=(x-oldX), 最後再 oldX=x 再定一次錨


```C++
#include <GL/glut.h>
float angle=0, oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle, 0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x, int y)
{
    angle += (x-oldX);
    oldX = x;
    display();///重畫畫面
}
void mouse(int button, int state, int x, int y)
{
    oldX = x; ///定錨
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion);///mouse motion動
    glutMouseFunc(mouse);///上週教: mouse按下去、放開來
    glutMainLoop();
}
```

## step03-2
複習上週教的「用滑鼠寫程式」,,老師利用mouse()來印出程式碼,並把座標備份在mx[]及my[]裡面,配合N知道已經記錄了幾個座標。再於display()裡面,利用for迴圈,把這些座標利用GL_LINE_LOOP畫出來看。希望大家對於座標、座標換算、頂點、glBegin()等更有概念

```C++
///上週的複習
#include <GL/glut.h>
#include <stdio.h>
int mx[1000],my[1000];///用來備份你的mouse的座標
int N=0;///有幾個點按好了?
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){
        glVertex2f( (mx[i]-150)/150.0, -(my[i]-150)/150.0 );
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{//  printf("%d %d %d %d\n", button, state, x, y);
    if(state==GLUT_DOWN){///如果state是按下去0,才印程式碼
        printf("    glVertex2f( (%d-150)/150.0, -(%d-150)/150.0 );\n", x, y);
        N++;
        mx[N-1]=x; my[N-1]=y;
    }
    display();///重畫
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///上週教: mouse按下去、放開來
    glutMainLoop();
}
```

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

# Week06 打光

gist.github.com 可以分享程式碼

## step01-1

jsyeh.org/3dcg10 下載 data win32

windows.zip => 下載\windows\Light Material.exe

data.zip    => 下載\windows\data\模型

主角 Light Material.exe

(左上)左鍵drag可旋轉

(左上)右鍵,換模型

(左下)右鍵,換 Material 

(以下程式碼都不用寫)(都用剪貼的)

右邊的參數 glLightfv(...) 的 fv 是 float vector (陣列)

```c++
GLfloat light_pos[] = {-2.0, 2.0, 2.0, 1.0 }; 陣列
glLightfv(GL_LIGHT0, GL_POSITION, 陣列)
          第幾個燈
                     設定它的位置
```
## step01-2

講解光的性質(位置, Ambient, Diffuse, Specular), 講解glLightfv()的參數意思,了解fv是有小數點的陣列, 了解 GL_POSITION可以設定光的位置.


## step01-3

講解完程式碼, 接下來是偷程式碼時間。File-New-Project 選 GLUT專案, 就好了。接下來Ctrl-F找關鍵字light 找到 (1) 有陣列宣告、(2)有函式呼叫 就這樣。

實作時間:
0. freeglut 裝好, lib 改一下 libglut32.a
1. File-New-Project, GLUT專案 沒了....
2. 從 GLUT 範例 偷程式碼!!! Ctrl-F 找 light
3. (1) 有陣列宣告、(2)有函式呼叫

```C++
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
```

```C++
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
```

## step02-1

結合之前 GLUT 10行茶壼程式, 配合打光的程式碼 8+10行, 做出打光的茶壼, 其中光的位置有稍微調一下z的值


```C++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1, 1, 0);
        glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main( int argc, char** argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);

    ///偷來的程式,要放 glutCreateWindow()之後,才會有效
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
    ///放在 glutMainLoop()之前

    glutMainLoop();///卡在這裡,之後的程式,都不會執行到
}
```



## step02-2
week06_light_mouse_motion_rotate

```C++
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

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

    ///偷來的程式,要放 glutCreateWindow()之後,才會有效
    //glEnable(GL_DEPTH_TEST);
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
    ///放在 glutMainLoop()之前

    glutMainLoop();
}
```


## step03-1 講解法向量




## step03-2 期中考題

```C++
glPushMatrix();///備份矩陣 10分
  glTranslatef(x,y,z);//移動 10分
  glRotatef(角度,x,y,z);//旋轉 10分
  glScalef(x,y,z);//縮放 10分
  glBegin(GL_POLYGON);//開始畫 10分
    glColor3f(r,g,b);//色彩 10分
    glNormal3f(nx,ny,nz);//打光的法向量
    glTexCoord2f(tx,ty);//貼圖座標
    glVertex3f(x,y,z);//頂點 10分
  glEnd();
glPopMatrix();///還原矩陣 10分
```

## step03-3

今天最後一節課,想要整合打光+上週教的程式,所以讓同學接續前一個打光的程式,加上旋轉的效果

```C++
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150, y=150, z=0, scale=1.0, angle=0.0;
int oldX=0, oldY=0;

void display()
{
    glClearColor( 0.5, 0.5, 0.5, 1 );///R,G,B,A 其中A半透明功能,目前沒開
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 ,z);
        glRotatef(angle, 0,1,0);///對Y軸轉動
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
    angle += (mouseX-oldX);///轉動
    ///if( mouseX-oldX > 0 ) scale *= 1.01; ///縮放
    ///if( mouseX-oldX < 0 ) scale *= 0.99;
    ///x += (mouseX-oldX);  y += (mouseY-oldY);//移動
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

    ///偷來的程式,要放 glutCreateWindow()之後,才會有效
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
    ///放在 glutMainLoop()之前

    glutMainLoop();
}
```

## step03-4

今天最後一個程式,把剛剛的程式,整合成 week06_light_keyboard_mouse_motion_all 可以利用keyboard切換now的值,來做移動、旋轉、縮放。

```C++
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150, y=150, z=0, scale=1.0, angle=0.0;
int oldX=0, oldY=0, now=1;///now: 1移動, 2轉動, 3縮放

void display()
{
    glClearColor( 0.5, 0.5, 0.5, 1 );///R,G,B,A 其中A半透明功能,目前沒開
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 ,z);
        glRotatef(angle, 0,1,0);///對Y軸轉動
        glScalef(scale, scale, scale);///都縮放成 scale倍
        glColor3f(1,1,0);///黃色的
        glutSolidTeapot( 0.3 );///茶壼
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}

void keyboard( unsigned char key, int mouseX, int mouseY )
{
    if(key=='1' || key=='w' || key=='W') now=1;///移動
    if(key=='2' || key=='e' || key=='E') now=2;///轉動
    if(key=='3' || key=='r' || key=='R') now=3;///縮放
}

void mouse(int button, int state, int mouseX, int mouseY )
{///為了解決瞬間移動的錯誤,我們改用正確的方法
    oldX = mouseX; oldY = mouseY;
}

void motion(int mouseX, int mouseY)
{
    if(now==1){///移動
        x += (mouseX-oldX);  y += (mouseY-oldY);///移動
    }else if(now==2){///轉動
        angle += (mouseX-oldX);///轉動
    }else if(now==3){
        if( mouseX-oldX > 0 ) scale *= 1.01; ///縮放
        if( mouseX-oldX < 0 ) scale *= 0.99;
    }
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

    ///偷來的程式,要放 glutCreateWindow()之後,才會有效
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
    ///放在 glutMainLoop()之前

    glutMainLoop();
}
```

# Week08
電腦圖學 Week08 2022-04-11
1. 主題: 3D模型
2. 主題: OBJ模型檔 (v vt vn f)
3. 實作: glm.h glm.cpp (c)
4. 期中考題: OpenGL必背10函式

先看課本範例
1. jsyeh.org/3dcg10 下載
2. windows.zip => 下載\windows\Light Material.exe
3. data.zip    => 下載\windows\data\ 3D模型
4. source.zip 
5. 執行 Light Material.exe 今天的主角(打光/模型)

## step01-1
複習上次上課時的課本打光範例, 確定大家可以執行。裡面的 Light Material.exe 有用到「打光、模型」是今天的主角

step01-2 實作看看!!! (GLUT的範例, source.zip 的範例)

1. freeglut Moodle下載/安裝, lib\libglut32.a
File-New-Project, GLUT專案, 偷它的程式 放 Notepad++

## step01-3 了解 GLUT範例 sample.cpp 177行 做什麼事

step01-3 了解 GLUT範例 sample.cpp 177行 做什麼事,其中有 include glut.h, 有介紹 GLUT callback 像是 display() mouse() motion() keyboard(), 有期中考題,像是 glPushMatrix()等, 重點是打光的陣列、打光的函式

TODO: 開blog
```c++
#include <GL/glut.h>
```

GLUT callback ? 會被 GLUT 呼叫的函式
我們寫的那些display() keyboard() mouse() motion()函式

```c++
//期中考試題
glPushMatrix();//備份矩陣
  glTranslatef(x,y,z);//移動
  glRotatef(角度, x,y,z);//轉動
  glScalef(x,y,z);//縮放 (有50分)

glPopMatrix();//還原矩陣
```

打光的程式碼: (1) 打光的陣列, (2) 打光的函式

TODO: 寫 Blog (ing)

## step01-4 從 GitHub 拿出上週的程式!!! week06_light 
1. git 下載你上週的程式
2. git clone 下來 或在你的專案資料夾裡 git pull
3. 把 week06_light\main.cpp 用 Notepad++ 開起來, copy paste 到 week08_model 的 main.cpp
4. 執行,會看到打光的黃色茶壼


## step02-1 把 source.zip 看裡面的3個程式 glm.h glm.c lightmaterial.cpp, 拿裡面的程式來用,便能讀入3D模型

step02-1_把 source.zip 看裡面的3個程式 glm.h glm.c 研究 lightmaterial.cpp, 拿裡面的程式來用,便能讀入3D模型, 要include 雙引號的 glm.h 要把 glm.c改檔名成glm.cpp 並加入專案, 再用 Notepad++研究學習lightmaterial.c的程式內容

1. glm.h 我們要 include 它
2. glm.c 改檔名 glm.cpp 要加入專案
3. lightmaterial.cpp 用 Notepad++ 研究"學習"

TODO: Blog (ing)
```C++
#include <GL/glut.h> //角括號,是系統的include裡 的檔案
#include "glm.h" //雙引號,同目錄裡 的檔案
```

```C++
GLMmodel* pmodel = NULL; //指到GLMmodel模型的指標,NULL代表還沒好
```

```C++
void
drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/soccerball.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH);
}///用來畫3D模型的程式碼, "學習它"
```

## step02-2 畫 3D 模型檔
step02-2_畫 3D 模型檔,要把 glutSolidTeapot()改成畫 drawmodel(), 要在下方Build Log 找你的 working dir 工作目錄 好像是 Desktop的freeglut的bin目錄, 在裡面放 data資料夾, 以便讀取 data的 soccerball.obj 模型, 再把glm.cpp 及 glm.h 放在 week08_model 目錄中, 再 Add files 把 glm.cpp 加到專案中

1. (用哪一行程式?) drawmodel() TODO: 在 display()取代 glutSolidTeapot()
2. (檔案在哪裡?) 要在放 working dir 工作目錄裡!!!!
3. (在 CodeBlocks下方 藍色 Build Log 說我們的工作目錄在...)
4. (in C:\Users\...\Desktop\freeglut\bin\ )
5. TODO: 剛剛下載的 下載\data.zip 裡面的 data資料夾,整包放在 "工作目錄"
6. TODO: 把 glm.h 還有 glm.c (檔名改成 glm.cpp) 放到 week08_model 目錄
7. 注意: 副檔名要看到才行!!!! 
8. TODO: 在 week08_model 的專案中, Add 同目錄裡面的 glm.cpp

## step02-3
複習問問題


## step03-1
講解各種模形,可以自己改, 再把專案 week08_model File-Save Project存檔, 放到 GitHub 裡

## step03-2 介紹3D模型相關資料
1. Wavefront OBJ 檔 https://zh.wikipedia.org/wiki/Wavefront_.obj%E6%96%87%E4%BB%B6
2. Wavefront OBJ 英文介紹較詳細https://en.wikipedia.org/wiki/Wavefront_.obj_file
3. OBJ vs. MTL 檔, 其中 .mtl 檔 material (m t    l)
4. v 是 vertex, vn 是 vertex normal, vt 是 vertex texture coordinate, f 是 face 點線面的面

## step03-3
期中考 OpenGL 必背10函式 模擬練習

[jsyeh.org/gl](https://jsyeh.org/gl)
gl是OpenGL的GL

考試練習：請在下方「淡黃文字區」輸入老師教的 OpenGL必背10函式(11行程式)。 \
拼字(含大小寫)必須完全正確、參數的數目也需要正確，要合文法、能compile編譯，並記得加中文註解。 \
完成後，點擊按鈕【按我評分】自行模擬評分

```c++
glPushMatrix(); //備份矩陣
   glTranslatef(x,y,z);//移動
   glRotatef(角度, x,y,z);//轉動
   glScalef(x,y,z);//縮放
   glBegin(GL_POLYGON);//開始畫
     glColor3f(r,g,b);//色彩
     glTexCoord2f(tx, ty);//貼圖座標
     glNormal3f( nx,ny,nz);//打光法向量
     glVertex3f(x,y,z);//頂點
   glEnd();//結束畫
 glPopMatrix(); //還原矩陣
```

# Week09
電腦圖學 Week09 2022-04-19
1. 考試: OpenGL必背10函式
2. 主題: 貼圖
3. 實作: OpenCV 讀圖、秀圖
4. 實作: 貼圖設定
5. 實作: 貼圖座標

## step01-0
期中考試: OpenGL必背10函式

在電腦圖學課程中, 我們會教很多主題, 其中最關鍵的10個主題, 與 OpenGL 的 10個函式有關。老師上課時有有依序介紹它們, 並給大家一個模擬考系統, 讓大家可以事先練習。現在, 請在 Moodle裡, 把這10個函式寫出來(含中文的意思), 同時必須注意拼字大小寫、參數的數目等。

註: 寫出來的答案, 會用 jsyeh.org/gl 裡面的系統來評分。

## step01-1

1. jsyeh.org/3dcg10 下載 windows.zip, data.zip source.zip
2. windows.zip => 下載\windows\Texture.exe
3. data.zip    => 下載\windows\data\圖檔
4. Texture.exe 貼圖 
5. 把blog開起來, 理解、寫一下

## step01-2
1. moodle/teams 下載 opencv 2.1.0 win32 vs2008 (最小、最快安裝、簡單、跨平台)
2. 安裝時要小心: (1) Add PATH 選第2個, (2) 目錄不要改 C:\OpenCV2.1
3. PATH 安裝之後,會新增 C:\OpenCV2.1\bin。PATH 是程式執行時,會去找 exe 或 dll 的目錄路徑

## step02-1
2行! 寫 OpenCV 讀圖, 秀圖

0. CodeBlocks 要重開 (PATH 安裝完之後, 便會修改 PATH 的設定。)
1. 寫程式很簡單、BUT設定很困難!!!
2. File-New-EmptyFile, 存成 week09_opencv.cpp 
3. 設定很困難: Setting-Compiler 設定 Include 目錄
4. 設定很困難: Setting-Compiler 設定 Lib 目錄
5. 設定很困難: Setting-Compiler 咒語 Linker 加 cv210 cxcore210 highgui210

- Search directories 目錄在哪裡!!
- Compiler 的 Include 目錄 c:\opencv2.1\include
- Linker 的 Lib 目錄       c:\opencv2.1\lib

```c++
#include <opencv/highgui.h> //使用 opencv 的外掛
int main()
{
	IplImage * img = cvLoadImage("檔名.png"); //讀圖
	cvShowImage( "week09", img ); //秀圖
	cvWaitKey( 0 );//等待任意鍵繼續
}
```
## step03-1 
1. 結合 OpenCV 和 OpenGL 哦!!!
2. 。非常複雜、  非常簡單
3. 。設定/程式碼 用剪貼的
4. 最簡單的整合: 把 10行GLUT範例 + 3-5行OpenCV讀圖秀圖
5. 。File-New-Project, GLUT專案 week09_texture 專案
6. 。寫出10行囉!
7. 。加入 3-5行 OpenCV 的程式
8. 。圖檔要放在 工作目錄 (in C:\Users...\freeglut\bin)

- 非常複雜、非常簡單
- 程式碼    用剪貼的

```c++
///請自己去剪貼 10行 GLUT範例
#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()
{
    IplImage * img = cvLoadImage("earth.jpg");
    cvShowImage("opencv", img);
    ///cvWaitKey( 0 );///可以不用寫,因為有glutMainLoop()卡住
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);
    myTexture();

    glutMainLoop();
}
```

## step03-2
實作: 貼圖設定

https://gist.github.com/jsyeh/5ed01210559721ec71b659b3ffed2dd7

```c++
//myTexture.cpp
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
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
```

```c++
//myTexture_sample.cpp
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);
    myTexture("earth.jpg");

    glutMainLoop();
}
```

# Week10
電腦圖學 Week09 2022-04-25

討論: 期中考成績、校長的信/累/快篩/缺貨/APP/降價
主題: 上週貼圖+貼到四邊形=背景
主題: 上週貼圖+貼到圓球=會轉的地球
主題: 上週貼圖+貼到模型=鋼彈模型

## step01-0
上課前, 老師先介紹期中考的狀況,接下來看校長寄的信,了解目前銘傳大學的疫情狀況、快篩相關的議題,希望能度過疫情,迎向正常的生活

## step01-1
第一節課想要將上週貼圖+貼到四邊形,變成背景的圖。先安裝好freeglut及OpenCV2.1並做好對應的修正後,重開CodeBlocks,新增GLUT專案,把上週的myTexture及 GLUT的10行程式碼拿來用。目前還不能執行哦

1. 安裝 freeglut (libglut32.a要有), OpenCV2.1 (Add PATH)
2. (重開CodeBlocks) File-New-Project, GLUT專案, week10_texture_background
3. 把上週blog有 myTexture.txt 拿來用
4. 把上上週blog 10行 GLUT程式碼拿來用

myTexture 的程式碼
```cpp
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
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
```

GLUT的10行程式碼, 其中最後

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glutDisplayFunc(display);
    myTexture("earth.jpg");///地球的地圖,圖等一下會準備好

    glutMainLoop();
}
```


## step01-2
接下來,把OpenCV的3個設定設好(compiler include目錄、linker lib目錄、linker的咒語), 還有 工作執行目錄working_dir 在 (in C的Users的使用者的Desktop的freeglut的bin) 裡面放圖檔earth.jpg

1. OpenCV設定: Setting-Compiler, Search directories, Compiler include: C:\OpenCV2.1\include
2. OpenCV設定: Setting-Compiler, Search directories, Linker lib目錄: C:\OpenCV2.1\lib
3. OpenCV設定: Setting-Compiler, Linker設定: 咒語 cv210 cxcore210 highgui210
4. earth.jpg 圖檔要放哪裡: 工作目錄working_dir   (in C:\Users\...\Desktop\freeglut\bin)


## step02-1
接下來我們想要利用期中考考過的 glBegin(GL_POLYGON) 開始畫 及 glEnd()結束畫, 中間夾4行 glTexCoord2f(tx,ty) 及 glVertex2f(x,y) 來把背景貼圖做出來。

- glBegin(GL_POLYGON); //開始畫 
-   glTexCoord2f(tx,ty); glVertex2f(x,y); // 寫4次
- glEnd(); //結束畫

## step02-2
今天的第2個主題: 主題: 上週貼圖+貼到圓球=會轉的地球
1. File-New-Project, GLUT專案, week10_texture_eartch 貼上前面的程式
2. Q: 圓球怎麼畫? A: 圓球的3D座標 & 2D的貼圖座標,要用 cos(), sin()來算出來
3. `GLUquadric * sphere = NULL; //指標,指到二次曲面`
4. 在 main() `sphere = gluNewQuadric();///準備好二次曲面`
5. 在 display() `gluQuadricTexture(sphere, 1);//設好貼圖`
6. 在 display() `gluSphere( sphere, 1, 30, 30 ); //畫圓球`

`gluSphere( 一個指標, r半徑, slices柳丁切經線, stacks堆疊緯 );`
`gluSphere( sphere,    1,    30,               30 );`

- OpenGL (GL) 的函式 ex. glVertex2f()
- OpenGL Utilities (GLU) 的函式 ex. gluSphere()
- OpenGL User Toolkit (GLUT) 的函式 ex. glutSolidTeapot()

```cpp
///用上一個程式來改
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere = NULL;///指標,指到二次曲面
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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluQuadricTexture(sphere, 1); ///設好貼圖
    gluSphere(sphere, 1, 30, 30); ///畫圓球
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glutDisplayFunc(display);
    myTexture("earth.jpg");///地球的地圖,圖等一下會準備好
    sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}
```

## step02-3
要動起來!!!
step02-3_做出會旋轉的地球。使用的方法,是利用 float angle=0 變數, 在 display()裡 glPushMatrix() 及 glPopMatrix()的中間, 有 glRotatef(angle, 0,0,1) 對z軸轉。display()最後 angle += 1 改變角度。 main() 裡面 glutIdleFunc(display) 會在有空時重覆呼叫display()

```cpp
//前面省略
float angle=0;///旋轉角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef( angle, 0,0,1);
        gluQuadricTexture(sphere, 1); ///設好貼圖
        gluSphere(sphere, 1, 30, 30); ///畫圓球
    glPopMatrix();

    glutSwapBuffers();
    angle+=1; ///每次執行 display() 加 1度
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glutIdleFunc(display);///有空idle 呼叫 display()
    glutDisplayFunc(display);
    myTexture("earth.jpg");///地球的地圖,圖等一下會準備好
    sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}
```

## step03-1
剛剛旋轉中的地球,是看到北極在轉動。現在我們把它轉正,使用glRotatef(90, 1,0,0) 但看到破圖,原來是3D深度測試的功能還沒開 就 glEnable(GL_DEPTH_TEST) 開起來,就好了

```cpp
//前面省略
float angle=0;///旋轉角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(90, 1,0,0);///把它轉正
        glRotatef( angle, 0,0,1);
        gluQuadricTexture(sphere, 1); ///設好貼圖
        gluSphere(sphere, 1, 30, 30); ///畫圓球
    glPopMatrix();

    glutSwapBuffers();
    angle+=1; ///每次執行 display() 加 1度
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glEnable(GL_DEPTH_TEST);///開3D深度測試,才會有3D的效果
    glutIdleFunc(display);///有空idle 呼叫 display()
    glutDisplayFunc(display);
    myTexture("earth.jpg");///地球的地圖,圖等一下會準備好
    sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}
```

## step03-2
step03-2_想結合上週的貼圖+上上週的3D模型,時間來不及讓大家練習, 老師先做出來給你看。重點是有很多要設定的地方,上週、上上週都有做過、檔案也要放在對的目錄。請看老師的筆記吧。

上週貼圖+貼到模型=鋼彈模型
1. 下載 jsyeh.org/3dcg10 課本的 windows.zip data.zip source.zip(glm.h glm.cpp 放在專案的目錄)
2. 下載老師買的 Gundam模型 myGundam.zip
3. File-New-Project, GLUT專案, week10_texture_model
4. 小心, 工作目錄在 C:\...\freeglut\bin 裡要放 Gundam 3D模型
5. 小心, glm.h glm.cpp 放在專案的目錄, 放在 main.cpp 的旁邊
6. 把地球的程式拿來, 改成 3D模型的版本

前面要 `#include "glm.h"`

```cpp
#include "glm.h" ///使用3D模型
GLMmodel * pmodel = NULL;///使用3D模型
```

在 `display()` 的地方做修改
```cpp
loat angle=0;///旋轉角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle, 0,1,0);
        if(pmodel==NULL){ ///使用3D模型
            pmodel = glmReadOBJ( "data/Gundam.obj" ); ///使用3D模型
            glmUnitize(pmodel);///使用3D模型,縮放到 -1...+1間,才看得到
            glmFacetNormals(pmodel);///使用3D模型,面的法向量
            glmVertexNormals(pmodel, 90);///使用3D模型, 頂點的法向量
        }
        glmDraw(pmodel, GLM_TEXTURE);
    glPopMatrix();

    glutSwapBuffers();
    angle+=1; ///每次執行 display() 加 1度
}
```

最後 main() 要讀入模型 `myTexture("data/Diffuse.jpg")`

```cpp
//前面省略
    myTexture( "data/Diffuse.jpg" );

    glutMainLoop();
}
```

# Week11
電腦圖學 Week11 2022-05-02
1. 主題: 持續實作 glm 模型相關練習
2. 主題: 利用 Maya 切割模型
3. 主題: 對(特定)旋轉軸轉動(下週作業&下下週考試)
   組合技: T移動、R旋轉、T移動
   
## step01-1
持續實作 glm 模型相關練習: OpenCV讀圖

1. (家裡OK) freeglut裝好 lib\libglut32.a 工作目錄
2. (家裡OK) OpenCV2.1裝好 小心!! Add PATH C:\OpenCV2.1\bin
3. (家裡OK) OpenCV 咒語 Setting-Compiler-Search directories目錄 Compiler include目錄
4. (家裡OK) OpenCV 咒語 Setting-Compiler-Search directories目錄 Linker lib目錄
5. (家裡OK) OpenCV 咒語 Setting-Compiler-Linker設定 cv210 cxcore210 highgui210
6. (重開CodeBlocks)File-New-Project, GLUT專案 桌面 week11_gundam (in 工作執行目錄) C:...\桌面\freeglut\bin
7. 放 myGundam.zip 的模式檔 data裡的檔案 放到 工作執行目錄 freeglut\bin\data\ 裡面
8. 把 week09_opencv 的範例,拿來用,小心圖檔在哪裡!!!
```cpp
#include <opencv/highgui.h>
int main()
{
	IplImage * img = cvLoadImage( "data/Diffuse.jpg" );//gundam的貼圖
	cvShowImage("week11", img);
	cvWaitKey(0);
}
```
## step01-2
持續實作 glm 模型相關練習: 把茶壼貼上Gundam的貼圖
1. 上面: 上週的 myTexture 放程式
2. 下面: GLUT 10行程式 放程式
3. main() 的 glutMainLoop()之前,加入 myTexture( "data/Diffuse.jpg" );

上面: 上週的 myTexture 放程式

```cpp
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
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
```

下面: GLUT 10行程式 放程式

另外 main() 的 glutMainLoop()之前,加入 myTexture( "data/Diffuse.jpg" );

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 gundam");

    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");

    glutMainLoop();
}
```

## step02-1
持續實作 glm 模型相關練習: 把模型 讀進來, 畫出來
1. 在 jsyeh.org/3dcg10 下載 source.zip (裡面的 glm.h glm.c 還有 transformation.c要拿來參考)
2. 把 glm.c 改檔名成 glm.cpp (小心副檔名), 把 glm.h glm.cpp 放到 week11_gundam 專案目錄中,當main.cpp的鄰居
3. 在 week11_gundam 專案中(左邊), Add Files... 加入 glm.cpp 成為 main.cpp 的鄰居
4. 加入程式碼 (暗示:可參考 transformation.c 的 glm相關程式)
5. main.cpp 在前面 include 2行
6. display() 裡 加入好多行

main.cpp 在前面 include 2行
```cpp
#include "glm.h"
GLMmodel * pmodel = NULL; //空指標
```

display() 裡 加入好多行
```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot( 0.3 );
    if( pmodel == NULL ){ //如果是 空指標, 表示模型沒準備好
        pmodel = glmReadOBJ("data/Gundam.obj"); //就讀模型
        glmUnitize( pmodel ); //換算成Unit單位大小 -1...+1 
        glmFacetNormals( pmodel ); //重新計算模型的面的法向量
        glmVertexNormals( pmodel , 90 ); //重新計算模型的頂點的法向量
    }
    glmDraw( pmodel, GLM_TEXTURE ); //有模型後, 畫面,要記得畫貼圖
    glutSwapBuffers();
}
```


## step02-2
發現問題:
1. 貼圖好像上下倒過來!!! 身體是藍色,腳是白色
2. 所以,把 data\Diffuse.jpg 用小畫家改一下
3. 好像模型(前後)被壓扁了...下一個課堂作業,要解決它!!!

## step03-1
前一節課的程式裡, 模型(前後)被壓扁了, 因為還沒開 3D的前後深度測試

所以需要開啟 3D前後深度測試功能 glEnable(GL_DEPTH_TEST), 最後,我們希望模型可以轉動,所以利用 float angle 配合 angle += 1 及 glutIdleFunc(display) 持續重畫畫面來轉動

1. glEnable(GL_DEPTH_TEST);
2. 轉起來!!!! glRotatef(angle, 0,1,0);
3. angle += 1; //每次 display加1度
4. glutIdleFunc( display );

```cpp
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    if( pmodel == NULL ){ ///如果是 空指標, 表示模型沒準備好
        pmodel = glmReadOBJ("data/head.obj"); ///就讀模型
        glmUnitize( pmodel ); ///換算成Unit單位大小 -1...+1
        glmFacetNormals( pmodel ); ///重新計算模型的面的法向量
        glmVertexNormals( pmodel , 90 ); ///重新計算模型的頂點的法向量
    }

    glPushMatrix();
        glRotatef(angle, 0,1,0);
        glmDraw( pmodel, GLM_TEXTURE ); ///有模型後, 畫面,要記得畫貼圖
    glPopMatrix();

    glutSwapBuffers();
    angle += 1;
}
```

## step03-2
老師利用 YouTube影片示範 Maya 如何匯出OBJ模型檔,同時可調整material,再利用selection來決定如何分割匯出對應的模型

https://www.youtube.com/watch?v=D4a7cNFF9kQ
如何使用 Maya 匯出 3D模型檔(OBJ)

## step03-3
最後老師示範T-R-T的技巧,可以將做出特定軸轉動。下週會再教一次,並且有作業、下下週有考試, 強化這個觀念

1. 模仿前一個程式寫法, 也就是讓 angle 可以一直有變化
2. 簡單的程式, 使用茶壼來畫出 body() 及 hand() 
3. 重點的地方, 是 glPushMatrix() ... glPopMatrix() 中間, 有 glTranslatef(), glRotatef(), glTranslatef() 這樣的程式架構

```cpp
#include <GL/glut.h>
void hand(){
    glColor3f(0,1,0);
    glutSolidTeapot( 0.2 );
}
void body(){
    glColor3f(1,1,0);
    glutSolidTeapot( 0.3 );
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    body();
    glPushMatrix();
        glTranslatef(0.5, 0.2, 0);
        glRotatef(angle, 0,0,1);
        glTranslatef(0.3, 0, 0);
        hand();
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 TRT");

    glutIdleFunc( display );
    glutDisplayFunc( display );

    glutMainLoop();
}
```


# Week12

## step01-1
課本範例 Transformation.exe 再看它的變化
step01-1_利用課本範例,想要搞懂 translate 及 rotate 在不同順序的差別。老師使用畫框框的方法,讓同學可以從小到大,慢慢理解程式。

1. jsyeh.org/3dcg10 下載 windows.zip data.zip
2. windows.zip => 下載\windows\Transformation.exe
3. data.zip    => 下載\windows\data\模型
4. 重點在: 有T移動、有R轉動, 按右鍵 Swap交換 T R
5. glTranslatef( 0.9 , 0.0 , 0.0 ); 移動
6. glRotatef( 角度, 0, 1, 0); 旋轉

在右邊 轉動的 藍色車子 (自轉)
```cpp
glTranslatef( 0.9 , 0.0 , 0.0 ); 移動 在右邊
glRotatef( 角度, 0, 1, 0); 旋轉
畫一台藍色的車子
```

繞著中間轉彎的車子 (公轉)
```cpp
glRotatef( 角度, 0, 1, 0); 旋轉
glTranslatef( 0.9 , 0.0 , 0.0 ); 移動 在右邊
畫一台藍色的車子
```

## step01-2
step01-2_老師做了一個教學網頁,示範 OpenGL T-R-T 的效果, 網頁可以畫圖、可以旋轉、可以移動程式碼的順序。先讓大家看 glRotatef() 影響身體、影響手臂的狀況

用另一個程式來理解 OpenGL T-R-T函式: 對特定軸轉動練習
1. 120.125.80.50/GL 有程式 (小心! 不安全, 繼續) 期中考題、小考題
2. (右下角) 點 ToDraw, 左邊黑色可畫圖
3. Ctrl-R Reload可清空
4. 可以畫個身體 叫 myDrawObject(0)
5. 可以畫個手臂 叫 myDrawObject(1)
6. 可以改程式碼的順序
7. 可以按 angle= 再按空白鍵 會自動改變動畫

如果切換動畫時, 下面的手臂會很誇張的轉動
```cpp
glPushMatrix();
	glRotatef(angle, 0, 0, 1);
	myDrawObject(1);//畫手臂
glPopMatrix();
```

下面的程式, 則是手臂與身體都會一起轉動
```cpp
glPushMatrix();
	glRotatef(angle, 0, 0, 1);
	myDrawObject(1);//畫手臂
	myDrawObject(0);//畫身體
glPopMatrix();
```

下面的程式, 身體會轉動, 手臂會留在原地, 為什麼, 你能理解嗎?

```cpp
glPushMatrix();
	myDrawObject(1);//畫手臂
	glRotatef(angle, 0, 0, 1);
	myDrawObject(0);//畫身體
glPopMatrix();
```

理解的時候, 就使用老師 step01-1 教過的畫框框方法, 從小框框到大框框,慢慢增加程式碼

## step02-1
step02-1_剛剛的網頁, 繼續加新的功能glTranslate() 目標是讓手臂正確揮手, 身體不要動。我們先把手臂砍下來,把軸心放在世界轉盤的中心, 再把整個世界轉動, 得到長在肚臍的手臂在轉動。最後在上面再加一行移動,把整個轉動的手搬到肩膀掛上去
1. 把 glTranslatef()那一行,點它,變紅色,便可以移動左邊的東西
2. 把一個 glTranslatef()放在 Rotatef()的下面、手臂的上面
3. 另一個 glTranslatef()放在 Rotatef()的上面

經過下面的程式碼, 請想像成把手臂砍下來, 把軸心放在世界轉盤的中心。這時候, 再把整個世界轉動, 便可以看到很變態的、長在肚臍的手臂在轉動。

```cpp
glPushMatrix();
	myDrawObject(0);//畫身體
	glRotatef(angle, 0, 0, 1); //這個旋轉,會轉下面整個東西
	glTranslatef(-0.3, -0.19, 0);//往左下方移(讓軸心 放世界的中心)
	myDrawObject(1);//畫手臂 (右上方)
glPopMatrix();
```

最後, 把最上面的T擺好、掛到身體的右上角

```cpp
myDrawObject(0);//畫身體
glPushMatrix();
	glTranslatef(0.29, 0.31, 0);//往右上方移(掛到身體的右上角)
	glRotatef(angle, 0, 0, 1); //這個旋轉,會轉下面整個東西
	glTranslatef(-0.3, -0.19, 0);//往左下方移(讓軸心 放世界的中心)
	myDrawObject(1);//畫手臂 (右上方)
glPopMatrix();
```

## step02-2
花了2小時理解今天教的 T-R-T 之後, 老師講解下週的考試題目, 會有一張照片 drawXXX()畫東西, 但是直接旋轉時會發生悲劇, 所以要 (1) 用最下面的T, 把旋轉中心放到正中心, (2) 轉動某個角度, (3) 最上面的T,把整個東西掛在對的位置


```cpp
glPushMatrix();
  glTranslatef(-0.5, -0.9, 0); //(3)最上面的T,把整個東西掛在對的位置
  glRotatef(-45, 0,0,1); //(2)轉動某個角度
  glTranslatef(-0.8, 0.9, 0); //(1)用最下面的T, 把旋轉中心放到正中心
  drawHand();
glPopMatrix();
```

## step02-3
step02-3_現在開始寫程式。使用剪貼的方式, 把剛剛準備考試的筆記 T-R-T 加到 GLUT 10行程式碼的範例中, 配合上週的自動旋轉, 等一下要把 glTranslatef()裡面的值設定好

現在要寫程式了, 請用剪貼的, 從今天的筆記, 之前的筆記
1. File-New-Project, GLUT專案, week12_TRT
2. 把 10行程式碼放上去 (之前的筆記)
3. 把 T-R-T 的6行放上去 (今天的筆記)
4. 再讓它會自動轉 float angle=0; 
5. 配上 glRotatef(angle, 0,0,1); 
6. 再 angle++
7. glutIdleFunc( display ); (上週的筆記)

```cpp
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        ///glTranslatef(0, 0, 0);
        glRotatef( angle, 0, 0, 1);
        ///glTransaltef(0, 0, 0);
        glutSolidTeapot( 0.2 );///想像它是手臂
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main( int argc, char** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE|GLUT_DEPTH );
    glutCreateWindow("week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step03-1
做出茶壼超人, 有白色的身體, 有紅色的小手臂, 要利用T-R-T讓小手臂對任意軸轉動

```cpp
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot( 0.3 );///茶壼當身體
    glPushMatrix();
        glTranslatef(0.2, 0, 0);///(3)掛到右邊 (把整個往右移動)
        glRotatef( angle, 0, 0, 1);///(2)旋轉
        glTranslatef(0.2, 0, 0); ///(1)把旋轉中心,放到世界中心
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot( 0.2 );///小茶壼 想像它是手臂
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main( int argc, char** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE|GLUT_DEPTH );
    glutCreateWindow("week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step03-2
step03-2_為了寫回家作業, 老師開新的專案 week12_TRT_TRT 給大家看, 裡面將會有上手臂、下手肘。好像大一學程式時的兩層大括號的感覺。

1. 要有 3D模型 (可以自己用Maya建出來, 也可以用網路上找的模型再來裁切), 要有身體、要有上手臂、下手肘
2. 要用 TRT TRT 做出來

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);///白色
    glutSolidTeapot( 0.3 );///茶壼當身體
    glPushMatrix(); ///右邊的手臂、手肘
        glTranslatef(0.2, 0, 0);///(3)掛到右邊 (把整個往右移動)
        glRotatef( angle, 0, 0, 1);///(2)旋轉
        glTranslatef(0.2, 0, 0); ///(1)把旋轉中心,放到世界中心
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot( 0.2 );///小茶壼 想像它是手臂
        glPushMatrix();
            glTranslatef(0.2, 0, 0);///(3)掛到右邊 (把整個往右移動)
            glRotatef( angle, 0, 0, 1);///(2)旋轉
            glTranslatef(0.2, 0, 0); ///(1)把旋轉中心,放到世界中心
            glColor3f(1,0,0);///紅色的
            glutSolidTeapot( 0.2 );///小茶壼 想像它是手臂
        glPopMatrix();
    glPopMatrix();
	
    glutSwapBuffers();
    angle++;
}
```

## step03-3
step03-3_如果右手臂、右手肘做出來, 其實複製後, 改一下正負號, 可以做出左手邊的手臂、手肘哦

```cpp
    glPushMatrix(); ///右邊的手臂、手肘
        glTranslatef(0.2, 0, 0);///(3)掛到右邊 (把整個往右移動)
        glRotatef( angle, 0, 0, 1);///(2)旋轉
        glTranslatef(0.2, 0, 0); ///(1)把旋轉中心,放到世界中心
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot( 0.2 );///小茶壼 想像它是手臂
        glPushMatrix();
            glTranslatef(0.2, 0, 0);///(3)掛到右邊 (把整個往右移動)
            glRotatef( angle, 0, 0, 1);///(2)旋轉
            glTranslatef(0.2, 0, 0); ///(1)把旋轉中心,放到世界中心
            glColor3f(1,0,0);///紅色的
            glutSolidTeapot( 0.2 );///小茶壼 想像它是手臂
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左邊的手臂、手肘
        glTranslatef(-0.2, 0, 0);///(3)掛到右邊 (把整個往右移動)
        glRotatef( -angle, 0, 0, 1);///(2)旋轉
        glTranslatef(-0.2, 0, 0); ///(1)把旋轉中心,放到世界中心
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot( 0.2 );///小茶壼 想像它是手臂
        glPushMatrix();
            glTranslatef(-0.2, 0, 0);///(3)掛到右邊 (把整個往右移動)
            glRotatef( -angle, 0, 0, 1);///(2)旋轉
            glTranslatef(-0.2, 0, 0); ///(1)把旋轉中心,放到世界中心
            glColor3f(1,0,0);///紅色的
            glutSolidTeapot( 0.2 );///小茶壼 想像它是手臂
        glPopMatrix();
    glPopMatrix();
```



## step03-4
複習Git指令, 上傳到GitHub

1. 安裝 Git for Windows, 再開啟 Git Bash
2. 要會改變目錄(change directory), ex. cd desktop 桌面, 有人的電腦的桌面在奇怪的地方(OneDrive,D:,...), 就會進不去
3. start . 開啟現在的目錄
4. git clone https://github.com/jsyeh/2022graphics1
 可以把你在 GitHub 上面的雲端 clone 複製下來。但是有些人已經複製過,就不能複製第2次 (會有錯誤訊息 already exists), 這時就不用到clone了
5. cd 2022graphics1 進入你的(倉庫)目錄 (黃色會說明你在哪裡)
6. git pull 是把雲端拉下來你的硬碟的倉庫
7. start . 可以開啟現在的目錄, 就可以Ctrl-C Ctrl-V 複製你的程式
8. git status 看你的倉庫的狀況 (多了2個紅色的目錄)
9. git add  .  把你目錄中紅色的都加到你的 git帳冊
10. git status 看你的倉庫的狀況 (多了綠色的一堆東西)
11. 要 git commit -m "add week12" 確認你的 git帳冊 (不過,如果你之前沒有做過, 那你要 git config --global user.name jsyeh 還有 git config --global user.email jsyeh@mail.mcu.edu.tw 做第1次設定)
12. git push 推送上雲端
 


# Week13

## step01-1
step01-1_利用 glRectf(x1,y1, x2,y2) 想簡化程式,示範TRT的觀念

glRectf(x1,y1, x2,y2) 方塊

1. File-New-Project, GLUT專案, week13_rect_TRT
2. 貼上 GLUT 10行程式,不用茶壼, 改 glRectf()

```cpp
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glRectf( 0.3, 0.5,  -0.3, -0.5);///四邊形
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step01-2
step01-2_接下來,再把紅色的手臂準備好, 同時把 T-R-T 的程式放好, 讓大家了解程式的架構

想把手加上去,而且要讓它可以轉動
1. 另一個小方塊 加點色彩
2. 準備好TRT程式碼

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf( 0.3, 0.5,  -0.3, -0.5);///身體,四邊形
    glPushMatrix();
        ///glTranslatef(x, y, z);//(3)把手臂掛回身體
        ///glRotatef(angle, 0,0,1);//(2)旋轉 對z軸轉
        ///glTransaltef(x2, y2, z2);//(1)把手臂的旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf( 0.3, 0.5,  0.7, 0.3);
    glPopMatrix();
    glutSwapBuffers();
}
```

## step01-3 
step01-3_接下來我們依序把 T-R-T 慢慢寫出來。(1)先寫最下面的T,把手臂的旋轉中心放到世界的中心, (2) float angle=45 轉動45度,可以看到手臂在肚臍的地方轉45度, (3) 最上面的T把手臂再掛回原本的位置, 完成

先把旋轉中心放在正中心
把 (0.3 0.4) 移到 (0 0)
glTranslatef(-0.3, -0.4, 0);

再把旋轉做好

最後再掛回身體的手臂位置

```cpp
#include <GL/glut.h>
float angle=45;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf( 0.3, 0.5,  -0.3, -0.5);///身體,四邊形
    glPushMatrix();
        glTranslatef( 0.3,  0.4, 0);///(3)把手臂掛回身體
        glRotatef(angle, 0,0,1);///(2)旋轉 對z軸轉
        glTranslatef(-0.3, -0.4, 0);///(1)把手臂旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf( 0.3, 0.5,  0.7, 0.3);
    glPopMatrix();
    glutSwapBuffers();
}
```

## step02-1
step02-1_剛剛的程式最後收尾時,我們利用 mouse motion 來改變它的角度, 要記得glutMouseFunc(mouse)及glutMotionFunc(motion)也要加上去哦.zip

接下來要利用 mouse motion 來旋轉手臂的角度值

```cpp
#include <GL/glut.h>
float angle=45, oldX=0;
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();///請GLUT重畫畫面 Re display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf( 0.3, 0.5,  -0.3, -0.5);///身體,四邊形
    glPushMatrix();
        glTranslatef( 0.3,  0.4, 0);///(3)把手臂掛回身體
        glRotatef(angle, 0,0,1);///(2)旋轉 對z軸轉
        glTranslatef(-0.3, -0.4, 0);///(1)把手臂旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf( 0.3, 0.5,  0.7, 0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step02-2
step02-2_新開專案week13_rect_TRT_TRT 想要做出2個關節。所以接續前面的程式,先把float angle=0 變回0度, 再增加下面的綠手肘的部分

新開專案 week13_rect_TRT_TRT 做出更多關節

1. File-New-Project, GLUT專案, week13_rect_TRT_TRT
2. 把前面的程式拿來用
3. 要新增的地方, 是第二個關節

```cpp
///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=0, oldX=0;
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();///請GLUT重畫畫面 Re display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf( 0.3, 0.5,  -0.3, -0.5);///身體,四邊形

    glPushMatrix();
        glTranslatef( 0.3,  0.4, 0);///(3)把手臂掛回身體
        glRotatef(angle, 0,0,1);///(2)旋轉 對z軸轉
        glTranslatef(-0.3, -0.4, 0);///(1)把手臂旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf( 0.3, 0.5,  0.7, 0.3);///上手臂

        glPushMatrix();
            ///glTranslatef( x, y, z);
            ///glRotatef(angle, 0,0,1);
            ///glTranslatef(x2,y2,z2);
            glColor3f(0,1,0);///綠色的
            glRectf( 0.7, 0.5, 1.0, 0.3);///下手肘
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}
```

## step02-3
接下來, 照著把下手肘的T-R-T依序做出來。
```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf( 0.3, 0.5,  -0.3, -0.5);///身體,四邊形

    glPushMatrix();
        glTranslatef( 0.3,  0.4, 0);///(3)把手臂掛回身體
        glRotatef(angle, 0,0,1);///(2)旋轉 對z軸轉
        glTranslatef(-0.3, -0.4, 0);///(1)把手臂旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf( 0.3, 0.5,  0.7, 0.3);///上手臂

        glPushMatrix();
            glTranslatef( 0.7,  0.4, 0);///(3)把手肘掛回剛剛的位置
            glRotatef(angle, 0,0,1);///(2)旋轉
            glTranslatef(-0.7, -0.4, 0);///(1)把手肘旋轉中心,放中心
            glColor3f(0,1,0);///綠色的
            glRectf( 0.7, 0.5, 1.0, 0.3);///下手肘
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}
```

## step03-1 
step03-1_接下來是今天的最後一個專案 week13_rect_many_TRT, 要做出更多的關節。利用左右對稱的原則,複製 glPushMatrix()...glPopMatrix() 的程式碼, 再把x座標正負修改, 便完成鏡射了

新的專案 week13_rect_many_TRT
再寫新的程式碼

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf( 0.3, 0.5,  -0.3, -0.5);///身體,四邊形

    glPushMatrix(); ///右半部
        glTranslatef( 0.3,  0.4, 0);///(3)把手臂掛回身體
        glRotatef(angle, 0,0,1);///(2)旋轉 對z軸轉
        glTranslatef(-0.3, -0.4, 0);///(1)把手臂旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf( 0.3, 0.5,  0.7, 0.3);///右上手臂

        glPushMatrix();
            glTranslatef( 0.7,  0.4, 0);///(3)把手肘掛回剛剛的位置
            glRotatef(angle, 0,0,1);///(2)旋轉
            glTranslatef(-0.7, -0.4, 0);///(1)把手肘旋轉中心,放中心
            glColor3f(0,1,0);///綠色的
            glRectf( 0.7, 0.5, 1.0, 0.3);///右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左半部
        glTranslatef(-0.3,  0.4, 0);///(3)把手臂掛回身體
        glRotatef(angle, 0,0,1);///(2)旋轉 對z軸轉
        glTranslatef(+0.3, -0.4, 0);///(1)把手臂旋轉中心,放中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3, 0.5, -0.7, 0.3);///左上手臂

        glPushMatrix();
            glTranslatef(-0.7,  0.4, 0);///(3)把手肘掛回剛剛的位置
            glRotatef(angle, 0,0,1);///(2)旋轉
            glTranslatef(+0.7, -0.4, 0);///(1)把手肘旋轉中心,放中心
            glColor3f(0,1,0);///綠色的
            glRectf(-0.7, 0.5,-1.0, 0.3);///左下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
```

## step03-2
step03-2_最後可以使用鍵盤keyboard()來切換 angleID, 之後可以用 angle[angleID] 來修改對應的關節, 比如 angleID=0時, 會動到angle[0] 的關節

如果只有一個角度 angle 沒有辦法
要幾個角度? 20個
float angle=0;
float angle[20];
改完後, 要全部的 angle都改

很多關節, 可用keyboard()切換

```cpp
float angle[20], oldX=0;
int angleID=0; ///0號關節, 1號關節, 2號關節, 3號關節
void keyboard(unsigned char key, int x, int y){
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
    oldX = x;
    glutPostRedisplay();///請GLUT重畫畫面 Re display
}
```
記得 main() 要加上 glutKeyboardFunc(keyboard);

## step03-3
step03-3_今天課程結束。有同學在網路上問到作業要如何用許多的關節轉動, 老師用同學的例子做示範, 先把程式碼重覆的地方用函式來簡化, 接下來便是用今天教的許多TRT來完成身體各關節的轉動。


# Week14
電腦圖學 Week14 2022-05-24
1. 寫檔、讀檔
2. 關節、做動畫
3. 計時器 glutTimerFunc(時間, timer, 參數t)
4. 播放聲音

## step01-1
step01-1_為了記錄動畫的動作,我們需要寫檔。fopen()開檔, fprintf()寫檔, fclose()關檔

write 寫檔 File Output (記錄)
0. File-New-Empty File, 存檔到 week14-1_fprintf 目錄裡的 week14-1.cpp
1. fopen() 開啟檔案 `FILE * fout = fopen("檔名", "w+");`
2. printf() => fprintf() File Output
3. fclose() 關閉檔案

```cpp
///Week14-1.cpp step01-1
#include <stdio.h>
int main()
{///檔案指標 fout  開啟檔案(檔名, write模式)
    FILE * fout = fopen("file.txt", "w+");
     printf(     "Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///關閉檔案
}
```

## step01-2
step01-2_再加上讀檔,使用fscanf()來讀檔,要小心變數要有&在前面

read 讀檔 File Input 
0. File-New-EMpty File, 存檔到 week14-2_fprintf_fscanf 目錄裡的 week14-2.cpp
1. 把剛剛 week14-1.cpp 拿來用
2. 另外一組  `FILE * fin = fopen("檔名", "r");`
3. scanf() => fscanf() File Input
4. fclose()

```cpp
///Week14-2.cpp step01-2
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt", "w+");
    fprintf(fout,"3.1415926\n");
    fclose(fout);///關閉檔案

    float angle=0;
    FILE * fin = fopen("file.txt", "r");
    fscanf(fin, "%f", &angle ); ///沒加&會當掉
    printf("讀到了角度:%f", angle);
    fclose(fin);
}
```

## step01-3
step01-3_有了前面檔案的基礎,接下來把上週week13_rect_many_TRT 拿來改裝, 加上寫檔案的功能, 先把FILE指標fout=NULL還沒開啟,在void myWrite()裡面如果fout沒開好,就fopen(),接下來用for迴圈印出20個角度的值(到小黑、也到檔案),我們還沒有fclose()

把上週的程式 week13_rect_many_TRT 拿來改
0. File-New-Project, GLUT專案 week14_angles_fprintf
1. 將 week13_rect_many_TRT 的 main.cpp 內容copy過來
2. 加上 `FILE * fout=NULL;`
3. 加上 void myWrite() 裡面有fopen() 及 for迴圈裡 fprintf()
4. 在 motion()裡, 呼叫 myWrite()

```cpp
///week14_angles_fprintf 改自 week13_rect_many_TRT
#include <GL/glut.h>
#include <stdio.h>
float angle[20], oldX=0;
int angleID=0;
FILE * fout = NULL;
void myWrite(){
    if( fout == NULL ) fout = fopen("file.txt", "w+");

    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i] );///小黑印出來
        fprintf(fout, "%.1f ", angle[i] );///檔案印出來
    }///這裡老師沒有fclose
}
void keyboard(unsigned char key, int x, int y){
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
    myWrite();
    oldX = x;
    glutPostRedisplay();///��GLUT���e�e�� Re display
}
//下略
```

## step02-1
step02-1_又是新的專案。copy前一步程式myWrite()可以寫檔, 現在再加上myRead(), 並且在keyboard()裡如果按下r鍵,就會讀一行資料。一直按著r就會一直讀資料,並且glutPostRedisplay()持續重畫更新

要做動畫囉!!!
0. File-New-Project, GLUT專案 week14_angles_fprintf_fscanf
1. copy前一個版本的程式來修改
2. 要寫 void myRead() 
3. keyboard()裡, 按下 'r' 呼叫 myRead()

```cpp
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
    if( key=='r' ) myRead();
    if( key=='0' ) angleID=0;
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}
```

## step02-2
step02-2_有同學遇到目錄的問題,所以老師教大家 GLUT專案 freeglut.dll 歷史餘毒的問題, 解釋 What Why How 如何解決, 就是安裝 Notepad++ 後, 便可以修改 .cbp CodeBlocks專案檔, 把裡面的working_dir=右邊雙引號裡改成小數點,就會用專案的這個目錄。只是要記得把桌面的freeglut的bin的freeglut.dll也放到你的專案目錄中

很奇怪, 我們為什麼產生的檔案file.txt放在奇怪的目錄 C:\Users\user\Desktop\freeglut\gin 好奇怪!!! 想要放在程式專案的那個目錄!!
0. What! 好奇怪!!! file.txt放在奇怪的目錄 
1. Why? 原來是歷史餘毒 GLUT專案 需要 freeglut.dll 所以 working_dir被設到 freeglut\bin 裡面
2. How? 在 .cbp CodeBlocks Project 檔裡, 有 working_dir的設定 工作執行的目錄
3. 使用 Notepad++ 把 .cbp 的 working_dir="....."  改 working_dir="." 小數點
4. Notepad++存檔後, CodeBlocks Reload它, 便成功了!!!!
5. 小心 歷史餘毒 freeglut.dll 要再修正, 放到week14_angles_fprintf_fscanf 程式專案的同目錄, 再執行時, 便可以 mouse motion 動動動, 按r重播,而且file.txt 也放在你的程式專案目錄囉!!!

沒裝 Notepad++ 的, 快去下載台灣人 Don Ho 侯今吾先生寫的 Notepad++

## step03-1

glutTimerFunc() 計時器
```
rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
rrrrrrrr
rrrrrrrrrrrrrrrrrrrrrrrrrrr
rrrrrrrrrrrr
rrrrrrrrrrrrrrrrrrrr
rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
要看你的keyboard的速度,每個人的電腦設定會不同!
```
0. File-New-Project, GLUT專案 week14_timer
1. void timer(int t) 寫 timer函式
2. glutTimerFunc( 等多久, timer, t參數 );
3. 其他就是 GLUT 的10行程式碼!!

```cpp
///Week14_timer 每天早晨, 老師 05:50 鬧鐘響
///起床,閉著眼,再設定 05:53鬧鐘,再睡
///起床,閉著眼,再設定 05:56鬧鐘,再睡
///...
///起床,閉著眼,再設定 07:50鬧鐘...嚇死了..
#include <GL/glut.h>
#include <stdio.h>
void timer(int t){
    printf("起床,現在時間: %d\n", t);
}
void display(){
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14 timer");
    ///班代一次全部設好,不用那麼麻煩
    glutTimerFunc(1000, timer, 1);
    glutTimerFunc(2000, timer, 2);
    glutTimerFunc(3000, timer, 3);
    glutTimerFunc(4000, timer, 4);
    glutTimerFunc(5000, timer, 5);
    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step03-2
step03-2_timer最後面其實可再設定下一個timer出現的時機, 便能源源不絕的有timer定時叫起來

期末作品30秒,每秒30格, 900個timer有點麻煩, 程式應該自動一點
函式呼叫函式, 好像很帥!!! 但再改造一下, 

```cpp
void timer(int t){
	printf("我起床囉! %d\n", t);
	//做我的事
	glutTimerFunc(1000, timer, t);//要倒下去睡之前, 再設一個鬧鐘
}
```

## step03-2
step03-3_接下來可以在 timer()裡面定時播放聲音哦,只要PlaySound()並事先將do.wav檔準備好, 再include mmsystem.h 便可以順利播放 PlaySound(檔名, NULL, SND_ASYNC);

播放聲音 PlaySound() 請先下載 do.wav
1. 繼續改 week14_timer_one_by_one 
2. #include <mmsystem.h>
3. PlaySound("do.wav", NULL, SND_ASYNC); 

```cpp
void timer(int t){
	printf("我起床囉! %d\n", t);
	PlaySound("do.wav", NULL, SND_ASYNC); 
	glutTimerFunc(2000, timer, t+1 );
}
```

# Week15
電腦圖學 Week15 2022-05-31
1. 播聲音、播MP3
2. 播放動畫、內插
3. 機器人擺動作、跳舞

## step01-1
PlaySound() 更詳細解說

0. File-New-Empty File, 存成 week15-1_PlaySound.cpp
1. //#include <mmsystem.h> 上週教的
2. #include <windows.h> 本週改這
3. //PlaySound( "檔名.wav", NULL, SND_ASYNC);//上週 不等待/不同步
4. PlaySound( "檔名.wav", NULL, SND_SYNC);//本週, 等待,同步
5. Setting-Compiler..., Linker Setting 加入 winmm
5. 注意工作執行目錄 working_dir  (in C:\......)

```cpp
///Week15-1 PlaySound.cpp
#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");
    PlaySound("07042111.wav", NULL, SND_SYNC);///檔案不存在,會有很小聲的錯誤聲
    printf("PlaySound()之後\n");
}
```

## step01-2
PlaySound() 更多參數
0. File-New-Empty File, 存成 week15-2_SND_SYNC_SND_ASYNC
1. PlaySound("檔名.wav", NULL, SND_SYNC); 等待同步,結束後才下一行
2. PlaySound("檔名.wav", NULL, SND_ASYNC); 不等待同步,直接下一行
3. 

```cpp
///Week15-2 SND_SYNC SND_ASYNC
///不用再設定 Setting-Compiler.., Linker 加 winmm 因為加過了
#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("do.wav", NULL, SND_SYNC);///ASYNC不等待
    PlaySound("re.wav", NULL, SND_SYNC);///ASYNC不等待
    PlaySound("mi.wav", NULL, SND_SYNC);///ASYNC不等待
}///最後一行,就結束/死掉了
```

## step02-1
WAV(大/原始) vs. MP3(小/有壓縮) 檔案內容不一定
PlaySound()只能用大/原始的WAV檔, 只要1行

MP3檔比較麻煩, 很多行。有個好東西送給大家
Moodle可下載 CMP3_MCI.h

0. File-New-Empty File, week15-3_mp3.cpp
1. 在 Moodle 下載 CMP3_MCI.h 放在同目錄
2. 程式碼 #include "CMP3_MCI.h"
3. 宣告 CMP3_MCI mp3;
4. mp3.Load("檔名.mp3");
5. mp3.Play();

```cpp
#include <stdio.h>
#include "CMP3_MCI.h" ///記得要下載、放同目錄中
CMP3_MCI mp3;///宣告變數

int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();

    printf("隨便等你輸入數字,程式就卡住囉: ");
    int N;///為了卡住程式不要直接就結束了
    scanf("%d", &N);
}
```

## step02-2
今天主要都是接續上週的進度, 加強大家印象。接下來是要將動畫相關的動作編輯進行改良。接續上週的 week14_angles_fprintf_fscanf

0. File-New-Project, GLUT專案, week15_angles_TRT_again
1. copy 上週的程式碼, 改成 week15 並試跑: mouse motion, keyboard '0' '1' '2' '3' 換關節, 最後按 'r' 長按,可慢慢讀入資料
2. 發現問題: 很不像動畫!! 只是拉某一個關節, 很慢...
3. myWrite() 會寫一行, myRead()會讀一行
4. 不能把 myWrite() 放 motion()
5. 把動作對應的關節全部調好後, 才存(一行)動作
6. 所以在擺動作時, 擺好後,按 's' 存動作
7. 執行時,存幾個動作, 'r' 可讀入
8. 事後在工作執行目錄 file.txt 可以大量copy 動作,重覆,再重新跑程式,動作就多了!!!

## step03-1
機器人擺動作
1. 需要 3D Model (glm.h glm.cpp) (.obj .mtl .jpg ...)
2. 把模型切成很多塊 (因整塊就無法動關節) 分別讀入
3. TRT 的程式,才能轉動
4. keyboard() 切換關節, mouse motion() 轉動那一個關節

一步步做
1. File-New-Project, GLUT專案, week15_hw_gundam_parts
2. 工作執行目錄 working_dir 不太好, 要改到現在程式的目錄
3. 使用 Notepad++ 把 week15_hw_gundam_parts.cbp (CodeBlocks Project) 改裡面的 working_dir
4. 要把 glm.h glm.cpp 及 gundam 的 data目錄,全部放在你的程式目錄
5. 在 CodeBlocks 左邊的專案,加入 Add glm.cpp
6. 開始將 舊程式中的cvRectf()方塊, 逐一變成 3D模型。
7. 重點在, 要小心 T-R-T 的2個T的值是否正確 (需要一點經驗, 才能熟練地調好)


# Week16

## step01-1
step01-1_利用Excel來把alpha內插公式實作出來, 讓大家看到新的、舊的資料可以做內插

alpha內插公式: alpha: `0.0~1.0`

`angle = alpha*新 + (1-alpha)*舊`
ex.
- alpha: 0  => 舊
- alpha:0.5 => 半新半舊
- alpha: 1  => 新
使用 Excel or Google Spreadsheet 來做練習

## step01-2
step01-2_將上週的程式改造成有alpha內插的版本,按下'p'可以逐步進行內插, 必要時刻要把新的變舊的、再讀新的資料

用程式試試看 week15_angles_TRT_again 拿來改
1. File-New-Project, GLUT, week16_interpolation 內插
2. 複製程式,執行,按s存1行, mouse motion改動作4次,按s存檔
3. 原本失敗的結果, 按r會讀到動作,不連續, 關掉

接下來,要改造程式
1. void myInterplate(float alpha) 
2. 使用 for迴圈來改變20個關節的角度值
3. 計算出 alpha 值後, 便可以利用 `angle[i] = alpha * NewAngle[i] + (1-alpha) * NewAngle[i];`
4. 要修改 myRead() 裡面先把新的變舊的 `OldAngle[i] = NewAngle[i];` 再從檔案讀入新的角度 `fscanf(fin, "%f", &NewAngle[i] );`

```cpp
float NewAngle[20], OldAngle[20];
void myRead(){
    if( fout != NULL ) { fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        OldAngle[i] = NewAngle[i]; ///原來的新的,變舊
        fscanf(fin, "%f", &NewAngle[i] );///讀到新的角度
        ///fscanf(fin, "%f", &angle[i] );
    }
    glutPostRedisplay();///重畫畫面
}
void myInterpolate(float alpha){
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
    }
}
int t=0;
void keyboard(unsigned char key, int x, int y){
    if( key=='p' ){///Play
        if(t%30==0) myRead();
        myInterpolate(  (t%30)/30.0  ); ///介於 0.0~1.0
        glutPostRedisplay();
        t++;
    }
    if( key=='s' ) myWrite();///調好動作,才Save存檔
    if( key=='r' ) myRead();
    if( key=='0' ) angleID=0;
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}
```

## step02-1
step02-1_剛剛的myInterpolate()改成在 timer()裡面呼叫, 便能讓內插的動作更簡單運作。

```cpp
///int t=0;
void timer(int t){
    if( t%50==0 ) myRead();
    myInterpolate( (t%50)/50.0 );
    glutPostRedisplay();
    glutTimerFunc( 20, timer, t+1 );
}
void keyboard(unsigned char key, int x, int y){
    if( key=='p' ){///Play
        myRead();
        glutTimerFunc( 0, timer, 0 );
        ///if(t%30==0) myRead();
        ///myInterpolate(  (t%30)/30.0  ); ///介於 0.0~1.0
        ///glutPostRedisplay();
        ///t++;
    }
    if( key=='s' ) myWrite();///調好動作,才Save存檔
    if( key=='r' ) myRead();
    if( key=='0' ) angleID=0;
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}
```

## step02-2
step02-2_利用課本的範例 Projection.exe ,講解gluLookAt(眼睛座標、看哪裡、up向量)

## step03-1

step03-1_我們參考CodeBlocks GLUT範例,參考glutReshapeFunc()設定一個視窗可依長寬比來調整aspect ratio 在 gluPerspective()的參數, 並配合gluLookAt()函式來調整視角

1. File-New-Project, GLUT, week16_camera_projection_gluLookAt
2. 備份177行範例, 要改造裡面的程式
3. aspect ratio 長寬比 ex. 1920x1080, 1280x720, 640x480, 16:9, 4:3

```cpp
#include <GL/glut.h>
void reshape(int w, int h){///不能 整數除
    float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);///3D變2D
    glLoadIdentity();
    gluPerspective(60, ar, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);///3D Model+View
    glLoadIdentity() ;
    gluLookAt(0, 0, 3, ///eye
              0, 0, 0, ///center看哪裡
              0, 1, 0);///up向量
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16 camera");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);///範例是用resize
    glutMainLoop();
}
```

## step03-2
step03-2_利用motion()來修改 gluLookAt()的eye位置, 看到從不同地方看茶壼的效果。期末作品如果有了這個功能,會很帥氣,因為可以運鏡.

```cpp
#include <GL/glut.h>
void reshape(int w, int h){///不能 整數除
    float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);///3D變2D
    glLoadIdentity();
    gluPerspective(60, ar, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);///3D Model+View
    glLoadIdentity() ;
    gluLookAt(0, 0, 3, ///eye
              0, 0, 0, ///center看哪裡
              0, 1, 0);///up向量
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);
    glutSwapBuffers();
}
void motion(int x, int y){///新加的
    glMatrixMode(GL_MODELVIEW);///3D Model+View
    glLoadIdentity() ;
    gluLookAt((x-150)/150.0, (y-150)/150.0, 3, ///eye
              0, 0, 0, ///center看哪裡
              0, 1, 0);///up向量
    glutPostRedisplay();///請重畫畫面
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16 camera");
    glutMotionFunc(motion);///新加的
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);///範例是用resize
    glutMainLoop();
}
```

# Week17
電腦圖學 Week17 2022-06-14
1. 期末作品繳交方式
2. 期末作品評分方式
3. 網友問 push matrix 和 pop matrix 事件
4. 整學期大複習-示範期末作品怎麼做
## step01
介紹 Moodle 繳交期末作品的3個檔案, 其中圖檔會變成 slido 手機投票的縮圖。下下週上課時, 請用電腦 Teams 分享桌面, 再用 

## step02
老師想要示範如何完成期末作品,一步步慢慢來。
不要改別人的程式, 因為會改不出來。
(貼別人的程式 倒是還不錯) 5-10行

2022電腦圖學 Computer Graphics 授課教師: 葉正聖 銘傳大學資訊傳播工程系 每週主題: 程式環境、點線面顏色、移動/旋轉/縮放與矩陣(Matrix)、階層性關節轉動(T-R-T)、做出機器人、打光、貼圖、glu/glut函式、鍵盤、滑鼠、計時器(timer)、讀入3D模型、粒子系統、聲音、特效、投影矩陣、攝影機與運鏡、機器人2.0、期末作品


程式環境: Week01(freeglut,GLUT專案), Week10(OpenCV的設定), Week16(改 CBP 的 working_dir)

點線面顏色: 10行程式碼  display() main()前3行設定, 最後一行glutMainLoop()

打光: 8行 + 10多行

讀入3D模型:  模型在工作目錄, glm.h glm.cpp 加進去 #include "glm.h" 再 GLMmodel * body; 再...

貼圖: OpenCV 及 myTexture範例, 還有圖 而且畫 glmDraw(pmodel, GLM_TEXTURE | GLM_SMOOTH);

攝影機與運鏡: 透視投影法 gluPerspective,配上 glutReshapeFunc() 再上 gluLookAt()

兩張貼圖: Gundam, 木紋, 宣告2個整數 GLuint tex1, tex2; 在 main() 裡 
tex1 = myTexture("data/Diffuse.jpg"); 
tex2 = myTexture("data/wood.png");
在 display() 裡
glBindTexture(GL_TEXTURE_2D, tex1) 及 glBindTexture(GL_TEXTURE_2D, tex2) 來切換

把全部的模型讀入: 改寫 myReadGundam()改成 myReadOne() 及 myReadAll();

TRT: 必須要有中心點 才能把每個部位放好, 才能正確轉,才能掛在對的地方
可以使用 mouse motion 來知道值在哪裡
要經常註解程式,才能找到 T-R-T 的值