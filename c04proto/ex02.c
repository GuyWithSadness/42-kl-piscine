#include <unistd.h>
#include <stdio.h>

void 	ft_putchar(char a);
void	ft_putnbr(int nb);

int main()
{
	ft_putnbr(123);
	write(1,"\n",1);
	ft_putnbr(765479);
	write(1,"\n",1);
	ft_putnbr(2147483647);
	write(1,"\n",1);
	ft_putnbr(-238);
	write(1,"\n",1);
	ft_putnbr(-2147483648);
	write(1,"\n",1);
}

void 	ft_putchar(char a)
{
	write(1,&a,1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
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
