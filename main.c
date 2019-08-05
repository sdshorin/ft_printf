int ft_printf(char*, ...);

#include <stdio.h>
int main ()
{
	char input[] = ".% 029d.%s%i\n";
	ft_printf(input, 1100333334234323101, "second", 11);
	printf(input,1100333334234323101, "second", 11);
}
