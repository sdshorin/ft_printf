int ft_printf(char*, ...);

#include <stdio.h>
int main ()
{
	char input[] = ".% #-19.18o.\n";
	int a = ft_printf(input, -1113);
	int b = printf(input,-1113);
	ft_printf("ft: %i, or: %i\n", a, b);
}
