# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:41:56 by marvin            #+#    #+#              #
#    Updated: 2024/08/03 13:13:40 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
SRC = \
	./main.c \
	./calculators/ps_renumber.c \
	./calculators/ps_sort_for_three.c \
	./calculators/ps_str_to_int_array.c \
	./controllers/ps_append_cmdlst.c \
	./controllers/ps_destroy_cmldlst.c \
	./controllers/ps_destroy_ps.c \
	./controllers/ps_destroy_stack.c \
	./controllers/ps_get_cmdlst.c \
	./controllers/ps_get_stack.c \
	./controllers/ps_new_cmdlst.c \
	./controllers/ps_new_ps.c \
	./controllers/ps_new_stack.c \
	./controllers/ps_pa.c \
	./controllers/ps_pb.c \
	./controllers/ps_pop_stack.c \
	./controllers/ps_push_stack.c \
	./controllers/ps_ra.c \
	./controllers/ps_rb.c \
	./controllers/ps_rr.c \
	./controllers/ps_rra.c \
	./controllers/ps_rrb.c \
	./controllers/ps_rrr.c \
	./controllers/ps_sa.c \
	./controllers/ps_sb.c \
	./controllers/ps_ss.c \
	./controllers/ps_swap_stack.c \
	./logics/ps_main.c \
	./logics/ps_print_cmdlst.c \
	./logics/ps_print_error.c \
	./logics/ps_turk_sort.c \
	./validators/ps_validate_no_duplicates.c


OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CFLAGS += -Wall -Werror -Wextra -MP -MMD -I. -I./Libft
CLEAN_FILES = $(OBJS) $(DEPS)
FCLEAN_FILES = $(NAME)
# extern variables - defined and appended from libs
#   LIBS    : need libraries ex: Libft/libft.a
#   LDFLAGS : ld flags ex: -L Libft
#   LDLIBS  : load lib flags ex: -l ft

all: $(NAME) bonus

bonus: checker

debug: LDFLAGS += -g -O0 -fsanitize=leak
debug: CFLAGS  += -g -O0 -fsanitize=leak
debug: re

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
