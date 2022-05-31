///Week15-2 SND_SYNC SND_ASYNC
///不用再設定 Setting-Compiler.., Linker 加 winmm 因為加過了
#include <windows.h>
#include <stdio.h>
int main()
{            ///不等待,就會比較快執行到下一行,互動性佳
    PlaySound("07042111.wav", NULL, SND_ASYNC);///ASYNC不等待
    while( 1 ){
        printf("請輸入數字: ");
        int N;
        scanf("%d", &N);
        if(N==1) PlaySound("do.wav", NULL, SND_ASYNC);
        if(N==2) PlaySound("re.wav", NULL, SND_ASYNC);
        if(N==3) PlaySound("mi.wav", NULL, SND_ASYNC);
    }
}///最後一行,就結束/死掉了
