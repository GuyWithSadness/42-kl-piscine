#include <stdlib.h>
int	*ft_range(int min, int max);

#include <stdio.h>
int main()
{
	int* a;
	a = ft_range(5, 10);
	if (a != 0)
		for (int i = 0; i <= 10; i++)
			printf("%d ", a[i]);
	else
		printf("nope");
	printf("\n");
	a = ft_range(-5, 3);
	if (a != 0)
		for (int i = 0; i <= 10; i++)
			printf("%d ", a[i]);
	else
		printf("nope");
	printf("\n");
	a = ft_range(-25, -10);
	if (a != 0)
		for (int i = 0; i <= 25; i++)
			printf("%d ", a[i]);
	else
		printf("nope");
	printf("\n");
	a = ft_range(15, 10);
	if (a != 0)
		for (int i = 0; i <= 10; i++)
			printf("%d ", a[i]);
	else
		printf("nope");
	printf("\n");
	a = ft_range(0, 0);
	if (a != 0)
		for (int i = 0; i <= 10; i++)
			printf("%d ", a[i]);
	else
		printf("nope");
	printf("\n");
}

int	*ft_range(int min, int max)
{
	int n;
	int neededspace;
	int *a;
	int i;

	neededspace = max - min;
	a = (int *) malloc (neededspace * sizeof(int));
	if (min >= max)
		return (NULL);
	n = min;
	i = 0;
	while (n < max && i < neededspace)
	{
		a[i] = n;
		i++;
		n++;
	}
	return (a);
}
