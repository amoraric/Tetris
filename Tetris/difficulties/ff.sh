#!/bin/bash

# Create 25 files with the specified structure
for level in {1..25}
do
    # Determine the divisor based on the level
    if [ $level -eq 1 ]; then
        divisor=60
    elif [ $level -eq 2 ]; then
        divisor=53
    elif [ $level -eq 3 ]; then
        divisor=49
    elif [ $level -eq 4 ]; then
        divisor=45
    elif [ $level -eq 5 ]; then
        divisor=41
    elif [ $level -eq 6 ]; then
        divisor=37
    elif [ $level -eq 7 ]; then
        divisor=33
    elif [ $level -eq 8 ]; then
        divisor=28
    elif [ $level -eq 9 ]; then
        divisor=23
    elif [ $level -eq 10 ]; then
        divisor=18
    elif [ $level -eq 11 ]; then
        divisor=13
    elif [ $level -eq 12 ]; then
        divisor=8
    elif [ $level -eq 13 ]; then
        divisor=9
    elif [ $level -eq 14 ]; then
        divisor=10
    elif [ $level -eq 15 ]; then
        divisor=11
    elif [ $level -eq 16 ]; then
        divisor=7
    elif [ $level -eq 17 ]; then
        divisor=5
    elif [ $level -eq 18 ]; then
        divisor=4
    elif [ $level -eq 19 ]; then
        divisor=3
    else
        divisor=2
    fi

    # Calculate the lines and points required
    lines=$((level * 10))
    points=$((level * 5000))

    # Create the file with the required content
    filename="${level}.txt"
    echo $points > $filename
    echo $lines >> $filename
    echo $divisor >> $filename
done

echo "Files have been created successfully."

