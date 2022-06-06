#include <stdio.h>
int	ft_rec_fibonacci(int index);
int ft_ite_fibonacci(int index);

int	main()
{
	printf("%d\n", ft_rec_fibonacci(3));
	printf("%d", ft_ite_fibonacci(3));
}

int	ft_rec_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_rec_fibonacci(index - 1) + ft_rec_fibonacci(index - 2));
}

int ft_ite_fibonacci(int index)
{
	int i = 1;
	int a = 0;
	int b = 1;
	int aplused = 0;
	int bplused = 1;
	while (i < index - 1)
	{
		if (bplused == 0)
		{
			b = a + b;
			bplused++;
			aplused = 0;
		}
		else if (aplused == 0)
		{
			a = a + b;
			aplused++;
			bplused = 0;
		}
		i++;
	}
	if (index == 0)
		return 0;
	if (index < 0)
		return (-1);
	int c = a + b;
	return (c);
}
