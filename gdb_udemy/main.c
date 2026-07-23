#include "lvgl/lvgl.h"

int main(void) {
  lv_init();
  lv_display_t *disp =
      lv_sdl_window_create(320, 240); // SDL2 handles everything

  /* your UI */
  lv_obj_t *label = lv_label_create(lv_screen_active());
  lv_label_set_text(label, "Hello LVGL!");

  while (1) {
    lv_timer_handler();
    usleep(5000); /* 5ms */
  }
  return 0;
}
