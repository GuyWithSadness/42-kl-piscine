#include <unistd.h>

void	ft_print_combn(int n);

int main()
{
	ft_print_combn(3);
}

void	ft_print_combn(int n)
{
	char a[11];
	int count;
	int last;
	int i;

	i = n;

	last = n - 1;
	count = 0;
	a[0] = 0;

	while(a[0] < '7')
	{
		a[n] = ',';
		a[n+1] = ' ';

		while(count < n)
		{
			if (count[n-1] >= ':' - count + 1 - n)
			{
				count[n-1] = 0;
				count[n]++;
			}
			if (count[n] < '0' || n == )
			{

			}
		}

		count = (n-1);


		if(a[0] == ':' - n)
		{
			write(1, a, i);
		}
		else
			write(1, a, i+2);
	}
}
