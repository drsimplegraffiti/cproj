
#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include <stdio.h>

#define MAX_BLOCKS 30
#define MAX_BIRDS  5
#define MAX_PIGS   3

typedef struct {
  Vector2 pos, vel;
  float radius;
  int active;
} Circle;

typedef struct {
  Rectangle rect;
  int active;
  float health;
} Block;

// slingshot anchor
static const Vector2 ANCHOR = {150, 450};
static const float   MAX_PULL = 80.0f;

typedef enum { AIMING, FLYING, NEXT, GAMEOVER, WIN } State;

int main(void) {
  InitWindow(900, 600, "angry birds (raylib)");
  SetTargetFPS(60);

  // birds queue
  Circle birds[MAX_BIRDS] = {0};
  for (int i = 0; i < MAX_BIRDS; i++) {
    birds[i].radius = 18;
    birds[i].active = 0;
  }
  int birdIdx = 0;  // current bird

  // pigs
  Circle pigs[MAX_PIGS];
  pigs[0] = (Circle){{620, 460}, {0,0}, 20, 1};
  pigs[1] = (Circle){{720, 430}, {0,0}, 20, 1};
  pigs[2] = (Circle){{670, 390}, {0,0}, 20, 1};

  // blocks
  Block blocks[MAX_BLOCKS] = {0};
  int nb = 0;
  // tower 1
  for (int i = 0; i < 4; i++) blocks[nb++] = (Block){{590 + i%2*60, 480 - i/2*60, 55, 55}, 1, 3};
  // tower 2
  for (int i = 0; i < 2; i++) blocks[nb++] = (Block){{640, 420 - i*60, 55, 55}, 1, 3};
  // roof
  blocks[nb++] = (Block){{595, 360, 115, 25}, 1, 3};

  State state = AIMING;
  Vector2 pullPos = ANCHOR;
  Circle *bird = &birds[0];
  bird->pos = ANCHOR;
  bird->active = 1;

  float gravity = 600.0f;
  int score = 0;

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    Vector2 mouse = GetMousePosition();

    if (state == AIMING) {
      if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 delta = Vector2Subtract(mouse, ANCHOR);
        float dist = Vector2Length(delta);
        if (dist > MAX_PULL) delta = Vector2Scale(Vector2Normalize(delta), MAX_PULL);
        pullPos = Vector2Add(ANCHOR, delta);
        bird->pos = pullPos;
      }
      if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        // launch — velocity opposite of pull direction
        Vector2 delta = Vector2Subtract(ANCHOR, pullPos);
        bird->vel = Vector2Scale(delta, 7.0f);
        state = FLYING;
        pullPos = ANCHOR;
      }
    }

    if (state == FLYING) {
      bird->vel.y += gravity * dt;
      bird->pos = Vector2Add(bird->pos, Vector2Scale(bird->vel, dt));

      // ground
      if (bird->pos.y + bird->radius >= 510) {
        bird->pos.y = 510 - bird->radius;
        bird->vel.y *= -0.3f;
        bird->vel.x *= 0.7f;
        if (fabsf(bird->vel.y) < 20) { bird->vel = (Vector2){0,0}; state = NEXT; }
      }

      // off screen left/right/top — just go to next
      if (bird->pos.x > 950 || bird->pos.x < -50) state = NEXT;

      // bird vs pigs
      for (int i = 0; i < MAX_PIGS; i++) {
        if (!pigs[i].active) continue;
        if (CheckCollisionCircles(bird->pos, bird->radius, pigs[i].pos, pigs[i].radius)) {
          pigs[i].active = 0;
          score += 500;
          state = NEXT;
        }
      }

      // bird vs blocks
      for (int i = 0; i < nb; i++) {
        if (!blocks[i].active) continue;
        if (CheckCollisionCircleRec(bird->pos, bird->radius, blocks[i].rect)) {
          float speed = Vector2Length(bird->vel);
          blocks[i].health -= speed / 200.0f;
          if (blocks[i].health <= 0) { blocks[i].active = 0; score += 100; }
          // bounce bird
          bird->vel.x *= -0.4f;
          bird->vel.y *= -0.4f;
          state = NEXT;
        }
      }

      // blocks fall due to "physics" (simple: check if floating)
      for (int i = 0; i < nb; i++) {
        if (!blocks[i].active) continue;
        blocks[i].rect.y += 80 * dt;
        if (blocks[i].rect.y + blocks[i].rect.height >= 510)
          blocks[i].rect.y = 510 - blocks[i].rect.height;
        // crush pigs
        for (int p = 0; p < MAX_PIGS; p++) {
          if (!pigs[p].active) continue;
          if (CheckCollisionCircleRec(pigs[p].pos, pigs[p].radius, blocks[i].rect)) {
            pigs[p].active = 0; score += 500;
          }
        }
      }
    }

    if (state == NEXT) {
      birdIdx++;
      // check win/lose
      int pigsLeft = 0;
      for (int i = 0; i < MAX_PIGS; i++) if (pigs[i].active) pigsLeft++;
      if (pigsLeft == 0) { state = WIN; }
      else if (birdIdx >= MAX_BIRDS) { state = GAMEOVER; }
      else {
        bird = &birds[birdIdx];
        bird->pos = ANCHOR;
        bird->active = 1;
        state = AIMING;
      }
    }

    if ((state == GAMEOVER || state == WIN) && IsKeyPressed(KEY_R)) {
      // reset
      for (int i = 0; i < MAX_BIRDS; i++) { birds[i].active = 0; birds[i].vel = (Vector2){0,0}; }
      pigs[0] = (Circle){{620, 460}, {0,0}, 20, 1};
      pigs[1] = (Circle){{720, 430}, {0,0}, 20, 1};
      pigs[2] = (Circle){{670, 390}, {0,0}, 20, 1};
      nb = 0;
      for (int i = 0; i < 4; i++) blocks[nb++] = (Block){{590 + i%2*60, 480 - i/2*60, 55, 55}, 1, 3};
      for (int i = 0; i < 2; i++) blocks[nb++] = (Block){{640, 420 - i*60, 55, 55}, 1, 3};
      blocks[nb++] = (Block){{595, 360, 115, 25}, 1, 3};
      birdIdx = 0; bird = &birds[0];
      bird->pos = ANCHOR; bird->active = 1;
      score = 0; state = AIMING;
    }

    // draw
    BeginDrawing();
    ClearBackground((Color){135, 206, 235, 255}); // sky

    // ground
    DrawRectangle(0, 510, 900, 90, (Color){34, 139, 34, 255});
    DrawRectangle(0, 530, 900, 70, (Color){20, 100, 20, 255});

    // slingshot
    DrawLineEx((Vector2){ANCHOR.x - 15, ANCHOR.y - 60}, (Vector2){ANCHOR.x, ANCHOR.y + 10}, 8, (Color){101, 67, 33, 255});
    DrawLineEx((Vector2){ANCHOR.x + 15, ANCHOR.y - 60}, (Vector2){ANCHOR.x, ANCHOR.y + 10}, 8, (Color){101, 67, 33, 255});

    // slingshot band
    if (state == AIMING && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
      DrawLineEx((Vector2){ANCHOR.x - 15, ANCHOR.y - 60}, pullPos, 3, (Color){80, 40, 10, 255});
      DrawLineEx((Vector2){ANCHOR.x + 15, ANCHOR.y - 60}, pullPos, 3, (Color){80, 40, 10, 255});
    } else {
      DrawLineEx((Vector2){ANCHOR.x - 15, ANCHOR.y - 60}, (Vector2){ANCHOR.x + 15, ANCHOR.y - 60}, 3, (Color){80,40,10,255});
    }

    // queued birds (shown below slingshot)
    for (int i = birdIdx + 1; i < MAX_BIRDS; i++) {
      DrawCircle(80 + (i - birdIdx - 1) * 45, 530, 14, RED);
      DrawCircle(74 + (i - birdIdx - 1) * 45, 525, 5, (Color){255,200,200,255});
    }

    // current bird
    if (bird->active) {
      DrawCircle((int)bird->pos.x, (int)bird->pos.y, bird->radius, RED);
      DrawCircle((int)bird->pos.x - 5, (int)bird->pos.y - 5, 6, (Color){255, 180, 180, 255});
      // angry eyebrow
      DrawLineEx((Vector2){bird->pos.x - 10, bird->pos.y - 12},
                 (Vector2){bird->pos.x - 2,  bird->pos.y - 8}, 3, BLACK);
      DrawLineEx((Vector2){bird->pos.x + 2,  bird->pos.y - 8},
                 (Vector2){bird->pos.x + 10, bird->pos.y - 12}, 3, BLACK);
    }

    // blocks
    for (int i = 0; i < nb; i++) {
      if (!blocks[i].active) continue;
      float hp = blocks[i].health / 3.0f;
      Color bc = {(unsigned char)(80 + (1-hp)*120), (unsigned char)(60 + hp*40), 20, 255};
      DrawRectangleRec(blocks[i].rect, bc);
      DrawRectangleLinesEx(blocks[i].rect, 2, (Color){60, 40, 10, 255});
    }

    // pigs
    for (int i = 0; i < MAX_PIGS; i++) {
      if (!pigs[i].active) continue;
      DrawCircle((int)pigs[i].pos.x, (int)pigs[i].pos.y, pigs[i].radius, (Color){100, 200, 80, 255});
      DrawCircleLines((int)pigs[i].pos.x, (int)pigs[i].pos.y, pigs[i].radius, (Color){60, 140, 40, 255});
      // pig eyes
      DrawCircle((int)pigs[i].pos.x - 7, (int)pigs[i].pos.y - 5, 4, WHITE);
      DrawCircle((int)pigs[i].pos.x + 7, (int)pigs[i].pos.y - 5, 4, WHITE);
      DrawCircle((int)pigs[i].pos.x - 7, (int)pigs[i].pos.y - 5, 2, BLACK);
      DrawCircle((int)pigs[i].pos.x + 7, (int)pigs[i].pos.y - 5, 2, BLACK);
      // snout
      DrawCircle((int)pigs[i].pos.x, (int)pigs[i].pos.y + 6, 6, (Color){80, 170, 60, 255});
    }

    // score & birds left
    DrawText(TextFormat("score: %d", score), 10, 10, 22, WHITE);
    DrawText(TextFormat("birds: %d", MAX_BIRDS - birdIdx), 10, 36, 18, WHITE);

    if (state == AIMING)
      DrawText("drag & release to launch", 300, 570, 16, (Color){255,255,255,180});

    if (state == GAMEOVER) {
      DrawRectangle(200, 200, 500, 160, (Color){0,0,0,180});
      DrawText("GAME OVER", 290, 230, 40, RED);
      DrawText(TextFormat("score: %d", score), 360, 285, 24, WHITE);
      DrawText("press R to restart", 310, 325, 20, LIGHTGRAY);
    }

    if (state == WIN) {
      DrawRectangle(200, 200, 500, 160, (Color){0,0,0,180});
      DrawText("YOU WIN!", 310, 230, 40, YELLOW);
      DrawText(TextFormat("score: %d", score), 360, 285, 24, WHITE);
      DrawText("press R to restart", 310, 325, 20, LIGHTGRAY);
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
