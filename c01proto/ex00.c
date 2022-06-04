#include <stdio.h>
void    ft_ft(int *nbr);

int main()
{
	int a = 696969;
	int *ptr;

	ptr = &a;
	ft_ft(ptr);
	printf("%d", a);
}

void    ft_ft(int *nbr)
{
    *nbr = 42;
}
