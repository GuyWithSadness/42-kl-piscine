#include <stdio.h>
int ft_find_next_prime(int nb);
int ft_is_prime(int nb);

int main()
{

	for (int i = 0; i <= 1000; i++)
		printf("Next Prime of %d = %d\n",i ,ft_find_next_prime(i));
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
