#include <stdlib.h>

char** initialization(char **a);

void solve ()
{
	int row = 0;
	int col = 0;
	char** real;
	char** possi;
	char fill;

	// generates an array
	real = (char**)malloc(4*sizeof(char*));
	while (row < 4)
	{
		real[row] = (char*) malloc(4*sizeof(char));
		row++;
	}

	row = 0;
	// generates another array
	possi = (char**)malloc(4*sizeof(char*));
	while (row < 4)
	{
		possi[row] = (char*) malloc(4*sizeof(char));
		row++;
	}

	row = 0;
	while (row < 4)
	{
		while (col < 4)
		{
			possi[row][col] = "123";
			col++;
		}
		col = 0;
		row++;
	}

}

char** initialization(char **a)
{
	int row = 0;

	a = (char**)malloc(4*sizeof(char*));
	while (row < 4)
	{
		a[row] = (char*) malloc(4*sizeof(char));
		row++;
	}

	return a;
}

int main()
{
	solve ();
}
