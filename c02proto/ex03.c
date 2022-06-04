#include <stdio.h>
int	ft_str_is_numeric(char *str);

int main()
{
	char a[] = "\0";
	int test = ft_str_is_numeric(a);
	char b[] = "oops!";
	int test2 = ft_str_is_numeric(b);
	char c[] = "11231";
	int test3 = ft_str_is_numeric(c);
	char d[] = "123sajd!!==";
	int test4 = ft_str_is_numeric(d);
	printf("%d %d %d %d", test, test2 , test3 , test4);
}

int	ft_str_is_numeric(char *str)
{
	int i;
	char test;

	i = 0;
	while ( str[i] != '\0' )
	{
		if (str[i] < '0' || str[i] > '9')
		    return (0);
		++i;
	}
	return (1);
}
