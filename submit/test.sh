#!/bin/bash

CHECKER="checker"

err_exit() {
	printf "\e[31m%b\e[0m" "$1\n"
	exit 1
}

g_line_cnt=""
test_push_swap() {
	tmpdir="$(mktemp)"
	./push_swap "$@" > "$tmpdir"
	g_line_cnt="$(cat "$tmpdir" | wc -l)"
	RESULT="$(cat "$tmpdir" | ./"$CHECKER" "$@")"
	rm "$tmpdir"
	local exit_status
	if [ "$RESULT" = "OK" ]; then
		printf "\e[32m%b\e[0m" " $RESULT\n"
		exit_status="0"
	elif [ "$RESULT" = "KO" ]; then
		printf "\e[31m%b\e[0m" " $RESULT\n"
		exit_status="1"
	else
		printf "\e[31m%b\e[0m" " Error: checker output format (OK/KO) : $RESULT"
		exit 1
	fi
	test "$RESULT" = "OK" && return 0 || return 1
}

main () {
	printf "should display nothing (42)"
	test_push_swap "42"
	test "$g_line_cnt" -eq 0 || err_exit "over"

	printf "should display nothing (0 1 2 3)"
	test_push_swap 0 1 2 3
	test "$g_line_cnt" -eq 0 || err_exit "over"

	printf "should display nothing (0 1 2 3 4 5 6 7 8 9)"
	test_push_swap 0 1 2 3 4 5 6 7 8 9
	test "$g_line_cnt" -eq 0 || err_exit "over"

	printf "2 or 3 line (2 1 0)"
	test_push_swap 2 1 0
	test "$g_line_cnt" -eq 3 || test "$g_line_cnt" -eq 2 || err_exit "over"

	printf "instruction count should be less than 13 (1 5 2 4 3)"
	test_push_swap 1 5 2 4 3
	test "$g_line_cnt" -lt 13 || err_exit "over"

	printf "error test (\"\")"
	./push_swap "" 2>&1 | grep -q "^Error$" || err_exit "should occour error" && printf "\e[32m%b\e[0m" " OK\n"

	printf "error test. duplicate (1 1 3)"
	./push_swap 1 1 3 2>&1 | grep -q "^Error$" || err_exit "should occour error" && printf "\e[32m%b\e[0m" " OK\n"

	printf "error test. duplicate (3 1 1)"
	./push_swap 3 1 1 2>&1 | grep -q "^Error$" || err_exit "should occour error" && printf "\e[32m%b\e[0m" " OK\n"

	printf "error test. (2147483647 2147483648)"
	./push_swap 2147483647 2147483648 2>&1 | grep -q "^Error$" || err_exit "should occour error" && printf "\e[32m%b\e[0m" " OK\n"

	printf "error test. (2147483647 -2147483649)"
	./push_swap 2147483647 -2147483649 2>&1 | grep -q "^Error$" || err_exit "should occour error" && printf "\e[32m%b\e[0m" " OK\n"

	printf "no_error. (2147483647 -2147483648)"
	test_push_swap 2147483647 -2147483648

	printf "bonus: checker KO format"
	echo -n "" | ./"$CHECKER" 2 1 0 | cat -e | grep -E '^KO\$$' > /dev/null || err_exit "should print KO" && printf "\e[32m%b\e[0m" " OK\n"
	return 0
}

main
