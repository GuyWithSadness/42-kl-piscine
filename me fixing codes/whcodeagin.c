#include <stdio.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while ((count < n))
	{
		if (s1[count] != s2[count])
		{
			printf("%c and %c isnt same, %d", s1[count] , s2[count], s1[count] - s2[count]);
			return (s1[count] - s2[count]);
		}
		if (s1[count+1] == '\0' || s2[count+1] == '\0')
			return (s1[count+1] - s2[count+1]);
		count++;
	}

	return (0);
}


#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	int a = atoi(argv[3]);
	printf("Your function: %d\n", ft_strncmp(argv[1], argv[2], a));
	printf("Sys funtion: %d\n", strncmp(argv[1], argv[2], a));
}
