int	ft_is_sort(int *tab, int length, int(*f)(int, int));

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;
	int x;

	i = 0;
	while (i < length)
	{
		x = i + 1;
		while (x < length)
		{
			if (f(tab[i],tab[x]) > 0)
				return 0;
			x++;
		}
		i++;
	}
	return 1;
}

int	ft_cmp(int a, int b)
{
	return (a - b);
}

#include <stdio.h>
int main()
{
	int tab[] = {1,2,3,4,5,6,2,4,1,2};
	int sorted = ft_is_sort(tab, 10, ft_cmp);
	printf("%d", sorted);
}
