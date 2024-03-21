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
	Commands/append.c \
	Commands/create.c \
	Commands/destroy.c \
	Commands/command_list_append_repeatedly.c \
	compresser/compress_straight_rotate.c \
	compresser/halfcut_straight_rotate.c \
	Stack/create.c \
	Stack/destroy.c \
	Stack/print.c \
	Stack/instructions.c \
	Stack/clone.c \
	Stack/get_head.c \
	validators/validate_no_duplicates.c \
	validators/validate_numstrings.c \
	logics/compress_commands.c \
	logics/generate_sort_commands.c \
	logics/generate_stack_strs_to.c \
	logics/push_swap_bubble_sort.c \
	printers/print_commands.c \
	printers/print_error.c
SRC_BONUS = \
	$(filter-out main.c, $(SRC)) \
	checker_main_bonus.c

LIBFT = libft.a
LIBFTPRINTF = libftprintf.a
OBJS = $(SRC:.c=.o)
DEPENDS = $(SRC:.c=.d)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
DEPENDS_BONUS = $(SRC_BONUS:.c=.d)
CFLAGS += -Wall -Werror -Wextra -MP -MMD
INCS = -I./includes -I./Libft -I./ft_printf
CFLAGS += $(INCS)
LIBS += -L./Libft -l ft -L./ft_printf -l ftprintf

all: $(NAME)

include .install.mk
-include $(DEPENDS)
-include $(DEPENDS_BONUS)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $(filter %.o, $^) $(LIBS)

.PHONY: bonus
bonus: checker

checker: $(OBJS_BONUS) $(LIBFT) $(LIBFTPRINTF)
	: $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $(filter %.o, $^) $(LIBS)

$(LIBFT): Libft
	"$(MAKE)" --directory Libft
	cp Libft/$(LIBFT) ./$(LIBFT)

$(LIBFTPRINTF): ft_printf
	"$(MAKE)" --directory ft_printf
	cp ft_printf/$(LIBFTPRINTF) ./$(LIBFTPRINTF)

clean:
	find . -name "*.d" -delete
	find . -name "*.o" -delete
	find . -name "*.gcno" -delete

fclean: clean
	$(RM) $(NAME)
	$(RM) checker
	$(MAKE) --directory ft_printf fclean
	$(MAKE) --directory Libft fclean

re: fclean all
