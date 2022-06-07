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
	char a[] = "test";
	char b[] = "t";
	test = ft_split(a, b);
	for (int i = 0; i <= 10; i++)
		printf("%s\n",test[i]);
}

char	**ft_split(char *str, char *charset)
{
	char **splitted;
	// char *str;
	char *str2;
	int sets;
	int i;
	int words;

	// str = ft_strdup(str3);
	str2 = ft_strdup(str);
	sets = findsep(str, str2, charset);
	printf("Allocating memory of %d to splitted array\n", sets+1);
	splitted = (char **) malloc (sets + 1 * sizeof(char *));
	i = 0;
	while (i < sets)
	{
		words = countwords(str2);
		splitted[i] = (char *) malloc (words + 1 * sizeof(char));
		printf("Allocating memory of %d to %dth set\n",words+1, i);
		i++;
	}
	splitted[i] = (char *) malloc (sizeof(char));
	printf("Allocated 1 memory for null character in %d array\n", i);
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
	printf("placing 0 at the last pointer(%d)\n",i);
	dst[i] = 0;
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
				printf("replaced the seperator with -1 in the main\n");
				str[i] = -1;
				printf("replacing the seperator with -1 in the backup\n");
				str2[i] = -1;
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
	printf("in countwords\n");
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
		if (seen == 1)
		{
			printf("found a word = %s\n", str2[i]);
			wordcount++;
		}
		str2[i] = -2;
		i++;
	}
	printf("counted %d of words", wordcount - 1);
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
				printf("copying %s to %i word of %i letter of splitted..", str[i], j, x);
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
