# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:41:56 by marvin            #+#    #+#              #
#    Updated: 2024/02/25 23:41:56 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS += -Wall -Werror -Wextra -MP -MMD
SRC = \
	main.c
LIBFT = libft.a
LIBFTPRINTF = libftprintf.a
OBJS = $(SRC:.c=.o)
CFLAGS += $(addprefix -I, Libft ft_printf)

all: $(NAME)

include .install.mk
-include $(DEPENDS)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT): Libft
	$(MAKE) --directory Libft
	cp Libft/$(LIBFT) ./$(LIBFT)

$(LIBFTPRINTF): ft_printf
	$(MAKE) --directory ft_printf
	cp ft_printf/$(LIBFTPRINTF) ./$(LIBFTPRINTF)

clean:
	$(RM) \
		$(OBJS) \
		$(LIBFT) \
		$(LIBFTPRINTF)
	$(MAKE) --directory ft_printf clean
	$(MAKE) --directory Libft clean

fclean: clean
	$(RM) $(NAME)

re: fclean all
