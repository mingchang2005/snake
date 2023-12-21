#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 30
#define HEIGHT 20
#define DEFAULT_MAX_LENGTH 5
#define SPEED 100
#define life 3
#define MAXpoint 50
typedef struct {
    int x;
    int y;
} Point;
typedef struct {
    int length;
    Point body[MAXpoint];
    int direction;  // 1: ¤W, 2: ¤U, 3: ¥ª, 4: ¥k
} Snake;
Point food;
Snake snake;