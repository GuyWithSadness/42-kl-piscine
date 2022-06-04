#include <stdio.h>
int ft_str_is_lowercase(char *str);

int main()
{
	char a[] = "";
	int test = ft_str_is_lowercase(a);
	char b[] = "oops!";
	int test2 = ft_str_is_lowercase(b);
	char c[] = "11231";
	int test3 = ft_str_is_lowercase(c);
	char d[] = "123sajd!!==";
	int test4 = ft_str_is_lowercase(d);
	char e[] = "ajkwdhkjaw";
	int test5 = ft_str_is_lowercase(e);
	printf("%d %d %d %d %d", test, test2 , test3 , test4, test5);
}

int ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	while ( str[i] != '\0' )
	{
		if ( str[i] < 'a' || str[i] > 'z')
		    return (0);
		++i;
	}
	return (1);
}
