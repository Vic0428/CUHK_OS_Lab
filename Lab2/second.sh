#!/bin/bash

myarray=()
another_array=("three" 1 "five" 0)

# get the first item of another_array
# echo "${another_array[0]}"

# get the whole array
# echo "${another_array[@]}"

# get the number of the whole array
# echo "${#another_array[@]}"

# get the keys used in the array
echo "${!another_array[@]}"
