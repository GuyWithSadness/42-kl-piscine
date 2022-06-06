#include <stdio.h>

int ft_sqrt(int nb);
int ft_brutesqrt(int nb);
int BabyleonMeth(int nb);

#include <time.h>
int main()
{
	int start;
	int end;
	// printf("%d\n", ft_sqrt(3));
	for (int i = 0; i <= (46340*46340); i++)
	{
		start = clock();
		if (ft_brutesqrt(i) != 0)
		{
			printf("%d ", ft_brutesqrt(i));
			end = clock();
			printf("Time taken = %d seconds\n", (end - start));
		}
	}
}

// int ft_sqrt(int nb)
// {
// 	int i;

// 	i = 0;
// 	while (i <= 46340)
// 	{
// 		if (i * i == nb)
// 			return i;
// 		i++;
// 	}
// 	return 0;
// }

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

// int BabyleonMeth(int nb)
// {
// 	long int x;

// 	x = 1;
// 	while (x * x != nb)
// 	{
// 		x = ((x * x) + nb) / (2 * x);
// 		if (x == 0)
// 			break;
// 	}
// 	return ((int) x);
// }

int ft_brutesqrt(int nb)
{
	int i;
	int j;

	i = 46340;
	while (i != 0)
	{
		if (i * i > nb)
		{
			j = i + 1;
			i = i/2;
		}
		else
			break;
	}
	while (i != j)
	{
		if (i * i == nb)
			return i;
		i++;
	}
	return 0;
}
