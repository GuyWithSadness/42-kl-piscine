#include <stdio.h>
void	ft_rev_int_tab(int *tab, int size);

int main()
{
	
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	count;
	int	temp;

	count = -1;
	while (count++ <= (size/2))
	{
		temp = tab[0 + count];
		tab[0 + count] = tab[size - 1 - count];
		tab[size - 1 - count] = temp;
	}
}
