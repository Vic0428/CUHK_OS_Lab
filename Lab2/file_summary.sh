#!/bin/bash

# The option -n suppresses echo from
# adding new line character at the end of 
# a string
for item in "$@"; do
    counter=0
    wc -l ${item}
    while read line; do
        ((counter++))
        chars=$(echo -n ${line} | wc -c)
        words=$(echo -n ${line} | wc -w)
        echo "Line $((counter)): ${chars} chars, ${words} words"
    done < ${item}
    
done
