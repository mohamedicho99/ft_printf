#include "ft_printf.h"

static void ft_putstr(const char *s, int *counter)
{
	int i = 0;
	if (!s)
	{
		ft_putstr("(null)", counter);
		return ;
	}

	while (s[i])
	{
		ft_putchar(s[i], counter);
		i++;
	}
}

// split this logic into little functions
// handle numbers 
// handle s and chars
// handle p x X
// have a variable count that keeps incrementing
// with each character written to stdout
// change all write calls to write to stdout 1
static void format(char c, va_list args, int *counter)
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
	if (c == 'p')
	{
		void *ptr = va_arg(args, void*);
		ft_puthex((unsigned long)ptr, 2, counter);
	}
	if (c == 'x')
	{
		unsigned int n = va_arg(args, unsigned int);
		ft_puthex((unsigned long)n, 0, counter);
	}
	if (c == 'X')
	{
		unsigned int n = va_arg(args, unsigned int);
		ft_puthex((unsigned long)n, 1, counter);
	}
	if (c == '%')
		ft_putchar('%', counter);
}

int ft_printf(const char *s, ...)
{
	va_list args;
	int		counter;
	int		i;
	va_start(args, s);

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			// test this 
			if (s[i + 1] == '\0')
				ft_putchar('%', &counter);

			format(s[i + 1], args, &counter);
			i++;
		}
		else
			ft_putchar(s[i], &counter);
		i++;
	}
	//ft_putchar('\n', &counter);
	va_end(args);
	return (counter);
}

int main(void)
{
	// what if i do close(1)
	// don't let him test your printf with %
	// what is dprintf? why do i have to give the output of printf?
	// when does it return -1?
	// what does printf return and why am i still not keeping track of this?
	// what does printf return if formats are given in string
	// but with no more args

	int r = ft_printf("%s\n", 0);
	ft_printf("%d\n", r);


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
//
// for p and s
// for null you wanna print nil
