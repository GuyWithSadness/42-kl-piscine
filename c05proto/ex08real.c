#include <unistd.h>
#include <stdio.h>

void generate(char *column, unsigned long int number);
int ft_ten_queens_puzzle(void);
int conditions(char *column);

int main()
{
	ft_ten_queens_puzzle();
	printf("end\n");
}

int ft_ten_queens_puzzle(void)
{
	char column[10];
	unsigned long int number;

	number = 257948136;
	while (number <= 9742051863)
	{
		generate(column, number);
		if (conditions(column) == 1)
		{
			write(1,column,10);
			write(1,"\n",1);
		}
		number++;
	}
	return 1;
}

int conditions(char *column)
{
	char check;
	int i;
	int x;
	int j;

	x = 0;
	while (x < 10)
	{
		check = column[x];
		i = x;
		// go through row
		while (++i < 10)
		{
			if (check == column[i])
				return 0;
		}

		// go through diaganolly (downwards)
		i = 0;
		j = 1;
		while ((x+j) < 10)
		{
			if (column[x + j] == check + j)
				return 0;
			j++;
		}
		// go through diagonally (upwards)
		i = -1;
		j = 1;
		while ((x+j) < 10)
		{
			if (column[x + j] == check - j)
				return 0;
			j++;
		}
		x++;
	}
	return 1;
}

void generate(char *column, unsigned long int number)
{
	int row;
	unsigned long int div;

	row = 9;
	div = 1;
	while (row >= 0)
	{
		column[row] = (number%10) + '0';
		number = number / 10;
		row--;
	}
}
