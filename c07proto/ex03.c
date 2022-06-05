#include <stdlib.h>
char	*ft_strjoin(int size, char **strs, char *sep);

#include <stdio.h>
int main()
{
	char *strs[] = {
						"pasta",
						"pasta",
						"pasta",
						"pasta",
						"pasta",
						"pasta",
					};
	char sep[] = " pizza ";
	printf("%s", ft_strjoin(6, strs, sep));
}

//size is number of strings in strs
char	*ft_strjoin(int size, char **strs, char *sep)
{
	printf("you entered the function lol\n");
	char *fullstr;
	int totallengthstrs;
	int totallength;
	int lengthofsep;
	int neededsep;
	int i;
	totallengthstrs = 0;
	int lines;
	lines = 0;
	// strs[lines][words]
	while (lines < size)
	{
		i = 0;
		while (strs[lines][i] != '\0')
		{
			totallengthstrs++;
			i++;
		}
		printf("Total length of string = %d\n", totallengthstrs);
		lines++;
	}
	//find length of sep
	lengthofsep = 0;
	while (sep[lengthofsep] != '\0')
	{
		lengthofsep++;
	}
	printf("Total length of seperation = %d\n", lengthofsep);
	neededsep = size - 1;
	int totallengthofsepneeded = lengthofsep * neededsep;
	// "strs""seps""strs""seps""strs"
	totallength = totallengthofsepneeded + totallengthstrs + 1;
	fullstr = (char *) malloc (totallength * sizeof(char));

	lines = 0;
	i = 0;
	int j;
	while (lines < size)
	{
		j = 0;
		while (strs[lines][j] != '\0')
		{
			fullstr[i] = strs[lines][j];
			i++;
			j++;
		}
		j = 0;
		if (lines != size - 1)
		{
			while (sep[j] != '\0')
			{
				fullstr[i] = sep[j];
				i++;
				j++;
			}
		}
		lines++;
	}
	fullstr[i] = '\0';
	return fullstr;
}
