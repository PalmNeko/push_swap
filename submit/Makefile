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
SRC = \
	main.c \
	Stack/create.c \
	Stack/destroy.c \
	Stack/instructions.c \
	validators/validate_not_duplicated.c
LIBFT = libft.a
LIBFTPRINTF = libftprintf.a
OBJS = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra -MP -MMD
INCS = -I./validators -I./Libft -I./ft_printf -I./Stack
CFLAGS += $(INCS)
LIBS += -L./Libft -l ft -L./ft_printf -l ftprintf

all: $(NAME)

include .install.mk
-include $(DEPENDS)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $(filter %.o, $^) $(LIBS)

$(LIBFT): Libft
	"$(MAKE)" --directory Libft
	cp Libft/$(LIBFT) ./$(LIBFT)

$(LIBFTPRINTF): ft_printf
	"$(MAKE)" --directory ft_printf
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
