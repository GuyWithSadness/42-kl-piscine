#ifndef FT_H
#define FT_H

// input output functions
int		ft_atoi(char *str);
void	ft_putchar(char a);
void	ft_putnbr(int nb);

// operateur determination and error handling
int		math(int x, int y, int(*f)(int, int));
int		calculator(int x, int y, int operate);
int		precheck(int y, int i);
int		find_oper(char *operateur);

// meth
int		add(int x, int y);
int		modulus(int x, int y);
int		divide(int x, int y);
int		multiply(int x, int y);
int		subtract(int x, int y);

#endif
