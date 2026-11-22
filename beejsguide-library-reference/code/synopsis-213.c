#include <threads.h>

void call_once(once_flag *flag, void (*func)(void));
