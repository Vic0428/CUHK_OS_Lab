#!/bin/bash


my_long_str="this is a long string"

echo "My string: ${my_long_str}"
echo ""

echo "Number of characters in string ${#my_long_str}"
echo ""

echo "Spliting my string like an array:"
for word in ${my_long_str[@]}; do
    echo "${word}"
done

echo ""

