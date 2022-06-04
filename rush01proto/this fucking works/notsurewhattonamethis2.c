int con_cold(char **a, int col, char argv);
int con_colu(char **a, int col, char argv);
int con_col(char **a, char *argv);

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
