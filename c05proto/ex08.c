#include <unistd.h>
#include <stdio.h>

void generate(char *column, unsigned long int number);
int ft_ten_queens_puzzle(void);
int conditions(char *column);
void pos_sol(char *column);

int main()
{
	ft_ten_queens_puzzle();
	printf("end\n");
}

int ft_ten_queens_puzzle(void)
{
	char column[10];
	unsigned long int number;

	number = 9876543210;
	while (number <= 9876543210)
	{
		generate(column, number);
		if (conditions(column) == 1)
			write(1,column,11);
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
	printf("Testing\n");
	while (x < 10)
	{
		check = column[x];
		i = x;
		// go through row
		printf("\nchecking row\n");
		while (++i < 10)
		{
			printf("checking %c and %c\n",check, column[i]);
			if (check == column[i])
				return 0;
		}

		// go through diaganolly (downwards)
		i = 0;
		j = 1;
		printf("\n\nchecking downwards diagonally\n");
		while ((x+j) < 10)
		{
			printf("checking %c and %c\n", column[x + j], check + j);
			if (column[x + j] == check + j)
				return 0;
			j++;
		}
		// go through diagonally (upwards)
		i = -1;
		j = 1;
		printf("\n\nchecking upwards diagonally\n");
		while ((x+j) < 10)
		{
			printf("checking %c and %c\n", column[x + j], check - j);
			if (column[x + j] == check - j)
				return 0;
			j++;
		}
		x++;
	}
	printf("test succeed");
	return 1;
}

void pos_sol(char *column)
{
	//this will basically generate.... something
	//and it should write out the column if it... works....
}

void generate(char *column, unsigned long int number)
{
	int row;
	unsigned long int div;

	row = 9;
	div = 1;
	printf("number to key in %lu\n", number);
	while (row >= 0)
	{
		column[row] = (number%10) + '0';
		number = number / 10;
		row--;
	}
	printf("testing %s\n", column);
}
