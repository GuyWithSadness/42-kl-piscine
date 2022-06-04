#include <unistd.h>

void ft_putchar(char c);

int main()
{
    ft_putchar('t');
}

void ft_putchar(char c)
{
    write(1,&c,1);
}