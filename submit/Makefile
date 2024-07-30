# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:41:56 by marvin            #+#    #+#              #
#    Updated: 2024/07/30 14:21:22 by tookuyam         ###   ########.fr        #
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
	printers/print_error.c

OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CFLAGS += -Wall -Werror -Wextra -MP -MMD -I./includes -I./Libft
CLEAN_FILES = $(OBJS) $(DEPS)
FCLEAN_FILES = $(NAME)
# extern variables - defined and appended from libs
#   LIBS    : need libraries ex: Libft/libft.a
#   LDFLAGS : ld flags ex: -L Libft
#   LDLIBS  : load lib flags ex: -l ft

all: $(NAME) bonus

bonus: checker

include fony.mk
include libs.mk

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

checker:
	make -f checker.mk

checker_clean:
	make -f checker.mk clean

checker_fclean:
	make -f checker.mk fclean

clean:  checker_clean
fclean: checker_clean

-include $(DEPS)
