#include <stdlib.h>

char	**ft_split(char *str, char *charset);
char	*ft_strdup(char *src);
void	ft_cpy(char **splitted, char *str, int sets);
int		findsep(char *str, char *str2, char *charset);
int		countwords(char *str2);

#include <stdio.h>
int main()
{
	char** test;
	char a[] = "Hi, i am bob, i love to eat pizzas";
	char b[] = "a";
	test = ft_split(a, b);
	for (int i = 0; i <= 10; i++)
		printf("%s\n",test[i]);
}

char	**ft_split(char *str, char *charset)
{
	char **splitted;
	char *str2;
	int sets;
	int i;
	int words;

	str2 = ft_strdup(str);
	sets = findsep(str, str2, charset);
	printf("Allocating memory of %d to splitted array\n", sets);
	splitted = (char **) malloc (sets + 1 * sizeof(char *));
	i = 0;
	while (i < sets-1)
	{
		printf("Allocating memory to %dth set\n", i);
		words = countwords(str2);
		splitted[i] = (char *) malloc (words + 1 * sizeof(char));
		i++;
	}
	splitted[i] = (char *) malloc (sizeof(char));
	ft_cpy(splitted, str, sets);
	splitted[sets] = 0;
	return (splitted);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	printf("In ft_strdup\n");
	i = 0;
	while (src[i] != '\0')
		i++;
	dst = (char *) malloc (i+1 * sizeof(char));
	if (dst == 0)
		return (0);
	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	printf("successfully duplicated\n");
	return (dst);
}

int		findsep(char *str, char *str2, char *charset)
{
	int sets;
	int i;
	int j;

	printf("in findsep\n");
	sets = 0;
	i = -1;
	while(str[++i])
	{
		j = -1;
		while(charset[++j])
		{
			if (str[i] == charset[j])
			{
				printf("found a seperator\n");
				str[i] = -1;
				printf("replacing the seperator with -1 in the backup\n");
				str2[i] = -1;
				printf("replaced the seperator with -1\n");
				sets++;
			}
		}
	}
	printf("set found = %d\n", sets/2);
	sets = sets / 2;
	return (sets);
}

int		countwords(char *str2)
{
	int wordcount;
	int seen;
	int i;

	seen = 0;
	while(seen != 2)
	{
		if (str2[i] == -1 && seen == 0)
			seen = 1;
		else if (str2[i] == -1 && seen == 1)
			seen = 2;
		str2[i] = -2;
		if (seen == 1)
			wordcount++;
		i++;
	}
	return (wordcount - 1);
}

void	ft_cpy(char **splitted, char *str, int sets)
{
	int seen;
	int i;
	int j;
	int x;
	printf("in ft_cpy\n");
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
			if (seen == 1 && str[i] != -1)
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
