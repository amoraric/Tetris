#!/bin/bash

score=1000
lines=10
time=600
for i in {1..25}
do
	echo "$(($score*$i))" > "$i.txt"
	echo "$(($lines*$i))" >> "$i.txt"
	echo "$(($time*$i))" >> "$i.txt"
done
