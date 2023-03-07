import sys

n = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
d = {1:cards[0]}

def check_max(x):
    if x in d :
        return d[x]
    cmp = []
    for i in range(1, x):
        cmp.append(check_max(x-i)+check_max(i))
    cmp.append(cards[x-1])
    d[x] = max(cmp)
    return d[x]

print(check_max(n))