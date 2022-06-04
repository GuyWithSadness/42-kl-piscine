#include <unistd.h>
#include "EpicFunctions.h"

int main(int argc, char *argv[])
{
	/* int	i;
	int	nonumber;

	if (argc > 2)
	{
		write(1, "You Wrote Too Much Arguments\n", 29);
		return 0;
	}
	if (argc < 2)
	{
		write(1, "You Forgot To Put In Arguments\n", 31);
		return 0;
	}
	i = 0;
	nonumber = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			if(argv[1][i] >= '1' && argv[1][i++] <= '4')
			{
				nonumber++;
			}
			else
			{
				write(1, "1 <= x <= 4 only\n", 17);
				return 0;
			}
		}
		else if (argv[1][i++] == ' ')
			continue;
		else
		{
			write(1, "Only Numbers Allowed\n", 21);
			return 0;
		}
	}

	if (nonumber > 16)
	{
		write(1, "Too much input\n", 15);
		return 0;
	}
	else if (nonumber < 16)
	{
		write(1, "Not Enough Input\n", 17);
		return 0;
	} */

	write(1, "Generating...\n", 13);
	char a[] = "1 2 4 2 4 2 1 2 1 2 2 3 2 1 3 2";
	generate(a);
	// generate(argv[1]); disabled for testing
}


