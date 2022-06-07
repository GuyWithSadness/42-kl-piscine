#include "ft.h"

int main(int ac, char **av)
{
	if (ac != 4)
		return (4);
}

int (*operators[5])(int, int);
operators[1] = add;
operators[2] = subtract;
