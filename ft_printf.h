


#include <stdarg.h>



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