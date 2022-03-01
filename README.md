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

