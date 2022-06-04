#include <stdio.h>
#include <string.h>

int		ft_atoi(char *str);
int		power(int ten, int topowerof);

int main()
{
	printf("%d\n", ft_atoi("-12312"));
	printf("%d\n", ft_atoi("--wada+-12312"));
	printf("%d\n", ft_atoi("wadawd-12312"));
	printf("%d\n", ft_atoi("-12awdawd312"));
	printf("%d\n", ft_atoi("-+++12312"));
	printf("%d\n", ft_atoi("--12312"));
	printf("%d\n", ft_atoi("   --+-12312"));
}

int		ft_atoi(char *str)
{
	int i;
	i = 0;
	// this skips all the spaces i think
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;

	int totalnega;
	int nega;
	totalnega = 0;
	nega = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			totalnega++;
			printf("Negative saw, this amount = %d\n", totalnega);
		}
		i++;
		printf("Next digit %d\n", i);
	}
	if ((totalnega % 2) == 1)
	{
		printf("This Number has negative\n");
		nega = -1;
	}
	//when you exit this while loop you should be at the frst number // bullshit symbol
	int total;

	total = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
        total = (total * 10) + (str[i] - '0');
		i++;
	}
	return (total * nega);
}
