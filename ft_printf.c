#include "ft_printf.h"

static void handle_sac(char c, va_list args, int *counter)
{
	if (c == 's')
	{
		char *s = va_arg(args, char*);
		ft_putstr(s, counter);
	}
	if (c == 'c')
	{
		char nc = va_arg(args, int);
		ft_putchar(nc, counter);
	}
}

static void handle_nums(char c, va_list args, int *counter)
{
	if (c == 'd' || c == 'i')
	{
		int nd = va_arg(args, int);
		ft_putnbr(nd, counter);
	}
	if (c == 'u')
	{
		unsigned long uid = va_arg(args, unsigned long);
		ft_putnbr_un(uid, counter);
	}
}

static void handle_pahex(char c, va_list args, int *counter)
{
	if (c == 'p')
	{
		void *ptr = va_arg(args, void*);
		ft_putptr((unsigned long)ptr, counter);
	}
	if (c == 'x')
	{
		unsigned int n = va_arg(args, unsigned int);
		ft_puthex((unsigned long)n, 'x', counter);
	}
	if (c == 'X')
	{
		unsigned int n = va_arg(args, unsigned int);
		ft_puthex((unsigned long)n, 'X', counter);
	}
}

static void format(char c, va_list args, int *counter)
{
	handle_sac(c, args, counter);
	handle_nums(c, args, counter);
	handle_pahex(c, args, counter);
	if (c == '%')
		ft_putchar('%', counter);
}

int ft_printf(const char *s, ...)
{
	va_list args;
	int		(counter), (i);

	va_start(args, s);
	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
			{
				ft_putchar('%', &counter);
				return (1);
			}
			format(s[i + 1], args, &counter);
			i++;
		}
		else
			ft_putchar(s[i], &counter);
		i++;
	}
	va_end(args);
	return (counter);
}

int main(void)
{
	char r = 'r';
	ft_printf("d number:\t%d\n", -84);
	ft_printf("i number:\t%i\n", 55);
	ft_printf("u number:\t%u\n", -44);
	ft_printf("character:\t%c\n", r);
	ft_printf("pointer:\t%p\n", &r);
	ft_printf("string:\t\t%s\n", "icho ahmed");
	ft_printf("percent:\t%%\n");
	//ft_printf("again percent:\t%\n");
	ft_printf("hex:\t\t%p\n", 1551324);
	ft_printf("HEX:\t\t%X\n", 1551324);

	return (0);
}
