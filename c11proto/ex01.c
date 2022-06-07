#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int));

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *result;

	i = 0;
	result = (int *) malloc (length * (sizeof(int)));
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}

#include <stdio.h>
int ft_multi(int a)
{
	return (a*a);
}

int main()
{
	int tab[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int *result;
	result = ft_map(tab, 20, &ft_multi);
	for (int i = 0; i < 20; i++)
		printf("%d ", result[i]);
}
