#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	ft_putstr_base16(char *str, char *base16);
void	ft_putstr_non_printable(char *str);
void	ft_memory_address(void *addr, char *base16);
void	reverse(char *a);

int main()
{
	ft_print_memory("Bonjour les amin", 4);
	ft_print_memory("ches...c est fo", 4);
	ft_print_memory("u.tout.ce qu on", 4);
	ft_print_memory("peut faire avec.", 4);
	ft_print_memory("..print_memory\n\n", 4);
	ft_print_memory("..lol.lol. .", 4);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char *base16;

	base16 = "0123456789abcdef";
	if (size == 0)
		return 0;
	ft_memory_address(addr, base16);
	write(1, ":", 1);
	write(1, " ", 1);
	ft_putstr_base16(addr, base16);
	ft_putstr_non_printable(addr);
	write(1, "\n", 1);

	return (addr);
}

void	ft_memory_address(void *addr, char *base16)
{
	long int	address;
	int			i;
	char		a[16];

	i = -1;
	while (++i < 16)
		a[i] = '0';
	address = &addr[0];
	i = -1;
	while (address > 16)
	{
		a[++i] = base16[address%16];
		address = address / 16;
	}
	a[++i] = base16[address%16];
	reverse(a);
	write(1, a, 16);

	printf("Test (%p %x %li) ", &addr[0], &addr[0], &addr[0]);
}

void	reverse(char *a)
{
	int i;
	char temp;

	i = -1;
	while (++i < (16 / 2))
	{
		temp = a[0 + i];
		a[0 + i] = a[15 - i];
		a[15 - i] = temp;
	}
}

void	ft_putstr_base16(char *str, char *base16)
{
	int		n;

	n = -1;
	while (++n < 16 && str[n])
	{
		if (n == 16)
			break;
		write(1, &base16[(str[n])/16], 1);
		write(1, &base16[(str[n])%16], 1);
		if (n % 2 == 1)
			write(1," ",1);
	}
	if (n % 2 == 1 && n++)
	{
		write(1, "0", 1);
		write(1, "0", 1);
		write(1, " ", 1);
	}
	while (n++ < 16)
	{
		write(1," ",2);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		n;

	n = -1;
	while (str[++n] && n <= 16)
	{
		if (str[n] < 32 || str[n] > 126)
		{
			write(1, ".", 1);
		}
		else
			write(1, &str[n], 1);
	}
}
