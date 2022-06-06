#include <stdlib.h>
int	*ft_range(int min, int max);

#include <stdio.h>
void testenv(int min, int max)
{
	int* a;

	a = ft_range(min, max);
	if (a != 0)
		for (int i = 0; i <= 10; i++)
			printf("%d ", a[i]);
	else
		printf("nope");
	printf("\n");
}

int main(int ac, char *av[])
{
	testenv(atoi(av[1]), atoi(av[2]));
}

int	*ft_range(int min, int max)
{
	int neededspace;
	int *a;
	int i;

	neededspace = max - min;
	a = (int *) malloc (neededspace * sizeof(int));
	if (min >= max || a == 0)
		return (NULL);
	i = -1;
	while (min < max && ++i < neededspace)
	{
		a[i] = min;
		min++;
	}
	return (a);
}
