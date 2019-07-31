int ft_printf(char*, ...);

#include <stdio.h>
int main ()
{
	char input[] = "II%-3.2sII\n";
	ft_printf(input, "abcdefg");
	printf(input, "abcdefg");
}
