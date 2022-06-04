#include <stdio.h>
int ft_iterative_power(int nb, int power);

int main()
{
	printf("%d\n", power(10, 1));
	printf("%d\n", power(10, 2));
	printf("%d\n", power(10, 3));
	printf("%d\n", power(10, 4));
	printf("%d\n", power(10, 5));
	printf("%d\n", power(10, 6));
	printf("%d\n", power(10, 7));
	printf("%d\n", power(10, 8));
	printf("%d\n", power(10, 9));
}

int		power(int ten, int topowerof)
{
	if (topowerof == 1)
		return (1);
	while (topowerof > 2)
	{
		ten = ten * 10;
		topowerof--;
	}
	return (ten);
}

int ft_iterative_power(int nb, int power)
{
	int a;
	int count;
	int result;

	count = 1;
	result = 1;
	a = nb;
	if (power == 0)
		return (1);
	while (count <= power)
	{
		result = nb * result;
		count++;
	}
	return (result);
}
