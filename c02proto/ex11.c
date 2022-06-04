#include <unistd.h>
#include <stdio.h>
void	ft_putstr_non_printable(char *str);
void	ft_putchar(char c);

int	main()
{
	ft_putstr_non_printable("\a = Bell \b = Backspace \f = Form Feed \n = New line \r = Carriage return \t = Horizontal tab \v = Vertical tab");
}

void	ft_putstr_non_printable(char *str)
{
	char	*base16;
	int		n;

	base16 = "0123456789abcdef";
	n = -1;
	while (str[++n])
	{
		if (str[n] < 32 || str[n] > 126)
		{
			ft_putchar('\\');
			ft_putchar(base16[(str[n])/16]);
			ft_putchar(base16[(str[n])%16]);
		}
		else
			ft_putchar(str[n]);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
