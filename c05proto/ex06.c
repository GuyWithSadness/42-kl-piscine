#include <stdio.h>

int ft_is_prime(int nb);

int main()
{
	for (int i = 0; i <= 10000; i++)
		if (ft_is_prime(i) == 1)
			printf("%d is a prime number = %d\n", i, ft_is_prime(i));
}

int ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb == 0 || nb == 1)
		return 0;
	while (i < nb)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}
