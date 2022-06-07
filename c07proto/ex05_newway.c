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
	char a[] = "0kill015134354315813466489154131565470me0";
	char b[] = "0123456789";
	test = ft_split(a, b);
	for (int i = 0; i <= 10; i++)
		printf("this is in the %d string %s\n",i, test[i]);
}

char	**ft_split(char *str3, char *charset)
{
	char **splitted;
	char *str;
	char *str2;
	int sets;
	int i;
	int words;

	str = ft_strdup(str3);
	str2 = ft_strdup(str);
	sets = findsep(str, str2, charset);
	printf("Allocating memory of %d to splitted array\n", sets+1);
	splitted = (char **) malloc ((sets + 1) * sizeof(char *));
	i = 0;
	while (i < sets)
	{
		words = countwords(str2);
		splitted[i] = (char *) malloc (words + 1 * sizeof(char));
		printf("Allocating memory of %d to %dth set\n",words+1, i);
		i++;
	}
	ft_cpy(splitted, str, sets);
	printf("last set is %d\n", sets);
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
	printf("placing 0 at the last character (%d)\n",i);
	dst[i] = 0;
	printf("successfully duplicated\n");
	return (dst);
}

void	findsep(char *str, char *charset, int i, int j)
{
	int	seen;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j])
				str[i] = '[';
	}
	printf("this is how the string looks like %s\n", str);
	i = -1;
	seen = 0;
	while (str[++i])
	{
		if (str[i] != '}' && str[i] != '[' && str[i - 1] == '[' && seen == 0)
		{
			seen = 1;
			str[i - 1] = '}';
		}
		else if (str[i] != '}' && str[i] != '[' && str[i + 1] == '[' && seen == 1)
		{
			seen = 0;
			str[i + 1] = '}';
		}
	}
	printf("this is how the string looks like %s\n", str);
}

int		countwords(char *str2)
{
	int wordcount;
	int seen;
	int i;
	printf("in countwords\n");
	wordcount = 0;
	seen = 0;
	i = 0;
	while(seen != 2)
	{
		if (str2[i] == -1 && seen == 0)
		{
			printf("start counting\n");
			seen = 1;
		}
		else if (str2[i] == -1 && seen == 1)
			seen = 2;
		if (seen == 1 && str2[i] != -1 && str2[i] != -3)
		{
			printf("found a word = %d\n", str2[i]);
			wordcount++;
		}
		str2[i] = -2;
		i++;
	}
	printf("counted %d of words\n", wordcount);
	return (wordcount);
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
			if (seen == 1 && str[i] != -1 && str[i] != -3)
			{
				printf("copying %c to %ith word and %ith letter of splitted..\n", str[i], j, x);
				splitted[j][x] = str[i];
				x++;
			}
			str[i] = -2;
			i++;
		}
		printf("copying null to %ith word and %ith letter of splitted..\n", j, x);
		splitted[j][x] = '\0';
		j++;
	}
}
