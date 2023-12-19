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
    int direction;  // 1: 上, 2: 下, 3: 左, 4: 右
} Snake;
Point food;
Snake snake;
// 設定控制台上的游標位置
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// 繪製遊戲地圖
void drawMap() {
    for (int i = 0; i <= HEIGHT + 1; i++) {
        for (int j = 0; j <= WIDTH + 1; j++) {
            if (i == 0 || i == HEIGHT + 1 || j == 0 || j == WIDTH + 1) {
                printf("█");  // 繪製牆壁
            }
            else {
                printf(" ");  // 在牆壁內繪製空白區域
            }
        }
        printf("\n");
    }
}
// 在遊戲開始時初始化蛇的位置
void initializeSnake() {
    snake.length = 1;
    snake.body[0].x = WIDTH / 2;
    snake.body[0].y = HEIGHT / 2;
    snake.direction = 4;  // 初始方向向右
}
// 初始化食物的位置
void initializeFood() {
    srand(time(NULL));
    food.x = rand() % WIDTH + 1;
    food.y = rand() % HEIGHT + 1;
}
// 在控制台上繪製蛇和食物以及分數
void drawSnakeAndFood() {
    gotoxy(food.x, food.y);
    printf("*");  // 繪製食物
    for (int i = 0; i < snake.length; i++) {
        gotoxy(snake.body[i].x, snake.body[i].y);
        if (i == 0)
            printf("G");  // 繪製蛇的頭
        else
            printf("@");  // 繪製蛇的身體
    }
    gotoxy(WIDTH + 5, 1);
    printf("第%d回合得分: %d(按下x可結束)\0", g + 1, snake.length);
}
// 根據當前方向移動蛇
void moveSnake() {
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }
    switch (snake.direction) {
    case 1:  // 上
        snake.body[0].y--;
        break;
    case 2:  // 下
        snake.body[0].y++;
        break;
    case 3:  // 左
        snake.body[0].x--;
        break;
    case 4:  // 右
        snake.body[0].x++;
        break;
    }
}
// 檢查是否與牆壁或自己碰撞的函數
int checkCollision() {
    if (snake.body[0].x <= 0 || snake.body[0].x > WIDTH || snake.body[0].y <= 0 || snake.body[0].y > HEIGHT) {
        return 1;  // 與牆壁碰撞
    }
    // 清理碰撞牆壁的尾巴部分
    gotoxy(snake.body[snake.length - 1].x, snake.body[snake.length - 1].y);
    printf(" ");
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            return 1;  // 與自己碰撞
        }
    }
    return 0;
}
// 檢查蛇是否吃到食物的函數
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
                        printf("\n█");
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
        printf("\n█按下任意鍵進入結算畫面");
        _getch();
        system("cls");
        if (win)
            printf("You Win!\n得分:%d\n使用%d回合\n", MAX_LENGTH * life, ro);
        else
            printf("\nGame Over!\n總得分:%d\n", tt);
        tt = 0;
        // After each game, ask the user to start a new game or exit
        printf("按下任意鍵開始新遊戲或按下x結束\n");
    } while (_getch() != 'x');
    return 0;
}
