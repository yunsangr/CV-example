#!/bin/zsh

if [ $# -ne 1 ]
  then
    echo "usage:  [file name]"
    exit 1
fi
echo "Source code moved from main.cpp to $1"
mv main.cpp "$1"
touch main.cpp

cat mainTemplete.cpp >> main.cpp
