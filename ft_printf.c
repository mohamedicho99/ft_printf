#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

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

int ft_printf(const char *s, ...)
{
	va_list args;
	va_start(args, s);

	int i = 0;
	int was_found = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		if (s[i] == '%')
			was_found = 1;
		i++;
	}
	ft_putchar('\n');
	if (was_found)
		write(1, "percent was found\n", ft_strlen("percent was found\n"));

	va_end(args);
	return (i);
}

int main(void)
{
	ft_printf("icho is the best!%");
	
	return (0);
}

// cspdiuxX%
// compare with original printf
// %c prints a single character
// %s prints a string (as defined by the common c convention)
// %p the void * pointer argument has to be printed in hex format
// %d prints a decimal (base 10) number
// %i prints an integer in base 10.
// %u prints an unsinged decimal (base 10) number.
// %x prints a number in hex (base 16) lowercase format.
// %X prints a number in hex (base 16) uppercase format.
// %% prints a percent sign
