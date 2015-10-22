#!/bin/bash

if [ $# -lt 2 ];then
	echo "Error: '$0' needs 2 arguments"
	exit 1
fi

if [ ! -f "$1" ];then
	echo "Error: '$1' does not exist"
	exit 1
fi

webs="$(<$1)"
rank=1
for web in $webs;do
	echo "Performing measurement on "$web
	temp="$(./perform-measurement.sh "$web")"
	if [ $temp -eq 0 ];then
		echo "...failed"
		((rank++))
	else
		echo "...success"
		echo "$rank "$web" $temp" >> "$2"
		((rank++))
	fi
done
exit

