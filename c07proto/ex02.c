#include <stdlib.h>
int	ft_ultimate_range(int **range, int min, int max);

#include <stdio.h>
int main()
{
	int *range[1];
	printf("%d",ft_ultimate_range(range, 2, 5));
}

// no idea if this works anot
int	ft_ultimate_range(int **range, int min, int max)
{
	int n;
	int neededspace;
	int *a;
	int i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	neededspace = max - min;
	a = (int *) malloc (neededspace * sizeof(int));
	if (a == 0)
		return (-1);
	n = min;
	i = 0;
	i = -1;
	while (min < max && ++i < neededspace)
	{
		a[i] = min;
		min++;
	}
	*range = a;
	return (neededspace);
}
