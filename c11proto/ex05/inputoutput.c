#include <unistd.h>

int	ft_atoi(char *str)
{
	int n;
	int sign;
	int rtval;

	n = 0;
	sign = 1;
	rtval = 0;
	while ( str[n] == ' ' || (str[n] >= 9 && str[n] <= 13))
		++n;
	while ( str[n] == '+' || str[n] == '-')
		if(str[n++] == '-')
			sign *= -1;
	while (str[n] >= '0' && str[n] <= '9')
		rtval = (rtval * 10) + (str[n++] - '0');
	return (rtval * sign);
}

void 	ft_putchar(char a)
{
	write(1,&a,1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1,"-2147483648",11);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb/10);
		ft_putchar(nb%10 + '0');
	}
	else
		ft_putchar(nb%10 + '0');
}
