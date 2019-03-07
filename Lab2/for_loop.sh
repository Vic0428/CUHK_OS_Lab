#!/bin/bash

A=("a" "b" "c")

# print 1, 2, ..., 10
for item in {1..10}; do
    echo "$item"
done

# print elements in A
for item in ${A[@]}; do
    echo "$item"
done

