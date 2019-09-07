# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjesse <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 17:09:44 by bjesse            #+#    #+#              #
#    Updated: 2019/06/18 21:22:39 by bjesse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE = ft_printf.c list.c param.c parse_param.c  print_format_str.c\
print_csp.c help_function.c int_command.c int_print.c o_command.c\
o_print.c u_command.c u_print.c x_command.c x_print.c double_command.c\
double_long_comput.c double_parse.c double_print.c double_print_nan.c

OBJ = $(patsubst %.c,%.o,$(SOURCE))

LIB = -L libft -lft

all: $(NAME)


$(NAME): $(OBJ)
	make -C ./libft
	ar rc $(NAME) $(SOURCE:.c=.o)
	ranlib $(NAME)

%.o: %.c
	gcc -g -Wall -Wextra -Werror -c -o $@ $<

clean:
	/bin/rm -f $(SOURCE:.c=.o)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
