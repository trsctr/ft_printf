# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2023/01/19 16:19:01 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
PRINTFSRC	= ft_printf.c
LIBFTSRC 	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
OBJS	= $(LIBFTSRC:.c=.o) $(PRINTFSRC:.c=.o)
LIBFTDIR	= libft/
INCDIR	= includes
CC	= cc
CFLAGS	= -Wall -Werror -Wextra
INCFLAG	= $(addprefix -I,$(INCDIR))

all: $(NAME)

$(NAME): $(addprefix $(LIBFTDIR),$(SRC))
	$(CC) $(CFLAGS) -c $(PRINTFSRC) $(addprefix $(LIBFTDIR),$(LIBFTSRC)) $(INCFLAG)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

test:
	$(CC) $(CFLAGS) main.c $(NAME) $(INCFLAG) -o test

.PHONY: all clean fclean re test