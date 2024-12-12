#include "ft_printf.h"

void ft_putchar(char c)
{
	write(0, &c, 1);
}

int ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_putstr(const char *s)
{
	int i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void format(char c, va_list args)
{
	if (c == 's')
	{
		char *s = va_arg(args, char*);
		ft_putstr(s);
	}
	if (c == 'c')
	{
		char nc = va_arg(args, int);
		ft_putchar(nc);
	}
	if (c == 'd' || c == 'i')
	{
		int nd = va_arg(args, int);
		//ft_putchar(nd);
		//use putnbr here
	}
	if (c == 'u')
	{
		unsigned int uid = va_arg(args, unsigned int);
		ft_putchar(uid);
	}
	if (c == '%')
		ft_putchar('%');
}

int ft_printf(const char *s, ...)
{
	va_list args;
	va_start(args, s);

	int i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			format(s[i + 1], args);
			i++;
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
	va_end(args);
	return (i);
}

int main(void)
{
	// ft_printf("%kcho%s %is t%%he %cbest!%dhere%uok%xanother%X%p");
	ft_printf("hi %%there %c is the %dth best", 'k', 9);
	//ft_printf("and his name is: %s %s", "John", "Cena");
	ft_printf("this is an unsigned int: %u", '44');
	return (0);
}

// cspdiuxX%
// compare with original printf
// %%  (done)
// %c  (done)
// %s  (done)
// %d  (done)
// %i  (done)
//
// %u prints an unsinged decimal (base 10) number.
// %p the void * pointer argument has to be printed in hex format
// %x prints a number in hex (base 16) lowercase format.
// %X prints a number in hex (base 16) uppercase format.
