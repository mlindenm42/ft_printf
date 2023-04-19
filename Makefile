# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 16:33:29 by mlindenm          #+#    #+#              #
#    Updated: 2022/06/24 13:13:18 by mlindenm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJFILES = ft_printf_char.o ft_printf_decimal.o ft_printf_hexa_low.o ft_printf_hexa_up.o ft_printf_integer.o ft_printf_pointer.o ft_printf_string.o ft_printf_undecimal.o ft_printf.o

FUNCTIONS = ft_printf_char.c ft_printf_decimal.c ft_printf_hexa_low.c ft_printf_hexa_up.c ft_printf_integer.c ft_printf_pointer.c ft_printf_string.c ft_printf_undecimal.c ft_printf.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJFILES)
	@ar -rcs $@ $(OBJFILES)

$(OBJFILES): $(FUNCTIONS)
	@$(CC) $(CFLAGS) -c $(FUNCTIONS)

clean:
	@/bin/rm -f $(OBJFILES) $(BOBJFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
