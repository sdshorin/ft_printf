
// https://docs.oracle.com/cd/E19957-01/806-3568/ncg_math.html
// https://en.wikipedia.org/wiki/Extended_precision

#include "ft_printf.h"



int round_double(t_long_num *num, int position){
	int start;
	int rounding_num;

	start = num->point - position - 1;
	rounding_num = start + 1;
	if (num->num[start] != '5')
		return (0);
	while (start >= 0)
	{
		if (num->num[start] > '0')
			return (num->num[rounding_num]++);
		//else if (num->num[start] < '5')
		//	return (0);
		start--;
	}
	if ((num->num[rounding_num] - '0' + 1) % 2 == 0)
		return (num->num[rounding_num]++);
	else
		return (num->num[rounding_num]--);
	return (0);
}




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
	if ((*param)->precision == -1)
		(*param)->precision = 6;
	double_to_string(n, &num);
	if (num.point > (*param)->precision)
	{
		round_double(&num, (*param)->precision);
	}
	return put_long_double(param, &num);
}