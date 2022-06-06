#include <stdlib.h>
char	**ft_split(char *str, char *charset);

int x;
int i;
int j;
int firstsep;

#include <stdio.h>
int main()
{
	char** test;
	test = ft_split("5adaw15a5w1d5a1d2aw1d21aw3d1a3wd1", "0123456789");
	for (int i = 0; i <= 10; i++)
		printf("%s\n",test[i]);
}

char	**ft_split(char *str, char *charset)
{
	int sets;
	char **splitted;

	sets = countsets(str, charset);
	splitted = (char **) malloc ((sets + 1) * sizeof(char *));
	int startcounting;
	int wordlength;

	i = 0;
	j = 0;
	x = 0;
	firstsep = 0;
	wordlength = 0;
	while (str[++i])
	{
		j = -1;
		while(charset[++j])
		{
			if (str[i] == charset[j] && firstsep == 0)
			{
				firstsep = 1;
				startcounting = 1;
				break;
			}
			else if (str[i] == charset[j] && firstsep == 1)
			{
				wordlength++;
				firstsep = 0;
				startcounting = 2;
				break;
			}
		}
		if (startcounting == 1)
			wordlength++;
		if (startcounting == 2)
		{
			splitted[x] = (char *) malloc (wordlength + 1 * sizeof(char));
			wordlength = 0;
			startcounting = 0;
			x++;
		}
	}

	return (splitted);
}

int countsets(char *str, char *charset)
{
	int sets;

	firstsep = 0;
	sets = 0;
	i = -1;
	while(str[++i])
	{
		j = -1;
		while(charset[++j])
		{
			if (str[i] == charset[j] && firstsep == 0)
			{
				firstsep = 1;
				break;
			}
			else if (str[i] == charset[j] && firstsep == 1)
			{
				sets++;
				firstsep = 0;
				break;
			}
		}
	}
	return (sets);
}

int countword(char **splitted, char *str, char *charset)
{
}

void	ft_cpyarray(char **splitted, char *str, char *charset)
{
	int recording;
	int sets;

	recording = 0;
	i = 0;
	j = 0;
	x = -1;
	sets = 0;
	firstsep = 0;
	while(str[++i])
	{
		j = -1;
		while(charset[++j])
		{
			if (str[i] == charset[j] && firstsep == 0)
			{
				recording = 1;
				firstsep = 1;
				break;
			}
			else if (str[i] == charset[j] && firstsep == 1)
			{
				firstsep = 0;
				recording = 2;
				break;
			}
		}
		if (recording == 1)
			splitted[sets][x++] = str[i];
		else if (recording == 2)
		{
			splitted[sets][x+1] = '\0';
			sets++;
			x = 0;
			recording = 0;
		}
	}
	splitted[sets][0] = 0;
	return (splitted);
}

