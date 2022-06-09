#include "ft.h"

int	calculator(int x, int y, int operate)
{
	int	(*operations[5])(int x, int y);

	operations[0] = add;
	operations[1] = subtract;
	operations[2] = multiply;
	operations[3] = divide;
	operations[4] = modulus;
	return (math(x, y, operations[operate]));
}

int	math(int x, int y, int(*f)(int x, int y))
{
	return (f(x, y));
}
