#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	(void) argc;

	i = 0;
	// or you can if (argc > 0)
	//{
	while(argv[0][++i] != '\0')
	{
		write(1, &argv[0][i], 1);
	}
	write(1,"\n",1);
	//}
}

//REEEEEEEEEEEEEEEEEEEEEEEE HOW DID I FAIL THISSSSSSSSSSSSSSSSSSSS
