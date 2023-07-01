#!/usr/bin/python3
import sys
import math
file_name: str = sys.argv[1]

with open(file_name) as f:
    lines:list = f.readlines()
    for line in lines:
        num: int = int(line)
        median: int = int(math.sqrt(num)) + 1
        start: int = 2 if (num % 2 == 0) else 3

        for div in range(start, median, 2):
            if (num % div == 0):
                print(f"{num}={int(num/div)}*{div}")
                break
