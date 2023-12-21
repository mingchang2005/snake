#include"initiaHeader.h"
#include <stdio.h>
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

