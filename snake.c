
#include <raylib.h>

#define COLS 20
#define ROWS 20
#define CELL 30
#define WIDTH (COLS * CELL)
#define HEIGHT (ROWS * CELL)
#define MAX_SNAKE 400
#define FPS 60
#define MOVE_INTERVAL 0.12f

typedef struct { int x, y; } Vec2;

typedef struct {
  Vec2 body[MAX_SNAKE];
  int len;
  Vec2 dir;
  Vec2 nextDir;
} Snake;

Vec2 spawnFood(Snake *s) {
  Vec2 food;
  int valid;
  do {
    valid = 1;
    food.x = GetRandomValue(0, COLS - 1);
    food.y = GetRandomValue(0, ROWS - 1);
    for (int i = 0; i < s->len; i++)
      if (s->body[i].x == food.x && s->body[i].y == food.y) { valid = 0; break; }
  } while (!valid);
  return food;
}

void initSnake(Snake *s) {
  s->len = 3;
  s->body[0] = (Vec2){10, 10};
  s->body[1] = (Vec2){9, 10};
  s->body[2] = (Vec2){8, 10};
  s->dir = (Vec2){1, 0};
  s->nextDir = (Vec2){1, 0};
}

int main() {
  InitWindow(WIDTH, HEIGHT, "snake");
  SetTargetFPS(FPS);

  Snake snake;
  initSnake(&snake);
  Vec2 food = spawnFood(&snake);
  int score = 0;
  int alive = 1;
  float timer = 0;

  while (!WindowShouldClose()) {
    // input
    if (IsKeyPressed(KEY_UP)    && snake.dir.y != 1)  snake.nextDir = (Vec2){0, -1};
    if (IsKeyPressed(KEY_DOWN)  && snake.dir.y != -1) snake.nextDir = (Vec2){0,  1};
    if (IsKeyPressed(KEY_LEFT)  && snake.dir.x != 1)  snake.nextDir = (Vec2){-1, 0};
    if (IsKeyPressed(KEY_RIGHT) && snake.dir.x != -1) snake.nextDir = (Vec2){1,  0};
    if (IsKeyPressed(KEY_R)) {
      initSnake(&snake);
      food = spawnFood(&snake);
      score = 0;
      alive = 1;
      timer = 0;
    }

    // update
    if (alive) {
      timer += GetFrameTime();
      if (timer >= MOVE_INTERVAL) {
        timer = 0;
        snake.dir = snake.nextDir;

        Vec2 head = { snake.body[0].x + snake.dir.x, snake.body[0].y + snake.dir.y };

        // wall collision
        if (head.x < 0 || head.x >= COLS || head.y < 0 || head.y >= ROWS) {
          alive = 0;
        } else {
          // self collision
          for (int i = 0; i < snake.len; i++) {
            if (snake.body[i].x == head.x && snake.body[i].y == head.y) { alive = 0; break; }
          }
        }

        if (alive) {
          // shift body
          for (int i = snake.len; i > 0; i--)
            snake.body[i] = snake.body[i - 1];
          snake.body[0] = head;

          // eat food
          if (head.x == food.x && head.y == food.y) {
            snake.len++;
            score++;
            food = spawnFood(&snake);
          }
        }
      }
    }

    // draw
    BeginDrawing();
    ClearBackground((Color){15, 15, 30, 255});

    // grid
    for (int x = 0; x < COLS; x++)
      for (int y = 0; y < ROWS; y++)
        DrawRectangleLines(x * CELL, y * CELL, CELL, CELL, (Color){255, 255, 255, 10});

    // food
    DrawCircle(food.x * CELL + CELL / 2, food.y * CELL + CELL / 2, CELL / 2 - 4, (Color){224, 92, 58, 255});

    // snake
    for (int i = 0; i < snake.len; i++) {
      int shade = 200 - (i * 100 / snake.len);
      Color c = {0, shade, 80, 255};
      DrawRectangle(snake.body[i].x * CELL + 1, snake.body[i].y * CELL + 1, CELL - 2, CELL - 2, c);
    }

    // score
    DrawText(TextFormat("score: %d", score), 10, 10, 20, WHITE);

    if (!alive)
      DrawText("game over — press R", WIDTH / 2 - 110, HEIGHT / 2 - 10, 20, RED);

    EndDrawing();
  }

  CloseWindow();
}
