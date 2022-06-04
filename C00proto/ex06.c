#include <unistd.h>
/* authors notes

Have you ever cared about kindergarden?
No
Would you like too?

a harder ex05

Basic Concepts that i thought of while eating family mart sandwish

Displays all different combination of 2 digits between 00 and 99
basically

00 01 - 00 99
01 02 - 01 99
02 03 - 02 99
once again, the 2nd value is the 1st value + 1

problem is, we cant use int to do additions
if only we could find a way to plus the digit like doing maths
... wait

*/

void ft_putchar(char c);
void print_numbers(char a, char b, char c, char d);
void ft_print_comb2(void);


int main()
{

    ft_print_comb2();
    return 0;

}

void ft_putchar(char c)
{
    write(1,&c,1); //this is to type out the number, WE CAN ONLY TYPE DIGIT PER DIGIT
}

void print_numbers(char a, char b, char c, char d)
{
    ft_putchar(a);
    ft_putchar(b);
    ft_putchar(' ');
    ft_putchar(c); //once again, print would be more useful here
    ft_putchar(d);
    ft_putchar(',');
    ft_putchar(' ');
}

void ft_print_comb2(void)
{
    char a, b, c, d;
    int n;
    a = '0';
    b = '0';
    c = '0'; //the very first value
    d = '1';
    n = 1;

    while (a <= '9') // needed to make the while loop run or something, i think i can put a 1 here not sure
    {
        if (a == '9' && b == '9')
        {
            break; // break once the first value is 99, which couldn't exists (since you need the second value to be 100)
        }
        
        print_numbers(a,b,c,d);

        /* 
        code to display all different combination of two digits
        without logic gate, it just display all combination of 2 digits
        */

        d++;
        if (d == ':')
        {
            d = '0';
            ++c;
            if (c == ':')
            {
                c = '0';
                ++b;
                
                if (b == ':')
                {
                    b = '0';
                    ++a;
                }
                
                // LOGIT GATEEEEEEE
                /* 
                
                i try to explain this

                basically, n is a tracker to track what is the actual value of the 2nd digit
                but how are we going to slap value n to the 2nd digit?


                tenth digit and ones digit

                _ _

                say if n = 81
                
                if we divide 81, we will get 8 (which is actually the tenth value (2nd digit for 2nd value))
                if we modulus 81, we will get 1 (the oneth digit for the 2nd value)
                instead of slapping 81, we slap the tenth value in the 2nd digit and the oneth value in the 1st digit
                
                */

                ++n;  // record what the 2nd value is suppose to be
                c = c + (n/10); // the tenth value
                d = d + (n%10); // the oneth value
            }
        }
    }
}


