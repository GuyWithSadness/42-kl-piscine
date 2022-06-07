#include <stdio.h>
int ft_str_is_uppercase(char *str);

int main()
{
	char a[] = "";
	int test = ft_str_is_uppercase(a);
	char b[] = "oops!";
	int test2 = ft_str_is_uppercase(b);
	char c[] = "11231";
	int test3 = ft_str_is_uppercase(c);
	char d[] = "123sajd!!==";
	int test4 = ft_str_is_uppercase(d);
	char e[] = "ADAWKJDLAKW";
	int test5 = ft_str_is_uppercase(e);
	printf("%d %d %d %d %d", test, test2 , test3 , test4, test5);
}

int ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	while ( str[i] != '\0' )
	{
		if ( str[i] < 'A' || str[i] > 'Z')
		    return (0);
		++i;
	}
	return (1);
}
