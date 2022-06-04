#include <unistd.h>
int main(int argc, char *argv[])
{
	int i;
	int count;

	count = argc;
	i = -1;


	while (--count > 0)
	{
		while (argv[count][++i] != '\0')
		{
			write(1, &argv[count][i], 1);
		}
		write(1, "\n", 1);
		i = -1;
	}
}
