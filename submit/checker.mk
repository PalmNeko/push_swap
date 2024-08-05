# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:41:56 by marvin            #+#    #+#              #
#    Updated: 2024/08/05 13:24:35 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = cc
SRC = \
	./checker_main_bonus.c \
	$(shell find . -type f -name "ps_*.c")

OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CFLAGS += -g -O0 -fsanitize=leak -Wall -Werror -Wextra -MP -MMD -I. -I./Libft
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
