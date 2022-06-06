#include <stdio.h>
#include <unistd.h>
int main()
{
	char a[10] = "abcdefg";
	char* ptr;
	ptr = &a[0];

	for (ptr; ptr <= &a[9] ; ptr++)
		write(1,ptr,1);
}
