int ft_printf(char*, ...);

#include <stdio.h>
int main ()
{
	char input[] = ".%i\n";
	ft_printf(input, 10);
	printf(input,10);
}
