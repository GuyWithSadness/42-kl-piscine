char	*ft_strstr(char *str, char *to_find);
int	ft_strlen(char *str);
void reset(int *same, int *firstfound, int *j);

#include <stdio.h>
#include <string.h>

int    main () {
   char a[] = "abcdefghijklmnabzdefg";
   char b[] = "";
   char c[] = "abcdefghijklmnabzdefg";

   printf("my function: %s\n", ft_strstr(c, b));
   printf("sys function: %s\n",  strstr(a, b));

   return(0);
}

int     ft_strlen(char *str)
{
    int n = -1;
    while (str[++n] != '\0'){};
    return (n);
}

char    *ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		same;
	int		firstfound;

	i = -1;
	j = 0;
	same = 0;
	firstfound = 0;
	while (str[++i] != 0 && to_find[j] != 0)
	{
		if (str[i] == to_find[j])
		{
			if (j++ == 0)
				firstfound = i;
			same++;
			if (same == ft_strlen(to_find))
				break;
		} else
			reset(&same, &firstfound, &j);
	}
	if (same == ft_strlen(to_find))
		return(&str[firstfound]);
	return (NULL);
}

void reset(int *same, int *firstfound, int *j)
{
	*same = 0;
	*firstfound = 0;
	*j = 0;
}
