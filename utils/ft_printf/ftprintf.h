#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	print_char(char c);
int	print_string(char *s);
int	print_pointer(uintptr_t p);
int	print_number(int n);
int	print_unsigned_number(unsigned int n);
int	print_hex(unsigned int n, int c);

#endif