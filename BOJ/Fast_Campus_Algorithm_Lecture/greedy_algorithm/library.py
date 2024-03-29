import heapq

n,m = map(int, input().split())
num = list(map(int, input().split()))
positive = []
negative = []

largest = max(max(num), - min(num))

for i in num:
    if i > 0:
        heapq.heappush(positive, -i)
    else:
        heapq.heappush(negative, i)

result = 0

while positive:
    result += heapq.heappop(positive)
    for _ in range(m - 1):
        if positive:
            heapq.heappop(positive)

while negative:
    result += heapq.heappop(negative)
    for _ in range(m - 1):
        if negative:
            heapq.heappop(negative)

print(-result * 2 - largest)