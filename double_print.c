
#include "ft_printf.h"

int get_double_num_size(t_param **param, t_long_num *num)
{
	int size = 0;
	if (num->sig || (*param)->plus)
		size++;
	if ((*param)->precision > 0)
		size += 1 + (*param)->precision;
	size += ft_strlen(num->num) - num->point;
}

int print_double_prenum(t_param **param, t_long_num *num)
{

}

int put_long_double(t_param **param, t_long_num *num)
{
	int len;

	if (num->inf || num->nan)
		return print_double_nan_inf(param, num);
	len = get_double_num_size(param, num);
	if ((*param)->minimum_size < len)
		return (print_long_double(param, num));
	if ((*param)->minus)
	{
		print_double_prenum(param, num);
		print_long_double(param, num);
		ft_write_char_many(' ',(*param)->minimum_size - len);
		return ((*param)->minimum_size);
	}
	put_long_double_whide(param, num);
	return ((*param)->minimum_size);
}

int put_long_double_whide(t_param **param, t_long_num *num){
	int len;

	len = get_double_num_size(param, num);
	if ((*param)->zero)
	{
		print_double_prenum(param, num);
		ft_write_char_many('0',(*param)->minimum_size - len);
		print_long_double(param, num);
		return (len);
	}
	ft_write_char_many(' ',(*param)->minimum_size - len);
	print_double_prenum(param, num);
	print_long_double(param, num);
	return (len);
}

int print_long_double(t_param **param, t_long_num *num)
{
	int i;

	i = LONG_NUM - 1;
	while (i >= 0 && i >= num->point - (*param)->precision)
	{
		if (num->num[i])
			ft_putchar(num->num[i]);
		else if (i <= num->point)
			ft_putchar('0');
		if (i == num->point && (*param)->precision)
			ft_putchar('.');
		i--;
	}
	if ((*param)->precision - num->point > 0)
		ft_write_char_many('0',(*param)->precision - num->point > 0);
	return get_double_num_size(param, num);
}