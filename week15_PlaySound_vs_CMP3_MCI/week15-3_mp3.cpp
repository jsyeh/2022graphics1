#include <stdio.h>
#include "CMP3_MCI.h" ///�O�o�n�U���B��P�ؿ���
CMP3_MCI mp3;///�ŧi�ܼ�

int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();

    printf("�H�K���A��J�Ʀr,�{���N�d���o: ");
    int N;///���F�d��{�����n�����N�����F
    scanf("%d", &N);
}
