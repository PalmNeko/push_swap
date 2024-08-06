#!/bin/bash

CHECKER="checker"

err_exit() {
	printf "\e[31m%b\e[0m" "$1\n"
	exit 1
}

g_line_cnt=""
test_push_swap() {
	CMDS="$(./push_swap "$@")"
	g_line_cnt="$(echo -n "$CMDS" | wc -l)"
	RESULT="$(echo -n "$CMDS" | ./"$CHECKER" "$@")"
	local exit_status
	if [ "$RESULT" = "OK" ]; then
		printf "\e[32m%b\e[0m" " $RESULT\n"
		exit_status="0"
	else
		printf "\e[31m%b\e[0m" " $RESULT\n"
		exit_status="1"
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
	test "$g_line_cnt" -le 3 || err_exit "over"

	printf "instruction count should be less than 13 (1 5 2 4 3)"
	test_push_swap 1 5 2 4 3
	test "$g_line_cnt" -lt 13 || err_exit "over"

	return 0
}

main
