----------------------------------------------------------------------------TIC TAC TOE ---------------------------------------------------------------------------
#include <graphics.h>
#include <conio.h>

#define WIDTH 20
#define HEIGHT 20
#define GRID_SIZE 20
#define SNAKE_LENGTH 5

typedef struct {
    int x, y;
} Point;

void drawGrid() {
    for (int i = 0; i <= WIDTH; i++) {
        line(i * GRID_SIZE, 0, i * GRID_SIZE, HEIGHT * GRID_SIZE);
    }
    for (int i = 0; i <= HEIGHT; i++) {
        line(0, i * GRID_SIZE, WIDTH * GRID_SIZE, i * GRID_SIZE);
    }
}

void drawSnake(Point snake[], int length) {
    for (int i = 0; i < length; i++) {
        setfillstyle(SOLID_FILL, i % 8);
        bar(snake[i].x * GRID_SIZE, snake[i].y * GRID_SIZE, (snake[i].x + 1) * GRID_SIZE, (snake[i].y + 1) * GRID_SIZE);
    }
}

void drawFood(Point food) {
    setfillstyle(SOLID_FILL, 9);
    bar(food.x * GRID_SIZE, food.y * GRID_SIZE, (food.x + 1) * GRID_SIZE, (food.y + 1) * GRID_SIZE);
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Point snake[SNAKE_LENGTH];
    Point food;
    int length = SNAKE_LENGTH;
    int direction = 0; // 0: up, 1: down, 2: left, 3: right

    for (int i = 0; i < SNAKE_LENGTH; i++) {
        snake[i].x = WIDTH / 2 - i;
        snake[i].y = HEIGHT / 2;
    }
    food.x = 5;
    food.y = 5;

    drawGrid();
    drawSnake(snake, length);
    drawFood(food);

    while (1) {
        if (kbhit()) {
            char c = getch();
            switch (c) {
                case 'w':
                    direction = 0;
                    break;
                case 's':
                    direction = 1;
                    break;
                case 'a':
                    direction = 2;
                    break;
                case 'd':
                    direction = 3;
                    break;
            }
        }

        for (int i = length - 1; i > 0; i--) {
            snake[i].x = snake[i - 1].x;
            snake[i].y = snake[i - 1].y;
        }
        switch (direction) {
            case 0:
                snake[0].y--;
                break;
            case 1:
                snake[0].y++;
                break;
            case 2:
                snake[0].x--;
                break;
            case 3:
                snake[0].x++;
                break;
        }

        if (snake[0].x < 0 || snake[0].x >= WIDTH || snake[0].y < 0 || snake[0].y >= HEIGHT) {
            break;
        }

        for (int i = 1; i < length; i++) {
            if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                break;
            }
        }

        if (snake[0].x == food.x && snake[0].y == food.y) {
            length++;
            food.x = 10;
            food.y = 10;
        }

        cleardevice();
        drawGrid();
        drawSnake(snake, length);
        drawFood(food);

        delay(100);
    }

    closegraph();
}