# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.d.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 12:28:22 by tookuyam          #+#    #+#              #
#    Updated: 2024/08/08 19:05:29 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR ?= Libft
LIBFT = libft.a
LIBS += $(LIBFT_DIR)/$(LIBFT)
LDLIBS += -l ft
LDFLAGS += -L $(LIBFT_DIR)

$(LIBFT_DIR)/$(LIBFT): $(LIBFT_DIR)
	make -C "$(LIBFT_DIR)"

$(LIBFT_DIR):
	git clone https://github.com/PalmNeko/Libft
