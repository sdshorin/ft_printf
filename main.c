int ft_printf(char*, ...);



#define TEST ("%f", (long double)-0)
#include <stdio.h>
int main ()
{
       char input[] = ".%+ #10.4f.\n";
       double num = 234234.34275;
	   
		int a = ft_printf TEST ;
		printf("\n");
		int b = printf TEST ;
		printf("\n");
		printf("%d  %d\n", a, b);
}