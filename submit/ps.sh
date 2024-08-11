#!/bin/bash

readonly CHECKER="checker"

cd "$(dirname $0)"

main() {
	make debug > /dev/null
	readonly TMP_STDOUT="$(mktemp)"
	printf "input num > "
	echo "$@" >&2
	./push_swap "$@" > "$TMP_STDOUT"
	printf "command cnt: %s\n" "$(cat "$TMP_STDOUT" | wc -l)"
	cat "$TMP_STDOUT" | ./"$CHECKER" "$@"
	rm "$TMP_STDOUT"
	return 0
}

main "$@"
