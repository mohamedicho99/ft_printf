#include "ft_printf.h"

int main()
{
	int i = 0;
	int *pi = &i;
	ft_printf("icho is the legend!\n");
	ft_printf("give char: %c\n", 'a');
	ft_printf("give numd: %d\n", 22);
	ft_printf("give numi: %i\n", 22);
	ft_printf("give numu: %u\n", 22);
	ft_printf("give x: %x\n", 29292);
	ft_printf("give X: %X\n", 29292);
	ft_printf("give p: %p\n", pi);
	ft_printf("givehpercent: %%\n");
	//printf("give percent: %%\n");
	ft_printf("give s: %s\n", "arrriba\n");
	//printf("icho is the legend!\\n\");
	//

	return (0);
}

/*
 * cspdiuxX%
 *
 * */
