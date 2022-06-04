#include <stdio.h>
#include <string.h>

int		ft_atoi(char *str);

int main()
{
	printf("%d\n", ft_atoi(""));
	printf("%d\n", ft_atoi("a"));
	printf("%d\n", ft_atoi("12312"));
	printf("%d\n", ft_atoi("-12312"));
	printf("%d\n", ft_atoi("--wada+-12312"));
	printf("%d\n", ft_atoi("wadawd-12312"));
	printf("%d\n", ft_atoi("-12awdawd312"));
	printf("%d\n", ft_atoi("-+++12312"));
	printf("%d\n", ft_atoi("--12312"));
	printf("%d\n", ft_atoi("   --+-12312"));
	printf("%d\n", ft_atoi(" - 12312"));
}

int		ft_atoi(char *str)
{
	int i;
	int totalnega;
	int nega;
	int total;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	totalnega = 0;
	nega = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			totalnega++;
		i++;
	}
	if ((totalnega % 2) == 1)
		nega = -1;
	total = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
        total = (total * 10) + (str[i] - '0');
		i++;
	}
	return (total * nega);
}
