#include <stdio.h>
int ft_recursive_power(int nb, int power);

int main()
{
	for (int i = -3; i <= 15; i++)
		printf("%d\n", ft_recursive_power(2, i));
}

int ft_recursive_power(int nb, int power)
{
	int a;

	if (power < 0)
		return (0);
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
