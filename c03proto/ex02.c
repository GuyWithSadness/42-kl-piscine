char	*ft_strcat(char *dest, char *src);

#include <stdio.h>
#include <string.h>

int main () {
   char str1[100] = "abcd";
   char str2[5] = "efgh";
   char str3[100] = "abcd";

   ft_strcat(str1, str2);
   printf("my function = %s\n", str1);
   strcat(str3, str2);
   printf("sys function = %s", str3);
   return(0);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while(dest[++i] != '\0'){};
	while(src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return dest;
}
