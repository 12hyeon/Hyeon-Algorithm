import sys

# 비교가 될 집단의 수 담기
g_num = int(sys.stdin.readline())
# 집단을 입력받기
group = []
for g in range(g_num):
    value = list(map(int, sys.stdin.readline().rstrip().split()))
    group += [[value[0], value[1:]]]

# 집단의 평균 구하기

for p_num, score in group:
    ave = sum(score)/p_num
    p = 0
    for s in score:
        if s > ave:
            p += 1
    # 평균을 넘는 인원의 비율 구하기
    result = round(p/p_num, 5)
    print('{:.3f}%'.format(result*100))
