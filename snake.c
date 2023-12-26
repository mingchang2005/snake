#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include"parameter.h"
int g, tt = 0, ro, win, rod = 1,pon;
int MAX_LENGTH = DEFAULT_MAX_LENGTH;  // 最大長度
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
    printf("第%d回合得分: %d(按下x可結束z可暫停)\0", rod, snake.length);
}
// 初始化遊戲參數
void initializeGame() {
    printf("請輸入最大長度（請勿小於%d或大於%d超過範圍將設定為預設值%d或%d）：", DEFAULT_MAX_LENGTH, MAXpoint, DEFAULT_MAX_LENGTH, MAXpoint);
    scanf("%d", &MAX_LENGTH);
    // 確保最大長度不小於預設值
    if (MAX_LENGTH < DEFAULT_MAX_LENGTH)
        MAX_LENGTH = DEFAULT_MAX_LENGTH;
    else if (MAX_LENGTH > MAXpoint)
        MAX_LENGTH = MAXpoint;
    // 清空螢幕，初始化蛇和食物，並繪製地圖
    system("cls");
    initializeSnake();
    initializeFood();
    drawMap();  // 遊戲開始時重繪地圖
}
// 將蛇復位到初始位置
void resetSnake() {
    initializeSnake();
    drawSnakeAndFood();
    system("cls");
    printf("正在建置地圖...");
    Sleep(500);
    system("cls");
    drawMap();
    Sleep(100);
}
// 檢查蛇是否吃到食物的函數
int checkFood() {
    if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
        snake.length++;
        tt++;
        initializeFood();
    }
}
int main() {
    // 遊戲開始前清空螢幕
    system("cls");
    do {
        for (g = 0; g < life; g++) {
            // 每三回合詢問使用者設定最大長度
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
                        printf("\n█");
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
                // 只更新必要的部分而不是清空整個螢幕
                drawSnakeAndFood();
                checkFood();
                Sleep(SPEED);
                // 清除蛇的尾巴部分，避免留下痕跡
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
        // 顯示結束後的畫面
        Sleep(SPEED);
        rod--;
        drawSnakeAndFood();
        rod = 1;
        printf("\n█按下任意鍵進入結算畫面");
        _getch();
        system("cls");
        if (win)
        {
            printf("You Win!\n得分:%d\n使用%d回合\n", MAX_LENGTH * life, ro);
            pon = MAX_LENGTH * life;
        }
        else
        {
            printf("\nGame Over!\n總得分:%d\n", tt + life);
            pon = tt + life;
        }
        MAX(pon);
        tt = 0;
        printf("是否重製最高分數?(y/n)\n");//y為是其餘按鍵皆為否
        if (_getch() == 'y')
            MAX(-1);
        // 回合結束後，詢問使用者是否開始新遊戲或結束
        printf("按下任意鍵開始新遊戲或按下x結束\n");
    } while (_getch() != 'x');
    return 0;
}