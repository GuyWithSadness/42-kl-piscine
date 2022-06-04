#include <stdio.h>
#include <string.h>

int ft_iterative_factorial(int nb);

int main()
{
	printf("%d", ft_iterative_factorial(15));
}

int ft_iterative_factorial(int nb)
{
	int a;
	int result;

	a = 0;
	result = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (++a <= nb)
	{
		result = a * result;
	}
	return (result);
}
