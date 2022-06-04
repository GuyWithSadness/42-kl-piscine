#include <unistd.h>
void ft_putchar(char c);
void ft_print_combn(int n);
void logictest();

int main()
{
    int a = 1;

    ft_print_combn(2);
    /* check the first value of everything or something

    while (a <= 9)
    {
        ft_print_combn(a);
        ft_putchar(' ');
        ++a;
    }

    */
    return 0;

    
}

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_print_combn(int n)
{
    int count = 0;
    int count2 = (n-1);
    int fstdigit = 0;
    int lastdigit = (n-1);
    int totaldigit = lastdigit;
    int digit;
    char a[n];

    //determines the first value
    while (count2 >= 1)
    {
        a[count2] = '0' + (n-1);
        --count2;
    }
    a[0] = '0';

    /* prints the first value
    while (count <= n)
    {
        ft_putchar(a[count]);
        ++count;
    }
    count = 0; */

    while (a[fstdigit] <= (':' - 2)) //while (num2 <= '8')
    {
        digit = 0;            //
        while (digit <= (n-1))        // putchar num1
        {                         // putchar num2
            ft_putchar(a[digit]); // 
            digit++;              //
        }                         //

        ft_putchar(' ');          // decorative purposes

        a[lastdigit]++;           // num2++

        if (n > 1)
        {
            if (a[lastdigit] == ':')
            {
                ++(a[fstdigit]);         //working on the logic test
                a[lastdigit] = a[fstdigit] + 1;
            }
        }
    }
}

void logictest()
{
    
}

