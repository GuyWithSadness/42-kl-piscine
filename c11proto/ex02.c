int	ft_any(char **tab, int(*f)(char*));

int	ft_any(char **tab, int(*f)(char*))
{
	int i;

	i = -1;
	while (tab[++i] != 0)
	{
		if(f(tab[i]))
			return (1);
	}
	return (0);
}

#include <stdio.h>

int findgay(char *a)
{
	int i = 0;
	char *gay = "gay!";
	while (a[i])
	{
		printf("%c and %c\n", a[i], gay[i]);
		if (a[i] != gay[i])
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	char *tab[6] =  {
				"hey!",
				"hey!",
				"hey!",
				"hey!",
				"hey!",
				0
	};
	int a = ft_any(tab, &findgay);
	if (a == 0)
		printf("no gay");
	else
		printf("gay!");
}
