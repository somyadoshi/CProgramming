#!/bin/bash

# arugment more than 2 
if [ $# -gt 2 ];then
	echo "Error: '$0' takes no more than two arguments"
	exit 1
fi
# check the first argument
if [ ! -f $1 ];then
	echo "Error: '$1' does not exist"
	exit 1
fi

egrep -io "http:\/\/[a-zA-Z0-9+.]*" "$1" | uniq > t
egrep -vwE "100bestwebsites|altavista|en.wikipedia.org|oregonstate" t > "$2"
rm t

exit
