#include <stdio.h>
#include <string.h>

int ft_recursive_factorial(int nb);

int main()
{
	for (int i = 0; i <= 45; i++)
		printf("%d\n", ft_recursive_factorial(i));
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
