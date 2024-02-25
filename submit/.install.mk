

.PHONY: install reinstall uninstall

install: Libft ft_printf

reinstall: uninstall install

uninstall:
	rm -rf Libft ft_printf

Libft:
	rm -rf tmp
	git clone -nq git@github.com:PalmNeko/Libft.git tmp
	cd tmp && git checkout HEAD -- submit
	cp -rfT tmp/submit Libft
	rm -rf tmp

ft_printf:
	rm -rf tmp
	git clone -nq git@github.com:PalmNeko/ft_printf.git tmp
	cd tmp && git checkout HEAD -- submit
	cd tmp && git checkout HEAD -- install_dep.sh
	cd tmp && bash install_dep.sh
	cp -rfT tmp/submit ft_printf
	rm -rf tmp

