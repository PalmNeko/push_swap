# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    install.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 23:07:19 by tookuyam          #+#    #+#              #
#    Updated: 2024/03/15 23:07:19 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TYCTEST = includes/tyctest libs/libtyctest_main.a libs/libtyctest.a bin/uninstall_tyctest.sh
INSTALLS = $(TYCTEST)

.PHONY: install
install: $(INSTALLS)

.PHONY: uninstall
uninstall:
	$(RM) -r $(INSTALLS)

.PHONY: reinstall
reinstall: uninstall install

$(TYCTEST):
	git clone git@github.com:PalmNeko/tyCtest_tool.git tyCtest_tool
	bash tyCtest_tool/install.sh
	rm -rf tyCtest_tool