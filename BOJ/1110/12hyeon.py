import sys

# 비교하는 pre, 비교될 대상인 now, 다음 비교가 될 next
# 숫자의 마지막 자리수를 이용해야하므로 비교할 때는 각 숫자들이 자리수에 따라 분리된 리스트 이용

# 숫자를 불러들이기
pre = list(map(int, list(sys.stdin.readline().rstrip())))

# 숫자의 합이 1자리인 경우에 2자리 숫자로 만들기
if len(pre) < 2:  # 추가 : len, int 속도 비교
    pre.insert(0, 0)

# 다음 수 만들기
result = 1
now = [pre[-1], sum(pre)%10]

# 다음수를 비교하기
while pre != now:
    # next 생성 & now <- next로 다음 수와 계속 비교
    next = [now[-1], sum(now)%10]
    result += 1
    now = next
print(result)