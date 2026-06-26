#ifndef MENUS_AUX_H
#define MENUS_AUX_H
#include "menus.h"

void clear_input_buffer(void);
int get_int(const char *prompt, int *value);
int get_line(const char *prompt, char *buf, int size);
void separator(void);
void header(const char *title);
void pause_enter(void);
void clear_screen(void);

#endif