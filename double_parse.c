


#include "ft_printf.h"

void get_e_and_sig(long double num, int *e, int *sig)
{
	unsigned char *bits;
	
	bits = (unsigned char*)(void*)&num;
	bits += 8;
	*e = *bits;
	bits++;
	*e += (*bits - (*bits & 128)) * 256;
	*sig = *bits & 128;
}

void parse_f(long double d_num, t_long_num *l_num)
{
	int i;
	int j;
	unsigned char *bits;

	bits = ((unsigned char*)(void*)&d_num) + 7;
	i = 0;
	while (i < 8)
	{
		j = 7;
		while (j >= 0)
		{
			long_comput_mult_two(l_num);
			if (*bits >> j & 1)
				long_comput_add_dig(l_num->num, 0, 1);
			j--;
		}
		bits--;
		i++;
	}
}

int is_double_inf_or_nan(int e, t_long_num *num)
{
	// TO DO


	if (0)
	{
		num->nan = 1;
		num->inf = 1;
		return (1);
	}
	else
	{
		num->nan = 0;
		num->inf = 0;
	}
	return (0);
}

void double_to_string(long double d_num, t_long_num *l_num)
{
	int e;

	ft_memset(l_num->num, '\0', LONG_NUM);
	l_num->point = 0;
	get_e_and_sig(d_num, &e, &(l_num->sig));
	parse_f(d_num, l_num);
	if (is_double_inf_or_nan(e, l_num))
		return ;
	e -= 16383 + 63;
	while (e != 0)
	{
		if (e > 0)
		{
			long_comput_mult_two(l_num);
			e--;
		}
		else
		{
			long_comput_div_two(l_num);
			e++;
		}
	}
}