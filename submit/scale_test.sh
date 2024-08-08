#!/bin/bash

cd "$(dirname $0)"

for i in $(seq "$@"); do
	printf "$i,%s\n" "$(./push_swap $(seq $i | sort -R) | wc -l)"
done
