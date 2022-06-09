#include "ft.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	int	x;
	int	y;
	int	result;
	int	operate;

	if (ac != 4)
		return (4);
	x = ft_atoi(av[1]);
	y = ft_atoi(av[3]);
	operate = find_oper(av[2]);
	if (operate == -1)
		write (1, "0", 1);
	else
	{
		if (operate == 3 || operate == 4)
			if (precheck(y, operate) == 0)
				return (90);
		result = calculator(x, y, operate);
		ft_putnbr(result);
	}
	write(1, "\n", 1);
	return (0);
}

int	find_oper(char *operateur)
{
	char	*pos_oper;
	int		i;

	pos_oper = "+-*/%";
	i = 0;
	while (pos_oper[i] != '\0')
	{
		if (operateur[0] == pos_oper[i])
			return (i);
		i++;
	}
	return (-1);
}

int	precheck(int y, int i)
{
	if (y == 0 && i == 3)
		write (1, "Stop : division by zero\n", 24);
	else if (y == 0 && i == 4)
		write (1, "Stop : modulo by zero\n", 22);
	else
		return (1);
	return (0);
}
