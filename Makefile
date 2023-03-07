# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2023/03/07 13:42:51 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
SRCS	= ft_printf.c ft_printf_parse.c ft_printf_convert_hex.c \
			ft_printf_convert_uidcs.c
OBJS	= $(SRCS:.c=.o)
HEADERS = ft_printf.h libft/libft.h
INCFLAG = -I libft
CC	= cc
CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@make -C libft
	@cd libft && mv libft.a ..
	@mv libft.a $(NAME)
	@echo "Compiling ft_printf object files"
	@$(CC) $(CFLAGS) -c $(SRCS) $(INCFLAG)
	@echo "Combining libraries and creating libftprintf.a"
	@ar rcs $(NAME) $(OBJS)
	@echo "Done!"

clean:
	@make -C libft clean
	@echo "Cleaning ft_printf object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing libftprintf.a"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re