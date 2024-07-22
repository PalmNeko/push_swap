# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libftprintf.d.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 12:28:22 by tookuyam          #+#    #+#              #
#    Updated: 2024/07/22 12:59:16 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_DIR ?= ft_printf
LIBFT_PRINTF = libftprintf.a
LIBS += $(FT_PRINTF_DIR)/$(LIBFT_PRINTF)
LDLIBS += -lftprintf
LDFLAGS += -L $(FT_PRINTF_DIR)

$(FT_PRINTF_DIR)/$(LIBFT_PRINTF): $(FT_PRINTF_DIR)
	make -C "$(FT_PRINTF_DIR)"

$(FT_PRINTF_DIR):
	echo 'please clone'

clean_libft_printf:
	make -C "$(FT_PRINTF_DIR)" clean

fclean_libft_printf:
	make -C "$(FT_PRINTF_DIR)" fclean

clean: clean_libft_printf
fclean: fclean_libft_printf
