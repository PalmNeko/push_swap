#!/bin/bash
count_strings() {
  declare -A count_map
  while IFS= read -r line || [ -n "$line" ]; do
    count_map["$line"]=$((count_map["$line"] + 1))
  done

  for key in "${!count_map[@]}"; do
    echo "$key: ${count_map[$key]}"
  done
}

NBR_COUNT="${1:-6}"
##
if [ "$1" = "--" ]; then
	shift
	NBR="$*"
elif [ -n "$1" ]; then
	NBR_COUNT="${1}"
	NBR=$(seq 1 $NBR_COUNT | sort -R | tr '\n' ' ' | sed 's/ $//g')
else
	NBR="5 2 7 1 6 3 9 4 8"
fi
# NBR=$(seq 1 $NBR_COUNT | tr '\n' ' ' | rev | cut -c 2- | rev)
CMD=$(./push_swap $NBR)
echo "$CMD" | count_strings
NBR_LINK=$( echo "$NBR" | tr ' ' ',' )
CMD_LINK=$( echo "$CMD" | sed -e"s/rra/g/g" -e"s/rrb/h/g" \
-e"s/rrr/i/g" -e"s/sa/a/g" -e"s/sb/b/g" -e"s/ss/c/g" \
-e"s/ra/d/g" -e"s/rb/e/g" -e"s/rr/f/g"  -e"s/pa/j/g" -e"s/pb/k/g" | tr -d '\n')
CMD_COUNT=${#CMD_LINK}
CHECKER="checker"
RESULT=$( ./push_swap $NBR | ./"$CHECKER" $NBR 2>&1 )
# RESULT=$( echo $CMD | ./checker $NBR 2>&1 ) # not work but i don't know why.<= on windows.
echo "Operations: $CMD_COUNT"
echo "Result $RESULT"
echo "https://patrick-hacks.github.io/push-swap-pain/?&nbr=$NBR_LINK&cmd=$CMD_LINK"
