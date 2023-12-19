#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define WIDTH 30
#define HEIGHT 20
#define MAX_LENGTH 5
#define SPEED 100
#define life 3
int g, tt = 0, ro, win;
typedef struct {
    int x;
    int y;
} Point;
typedef struct {
    int length;
    Point body[MAX_LENGTH];
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
    printf("��%d�^�X�o��: %d(���Ux�i����)\0", g + 1, snake.length);
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
// �ˬd�O�_�P����Φۤv�I�������
int checkCollision() {
    if (snake.body[0].x <= 0 || snake.body[0].x > WIDTH || snake.body[0].y <= 0 || snake.body[0].y > HEIGHT) {
        return 1;  // �P����I��
    }
    // �M�z�I����������ڳ���
    gotoxy(snake.body[snake.length - 1].x, snake.body[snake.length - 1].y);
    printf(" ");
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            return 1;  // �P�ۤv�I��
        }
    }
    return 0;
}
// �ˬd�D�O�_�Y�쭹�������
void checkFood() {
    if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
        snake.length++;
        initializeFood();
    }
}
int main() {
    // Clear the screen once before the game starts
    system("cls");
    do {
        for (g = 0; g < 3; g++) {
            system("cls");
            initializeSnake();
            initializeFood();
            drawMap();  // Redraw the map once at the beginning of each game
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
                        break;
                    case 'x':
                        system("cls");
                        exit(0);
                        break;
                    }
                }
                moveSnake();
                // Instead of clearing the entire screen, update only the necessary parts
                drawSnakeAndFood();
                checkFood();
                Sleep(SPEED);
                // Clear the area where the snake was to avoid artifacts
                gotoxy(snake.body[snake.length - 1].x, snake.body[snake.length - 1].y);
                printf(" ");
                if (snake.length == MAX_LENGTH) {
                    ro = g + 1;
                    g = life;
                    win = 1;
                    break;
                }
                else if (checkCollision()) {
                    tt += snake.length;
                    win = 0;
                    break;
                }
            }
        }
        Sleep(SPEED);
        drawSnakeAndFood();
        printf("\n�i���U���N��i�J����e��");
        _getch();
        system("cls");
        if (win)
            printf("You Win!\n�o��:%d\n�ϥ�%d�^�X\n", MAX_LENGTH * life, ro);
        else
            printf("\nGame Over!\n�`�o��:%d\n", tt);
        tt = 0;
        // After each game, ask the user to start a new game or exit
        printf("���U���N��}�l�s�C���Ϋ��Ux����\n");
    } while (_getch() != 'x');
    return 0;
}
