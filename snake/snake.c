#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include"parameter.h"
typedef struct {
    int x;
    int y;
} Point;
typedef struct {
    int length;
    Point body[MAXpoint];
    int direction;  // 1: �W, 2: �U, 3: ��, 4: �k
} Snake;
Point food;
Snake snake;
// �]�w����x�W����Ц�m
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// ø�s�C���a��
void drawMap() {
    for (int i = 0; i <= HEIGHT + 1; i++) {
        for (int j = 0; j <= WIDTH + 1; j++) {
            if (i == 0 || i == HEIGHT + 1 || j == 0 || j == WIDTH + 1) {
                printf("�i");  // ø�s���
            }
            else {
                printf(" ");  // �b�����ø�s�ťհϰ�
            }
        }
        printf("\n");
    }
}
// �b�C���}�l�ɪ�l�ƳD����m
void initializeSnake() {
    snake.length = 1;
    snake.body[0].x = WIDTH / 2;
    snake.body[0].y = HEIGHT / 2;
    snake.direction = 4;  // ��l��V�V�k
}
// ��l�ƭ�������m
void initializeFood() {
    srand(time(NULL));
    food.x = rand() % WIDTH + 1;
    food.y = rand() % HEIGHT + 1;
}
// ��l�ƹC���Ѽ�
void initializeGame() {
    if (g % 3 == 0) {
        printf("�п�J�̤j���ס]�ФŤp��%d�Τj��%d�W�L�d��N�]�w���w�]��%d��%d�^�G", DEFAULT_MAX_LENGTH, MAXpoint, DEFAULT_MAX_LENGTH, MAXpoint);
        scanf("%d", &MAX_LENGTH);
        // �T�O�̤j���פ��p��w�]��
        if (MAX_LENGTH < DEFAULT_MAX_LENGTH)
            MAX_LENGTH = DEFAULT_MAX_LENGTH;
        else if (MAX_LENGTH > MAXpoint)
            MAX_LENGTH = MAXpoint;
    }
    // �M�ſù��A��l�ƳD�M�����A��ø�s�a��
    system("cls");
    initializeSnake();
    initializeFood();
    drawMap();  // �C���}�l�ɭ�ø�a��
}
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
    printf("��%d�^�X�o��: %d(���Ux�i����z�i�Ȱ�)\0", rod , snake.length);
}
// �ھڷ�e��V���ʳD
void moveSnake() {
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }
    switch (snake.direction) {
    case 1:  // �W
        snake.body[0].y--;
        break;
    case 2:  // �U
        snake.body[0].y++;
        break;
    case 3:  // ��
        snake.body[0].x--;
        break;
    case 4:  // �k
        snake.body[0].x++;
        break;
    }
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
// �ˬd�O�_�P����Φۤv�I�������
int checkCollision() {
    if (snake.body[0].x <= 0 || snake.body[0].x > WIDTH || snake.body[0].y <= 0 || snake.body[0].y > HEIGHT) {
        // �P����I���A�N�D�_��
        resetSnake();
        return 1;
    }
    // �M�z�I����������ڳ���
    gotoxy(snake.body[snake.length - 1].x, snake.body[snake.length - 1].y);
    printf(" ");
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            // �P�ۤv�I���A�N�D�_��
            resetSnake();
            return 1;
        }
    }
    return 0;
}
// �ˬd�D�O�_�Y�쭹�������
void checkFood() {
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
            printf("You Win!\n�o��:%d\n�ϥ�%d�^�X\n", MAX_LENGTH * life, ro);
        else
            printf("\nGame Over!\n�`�o��:%d\n", tt+life);
        tt = 0;
        // �^�X������A�߰ݨϥΪ̬O�_�}�l�s�C���ε���
        printf("���U���N��}�l�s�C���Ϋ��Ux����\n");
    } while (_getch() != 'x');
    return 0;
}