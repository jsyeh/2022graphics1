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
