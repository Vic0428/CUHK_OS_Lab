#!/bin/bash

mystr="name.email.phone.remarks"

# Change the IFS in code
IFS='.'
# Output mystr splited by IFS
for item in ${mystr[@]}; do
    echo "$item"
done

# restore IFS
IFS=" "$'\n'$'\t'

# Test the $ meaning
test_str=" "$'1'
echo "${test_str}"