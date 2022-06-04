#include <stdio.h>
#include <string.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main()
{
	int i;
	char a[14];
	char b[14];
	char c[] = "explain";
	ft_strncpy(a, c, 7);
	printf("my funciton: %s\n", a);
	for(i = 0; i < 15; i++)
	{
		printf("%d ", a[i]);
	}

	strncpy(b, c, 7);
	printf("\nsystem funciton: %s\n", b);
	for(i = 0; i < 15; i++)
	{
		printf("%d ", b[i]);
	}
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	i = 0;

	while(i < n)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return dest;
}
