#include "ft_printf.h"

static void wprefix(int *counter)
{
	write(1, "0x", 2);
	*counter += 2;
}

void ft_putptr(unsigned long n, int *counter)
{
	if (!n)
	{
		ft_putstr("(nil)", counter);
		return ;
	}
	wprefix(counter);
	ft_puthex(n, 'x', counter);
}

static void ft_strcpy(char *src, char *dst)
{
	if (!src || !dst)
		return ;
	int i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void ft_puthex(unsigned long n, char con, int *counter)
{
	char *num;
	size_t num_len;
	int i;
	char hex[17];
	
	ft_strcpy("0123456789abcdef", hex);
	if (con == 'X')
		ft_strcpy("0123456789ABCDEF", hex);
	num = ft_calloc(sizeof(char), 21);
	if (!num)
		return ;
	i = 0;
	while (n && i < 16)
	{
		num[i] = hex[n % 16];
		n /= 16;
		i++;
	}
	num_len = ft_strlen(num);
	while (num_len--)
		ft_putchar(num[num_len], counter);
	free(num);
}
