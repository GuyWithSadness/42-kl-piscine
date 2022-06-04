#include <stdio.h>
char	*ft_strlowcase(char *str);

int main()
{
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ft_strlowcase(a);
	printf("%s \n", a);
	char b[] = "AwhJADWhLAJWHDjawdlahDWJ";
	ft_strlowcase(b);
	printf("%s \n", b);
	char c[] = "AKhhdLLKndLD P9 -ASD== 1-2;";
	ft_strlowcase(c);
	printf("%s \n", c);
	char d[] = "SEGGSSS";
	ft_strlowcase(d);
	printf("%s", d);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while ( str[i] != '\0' )
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		++i;
	}
	return str;
}
