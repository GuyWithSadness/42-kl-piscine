#include <unistd.h>
void ft_putchar(char c);
void ft_is_negative(int n);

int main()
{
    ft_is_negative(-1);
    ft_is_negative(91);
}

void ft_putchar(char c)
{

    write(1,&c,1);

}

void ft_is_negative(int n) //simple if else file
{
    if (n >= 0)
    {
        ft_putchar('P'); //if value of n is positive or null (null is 0 right?)
    }
    else
    {
        ft_putchar('N'); //if value is negative
    }
}
