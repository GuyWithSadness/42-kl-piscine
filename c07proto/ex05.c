#include <stdlib.h>
char	**ft_split(char *str, char *charset);

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
	int i;
	int sets;
	char **splitted;
	int j;
	int firstsep;

	// calculate how many sets
	firstsep = 0;
	sets = 0;
	i = 0;
	while(str[i])
	{
		j = 0;
		while(charset[j])
		{
			if (str[i] == charset[j] && firstsep == 0)
			{
				printf("found 1st %c in %dth letter\n", charset[j], i);
				firstsep = 1;
				break;
			}
			else if (str[i] == charset[j] && firstsep == 1)
			{
				printf("found 2nd %c in %dth letter\n", charset[j], i);
				sets++;
				firstsep = 0;
				break;
			}
			j++;
		}
		i++;
	}
	// allocate memory for all sets found

	printf("Found %i of sets\n", sets);
	splitted = (char **) malloc ((sets + 1) * sizeof(char *));
	printf("Allocated %d arrays for splitted array\n\n", (sets+1));

	// calculate and allocate memory for the array or something
	int x;
	i = 0;
	j = 0;
	x = 0;
	firstsep = 0;
	int startcounting;
	int wordlength;
	wordlength = 0;
	while(str[i])
	{
		j = 0;
		while(charset[j])
		{
			if (str[i] == charset[j] && firstsep == 0)
			{
				printf("found 1st %c in %dth letter\n", charset[j], i);
				firstsep = 1;
				startcounting = 1;
				break;
			}
			else if (str[i] == charset[j] && firstsep == 1)
			{
				printf("found 2nd %c in %dth letter\n", charset[j], i);
				wordlength++;
				firstsep = 0;
				startcounting = 2;
				break;
			}
			j++;
		}
		if (startcounting == 1)
		{
			printf("%c isnt a seperator, digit = %d\n", str[i], i);
			wordlength++;
			printf("wordlength is now = %d\n", wordlength);
		}
		if (startcounting == 2)
		{
			printf("%dth set length is %d\n",x , wordlength);
			splitted[x] = (char *) malloc (wordlength + 1 * sizeof(char));
			printf("Allocated %d of char memory for %dth array\n", wordlength+1 , x);
			wordlength = 0;
			startcounting = 0;
			x++;
		}
		i++;
	}
	//allocate the last one with the size of 1;
	printf("Allocated 1 char memory for %dth array\n\n", x);
	splitted[x] = (char *) malloc (1 * sizeof(char));
	// copy the sets into the allocated memory (please kill me)
	int recording;
	recording = 0;
	i = 0;
	j = 0;
	x = 0;
	sets = 0;
	firstsep = 0;
	while(str[i])
	{
		j = 0;
		while(charset[j])
		{
			if (str[i] == charset[j] && firstsep == 0)
			{
				printf("found 1st %c in %dth letter, started copying...\n", charset[j], i);
				recording = 1;
				firstsep = 1;
			}
			else if (str[i] == charset[j] && firstsep == 1)
			{
				printf("found 2nd %c in %dth letter, stop copying...\n", charset[j], i);
				firstsep = 0;
				recording = 2;
			}
			j++;
		}
		if (recording == 1)
		{
			printf("copied %c in %d of %dth array\n", str[i], x, sets);
			splitted[sets][x] = str[i];
			x++;
		}
		else if (recording == 2)
		{
			printf("copied %c in %d of %dth array\n", str[i], x, sets);
			splitted[sets][x] = str[i];
			printf("Placed \\0 in %d letter of %dth array\n", x+1, sets);
			splitted[sets][x+1] = '\0';
			sets++;
			x = 0;
			recording = 0;
		}
		i++;
	}

	// uhh "The last element of that array should equal to 0 to indicate the end of the array"
	printf("%dth array is 0\n", sets);
	splitted[sets][0] = 0;

	return (splitted);
}


// char	**ft_split(char *str, char *charset)
// {
// 	char **splitted;

// 	int i;
// 	int j;
// 	int sets;
// 	int firstsep;
// 	firstsep = 0;
// 	sets = 0;
// 	i = -1;
// 	while(str[++i])
// 	{
// 		j = -1;
// 		while(charset[++j])
// 		{
// 			if (str[i] == charset[j] && firstsep == 0)
// 			{
// 				firstsep = 1;
// 				break;
// 			}
// 			else if (str[i] == charset[j] && firstsep == 1)
// 			{
// 				sets++;
// 				firstsep = 0;
// 				break;
// 			}
// 		}
// 	}
// 	splitted = (char **) malloc ((sets + 1) * sizeof(char *));

// 	int x;
// 	int startcounting;
// 	int wordlength;
// 	i = 0;
// 	j = 0;
// 	x = 0;
// 	firstsep = 0;
// 	wordlength = 0;
// 	while(str[i])
// 	{
// 		j = 0;
// 		while(charset[j])
// 		{
// 			if (str[i] == charset[j] && firstsep == 0)
// 			{
// 				firstsep = 1;
// 				startcounting = 1;
// 				break;
// 			}
// 			else if (str[i] == charset[j] && firstsep == 1)
// 			{
// 				wordlength++;
// 				firstsep = 0;
// 				startcounting = 2;
// 				break;
// 			}
// 			j++;
// 		}
// 		if (startcounting == 1)
// 			wordlength++;
// 		if (startcounting == 2)
// 		{
// 			splitted[x] = (char *) malloc (wordlength + 1 * sizeof(char));
// 			wordlength = 0;
// 			startcounting = 0;
// 			x++;
// 		}
// 		i++;
// 	}
// 	splitted[x] = (char *) malloc (1 * sizeof(char));

// 	int recording;
// 	recording = 0;
// 	i = 0;
// 	j = 0;
// 	x = 0;
// 	sets = 0;
// 	firstsep = 0;
// 	while(str[i])
// 	{
// 		j = 0;
// 		while(charset[j])
// 		{
// 			if (str[i] == charset[j] && firstsep == 0)
// 			{
// 				recording = 1;
// 				firstsep = 1;
// 			}
// 			else if (str[i] == charset[j] && firstsep == 1)
// 			{
// 				firstsep = 0;
// 				recording = 2;
// 			}
// 			j++;
// 		}
// 		if (recording == 1)
// 		{
// 			splitted[sets][x] = str[i];
// 			x++;
// 		}
// 		else if (recording == 2)
// 		{
// 			splitted[sets][x] = str[i];
// 			splitted[sets][x+1] = '\0';
// 			sets++;
// 			x = 0;
// 			recording = 0;
// 		}
// 		i++;
// 	}

// 	splitted[sets][0] = 0;
// 	return (splitted);
// }
