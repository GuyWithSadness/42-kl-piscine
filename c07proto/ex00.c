#include <stdlib.h>

char	*ft_strdup(char *src);
char	*ft_cpy(char *dst, char *src);

#include <stdio.h>
#include <string.h>
int main()
{
	char *src2;
	char *src3;
	src2 = ft_strdup("Help");
	printf("my func = %s\n", src2);
	for (int i = 0; i <= 10; i++)
		printf("%d ", src2[i]);
	src3 = strdup("Help");
	printf("\nsys func = %s\n", src3);
	for (int i = 0; i <= 10; i++)
		printf("%d ", src3[i]);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	dst = (char *) malloc (i+1 * sizeof(char));
	if (dst == 0)
		return (0);
	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
