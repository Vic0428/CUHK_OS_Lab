#!/bin/bash

# We need to add one empty line
# in the end of data.csv
# Make sure output all lines in data.csv
while read line ; do
    echo "${line}" | awk -F ',' '{print $1 " " $3}'
done < data.csv
