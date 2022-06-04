#include <stdlib.h>
int	ft_ultimate_range(int **range, int min, int max);

#include <stdio.h>
int main()
{
	int *range[1];
	printf("%d",ft_ultimate_range(range, 2, 5));
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int n;
	int neededspace;
	int *a;
	int i;

	neededspace = max - min;
	a = (int *) malloc (neededspace * sizeof(int));
	if (a == 0)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	n = min;
	i = 0;
	while (n < max && i < neededspace)
	{
		a[i] = n;
		i++;
		n++;
	}
	*range = a;
	return (neededspace);
}
