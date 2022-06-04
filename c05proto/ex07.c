#include <stdio.h>
int ft_find_next_prime(int nb);
int ft_is_prime(int nb);

int main()
{
	printf("Next Prime = %d\n", ft_find_next_prime(68));
	printf("Next Prime = %d\n", ft_find_next_prime(0));
	printf("Next Prime = %d\n", ft_find_next_prime(5));
	printf("Next Prime = %d\n", ft_find_next_prime(127348));
	printf("Next Prime = %d\n", ft_find_next_prime(696969));
}

int ft_find_next_prime(int nb)
{
	while(1)
	{
		if (ft_is_prime(nb) == 1)
			return nb;
		nb++;
	}
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
