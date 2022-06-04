#include <unistd.h>
void ft_putchar(char c);
void print_numbers(char num1, char num2, char num3);
void ft_print_comb(void);

/* editors notes 

hOhOhOhOhOh
you thought i would be stumped but fuCK YOUUUU

basic concept:
012 -> 019 
020 is not 
021 has repeated

that means:
023 -> 029
030 IS NOT
031 REPEATED
032 REPEATED
033 also repeated

THAT MEANS
034 -> 039
are you noticing a pattern?

const num2 num3 2 unknown numbers
everytime num2 gets added, the first value of num3 is num2 + 1

for instant: 012, 023, 034

this is the same for 3 unkown numbers
num1  num2 num3
everytime num1 gets added, the first value of num2 is num1 + 1

for instance: 012, 123, 234

so we can exploit this

look below to see how i exploited this like how the british exploited our land in 1923
*/

int main()
{
    ft_print_comb(); //this is just to run the function, ignore
    return 0;
}

void ft_putchar(char c)
{
    write(1,&c,1); //this is to type out the number, WE CAN ONLY TYPE DIGIT PER DIGIT
}

void print_numbers(char num1, char num2, char num3) //to print the sequence
{
    if (num1 == '7' && num2 == '8' && num3 == '9') //this is the last digit, 789
    {
        ft_putchar(num1);
        ft_putchar(num2); //the last digit should not have ,(space)
        ft_putchar(num3);
    } else
    {
    ft_putchar(num1);
    ft_putchar(num2); //annoying shit why cant we use printf
    ft_putchar(num3);
    ft_putchar(',');
    ft_putchar(' ');
    }

}

void ft_print_comb(void)
{
    char num1, num2, num3; //call 3 digit variable
    num1 = '0';
    num2 = '1'; //the very first sequence of numbers
    num3 = '2';
    
    while (num1 <= '7') //the last digit of num1 is 7
    { 
        print_numbers(num1, num2, num3); //print the sequence of numbers
        num3++; // add +1 to the last digit so that we can print 012 -> 013
        
        /* here comes the fun part 
        
        i will try my best to explain what is going on here
        */

        if (num3 == ':') // after 9, ++num3 would become : "WE DO NOT WANT THIS"
        {
            ++num2; //when num3 = 9 and we wanna +1 to num3, we add 1 to num2
            /* so basically
            
            09 + 1 = (0+1)(9 = 0) = 10
            
            */
            if (num2 == '9') // same with what i did for num1, except the last digit of num2 is 8
            {
                ++num1; 
                /*when num2 = 8, add 1+ to num1
                08 + 1 10
                */
                num2 = num1 + 1; //exploit the fact that for every 3 digit number beginning with n, the first non repeating number is  (n n+1 n+2)
            }
            num3 = num2 + 1; //same shit
        }
        
    }

}