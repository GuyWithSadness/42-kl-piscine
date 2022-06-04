int checksign(char *str, int i);
int	ft_atoi_base(char *str, char *base);
int	checkbase(char *base, int baselen);
int convert(char *str, char *base, int baselen, int isnegative);
int checkspace(char *str);

#include <stdio.h>
int main()
{
	printf("1 - %d\n", ft_atoi_base("", "0123456789"));
	printf("2 - %d\n", ft_atoi_base("   +--+---5672674", ""));
	printf("3 - %d\n", ft_atoi_base("10101110101", "01+-"));
	printf("4 - %d\n", ft_atoi_base("   ++---yourmom", "0123456789"));
	printf("5 - %d\n", ft_atoi_base("23", "0123456789"));
	printf("6 - %d\n", ft_atoi_base("-129yourmom389", "0123456789"));
	printf("7 - %d\n", ft_atoi_base("++---23977", "0123456789"));
	printf("8 - %d\n", ft_atoi_base("++--2747", "0123456789"));
	printf("9 - %d\n", ft_atoi_base("  sdad ++---yourmom", "0123456789"));
	printf("10 - %d\n", ft_atoi_base("   +--+---5672674", "0123456789"));
	printf("11 - %d\n", ft_atoi_base("   +--+---122213", "012"));
	printf("12 - %d\n", ft_atoi_base("   +--+---567267", "0123456789"));
	printf("13 - %d\n", ft_atoi_base("122212134", "012345"));
	printf("14 - %d\n", ft_atoi_base("    --+-101010111", "01"));
	printf("15 - %d\n", ft_atoi_base("    --+-101aa010111", "01"));
}

int	ft_atoi_base(char *str, char *base)
{
	int baselen;
	int intvalue;
	int isnegative;
	int i;
	printf("\n\nHelp\n");
	baselen = 0;
	while(base[baselen] != '\0')
		baselen++;
	printf("got base length = this is a base-%d\n", baselen);
	printf("Base checking now...\n");
	if (checkbase(base, baselen) == 0)
	{
		printf("Base check failed\n");
		return (0);
	}
	printf("Base check success!\n");
	printf("Skipping White Spaces...\n");
	i = checkspace(str);
	printf("Now Checking Sign....\n");
	isnegative = checksign(str, i);
	printf("Your character negative value is = %d\n", isnegative);
	printf("working on it...\n");
	printf("...\n");
	printf("...\n\n");
	intvalue = convert(str, base, baselen, isnegative);
	return (intvalue);
}

int convert(char *str, char *base, int baselen, int isnegative)
{
	int intvalue;
	int i;
	int number;
	int end;

	i = checkspace(str);
	number = 0;
	intvalue = 0;
	while (1)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			i++;
			continue;
		}
		number = 0;
		printf("finding %c in base converter\n", str[i]);
		while (1)
		{
			if (base[number] == '\0')
			{
				printf("looks like theres no suitable digit, terminating\n");
				end = 1;
				break;
			}
			if (str[i] == base[number])
			{
				printf("found digit %c = %d\n", str[i], number);
				break;
			}
			number++;
		}
		if (end == 1)
			break;
		printf("initial intvalue = %d\n", intvalue);
		intvalue = intvalue * baselen;
		printf("made space for new digit = %d\n", intvalue);
		printf("adding new digit\n");
		intvalue = intvalue + number;
		printf("digit is now %d\n\n", intvalue);
		i++;
	}
	if (isnegative == 1)
		intvalue *= -1;
	return (intvalue);
}

int checksign(char *str, int i)
{
	int totalnega;
	int isnegative;

	totalnega = 0;
	isnegative = 0;
	while (str[i])
	{
		if (str[i] == '+');
		else if (str[i] == '-')
		{
			totalnega++;
			printf("found a negative sign =%d\n", totalnega);
		}
		else
		{
			printf("no more signs detected\n");
			if ((totalnega % 2) == 1)
				isnegative = 1;
			break;
		}
		i++;
	}
	return (isnegative);
}

int		checkbase(char *base, int baselen)
{
	int	i;
	int	j;
	if (baselen < 2)
	{
		printf("Whoops! your base length wasn't enough\n");
		return (0);
	}
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
		{
			printf("Whoops! you had - or + in your base\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				printf("Whoops! you had repeating characters in your base\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int checkspace(char *str)
{
    int n;

    n = 0;
    while ( str[n] == ' ' || (str[n] >= 9 && str[n] <= 13))
	{
		n++;
	}
    return (n);
}
