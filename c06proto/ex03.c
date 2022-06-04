#include <unistd.h>

void	ft_sort(char **tab, int size);
int	ft_strcmp(char *s1, char *s2);

int main(int argc, char *argv[])
{
	int i;
	int count;

	count = 0;
	i = -1;

	ft_sort(argv, argc);

	while (++count < argc)
	{
		while(argv[count][++i] != '\0')
		{
			write(1, &argv[count][i], 1);
		}
		write(1, "\n", 1);
		i = -1;
	}
}

void	ft_sort(char **tab, int size)
{
	int count;
	int compare;
	char *temp[1];

	count = 1;
	compare = 2;

	while (count != size)
	{
		while (compare != size)
		{
			if (ft_strcmp(tab[count], tab [compare]) > 0)
			{
					temp[0] = tab[count];
					tab[count]= tab[compare];
					tab[compare]= temp[0];
			}
			compare++;
		}
		count++;
		compare = count+1;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == s2[i] && s1[i] == '\0')
			return (0);
		i++;
	}
}
