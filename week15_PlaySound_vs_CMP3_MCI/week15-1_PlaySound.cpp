///Week15-1 PlaySound.cpp
#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()���e\n");
    PlaySound("07042111.wav", NULL, SND_SYNC);///�ɮפ��s�b,�|���ܤp�n�����~�n
    printf("PlaySound()����\n");
}
