dice = sorted(list(map(int, input().split())))
# 정렬된 주사위 리스트를 이용해서 각 조건에 따른 값 출력
if dice[0] == dice[2] :
    # 가장 작은 수와 가장 큰 수가 같다는 것은 사이 모든 수가 같다는 의미
    print(10000 + dice[0] * 1000)
elif dice[0] == dice[1] or dice[1] == dice[2]:
    # 3개가 모두 같은 경우 제외하고 크기 관계를 생각하면, 위 2가지만 2개가 같은 경우임
    print(1000+dice[1] * 100)
else: # 같은 것이 없는 경우 - 최대값을 이용
    print(dice[2]*100)
