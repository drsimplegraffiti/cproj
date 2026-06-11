#include <raylib.h>
#include <stdio.h>

// raylibs color
//              255  0     0      0       0 represents the absence of the color
// alpha means transparenecy of the color
// Color color = {red, green, blue, alpha};
// Color red= {255,0,0,255};

int main() {

  Color white = {255, 255, 255, 255};
  int ballX = 400;
  int ballY = 400;

  InitWindow(800, 800, "xybug");
  SetTargetFPS(60);       // Game speed, in 60 Frames Per Second
  ClearBackground(WHITE); // Set background color (framebuffer clear color)

  ToggleFullscreen(); // Toggle window state: fullscreen/windowed,
                      // resizes monitor to match window resolution

  // get the screen height and width
  int h = GetScreenHeight(); // Get current screen height
  int w = GetRenderWidth();
  printf("h and w: %d, %d\n", h, w);

  // game loop: event handling, updating positions, drawing objects
  while (WindowShouldClose() == false) {
    // 1 event handling

    // mouse
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Vector2 mouse = GetMousePosition();
      ballX = (int)mouse.x;
      ballY = (int)mouse.y;
    }

    // keyboard
    if (IsKeyDown(KEY_RIGHT))
      ballX += 3;
    else if (IsKeyDown(KEY_LEFT))
      ballX -= 3;
    else if (IsKeyDown(KEY_UP))
      ballY -= 3;
    else if (IsKeyDown(KEY_DOWN))
      ballY += 3;

    if (IsKeyDown(KEY_RIGHT)) {

      ballX += 3;
    } else if (IsKeyDown(KEY_LEFT)) {
      ballX -= 3;
    } else if (IsKeyDown(KEY_UP)) {
      ballY -= 3;
    } else if (IsKeyDown(KEY_DOWN)) {
      ballY += 3;
    }

    // clamp so ball stays within window bounds
    int radius = 20;
    if (ballX < radius)
      ballX = radius;
    if (ballX > 800 - radius)
      ballX = 800 - radius;
    if (ballY < radius)
      ballY = radius;
    if (ballY > 800 - radius)
      ballY = 800 - radius;

    // NOTE: computer graphics, the origin (x,y) starts from the upper top
    // left corner
    // x cordinate increases as we move to the right
    // y cordinate increases as we move down

    // 2 updating positions
    // ballX += 3;
    // ballY += 3;

    // 3 drawing objects
    BeginDrawing();
    ClearBackground(white);
    // draw a cricle at the center
    // DrawCircle(int centerX, int centerY, float radius, Color color)
    DrawCircle(ballX, ballY, 20.0, ORANGE);
    EndDrawing();
  }

  CloseWindow();
}
