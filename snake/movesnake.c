#include "moveHeader.h"
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