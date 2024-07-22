# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.d.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 12:28:22 by tookuyam          #+#    #+#              #
#    Updated: 2024/07/22 12:59:07 by tookuyam         ###   ########.fr        #
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
	echo 'please clone'

clean_libft:
	make -C "$(LIBFT_DIR)" clean

fclean_libft:
	make -C "$(LIBFT_DIR)" fclean

clean: clean_libft
fclean: fclean_libft
