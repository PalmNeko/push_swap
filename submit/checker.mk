# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:41:56 by marvin            #+#    #+#              #
#    Updated: 2024/07/22 12:38:57 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = cc
SRC = \
	Commands/append.c \
	Commands/create.c \
	Commands/destroy.c \
	Commands/command_list_append_repeatedly.c \
	compresser/compress_straight_rotate.c \
	compresser/halfcut_straight_rotate.c \
	compresser/renumber_stack.c \
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
	printers/print_error.c \
	logics/apply_order_bonus.c \
	validators/validate_instruction_format_bonus.c \
	validators/validate_is_sorted.c \
	checker_main_bonus.c

OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CFLAGS += -Wall -Werror -Wextra -MP -MMD -I./includes -I./Libft -I./ft_printf
# extern variables - defined and appended from libs
#   LIBS    : need libraries ex: Libft/libft.a
#   LDFLAGS : ld flags ex: -L Libft
#   LDLIBS  : load lib flags ex: -l ft

all: $(NAME)

include fony.mk
include libs.mk

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

-include $(DEPS)
