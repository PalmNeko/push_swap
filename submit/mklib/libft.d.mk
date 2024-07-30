# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.d.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 12:28:22 by tookuyam          #+#    #+#              #
#    Updated: 2024/07/30 14:23:53 by tookuyam         ###   ########.fr        #
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

clean_libft:
	make -C "$(LIBFT_DIR)" clean

fclean_libft:
	make -C "$(LIBFT_DIR)" fclean

clean: clean_libft
fclean: fclean_libft
