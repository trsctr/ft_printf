#include "libft.h"
#include <stdio.h>
//
int main (void)
{
	
	int fd = 1;
	int a;
	int b;

	a = ft_putnbr_fd(-12324, fd);
	ft_putchar_fd('\n', fd);
	b = printf("-12324");
	printf("\n");
	printf("%d\n", a);
	printf("%d\n", b);
}