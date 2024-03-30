#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/*Auxiliar prototypes*/
void print_string(char *s, int *p_count);
void print_char(char c, int *p_count);
void print_integer(int n, int *p_count);
int num_digits(long int num);

/*Prototypes Functions*/
int _printf(const char *format, ...);


#endif
