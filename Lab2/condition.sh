#!/bin/bash

A=1

# If we use ${A} instead of using $((A))
# , there may raise unexpeted error.
if [ $((A)) -eq 0 ]; then
    echo "A equals to 0"
elif [ $((A)) -gt 0 ]; then
    echo "A is greater than 0"
else
    echo "A is smaller than 0"
fi

# To summarize, $(()) works when A is either a number 
# or an arithmetic expression, while #{} works only when
# A is a number. 