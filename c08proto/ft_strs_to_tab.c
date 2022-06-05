// #include "ft_stock_str.h"
#include <stdio.h>

typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
} t_stock_str;

int ftstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_cpy(char *str, char *dest)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// struct s_stock_str *ft_str_to_tab(int ac, char **av)
// {
// 	// does something
// }

void slap_in_struct(t_stock_str *e, char *str)
{
	printf)
	e->size = ftstrlen(str);
	ft_cpy(str, e->str);
	ft_cpy(str, e->copy);
}

int main()
{
	t_stock_str teststruct;
	t_stock_str *ptr;
	ptr = &teststruct;
	char str[] = "test";
	slap_in_struct(ptr, str);
	printf("%d\n", teststruct.size);
	printf("%s\n", teststruct.str);
	printf("%s\n", teststruct.copy);
}
