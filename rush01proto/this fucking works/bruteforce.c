#include "EpicFunctions.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void generate(char* argv);
void printarray(char** a);
char** rando(int frow, int srow, int trow, int forow, char **a);
int runtest(char **e, char *argc, int b, int c, int d);

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

