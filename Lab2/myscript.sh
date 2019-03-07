#!/bin/bash


mynum=3150
coure_code="csci"
mystr=${coure_code}


# grow mystr from csci to csci3150
echo "Before: ${mystr}"
mystr+=${mynum}
echo "After: ${mystr}"


# when curly braces are necessary
echo "${course_code}3150 is a course about OS"

