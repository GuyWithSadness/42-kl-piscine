#include <unistd.h>
#include <stdio.h>

void 	ft_putchar(char a);
void	ft_putnbr_base(int nbr, char *base);
int		ft_strlen(char *str);
int		check(char *base, int baselen);
void	ft_putMININT_base(unsigned int nbr, char *base, unsigned int baselen);

int main()
{
	ft_putnbr_base(-12312312, "012");
}

void	ft_putchar(char a)
{
	write(1,&a,1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (check(base, baselen) == 0)
		return ;
	else if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
		{
			ft_putMININT_base(2147483648, base, (unsigned int) baselen);
			return ;
		}
		ft_putnbr_base(-nbr, base);
	}
	else if (nbr >= baselen)
	{
		ft_putnbr_base((nbr / baselen), base);
		ft_putchar(base[nbr % baselen]);
	}
	else
		ft_putchar(base[nbr % baselen]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	check(char *base, int baselen)
{
	int	i;
	int	j;
	if (baselen < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putMININT_base(unsigned int nbr, char *base, unsigned int baselen)
{
	if (nbr >= baselen)
	{
		ft_putMININT_base((nbr / baselen), base, baselen);
		ft_putchar(base[nbr % baselen]);
	}
	else
		ft_putchar(base[nbr % baselen]);
}
