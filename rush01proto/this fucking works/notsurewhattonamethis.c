int con_rowl(char **a, int row, char argv);
int con_rowr(char **a, int row, char argv);
int con_row(char **a, char *argv);


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
