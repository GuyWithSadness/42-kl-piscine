#include <unistd.h>

/* Authors Notes

ah yes
to convert a int to char

so you know how repeated division works right for base 2 conversion?

yeah just do that but for base 10 

for instance

                        452
                    |        %
                    45       2
                |       %
                0.4     5
                %
                4
then you can just add those values into the char with (n + '0') and voila

but to do that you need recursive functions
functions that calls itself in its own functions 

*/

void ft_putnbr(int nb);
void ft_putchar(char c);

int main()
{
    ft_putnbr(99999);
    ft_putnbr(42);
    ft_putnbr(-29);
    return 0;
}

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putnbr(int nb)
{
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putchar((nb % 10) + '0');
    } else if (nb < 10)
    {
        ft_putchar((nb % 10) + '0');
    }
}