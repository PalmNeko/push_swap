# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:41:56 by marvin            #+#    #+#              #
#    Updated: 2024/08/09 17:03:25 by tookuyam         ###   ########.fr        #
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

all: $(NAME) bonus

bonus:
	$(MAKE) -f checker.mk

test: clean debug push_swap_tester checker norm
	@echo "brief test" && ./test.sh
	@echo "100 random test 200 times" && cd push_swap_tester && python3 push_swap_tester.py -l 100 -c 200
	@echo "500 random test 200 times" && cd push_swap_tester && python3 push_swap_tester.py -l 500 -c 200

norm:
	! norminette *.c */*.c *.h | grep -v OK

debug: LDFLAGS += -g -O0 -fsanitize=leak
debug: CFLAGS  += -g -O0 -fsanitize=leak
debug: all

include fony.mk

LIBFT_DIR ?= Libft
LIBFT = libft.a
LIBS += $(LIBFT_DIR)/$(LIBFT)
LDLIBS += -l ft
LDFLAGS += -L $(LIBFT_DIR)

$(LIBFT_DIR)/$(LIBFT): $(LIBFT_DIR)
	make -C "$(LIBFT_DIR)"

$(LIBFT_DIR):
	git clone https://github.com/PalmNeko/Libft

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

checker_clean:
	make -f checker.mk clean

checker_fclean:
	make -f checker.mk fclean

checker: bonus

push_swap_tester:
	git clone https://github.com/nafuka11/push_swap_tester.git

clean:  checker_clean
fclean: checker_clean

-include $(DEPS)
