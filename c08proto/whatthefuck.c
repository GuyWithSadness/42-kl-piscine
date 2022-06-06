// #include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stock_str
{
    int size;
    char *str;
    char *copy;
} t_stock_str;

int ftstrlen(char *str)
{
    int    i;

    i = 0;
    while (str[i])
        i++;
    printf("counted %d of letters\n", i);
    return (i);
}

char *ft_cpy(char *str, char *dest)
{
    printf("in ft_cpy");
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        printf("copying %s to dest at %i", str[i], i);
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void slap_in_struct(t_stock_str e, char *str)
{
    printf("Slapping in the size\n");
    e.size = ftstrlen(str);
    printf("Allocating memory for string\n");
    e.str = (char *) malloc ((e.size + 1) * sizeof(char));
    printf("Slapping in the string\n");
    ft_cpy(str, e.str);
    printf("Allocating memory for Copy");
    e.copy = (char *) malloc ((e.size + 1) * sizeof(char));
    printf("Copying in the string\n");
    ft_cpy(str, e.copy);
}

struct s_stock_str *ft_str_to_tab(int ac, char av[2][5])
{
    int i;

    t_stock_str *array;
    printf("Allocating memory\n");
    array = (t_stock_str *) malloc ((ac-1) * sizeof(t_stock_str));
    printf("Successfully Allocate memory of %d\n", ac-1);
    i = 1;
    while (i <= ac)
    {
        printf("Slapping in struct for %dth element idk does this wrok?\n", i-1);
        slap_in_struct(array[i-1], av[i]);
        printf("Success!\n");
        i++;
    }
    return (array);
}

#include <stdio.h>
int main()
{
    t_stock_str *test;
    int ac = 2;
    char av[2][5] =
    {
      "AAaA",
      "bBBb"
    };
    test = ft_str_to_tab(ac, av);
    for(int i = 0; i <= ac; i++)
    {
        printf("Size is = %d\n", test[i].size);
        printf("String is = %s\n", test[i].str);
        printf("Copy of string is = %s\n", test[i].copy);
    }
}
