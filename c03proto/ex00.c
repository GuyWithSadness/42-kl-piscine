int	ft_strcmp(char *s1, char *s2);

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main () {
   char str1[] = "a";
   char str2[] = "b";
   int ret;
   int ret2;


   ret = ft_strcmp(str1, str2);
   ret2 = strcmp(str1, str2);
   printf("my function = %d\n",ret);
   printf("system function = %d", ret2);

   return(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == s2[i] && s1[i] == '\0')
			return (0);
		i++;
	}
}
