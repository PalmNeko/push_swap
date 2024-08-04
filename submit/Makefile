# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:41:56 by marvin            #+#    #+#              #
#    Updated: 2024/08/04 19:56:53 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
SRC = \
	./main.c \
	$(shell find . -type f -name "ps_*.c")


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
debug: $(NAME)

include fony.mk
include libs.mk

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

checker:
	# make -f checker.mk

checker_clean:
	make -f checker.mk clean

checker_fclean:
	make -f checker.mk fclean

clean:  checker_clean
fclean: checker_clean

-include $(DEPS)
