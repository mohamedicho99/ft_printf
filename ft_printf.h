#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define HEX "0123456789abcdef"

int ft_printf(const char *s, ...);
void ft_putnbr(long n);
void ft_putnbr_un(unsigned long n);
void ft_putchar(char c);
size_t ft_strlen(const char *s);
void ft_puthex(unsigned long n, int gate);
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t nmemb, size_t size);

#endif
