#include "ft_printf.h"

static void wprefix(int *counter)
{
	write(1, "0x", 2);
	*counter += 2;
}
// TODO:
// you may wanna have a put_pointer function that calls
// puthex and write prifix
// remove the conversion of hex to uppercase and just 
// create another var for uppercase
// don't forget to handle null on pointer

void ft_putptr(unsigned long n, int *counter)
{
	wprefix(counter);
	ft_puthex(n, 'x', counter);
}

void ft_strcpy(char *src, char *dst)
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

	/*
	while (num_len--)
	{
		if (gate == 1)
		{
			if (num[num_len] >= 97 && num[num_len] <= 122)
				ft_putchar(num[num_len] - 32, counter);
		}
		if ((num[num_len] >= 48 && num[num_len] <= 57) || gate != 1)
			ft_putchar(num[num_len], counter);
	}
	*/
	free(num);
}
/*
int main()
{
	int a = 1;
	int *pa = &a;
	int x = 2748;

	//char *str = ft_puthex((unsigned long)pa);
	char *str = ft_puthex((unsigned long)x);
	if (!str)
	{
		printf("didn't succeed allocating str\n");
		return (1);
	}
	write(1, "\n", 1);
	free(str);
	return (0);
}
*/

/* ft_putchar() is required to write a char
 *
	// so we keep dividing by 16 and keep the reminder 
	// so we just use the modulo then
	// 2748 % 16 and then store them in revese 
	// so the first reminder is the last digit in the 
	// whole number, 12 or C in hex should be 
	// in the most right char
	// we can keep storing them like that but write me in reverse
	// asat
	// so let's just store them correctly first
	//
	//
	//
	________________________________________
		// the result of n % 16 will always be between 0 and 15 
		// and thats what we want... for example we get 3
		// we access hex[3] which is 3 because indexing 
		// starts from 0 and also our hex start from 0
		// thats why it works
 *
 *
*/
