int ft_printf(char*, ...);

#include <stdio.h>
int main ()
{
	char input[] = ".%f.\n";
	int a = ft_printf(input, -1987.14);
	int b = printf(input, -1987.14);
	ft_printf("ft: %i, or: %i\n", a, b);
}
