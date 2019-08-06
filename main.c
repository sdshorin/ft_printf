int ft_printf(char*, ...);

#include <stdio.h>
int main ()
{
	char input[] = ".% #010X.\n";
	int a = ft_printf(input, 987);
	int b = printf(input, 987);
	ft_printf("ft: %i, or: %i\n", a, b);
}
