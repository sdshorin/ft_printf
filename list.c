
#include "ft_printf.h"



t_param *new_param_list()
{
	t_param *new;

	new = (t_param*)malloc(sizeof(t_param));
	if (!new)
		return (0);
	new->conversion = 0;
	new->h = 0;
	new->l = 0;
	new->L = 0;
	new->hash = 0;
	new->space = 0;
	new->zero = 0;
	new->minus = 0;
	new->plus = 0;
	new->minimum_size = -1;
	new->precision = -1;
	new->next = 0;
	new->ptr_shadow = 0;
	return (new);
}

int delete_param(t_param *param)
{
	t_param *next;

	while (param)
	{
		next = param->next;
		free(param);
		param = next;
	}
	return (0);
}
