#define WIDTH 30
#define HEIGHT 20
#define DEFAULT_MAX_LENGTH 5
#define SPEED 100
#define life 3
#define MAXpoint 50
void gotoxy(int, int);
void drawMap();
void initializeSnake();
void moveSnake();
void initializeFood();
void initializeGame();
int checkCollision();
int checkFood();
void MAX(int);
typedef struct {
    int x;
    int y;
} Point;
typedef struct {
    int length;
    Point body[MAXpoint];
    int direction;  // 1: �W, 2: �U, 3: ��, 4: �k
} Snake;
Point food;
Snake snake;