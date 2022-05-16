# dijkstra 알고리즘 구현

INF = 10000

def dijkstr(g, s, n):
    node = [0] * n  # 방문한 노드 1, 방문 전 노드 0
    d = [0] * n  # 거리 기록
    node[s] = 1  # 방문 노드
    for i in range(n):
        d[i] = g[s][i] # 시작 노드에서부터 각 노드까지의 거리

    for i in range(n-1) : # 나머지 노드 처리
        now = INF # 거리
        min = 0 # 인덱스
        for j in range(n):
            if (node[j] == 0) and (d[j] < now):
                now = d[j]  # 방문전 노드까지 거리의 최소
                min = j
        node[min] = 1 # 노드 방문

        for j in range(n):
            if (node[j] == 0):
                if (d[min]+g[min][j] < d[j]) :
                    d[j] = d[min] + g[min][j]
                    # 현재 선택한 노드를 지나는 길이 가장 값이 적으면 업데이트
    return d

n = int(input("입력할 그래프의 노드 수를 입력하세요 >> "))
g = [[0]]*n # 그래프

cnt = 0
while 1 :
    print("그래프를 입력하시오. 단, 무한대는 10000으로 나타내시오.")
    cnt = 0
    for x in range(n):
        print("  ", chr(65+x), end="  ")
    print()
    for x in range(n):
        print(chr(65+x), end=": ")
        g[x] = list(map(int, input().rstrip().split()))
        cnt += len(g[x])
    if cnt == n*n:
        break
    else:
        print('\n입력된 정보가 잘못 되었습니다.')

distance = dijkstr(g, 0, n)

print('\n최단 경로')
for i in range(n):
    print(chr(65+i), ":", distance[i])
