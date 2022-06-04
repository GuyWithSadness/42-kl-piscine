#include <stdio.h>
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);

int main()
{
	int n = 0;
	int number = 32;
	int byte_array_dec[32u] = {216, 102, 186, 175, 104, 34, 36, 167, 68, 180, 205, 69, 52, 126, 43, 49, 50, 109, 52, 111, 168, 205, 231, 204, 110, 41, 181, 146, 181, 27, 161, 238};
	ft_sort_int_tab(byte_array_dec, number);
	while(n < number)
	{
		printf("%d ", byte_array_dec[n]);
		n++;
	}
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


void	ft_sort_int_tab(int *tab, int size)
{
	int count;
	int compare;

	count = 0;
	compare = 1;
	while (count != size)
	{
		while (compare != size)
		{
			if (tab[count] > tab[compare])
				ft_swap(&tab[count], &tab[compare]);
			compare++;
		}
		count++;
		compare = count+1;
	}
}
