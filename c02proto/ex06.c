#include <stdio.h>

int	ft_str_is_printable(char *str);

int main()
{
	char a[] = {"asd\n"};
	printf("%d\n", ft_str_is_printable(a));
	char b[] = {"aiodhAIOW1238!@()#*"};
	printf("%d\n", ft_str_is_printable(b));
	char c[] = {"\aasd\n"};
	printf("%d\n", ft_str_is_printable(c));
}

int	ft_str_is_printable(char *str)
{
	int n;

	n = -1;
	while (str[++n] != '\0')
	{
		if (str[n] < 32 || str[n] > 126)
		{
			return (0);
		}
	}
	return (1);
}
