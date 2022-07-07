# Fly me to the Alpha Centauri
# idea : 시작과 마지막이 1칸으로 지정되었으므로 중간에서 가운데로 최대한 균형 맞게 증가

import sys

cnt = int(sys.stdin.readline().rstrip())
for n in range(cnt):
    value = list(map(int, sys.stdin.readline().rstrip().split()))
    x, y = value[0], value[1]
    rest = y-x
    result = 0
    i = 1
    while (rest != 0):
        if (rest - 2*i >= 0):
            rest -= 2*i
            result += 2
            i += 1
        elif (rest - i >= 0):
            rest -= i
            result += 1
        else:
            result += 1
            break
    print(result)