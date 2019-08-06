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

NAME = ft_printf

SOURCE = ft_printf.c list.c param.c parse_param.c  print_format_str.c  main.c\
print_csp.c print_other.c help_function.c int_command.c int_print.c o_command.c\
o_print.c u_command.c u_print.c x_command.c x_print.c

OBJ = $(patsubst %.c,%.o,$(SOURCE))

LIB = -L libft -lft

all: $(NAME)

%.o: %.c
	gcc -g -Wall -Wextra -c -o $@ $<

$(NAME): $(OBJ)
	make -C ./libft
	gcc -o $(NAME) $(SOURCE:.c=.o) $(LIB)

clean:
	/bin/rm -f $(SOURCE:.c=.o)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
