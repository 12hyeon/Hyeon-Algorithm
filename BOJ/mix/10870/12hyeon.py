def fibo(n):
    a = 0
    b = 1
    # 0일때의 결과 고려
    for i in range(n):
        # 2 값의 이용
        t = a
        a = b
        b = t+b
    return a
n = int(input())
print(fibo(n))