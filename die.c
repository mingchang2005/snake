#include"pointHeader.h"
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