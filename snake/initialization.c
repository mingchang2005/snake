#include"initiaHeader.h"
#include <stdio.h>
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

