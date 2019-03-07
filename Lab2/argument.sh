#!/bin/bash


echo "You called $0, with"

# For no arguments case
if [ $# -eq 0 ]; then
    echo "No arguments"
    exit 0
fi
# Output all input arguments
counter=0

for item in "$@"; do
    (( counter++ ))
    echo "Arg[${counter}]: ${item}"
done


