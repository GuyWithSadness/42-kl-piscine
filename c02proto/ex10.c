#include <stdio.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void test(int size);

int main()
{
	test(19);
    test(10);
    test(1);
    test(0);

    return(0);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if ( size == 0 )
		return (srclen);
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}

void test(int size)
{
    char string[] = "test";
    char buffer[100] = "test";
    int r;
	int z;

    z = ft_strlcpy(buffer,string,size);
	r = strlcpy(buffer,string,size);

    printf("sys function Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
    printf("my function Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            z
          );

    char string2[] = "i think momo dislikes me idk";
    char buffer2[19];
    int r2;
	int z2;

    z2 = ft_strlcpy(buffer2,string2,size);
	r2= strlcpy(buffer2,string2,size);

    printf("sys function Copied '%s' into '%s', length %d\n",
            string2,
            buffer2,
            r2
          );

    printf("my function Copied '%s' into '%s', length %d\n",
            string2,
            buffer2,
            z2
          );

	printf("\n");
}
