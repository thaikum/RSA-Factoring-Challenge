#!/usr/bin/python3
import sys
file_name: str = sys.argv[1]

with open(file_name) as f:
    lines:list = f.readlines()
    for line in lines:
        num: int = int(line)
        median: int = int(num / 2) + 1
        div: int = 2 if (num % 2 == 0) else 3

        while div <= median:
            if (num % div == 0):
                print(f"{num}={int(num/div)}*{div}")
                break
            div += 2
