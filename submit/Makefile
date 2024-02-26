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
	main.c \
	Stack/create.c \
	Stack/destroy.c \
	Stack/instructions.c
LIBFT = libft.a
LIBFTPRINTF = libftprintf.a
OBJS = $(SRC:.c=.o)
CFLAGS += $(addprefix -I, \
	Libft \
	ft_printf \
	Stack \
)

all: $(NAME)

include .install.mk
-include $(DEPENDS)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $(filter %.o, $^) -L./Libft -l ft -L./ft_printf -l ftprintf

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
	$(MAKE) --directory ft_printf fclean
	$(MAKE) --directory Libft fclean

re: fclean all
