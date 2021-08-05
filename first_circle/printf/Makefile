# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 21:01:03 by bahsoka           #+#    #+#              #
#    Updated: 2021/04/20 21:01:05 by bahsoka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = 	ft_printf.c \
		ft_printf_get_setting.c \
		ft_libft_functions.c \
		ft_printf_ifchar.c \
		ft_printf_ifstring.c \
		ft_printf_ifpercent.c \
		ft_printf_itoa.c \
		ft_printf_ifinteger.c \
		ft_printf_ifuninteger.c \
		ft_printf_ifhex.c \
		ft_printf_ifpointer.c \
		ft_printf_functions.c \
		ft_printf_extra.c \

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@gcc $(FLAG) -c $^ -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
