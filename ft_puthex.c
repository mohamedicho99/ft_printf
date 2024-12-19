#include "ft_printf.h"

static void wprefix(int *counter)
{
	write(1, "0x", 2);
	*counter += 2;
}

void ft_puthex(unsigned long n, int gate, int *counter)
{
	char *num;
	size_t num_len;
	int i;

	// why use 17 and not the number of digits unsigned long can have
	num = ft_calloc(sizeof(char), 21);
	if (!num)
		return ;
	i = 0;
	while (n && i < 16)
	{
		num[i] = HEX[n % 16];
		n /= 16;
		i++;
	}
	num_len = ft_strlen(num);
	if (gate == 2)
		wprefix(counter);
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
