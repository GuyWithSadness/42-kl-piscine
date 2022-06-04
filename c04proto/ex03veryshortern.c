int	ft_atoi(char *str);

// laian's code, thanks laian
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi("-12312"));
	printf("%d\n", ft_atoi("--wada+-12312"));
	printf("%d\n", ft_atoi("wadawd-12312"));
	printf("%d\n", ft_atoi("-12awdawd312"));
	printf("%d\n", ft_atoi("-+++12312"));
	printf("%d\n", ft_atoi("--12312"));
	printf("%d\n", ft_atoi("   --+-12312"));
}

int        ft_atoi(char *str)
{
    int n;
    int sign;
    int rtval;

    n = 0;
    sign = 1;
    rtval = 0;
    while ( str[n] == ' ' || (str[n] >= 9 && str[n] <= 13))
        ++n;
    while ( str[n] == '+' || str[n] == '-')
        if(str[n++] == '-')
            sign *= -1;
    while (str[n] >= '0' && str[n] <= '9')
        rtval = (rtval * 10) + (str[n++] - '0');
    return (rtval * sign);
}
