#include <stdio.h>

int	isletter(char *str);
void	ft_strupcase(char *str);
char	*ft_strcapitalize(char *str);
int	isnumber(char *str);
char	*ft_strlowcase(char *str);

int main()
{
	char a[] = {"abcde ABCDE -ABcde -abdce +jiaod +aa+waj 87afa -2103adhj"};
	printf("%s", ft_strcapitalize(a));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	ft_strlowcase(str);
	i = -1;
	while( str[++i] != '\0')
	{
		if (!(isletter(&str[i - 1])) && (!isnumber(&str[i - 1])))
		{
			ft_strupcase(&str[i]);
		}
	}
	return (str);
}

void	ft_strupcase(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
}

int	isletter(char *str)
{
	if (*str < 'A' || (*str > 'Z' && *str < 'a') || *str > 'z')
		return (0);
	else
		return (1);
}

int	isnumber(char *str)
{
	if (*str < '0' || *str > '9')
		return (0);
	else;
		return (1);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	while ( str[++i] != '\0' )
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return str;
}
