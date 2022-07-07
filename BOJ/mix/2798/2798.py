import sys

cnt, M = map(int, sys.stdin.readline().rstrip().split())
cards = list(map(int, sys.stdin.readline().split()))
answer = cards[0]+cards[1]+cards[2]

for n1 in range(1, cnt-1):
    for n2 in range(n1+1, cnt):
        for n3 in range(n2+1, cnt+1):
            s = cards[n1-1]+cards[n2-1]+cards[n3-1]
            if s <= M and s > answer:
                answer = s

print(answer)