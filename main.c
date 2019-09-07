int ft_printf(char*, ...);

#include <stdio.h>
int main ()
{
	char input[] = ".%+ #10.4f.\n";
	double num = 234234.34275;
	int a = ft_printf(input, num);
	int b = printf(input, num);
	ft_printf("ft: %i, or: %i\n", a, b);
}
