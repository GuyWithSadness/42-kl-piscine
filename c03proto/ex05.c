unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

#include <stdio.h>
#include <string.h>

int main () {
   char str1[100];
   char str2[100];
   char str3[100];
   int a;
   int b = 0;

   strcpy(str1, "DID IT WORK ");
   strcpy(str2, "I THINK IT DID NOT SURE");
   strcpy(str3, "DID IT WORK ");

   a = ft_strlcat(str1, str2, 30);
   printf("my  function = %s, Number: %d\n", str1, a);
   b = strlcat(str3, str2, 30);
   printf("sys function = %s, Number: %d", str3, b);

   return(0);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	int				z;
	int				y;
	unsigned int	j;

	y = -1;
	z = 0;
	i = 0;
	j = 0;
	while (src[z] != '\0')
		z++;
	while (dest[++y] != '\0')
	{
		--size;
		++i;
	}
	while (j < (size - 1))
		dest[i++] = src[j++];
	if (y != 0)
		dest[++i] = '\0';
	return (z + y);
}

