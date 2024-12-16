#include "ft_printf.h"

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
		ft_putnbr(nd);
	}
	if (c == 'u')
	{
		unsigned long uid = va_arg(args, unsigned long);
		ft_putnbr_un(uid);
	}
	if (c == 'p')
	{
		// %p the void * pointer argument has to be printed in hex format
		// use 0x prefix
		void *ptr = va_arg(args, void*);
		ft_puthex((unsigned long)ptr, 2);
	}
	if (c == 'x')
	{
		// %x prints a number in hex (base 16) lowercase format.
		unsigned int n = va_arg(args, unsigned int);
		ft_puthex((unsigned long)n, 0);
	}
	if (c == 'X')
	{
		// %X prints a number in hex (base 16) uppercase format.
		// and use to upper in X
		// either have a param in puthex which you set to 1 or true
		// if it's called from this function
		// or just uppercase that hex value here and store it in a 
		// variable
		unsigned int n = va_arg(args, unsigned int);
		ft_puthex((unsigned long)n, 1);
		//printf("%s\n", HEX);
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
	// ft_printf("hi %%there %c is the %dth best in %i there", 'k', 9, 12);
	// ft_printf("and his name is: %s %s", "John", "Cena");
	// ft_printf("this is an unsigned int: %d", 44);
	// check what does printf print for p
	//int n = 1;
	//int *np = &n;
	//ft_printf("this is p: %p", &np);
	ft_printf("this is p: %X", 7777777);
	return (0);
}

// cspdiuxX%
// compare with original printf
// %%  (done)
// %c  (done)
// %s  (done)
// %d  (done)
// %i  (done)
// %u  (done)
// for p and s
// for null you wanna print nil
