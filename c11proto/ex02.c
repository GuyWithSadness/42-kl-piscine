#include <stdio.h>
int	ft_str_is_alpha(char *str);

int main()
{
	char a[0];
	int test = ft_str_is_alpha(a);
	char b[] = "oops!";
	int test2 = ft_str_is_alpha(b);
	char c[] = "11231";
	int test3 = ft_str_is_alpha(c);
	char d[] = "getfuckef";
	int test4 = ft_str_is_alpha(d);
	printf("%d %d %d %d", test, test2 , test3 , test4);
}

int	ft_str_is_alpha(char *str)
{
	int i;
	char test;

	i = 0;
	while ( str[i] != '\0' )
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
		    return (0);
		++i;
	}
	return (1);
}
