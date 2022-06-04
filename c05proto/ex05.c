#include <stdio.h>

int ft_sqrt(int nb);
int ft_brutesqrt(int nb);
int BabyleonMeth(int nb);

int main()
{
	// printf("%d\n", ft_sqrt(3));
	printf("%d\n", ft_brutesqrt(46340*46340));
	// printf("%d\n", BabyleonMeth(4));
}

int ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i <= 46340)
	{
		if (i * i == nb)
			return i;
		i++;
	}
	return 0;
}

// ctrl+/ to uncomment this part
// int ft_brutesqrt(int nb)
// {
// 	int i;
// 	int j;
// 	i = 46340;
// 	while (1)
// 	{
// 		printf("Testing %d, limit is %d\n", i, j);
// 		if (i * i > nb)
// 		{
// 			printf("Bulk removing %d to %d, limit is %d\n", i,  i/4 ,  j);
// 			j = i + 1;
// 			i = i/2;
// 		}
// 		else
// 		{
// 			break;
// 		}
// 	}
// 	while (i != 0)
// 	{
// 		if (i * i == nb)
// 			return i;
// 		else if (i == j)
// 			return 0;
// 		printf("removing %d, limit is %d\n", i, j);
// 		i++;
// 	}
// 	return 0;
// }

int BabyleonMeth(int nb)
{
	long int x;

	x = 1;
	while (x * x != nb)
	{
		x = ((x * x) + nb) / (2 * x);
		if (x == 0)
			break;
	}
	return ((int) x);
}

int ft_brutesqrt(int nb)
{
	int i;
	int j;

	i = 46340;
	while (1)
	{
		if (i * i > nb)
		{
			j = i + 1;
			i = i/2;
		}
		else
			break;
	}
	while (i != 0)
	{
		if (i * i == nb)
			return i;
		else if (i == j)
			return 0;
		i++;
	}
	return 0;
}
