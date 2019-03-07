#!/bin/bash

function addition {
    echo "$(( $1 + $2 ))"
}

function main {
    result=
    addition "$@"
    echo "${result}"
}
main "$@"