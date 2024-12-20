#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


int ft_printf(const char *s, ...);
void ft_putnbr(long n, int *counter);
void ft_putnbr_un(unsigned long n, int *counter);
void ft_putchar(char c, int *counter);
size_t ft_strlen(const char *s);
void ft_puthex(unsigned long n, char con, int *counter);
void ft_putptr(unsigned long n, int *counter);
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
// format is not in here
// for every function that's used and not in here
// make it static

#endif
