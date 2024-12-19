#include "ft_printf.h"


void ft_putnbr(long n, int *counter)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-', counter);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
	else
		ft_putchar(n + '0', counter);
}
