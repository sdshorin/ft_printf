
#include "ft_printf.h"


int print_percent(t_param **param)
{
	if ((*param)->minus)
		ft_putchar('%');
	if ((*param)->minimum_size > 0)
		ft_write_char_many(' ', (*param)->minimum_size  - 1);
	if (!(*param)->minus)
		ft_putchar('%');
	if ((*param)->minimum_size > 0)
		return ((*param)->minimum_size);
	return (1);
}