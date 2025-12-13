#!/bin/bash

# Usage:
#   ./test_sort.sh ./your_program [count] [min] [max]
# Note: (max - min + 1) must be >= count

PROG="$1"
COUNT="${2:-20}"
MIN="${3:-0}"
MAX="${4:-100}"

if [ -z "$PROG" ]; then
    echo "usage: $0 <program> [count] [min] [max]" >&2
    exit 1
fi

RANGE=$((MAX - MIN + 1))
if [ "$RANGE" -lt "$COUNT" ]; then
    echo "error: range too small to avoid duplicates" >&2
    exit 1
fi

# Generate unique random numbers
nums=$(
	{
		i=0
		while [ "$i" -lt "$COUNT" ]; do
			echo $((RANDOM % RANGE + MIN))
			i=$((i + 1))
		done
	} \
	| sort -n \
	| uniq \
	| shuf \
	| head -n "$COUNT"
)

# Run your program
out="$("$PROG" $nums)"

# Extract lists
before=$(printf '%s\n' "$out" \
    | awk '/^Before:/ { for (i = 2; i <= NF; i++) print $i }')

after=$(printf '%s\n' "$out" \
    | awk '/^After:/ { for (i = 2; i <= NF; i++) print $i }')

# Reference sort
ref=$(printf '%s\n' "$before" | sort -n)

# Compare
if diff -u <(printf '%s\n' "$ref") <(printf '%s\n' "$after") >/dev/null
then
    echo "OK"
else
    echo "FAIL"
    echo "Expected:"
  #  printf '%s\n' "$ref"
    echo "Got:"
  #  printf '%s\n' "$after"
fi

