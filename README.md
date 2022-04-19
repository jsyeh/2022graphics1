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