# bottomUp 사용
import sys

x = int(sys.stdin.readline())

d=[0]*(x+1)
for i in range(2,x+1):
    d[i]=d[i-1]+1
    if i%2==0:
        d[i]=min(d[i],d[i//2]+1)
    if i%3==0:
        d[i]=min(d[i],d[i//3]+1)
print(d[x])

import sys
import Collection from
n = int(sys.stdin.readline())
q = deque([n])
visited = [0]*(n+1)