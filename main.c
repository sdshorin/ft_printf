int ft_printf(char*, ...);

#include <stdio.h>
int main ()
{
	char input[] = "II%.cII\n";
	ft_printf(input, 'A');
	printf(input, 'A');
}
