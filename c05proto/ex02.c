#include <stdio.h>
int ft_iterative_power(int nb, int power);

int main()
{
	for (int i = -1; i <= 15; i++)
		printf("%d\n", ft_iterative_power(2, i));
}

int ft_iterative_power(int nb, int power)
{
	int a;
	int count;
	int result;

	count = 1;
	result = 1;
	a = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (count <= power)
	{
		result = nb * result;
		count++;
	}
	return (result);
}
