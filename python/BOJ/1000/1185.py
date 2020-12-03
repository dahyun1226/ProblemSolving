# 백준 온라인 저지 1185번: 유럽여행
# 2016170813 산업경영공학부 강다현

import heapq

n, p = list(map(int, input().split()))
country = []
mincon = [-1, 1001]
# 입력 받기
for i in range(n):
    x = int(input())
    if x < mincon[1]:
        mincon[0] = i
        mincon[1] = x
    country.append(x)
dist = [[] * n for _ in range(n)]
for i in range(p):
    a, b, cost = list(map(int, input().split()))
    dist[a - 1].append([b - 1, cost])
    dist[b - 1].append([a - 1, cost])
# MST 만들기 - 프림 알고리즘
answer = 0
added = [0] * n
pq = [[0, 0]]
while len(pq) > 0:
    cost, con = heapq.heappop(pq)
    if added[con] != 0:
        continue
    added[con] = 1
    answer += cost
    for i in range(len(dist[con])):
        next, di = dist[con][i]
        heapq.heappush(pq, [di * 2 + country[con] + country[next], next])
print(mincon[1] + answer)
