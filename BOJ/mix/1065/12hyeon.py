import sys

max = int(sys.stdin.readline())
if max < 100:
    print(max)
else:
    result = 99
    length = len(str(max))
    for i in range(3, length+1): # i: 3~
        for d in range(5): # d: 0~4
            first = 1
            while (first+d*(i-1) < 10) :
                value = [str(first + d*n) for n in range(i)]
                if int(''.join(value)) <= max:
                    result += 1
                if d != 0 and value[0] == '1':
                    next = [str(first + d*n -1) for n in range(i)]
                    if int(''.join(reversed(next))) <= max:
                        result += 1
                if d != 0 and int(''.join(reversed(value))) <= max:
                    result += 1
                    print('2:', str(int(''.join(reversed(value)))))
                first += 1
    print(result)

# 생각 루틴

# 노가다 생각 -> 범위마다 자르는 방향 -> 예시를 보니 결과가 비슷해서 99이하 처리 확인
# -> 예시를 써가면서 규칙찾기
# -> len, d, 끝이 10보다 작은 경우만 돌아가게 (확실히 조건에 대한 것은 for문보다 while문이 나음)
# -> d>0일때 말고 d<0일때도 필요하다는 사실 인지
# -> d=0일때도 고려함 인지
# -> d<0인 경우에는 마지막이 0이 될 수도 있음 고려
