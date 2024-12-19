#include <stdio.h>
#include <unistd.h>

int main()
{
	int r = printf("%p", NULL);
	printf("%d\n", r);
	return (0);
}
