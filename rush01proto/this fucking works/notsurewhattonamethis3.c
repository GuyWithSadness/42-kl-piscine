#include "notsurewhattonamethis2.c"
#include "notsurewhattonamethis.c"

int duplicatecol(char** a);
int logic(char**a, char *argc);

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
