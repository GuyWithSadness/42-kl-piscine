#include "ft.h"
int calculator(int x, int y, int operate)
{
	int (*operations[5]) (int, int);

	operations[0] = add;
	operations[1] = subtract;
	operations[2] =	multiply;
	operations[3] = divide;
	operations[4] = modulus;
	return math(x, y, operations[operate]);
}

int math(int x, int y, int(*f)(int, int))
{
	return(f(x,y));
}

int add(int x, int y)
{
	return (x + y);
}

int modulus(int x, int y)
{
	return (x % y);
}

int divide(int x, int y)
{
	return (x / y);
}

int multiply(int x, int y)
{
	return (x * y);
}

int subtract(int x, int y)
{
	return (x - y);
}
