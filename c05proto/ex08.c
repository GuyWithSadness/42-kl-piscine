#include <stdio.h>
int ft_ten_queens_puzzle(void);

int main()
{
	ft_ten_queens_puzzle();
}

int ft_ten_queens_puzzle(void)
{
	// work in progress, might not check it like this
	char column[10];

	//idk
	int col;
	char row;

	row = '0';

	// runs as long as the queen isnt at the last row or sum
	while (row <= '9')
	{
		column[0] = row;
		pos_sol(column);
		row++;
	}
}

int conditions(void)
{
	// go through row
	// go through column
	// go through diaganolly
	// go through another diagonally
	// feel like this way is shit idk
}

void pos_sol(char *column)
{
	//this will basically generate.... something
	//and it should write out the column if it... works....
}
