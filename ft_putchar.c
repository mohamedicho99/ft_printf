#include "ft_printf.h"


void ft_putchar(char c)
{
	write(0, &c, 1);
}
