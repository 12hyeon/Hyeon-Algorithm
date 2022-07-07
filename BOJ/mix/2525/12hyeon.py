import sys

hour, min = map(int, sys.stdin.readline().rstrip().split())
time = int(input())
if min + time > 59 :
    hour += (min + time) // 60
    min = (min + time) % 60
else:
    min += time
if hour > 23:
    hour -= 24
print(hour, min)