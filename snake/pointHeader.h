#define MAXpoint 50
#define WIDTH 30
#define HEIGHT 20
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
