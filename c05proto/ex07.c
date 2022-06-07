#include <stdio.h>
int ft_find_next_prime(int nb);
int ft_is_prime(int nb);

int main()
{
	printf("Next Prime  = %d\n" ,ft_find_next_prime(100000000));
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
	if (nb <= 1)
		return 0;
	while (i < nb/i)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}
