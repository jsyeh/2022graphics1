///Week15-2 SND_SYNC SND_ASYNC
///���ΦA�]�w Setting-Compiler.., Linker �[ winmm �]���[�L�F
#include <windows.h>
#include <stdio.h>
int main()
{            ///������,�N�|����ְ����U�@��,���ʩʨ�
    PlaySound("07042111.wav", NULL, SND_ASYNC);///ASYNC������
    while( 1 ){
        printf("�п�J�Ʀr: ");
        int N;
        scanf("%d", &N);
        if(N==1) PlaySound("do.wav", NULL, SND_ASYNC);
        if(N==2) PlaySound("re.wav", NULL, SND_ASYNC);
        if(N==3) PlaySound("mi.wav", NULL, SND_ASYNC);
    }
}///�̫�@��,�N����/�����F
