#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
void MAX(int pon)
{
    int mer;
    FILE* pfile;
    if ((pfile = fopen("MAX.txt", "r+")) == NULL) {  // �P�_�ɮ׬O�_�}�ҥ���
        printf("MAX.txt �ɮ׵L�k�}��"); system("pause"); return(0);
    }
    if (pon == -1)
    {
        fseek(pfile, 0, SEEK_SET);
        fprintf(pfile, "%s", "     ");
        fseek(pfile, 0, SEEK_SET);
        fprintf(pfile, "%d", 0);
        printf("...�����w���s...\n");
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
        printf("�̰�����:%d\n", mer);
    }
    fclose(pfile); // �����ɮ�
}