
#include "ft_printf.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;
	size_t			i;

	ptr = (unsigned char *)s;
	c = 0;
	i = 0;
	while (i != n)
	{
		ptr[i] = c;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*space;
	size_t	total_len;

	total_len = nmemb * size;
	if (size != 0 && total_len / size != nmemb)
		return (NULL);
	space = malloc(total_len);
	if (!space)
		return (NULL);
	ft_bzero(space, nmemb * size);
	return (space);
}
