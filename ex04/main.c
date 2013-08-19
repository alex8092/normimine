#include <stdlib.h>
#include <stdio.h>

int ft_fibonacci(int index); 

int main(void)
{
	int i;
	for (i = 0;i < 15;++i)
		printf("%d\n", ft_fibonacci(i));
	return 0;
}
