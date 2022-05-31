///Week15-1 PlaySound.cpp
#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");
    PlaySound("07042111.wav", NULL, SND_SYNC);///檔案不存在,會有很小聲的錯誤聲
    printf("PlaySound()之後\n");
}
