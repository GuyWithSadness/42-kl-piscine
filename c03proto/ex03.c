char *ft_strncat(char *dest, char *src, unsigned int nb);

#include <stdio.h>
#include <string.h>

int main () {
   char str1[40];
   char str2[100];
   char str3[40];

   strcpy(str1, "bob");
   strcpy(str2, " the builder");
   strcpy(str3, "bob");

   ft_strncat(str1, str2, 2);
   printf("my function = %s\n", str1);
   strncat(str3, str2, 2);
   printf("sys function = %s", str3);

   return(0);
}

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	unsigned int j;

	i = -1;
	j = 0;

	while(dest[++i] != '\0'){};
	while(j < nb)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return dest;
}
