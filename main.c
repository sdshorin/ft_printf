int ft_printf(char*, ...);

#include <limits.h>
#include <stdio.h>
int main ()
{
    //    char input[] = ".%+ #10.4f.\n";
    //    double num = 234234.34275;
	// 	int a = ft_printf("@moulite");
	// 	int b = printf("@moulite");
	ft_printf("\n");
  ft_printf("%ho, %ho\n", 0, USHRT_MAX);
  printf("%ho, %ho\n", 0, USHRT_MAX);
}