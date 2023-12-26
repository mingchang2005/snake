#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
void MAX(int pon)
{
    int mer;
    FILE* pfile;
    if ((pfile = fopen("MAX.txt", "r+")) == NULL) {  // 判斷檔案是否開啟失敗
        printf("MAX.txt 檔案無法開啟"); system("pause"); return(0);
    }
    if (pon == -1)
    {
        fseek(pfile, 0, SEEK_SET);
        fprintf(pfile, "%s", "     ");
        fseek(pfile, 0, SEEK_SET);
        fprintf(pfile, "%d", 0);
        printf("...紀錄已重製...\n");
    }
    else if (fscanf(pfile, "%d", &mer) != EOF)
    {
        if (pon > mer)
        {
            mer = pon;
        }
        else
            mer = mer;
        fseek(pfile, 0, SEEK_SET);
        fprintf(pfile, "%s", "     ");
        fseek(pfile, 0, SEEK_SET);
        fprintf(pfile, "%d", mer);
        printf("最高分數:%d\n", mer);
    }
    fclose(pfile); // 關閉檔案
}