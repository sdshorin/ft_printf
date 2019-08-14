
// https://docs.oracle.com/cd/E19957-01/806-3568/ncg_math.html
// https://en.wikipedia.org/wiki/Extended_precision

#include "ft_printf.h"

int print_float(t_param **param, va_list ap)
{
	long double n;
	t_long_num num;

	if ((*param)->L != 0)
		n = (long double)va_arg(ap, long double);
	else if ((*param)->l == 0)
		n = (long double)va_arg(ap, double);
	else
		n = (long double)va_arg(ap, double);

	double_to_string(n, &num);

	return put_long_double(param, &num);
}