#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
#include "ft_show_tab.c"

char	*ft_strdup(char *src)
{
	char *dst;
	int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	dst = (char *) malloc (i+1 * sizeof(char));
	if (dst == 0)
		return (0);
	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

int	ft_strlen(char *src)
{
	int i;
	i = 0;
	while (src[i])
		i++;
	return (i);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i;
	t_stock_str *array;

	array = ((t_stock_str *) malloc ((ac + 1) * sizeof (t_stock_str)));
	if (!array)
		return (0);
	i = 1;
	while (i <= ac - 1)
	{
		array[i-1].size = ft_strlen(av[i]);
		array[i-1].str = ft_strdup(av[i]);
		array[i-1].copy = ft_strdup(av[i]);
		i++;
	}
	array[i-1].size = 0;
	array[i-1].str = 0;
	array[i-1].copy = 0;
	return (array);
}

#include <stdio.h>
int main(int ac, char **av)
{
	struct s_stock_str *test;

	test = ft_strs_to_tab(ac, av);
	ft_show_tab(test);
	return 0;
}

