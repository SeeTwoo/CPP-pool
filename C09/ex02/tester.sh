#!/bin/bash

# Usage:
#   ./test_sort.sh ./your_program [count] [min] [max]
# Defaults:
#   count = 20, min = 0, max = 100

PROG="$1"
COUNT="${2:-20}"
MIN="${3:-0}"
MAX="${4:-100}"

if [ -z "$PROG" ]; then
    echo "usage: $0 <program> [count] [min] [max]" >&2
    exit 1
fi

# Generate random numbers
nums=$(
    i=0
    while [ "$i" -lt "$COUNT" ]; do
        echo $((RANDOM % (MAX - MIN + 1) + MIN))
        i=$((i + 1))
    done
)

# Run your program
out="$("$PROG" $nums)"

# Extract lists
before=$(printf '%s\n' "$out" \
    | awk '/^Before:/ { for (i = 2; i <= NF; i++) print $i }')

after=$(printf '%s\n' "$out" \
    | awk '/^After:/ { for (i = 2; i <= NF; i++) print $i }')

# Reference sort (numeric)
ref=$(printf '%s\n' "$before" | sort -n)

# Compare
if diff -u <(printf '%s\n' "$ref") <(printf '%s\n' "$after") >/dev/null
then
    echo -e "\e[32mOK\e[0m"
else
    echo "\e[31mFAIL\e[0m"
    echo "Expected:"
    printf '%s\n' "$ref"
    echo "Got:"
    printf '%s\n' "$after"
fi
