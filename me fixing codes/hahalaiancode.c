#include <stdio.h>
#include <stdlib.h>

char     *ft_strjoin(int size, char **strs, char *sep);
char    *ft_strdup(char *src);
int        ft_strlen(char *src);

char *ft_strjoin(int size, char **strs, char *sep)
{
    int    n;
    int boolean;
    char *dest;

    n = 0;
    boolean = 0;
    while (size--)
    {
        if(boolean == 0)
        {
			printf("allocating memory for strs\n");
            if((dest = (char*)malloc((ft_strlen(strs[n])) * sizeof(char) + 1)) == NULL)
                return (0);
            dest = ft_strdup(strs[n]);
			printf("dest is now %s\n", dest);
            n++;
            boolean = 1;
        }
        if (boolean == 1)
        {
			printf("allocating memory for seps\n");
            if((dest = (char*)malloc((ft_strlen(sep)) * sizeof(char) + 1)) == NULL)
                return (0);
            dest = ft_strdup(sep);
			printf("dest is now %s\n", dest);
            boolean = 0;
        }
    }
    return (dest);
}

char    *ft_strdup(char *src)
{
    int n;
    char *dest;

    n = 0;
    if((dest = (char*) malloc(n * sizeof(char))) == NULL)
        return (0);
    while (src[n] != '\0')
    {
        dest[n] = src[n];
        n++;
    }
    dest[n] = '\0';
    return (dest);
}

int    ft_strlen(char *str)
{
    int    n;

    n = 0;
    while (str[n] != '\0')
        n++;
    return (n);
}

int main()
{
    char *test[] =
    {
        "your mother",
        "your mom",
        "yomom",
        "sex",
    };
    char sep[] = "this is";
    char *dest;
    int size;

    size = 4;
    dest = ft_strjoin(size, test, sep);
    printf("%s\n", dest);
    return (0);
}
