
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"


typedef struct	s_param {
	char			conversion;
	char			h;
	char			l;
	char			L;
	char			hash;
	char			zero;
	char			space;
	char			minus;
	char			plus;
	int				minimum_size;
	char			precision;
	struct s_param	*next;
}				t_param;

int read_params(t_param **param, char *format);
int print_format_str(t_param *param, char *str, va_list ap);

t_param *new_param_list();

char *parse_param_flags(char *format, t_param *now_param);
char *parse_param_width(char *input_string, t_param *now_param);
char *parse_param_precision(char *input_string, t_param *now_param);
char *parse_param_size(char *input_string, t_param *now_param);
char *parse_param_type(char *input_string, t_param *now_param);



int print_char(t_param **param, va_list ap);
int print_str(t_param **param, va_list ap);
int print_ptr(t_param **param, va_list ap);
int print_d(t_param **param, va_list ap);
int print_int(t_param **param, va_list ap);
int print_o(t_param **param, va_list ap);
int print_u(t_param **param, va_list ap);
int print_x(t_param **param, va_list ap);
int print_X(t_param **param, va_list ap);
int print_float(t_param **param, va_list ap);


void ptr_to_str(char *ptr_str, size_t ptr);
int write_prenum(t_param *param, long long n);
void write_num(t_param *param, long long n);
int ft_num_size(long long n);

