#include <unistd.h>

void    ft_putstr(char *str);

int main()
{
	ft_putstr("wajdkjawkd");
}

void    ft_putstr(char *str)
{
    int n = 0;
    while (str[n] != '\0')
    {
        write(1,&str[n++], 1);
    }
}
