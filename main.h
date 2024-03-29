#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/*Auxiliar prototypes*/
void print_string(char *s, int *p_count);
void print_char(char c, int *p_count);

/*Prototypes Functions*/
int _printf(const char *format, ...);


#endif
