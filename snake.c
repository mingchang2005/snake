#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include"parameter.h"
int g, tt = 0, ro, win, rod = 1,pon;
int MAX_LENGTH = DEFAULT_MAX_LENGTH;  // �̤j����
// �b����x�Wø�s�D�M�����H�Τ���
void drawSnakeAndFood() {
    gotoxy(food.x, food.y);
    printf("*");  // ø�s����
    for (int i = 0; i < snake.length; i++) {
        gotoxy(snake.body[i].x, snake.body[i].y);
        if (i == 0)
            printf("G");  // ø�s�D���Y
        else
            printf("@");  // ø�s�D������
    }
    gotoxy(WIDTH + 5, 1);
    printf("��%d�^�X�o��: %d(���Ux�i����z�i�Ȱ�)\0", rod, snake.length);
}
// ��l�ƹC���Ѽ�
void initializeGame() {
    printf("�п�J�̤j���ס]�ФŤp��%d�Τj��%d�W�L�d��N�]�w���w�]��%d��%d�^�G", DEFAULT_MAX_LENGTH, MAXpoint, DEFAULT_MAX_LENGTH, MAXpoint);
    scanf("%d", &MAX_LENGTH);
    // �T�O�̤j���פ��p��w�]��
    if (MAX_LENGTH < DEFAULT_MAX_LENGTH)
        MAX_LENGTH = DEFAULT_MAX_LENGTH;
    else if (MAX_LENGTH > MAXpoint)
        MAX_LENGTH = MAXpoint;
    // �M�ſù��A��l�ƳD�M�����A��ø�s�a��
    system("cls");
    initializeSnake();
    initializeFood();
    drawMap();  // �C���}�l�ɭ�ø�a��
}
// �N�D�_����l��m
void resetSnake() {
    initializeSnake();
    drawSnakeAndFood();
    system("cls");
    printf("���b�ظm�a��...");
    Sleep(500);
    system("cls");
    drawMap();
    Sleep(100);
}
// �ˬd�D�O�_�Y�쭹�������
int checkFood() {
    if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
        snake.length++;
        tt++;
        initializeFood();
    }
}
int main() {
    // �C���}�l�e�M�ſù�
    system("cls");
    do {
        for (g = 0; g < life; g++) {
            // �C�T�^�X�߰ݨϥΪ̳]�w�̤j����
            if (g % 3 == 0) {
                initializeGame();
            }
            Sleep(1000);
            while (1) {
                if (_kbhit()) {
                    char ch = _getch();
                    switch (ch) {
                    case 'w':
                        if (snake.direction != 2 || snake.length == 1)
                            snake.direction = 1;
                        break;
                    case 's':
                        if (snake.direction != 1 || snake.length == 1)
                            snake.direction = 2;
                        break;
                    case 'a':
                        if (snake.direction != 4 || snake.length == 1)
                            snake.direction = 3;
                        break;
                    case 'd':
                        if (snake.direction != 3 || snake.length == 1)
                            snake.direction = 4;
                        break;
                    case 'z':
                        drawSnakeAndFood();
                        printf("\n�i");
                        system("pause");
                        system("cls");
                        drawMap();
                        break;
                    case 'x':
                        system("cls");
                        exit(0);
                        break;
                    }
                }
                moveSnake();
                // �u��s���n�������Ӥ��O�M�ž�ӿù�
                drawSnakeAndFood();
                checkFood();
                Sleep(SPEED);
                // �M���D�����ڳ����A�קK�d�U����
                gotoxy(snake.body[snake.length - 1].x, snake.body[snake.length - 1].y);
                printf(" ");
                if (snake.length == MAX_LENGTH) {
                    ro = g + 1;
                    g = life;
                    win = 1;
                    break;
                }
                else if (checkCollision()) {
                    //tt += snake.length;
                    win = 0;
                    break;
                }
            }
            rod++;
        }
        // ��ܵ����᪺�e��
        Sleep(SPEED);
        rod--;
        drawSnakeAndFood();
        rod = 1;
        printf("\n�i���U���N��i�J����e��");
        _getch();
        system("cls");
        if (win)
        {
            printf("You Win!\n�o��:%d\n�ϥ�%d�^�X\n", MAX_LENGTH * life, ro);
            pon = MAX_LENGTH * life;
        }
        else
        {
            printf("\nGame Over!\n�`�o��:%d\n", tt + life);
            pon = tt + life;
        }
        MAX(pon);
        tt = 0;
        printf("�O�_���s�̰�����?(y/n)\n");//y���O��l����Ҭ��_
        if (_getch() == 'y')
            MAX(-1);
        // �^�X������A�߰ݨϥΪ̬O�_�}�l�s�C���ε���
        printf("���U���N��}�l�s�C���Ϋ��Ux����\n");
    } while (_getch() != 'x');
    return 0;
}