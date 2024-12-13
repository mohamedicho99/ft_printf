#include "ft_printf.h"

void ft_puthex(unsigned long n)
{
	// don't forget to use your own ft_calloc here
	char *num = calloc(sizeof(char), 17);
	if (!num)
		return ;

	int i = 0;
	while (n && i < 16)
	{
		num[i] = HEX[n % 16];
		n /= 16;
		i++;
	}

	size_t num_len = ft_strlen(num);

	while (num_len--)
		ft_putchar(num[num_len]);
	
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
