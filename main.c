int ft_printf(char*, ...);

#include <stdio.h>
int main ()
{
	char input[] = "II%0-400.30pII\n";
	ft_printf(input, input);
	printf(input, input);
}
