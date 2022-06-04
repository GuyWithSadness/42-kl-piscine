void generate(char* argv);
void printarray(char** a);
char** rando(int frow, int srow, int trow, int forow, char **a);
int logic(char**a, char *argc);
int runtest(char **e, char *argc, int b, int c, int d);
int con_cold(char **a, int col, char argv);
int con_colu(char **a, int col, char argv);
int con_col(char **a, char *argv);
int con_rowl(char **a, int row, char argv);
int con_rowr(char **a, int row, char argv);
int con_row(char **a, char *argv);
int duplicate(char** a);
int duplicatecol(char** a);

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char a[31] = "2 2 1 3 1 2 3 2 2 2 3 1 2 2 1 3";
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

	row = 0;

	//Fill array with placeholder letter
	while (row < 4)
	{
		while (col < 4)
		{
			a[row][col] = 'E';
			col++;
		}
		col = 0;
		row++;
	}
	printf("made a placeholder array\n");
	printf("Begin Cracking\n");

	if (runtest(a, argv, 0, 1, 2) == 1)
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
	a[0] = possible[15];
	a[1] = possible[2];
	a[2] = possible[6];
	a[3] = possible[23];
	printf("\nArray to test: \n");
	printarray(a);
	return a;
}

int logic(char**a, char *argc) //HOPEFULLY, checks everything
{
	printf("checking logic\n");
	printf("checking duplicates\n");
	if (duplicatecol(a) == 1)
		return 0;
	printf("checking row logic\n");
	if (con_row(a, argc) == 0)
		return 0;
	printf("checking col logic\n");
	if (con_col(a, argc) == 0)
		return 0;
	return 1;
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
						printf("Found it!\n");
						return 1;
					}
					printf("Aw That didnt work\n");
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
	printf("Checking down\n");
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
		{
			break;
		}
		printf("comparing...%c with %c\n", a[countrow][col], a[comparerow][col]);
		if (a[countrow][col] < a[comparerow][col])
		{
			countrow = comparerow;
			cansee++;
		}
		comparerow--;
	}
	printf("%c\n", cansee);
	if (cansee == argv)
		return 1;
	return 0;
}

int con_colu(char **a, int col, char argv) //check seen from up
{
	printf("Checking up\n");
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
		printf("comparing...%c with %c\n", a[countrow][col], a[comparerow][col]);
		if (a[countrow][col] < a[comparerow][col])
		{
			countrow = comparerow;
			cansee++;
		}
		comparerow++;
	}
	printf("%c\n", cansee);
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
	printf("checking left\n");
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
		printf("comparing...%c with %c\n", a[row][countcol], a[row][comparecol]);
		if (a[row][countcol] < a[row][comparecol])
		{
			cansee++;
			countcol = comparecol;
		}
		comparecol++;
	}
	printf("%c\n", cansee);
	if (cansee == argv)
		return 1;
	return 0;
}

int con_rowr(char **a, int row, char argv) //check seen from right
{
	printf("checking right\n");
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
		printf("comparing...%c with %c\n", a[row][countcol], a[row][comparecol]);
		if (a[row][countcol] < a[row][comparecol])
		{
			cansee++;
			countcol = comparecol;
		}
		comparecol--;
	}
	printf("%c\n", cansee);
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
		printf("checking %d row\n", countrow);
		if((con_rowl(a, countrow , argv[i])) == 0)
			return 0;
		countrow++;
		i+=2;
	}
	countrow = 0;
	while(i <= 30)
	{
		printf("checking %d row\n", countrow);
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
		printf("at column %d\n", col);
		while (row < 3)
		{
			while (rowcompare < 4)
			{
				printf("seeing %c and %c\n", a[row][col], a[rowcompare][col]);
				if (a[row][col] == a[rowcompare][col])
				{
					printf("duplicate found!");
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
