#include "ft_printf.h"

void	ft_putstr(const char *s, int *counter)
{
	int	i;

	i = 0;
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
