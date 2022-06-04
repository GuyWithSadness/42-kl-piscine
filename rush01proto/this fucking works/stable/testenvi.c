#include <unistd.h>
#include <stdlib.h>

void generate(char* argv);
void printarray(char** a);
char** rando(int frow, int srow, int trow, int forow, char **a);
int runtest(char **e, char *argc, int b, int c, int d);
int con_cold(char **a, int col, char argv);
int con_colu(char **a, int col, char argv);
int con_col(char **a, char *argv);
int con_rowl(char **a, int row, char argv);
int con_rowr(char **a, int row, char argv);
int con_row(char **a, char *argv);
int duplicatecol(char** a);
int logic(char**a, char *argc);

int main()
{
	char a[31] = "1 3 3 2 4 1 2 2 1 2 3 2 2 1 2 3";
	printf("Generating\n");
	generate(a);
}


void generate(char* argv)
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

	if (runtest(a, argv, -1, -1, -1) == 1)
		printarray(a);
	else
		write(1, "I Dont Think There Are Answer For This\n", 39);
}

void printarray(char** a)
{
	//print array
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

char** rando(int frow, int srow, int trow, int forow, char **a) //this works
{
	//HOPEFULLY, randoms the array (not sure if will work anot)
	int row = 0;
	char *possible[24]= { "1234", "1324", "1423", "1342", "1243",
		"1432", "2134", "2341", "2314", "2413",
		"2431", "2143", "3124", "3142", "3214",
		"3241", "3412", "3421", "4123", "4132",
		"4231", "4213", "4321", "4312" };
	a[0] = possible[frow];
	a[1] = possible[srow];
	a[2] = possible[trow];
	a[3] = possible[forow];
	return a;
}



int runtest(char **e, char *argv, int b, int c, int d) //just to run those test and to randomize the whatsthatcalled
{
	int a;

	a = -1;
	while (++a != 24)
	{
		while (++b != 24)
		{
			while (++c != 24)
			{
				while (++d != 24)
				{
					e = rando(a,b,c,d,e);
					if (logic(e, argv) == 1)
					{
						return 1;
					}
				}
				d = -1;
			}
			c = -1;
		}
		b = -1;
	}
	return a;
}

int con_cold(char **a, int col, char argv) //check seen from down
{
	int count;
	int countrow;
	int comparerow;
	char cansee;

	countrow = 3;
	comparerow = 2;
	cansee = '1';
	while(comparerow >= 0)
	{
		if (a[countrow][col] == '4')
			break;
		if (a[countrow][col] < a[comparerow][col])
		{
			countrow = comparerow;
			cansee++;
		}
		comparerow--;
	}
	if (cansee == argv)
		return 1;
	return 0;
}

int con_colu(char **a, int col, char argv) //check seen from up
{
	int count;
	int countrow;
	int comparerow;
	char cansee;

	comparerow = 1;
	countrow = 0;
	cansee = '1';
	while(comparerow <= 3)
	{
		if (a[countrow][col] == '4')
			break;
		if (a[countrow][col] < a[comparerow][col])
		{
			countrow = comparerow;
			cansee++;
		}
		comparerow++;
	}
	if (cansee == argv)
		return 1;
	return 0;
}

int con_col(char **a, char *argv) //check seen from up and down for all columns (i hope)
{
	int i;
	int countcol;
	countcol = 0;
	i = 0;
	while(i <= 6)
	{
		if( (con_colu(a, countcol, argv[i])) == 0)
			return 0;
		countcol++;
		i+=2;
	}
	countcol = 0;
	while(i <= 14)
	{
		if( (con_cold(a, countcol , argv[i])) == 0)
			return 0;
		countcol++;
		i+=2;
	}
	return 1;
}



int con_rowl(char **a, int row, char argv) //check seen from left
{
	int count;
	int countcol;
	int comparecol;
	char cansee;

	countcol = 0;
	comparecol = 1;
	cansee = '1';
	while(comparecol <= 3)
	{
		if (a[row][countcol] == '4')
			break;
		if (a[row][countcol] < a[row][comparecol])
		{
			cansee++;
			countcol = comparecol;
		}
		comparecol++;
	}
	if (cansee == argv)
		return 1;
	return 0;
}

int con_rowr(char **a, int row, char argv) //check seen from right
{
	int count;
	int countcol;
	int comparecol;
	char cansee;

	countcol = 3;
	comparecol = 2;
	cansee = '1';
	while(comparecol >= 0)
	{
		if (a[row][countcol] == '4')
			break;
		if (a[row][countcol] < a[row][comparecol])
		{
			cansee++;
			countcol = comparecol;
		}
		comparecol--;
	}
	if (cansee == argv)
		return 1;
	return 0;
}

int con_row(char **a, char *argv) //check seen from left and right for all rows (i hope)
{
	int i;
	int countrow;
	countrow = 0;
	i = 16;
	while(i <= 22)
	{
		if((con_rowl(a, countrow , argv[i])) == 0)
			return 0;
		countrow++;
		i+=2;
	}
	countrow = 0;
	while(i <= 30)
	{
		if((con_rowr(a, countrow , argv[i])) == 0)
			return 0;
		countrow++;
		i+=2;
	}
	return 1;
}

int duplicatecol(char** a)
{
	int row;
	int rowcompare;
	int col;

	row = 0;
	rowcompare = 1;
	col = 0;
	while (col < 4)
	{
		while (row < 3)
		{
			while (rowcompare < 4)
			{
				if (a[row][col] == a[rowcompare][col])
				{
					return 1;
				}
				rowcompare++;
			}
			row++;
			rowcompare = row + 1;
		}
		col++;
		row = 0;
		rowcompare = 1;
	}
	return 0;
}

int logic(char**a, char *argc) //HOPEFULLY, checks everything
{
	if (duplicatecol(a) == 1)
		return 0;
	if (con_row(a, argc) == 0)
		return 0;
	if (con_col(a, argc) == 0)
		return 0;
	return 1;
}
