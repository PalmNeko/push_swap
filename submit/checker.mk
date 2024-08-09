# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:41:56 by marvin            #+#    #+#              #
#    Updated: 2024/08/09 17:28:08 by tookuyam         ###   ########.fr        #
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

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

show:
	@printf "%s\n \t%s\n" "SRC" "$(SRC)"
	@printf "%s\n \t%s\n" "OBJS" "$(OBJS)"
	@printf "%s\n \t%s\n" "DEPS" "$(DEPS)"
	@printf "%s\n \t%s\n" "CFLAGS" "$(CFLAGS)"
	@printf "%s\n \t%s\n" "LDFLAGS" "$(LDFLAGS)"
	@printf "%s\n \t%s\n" "LIBS" "$(LIBS)"

-include $(DEPS)

LIBFT_DIR ?= Libft
LIBFT = libft.a
LIBS += $(LIBFT_DIR)/$(LIBFT)
LDLIBS += -l ft
LDFLAGS += -L $(LIBFT_DIR)

$(LIBFT_DIR)/$(LIBFT): $(LIBFT_DIR)
	make -C "$(LIBFT_DIR)"

$(LIBFT_DIR):
	git clone https://github.com/PalmNeko/Libft

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
