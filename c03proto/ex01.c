int	ft_strncmp(char *s1, char *s2, unsigned int n);

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main () {
   char str1[15];
   char str2[15];
   int ret;
   int ret2;

   strcpy(str1, "abcd:");
   strcpy(str2, "abcdO");

   ret = ft_strncmp(str1, str2, 7);
   ret2 = strncmp(str1, str2, 7);
   printf("my function = %d\n",ret);
   printf("i dont know function = %d", ret2);

   return(0);
}

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while(i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
