#include <stdio.h>
int ft_recursive_power(int nb, int power);

int main()
{
	printf("%d", ft_recursive_power(8, 10));
}

int ft_recursive_power(int nb, int power)
{
	int a;

	if (power == 0)
		return (1);
	if (power == 1)
		return nb;
	else
	{
		a = nb * ft_recursive_power(nb, power - 1);
	}
	return (a);
}
