#!/bin/bash

A=0

# print from 0 to 10
while [ $((A)) -lt 10 ]; do
    echo $((A))
    ((A++))
done
