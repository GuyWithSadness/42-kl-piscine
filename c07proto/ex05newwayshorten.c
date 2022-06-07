#include <stdlib.h>

char	**ft_split(char *str, char *charset);
char	*ft_strdup(char *src);
void	ft_cpy(char **splitted, char *str, int sets);
void	findsep(char *str, char *charset);
int		countwords(char *str2);

#include <stdio.h>
int main()
{
	char** test;
	char a[] = "0kill015134354315813466489154131565470me0";
	char b[] = "0123456789";
	test = ft_split(a, b);
	for (int i = 0; i <= 10; i++)
		printf("this is in the %d string %s\n",i, test[i]);
}

char	**ft_split(char *str3, char *charset)
{
	char	**splitted;
	char	*str;
	char	*str2;
	int		sets;
	int		i;
	int		words;

	str = ft_strdup(str3);
	str2 = ft_strdup(str);
	printf("epic1\n");
	findsep(str2, charset);
	findsep(str, charset);
	printf("epic2\n");
	i = -1;
	sets = 0;
	while(str[++i])
		if (str[i] == -1)
			sets++;
	printf("this is the number of seps found %d\n", sets);
	printf("this is the number of sets found %d\n", sets/2);
	splitted = (char **) malloc (((sets/2) + 1) * sizeof(char *));
	printf("malloc works\n");
	i = -1;
	while (++i < sets/2)
	{
		printf("i = %d\n", i);
		words = countwords(str2);
		splitted[i] = (char *) malloc ((words + 1) * sizeof(char));
	}
	printf("epic4\n");
	ft_cpy(splitted, str, sets/2);
	splitted[sets/2] = 0;
	return (splitted);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	dst = (char *) malloc ((i + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

void	findsep(char *str, char *charset)
{
	int	sets;
	int	i;
	int	j;

	sets = 0;
	i = -1;
	while(str[++i])
	{
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j])
				str[i] = -3;
	}
	i = -1;
	while(str[++i])
	{
		if (str[i] != -3 && str[i] != -1)
		{
			if (str[i - 1] == -3)
				str[i - 1] = -1;
			if (str[i + 1] == -3)
				str[i + 1] = -1;
		}
	}
}

int		countwords(char *str2)
{
	int	wordcount;
	int	seen;
	int	i;

	wordcount = 0;
	seen = 0;
	i = 0;
	while(seen != 2)
	{
		if (str2[i] == -1 && seen == 0)
			seen = 1;
		else if (str2[i] == -1 && seen == 1)
			seen = 2;
		if (seen == 1 && str2[i] != -1 && str2[i] != -3)
			wordcount++;
		str2[i] = -2;
		i++;
	}
	return (wordcount);
}

void	ft_cpy(char **splitted, char *str, int sets)
{
	int	seen;
	int	i;
	int	j;
	int	x;

	j = 0;
	i = 0;
	while (j < sets)
	{
		x = 0;
		seen = 0;
		while(seen != 2)
		{
			if (str[i] == -1 && seen == 0)
				seen = 1;
			else if (str[i] == -1 && seen == 1)
				seen = 2;
			if (seen == 1 && str[i] != -1 && str[i] != -3)
			{
				splitted[j][x] = str[i];
				x++;
			}
			str[i] = -2;
			i++;
		}
		splitted[j][x] = '\0';
		j++;
	}
}
