typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
} t_stock_str;

#include <unistd.h>
#include <stdio.h>

void	ft_show_tab(struct s_stock_str *par);
void	ft_printstr(char *str);
void	ft_putnbr(int nb);
void 	ft_putchar(char a);

void ft_show_tab(struct s_stock_str *par)
{
	int i;
	i = 0;
	while (par[i].str != 0)
	{
		ft_printstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_printstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

void ft_printstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
}

void 	ft_putchar(char a)
{
	write(1,&a,1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb/10);
		ft_putchar(nb%10 + '0');
	}
	else
		ft_putchar(nb%10 + '0');
}
