#include <stdio.h>
#include <string.h>
char	*ft_strcpy(char *dest, char *src);

int main()
{

	char a[20];
	char a2[20];
	ft_strcpy(a, "Whats");
	printf("%s \n", a);
	for(int i = 0; i < 21; i++)
	{
		printf("%d ", a[i]);
	}
	strcpy(a2, "whats");
	printf("\n%s\n", a2);
	for(int i = 0; i < 21; i++)
	{
		printf("%d ", a2[i]);
	}

}


char	*ft_strcpy(char *dest, char *src)
{
	int	n;
	n = 0;

	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';

	return dest;
}
