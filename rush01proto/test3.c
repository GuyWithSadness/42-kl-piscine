void generate();
void printarray(char** a);
int existed(char a, char *b[], int rowN, int colN);

#include <stdlib.h>
#include <unistd.h>

void generate()
{
	int row = 0;
	int col = 0;
	char** a;
	char fill;

	// generates an array
	a = (char**)malloc(4*sizeof(char*));
	while (row < 4)
	{
		a[row] = (char*) malloc(4*sizeof(char));
		row++;
	}

	row = 0;
	//Fill array with random numbers
	while (row < 4)
	{
		while (col < 4)
		{
			fill = '1';
			while (fill <= '4')
			{
				if (existed(fill, a ,row, col) == 0)
				{
					a[row][col] = fill;
					break;
				}
				fill++;
			}

			col++;
		}
		col = 0;
		row++;
	}

	col = 0;
	row = 0;
	printarray(a);
}

int existed(char a, char *b[], int rowN, int colN)
{
	int row = 0;
	while (row < 4)
	{
		if (a == b[row][colN])
			return 1;
		row++;
	}
	int col = 0;
	while (col < 4)
	{
		if (a == b[rowN][col])
			return 1;
		col++;
	}

	return 0;
}

void printarray(char** a)
{
	int row = 0;
	int col = 0;
	write(1, "\n", 1);
	while (row < 4)
	{
		while (col < 4)
		{
			write(1, &a[row][col], 1);
			write(1," ",1);
			col++;
		}
		write(1, "\n", 1);
		col = 0;
		row++;
	}
}

int main()
{
	generate();
}
