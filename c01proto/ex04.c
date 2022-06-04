#include <stdio.h>
void    ft_ultimate_div_mod(int *a, int *b);

void    ft_ultimate_div_mod(int *a, int *b)
{
    int num1;
    int num2;

    num1 = *a;
    num2 = *b;
    *a = num1/num2;
    *b = num1%num2;
}
