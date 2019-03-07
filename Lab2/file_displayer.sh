#!/bin/bash

# Missing file name
if [ $# -\lt 1 ]; then
    echo "$0 [file to display]"
    exit 1
fi

# If the input file isn't regular file
if [ ! -f $1 ]; then
    echo "Cannot display non-regular files"
    exit 1
fi

while  read line ; do
    echo "${line}"
done < $1






