#include <stdio.h>
#include <string.h>

int ft_recursive_factorial(int nb);

int main()
{
	printf("%d", ft_recursive_factorial(15));
}

int ft_recursive_factorial(int nb)
{
	int a;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	else
		a = nb * ft_recursive_factorial(nb - 1);
	return (a);
}
