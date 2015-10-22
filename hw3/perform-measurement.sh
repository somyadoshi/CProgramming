#!/bin/bash

if [ $# -lt 1 ];then
        echo "Usage: "$0" takes one arugment" >&2
        exit 1
fi

# download the web content
wget --timeout=5 -q -O web "$1"
wc -c web | egrep -o ^[0-9]*
rm web  
