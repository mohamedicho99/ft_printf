#include "ft_printf.h"

void ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}
