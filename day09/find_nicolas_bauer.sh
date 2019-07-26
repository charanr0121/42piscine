#!/bin/sh
cat $1 | grep -i "Nicolas" | grep -i "Bauer" |awk '{print $(NF-1)}'
