#include "moveHeader.h"
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