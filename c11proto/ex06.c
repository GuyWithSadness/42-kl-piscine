void	ft_sort_string_tab(char **tab);
int		ft_strcmp(char *current, char *compare);

void	ft_sort_string_tab(char **tab)
{
	int i;
	int j;
	char *temp;

	i = 0;
	while (tab[i] != 0)
	{
		j = i + 1;
		while (tab[j] != 0)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int		ft_strcmp(char *current, char *compare)
{
	int i;

	i = 0;
	while (current[i] == compare[i])
	{
		if (current[i] == '\0')
			return (0);
		i++;
	}
	return (current[i] - compare[i]);
}

#include <stdio.h>
int main()
{
	char *tab[] = {
		"b",
		"a",
		"c",
		"s",
		"d",
		"avadwa",
		"bawdaw",
		"bcadwad",
		"zadw",
		"e",
		0
	};

	ft_sort_string_tab(tab);
	int i;
	int j;
	i = 0;
	while (tab[i] != 0)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
