void ft_foreach(int *tab, int length, void(*f)(int));

void ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

#include <stdio.h>
void ft_putnbr(int a)
{
	printf("%d\n", a);
}

int main()
{
	int tab[] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
	ft_foreach(tab, 20, &ft_putnbr);
}
