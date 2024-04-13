#ifndef __TERMINAL__
#define __TERMINAL__

#include <termios.h>

void set_terminal_settings();
void restore_default_terminal_settings();
extern const struct termios original;

#endif
