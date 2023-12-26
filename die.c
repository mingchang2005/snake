#include"pointHeader.h"
// 檢查是否與牆壁或自己碰撞的函數
int checkCollision() {
    if (snake.body[0].x <= 0 || snake.body[0].x > WIDTH || snake.body[0].y <= 0 || snake.body[0].y > HEIGHT) {
        // 與牆壁碰撞，將蛇復位
        resetSnake();
        return 1;
    }
    // 清理碰撞牆壁的尾巴部分
    gotoxy(snake.body[snake.length - 1].x, snake.body[snake.length - 1].y);
    printf(" ");
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            // 與自己碰撞，將蛇復位
            resetSnake();
            return 1;
        }
    }
    return 0;
}