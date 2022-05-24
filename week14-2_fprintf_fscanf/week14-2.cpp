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
