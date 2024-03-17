# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 23:03:08 by tookuyam          #+#    #+#              #
#    Updated: 2024/03/15 23:03:08 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester
ifeq ($(OS),Windows_NT)
	NAME = tester.exe
endif
TARGET_DIR = ../submit
SRC = $(shell find $(TARGET_DIR) -not -name "__*.c" -name "*.c" -not -name "main.c" -not -path "*/Libft/*" -not -path "*/ft_printf/*")
SRC += $(shell find . -name "*_test.c")
OBJS = $(SRC:.c=.o)
DEPENDS = $(SRC:.c=.d)
CC = cc
CFLAGS += -Wall -Werror -Wextra
CFLAGS += -coverage
INCS = -I$(TARGET_DIR)/includes -I$(TARGET_DIR)/Libft -I$(TARGET_DIR)/ft_printf
INCS += -I./includes/tyctest
CFLAGS += $(INCS)
LIBS = -L./libs -L$(TARGET_DIR)/Libft -L$(TARGET_DIR)/ft_printf -ltyctest_main -ltyctest -lftprintf -lft

.PHONY: all
all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(filter %.o, $(OBJS)) $(LIBS)

.PHONY: clean
clean:
	find .. -name "*.o" -delete
	find .. -name "*.d" -delete
	find .. -name "*.gcno" -delete
	find .. -name "*.gcda" -delete
	find .. -name "*.gcov" -delete

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
