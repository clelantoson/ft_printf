# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 14:49:53 by cle-lan           #+#    #+#              #
#    Updated: 2021/03/15 14:31:30 by cle-lan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c \
		ft_putstr_count.c \
		ft_putchar_count.c \
		ft_deal_with_char.c \
		ft_is_in_type_list.c \
		ft_deal_with_str.c \
		ft_putnbr_count_chars.c \
		ft_deal_with_int.c \
		ft_init_struct.c \
		ft_deal_with_pc.c \
		*ft_ulltoa_base.c \
		ft_deal_with_hex.c \
		ft_str_tolower.c \
		ft_deal_with_ptr.c \

OBJ = $(SRC:.c=.o)

BONUSOBJ = $(BONUSSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	$(MAKE) clean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re