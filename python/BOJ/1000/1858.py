# 백준 온라인 저지 1858번: k번째 최단경로 찾기

import heapq

n, m, k = map(int, input().split())
adj = [[] for _ in range(n)]
for edge in range(m):
    i, j, time = map(int, input().split())
    adj[i - 1].append([j - 1, time])
dist = [[] for _ in range(n)]
pq = [[0, 0]]
while len(pq) > 0:
    nowCost, now = heapq.heappop(pq)
    if len(dist[now]) >= k:
        continue
    dist[now].append(nowCost)
    for next, nextCost in adj[now]:
        if len(dist[next]) >= k:
            continue
        heapq.heappush(pq, [nowCost + nextCost, next])
for i in range(n):
    if len(dist[i]) < k:
        print(-1)
    else:
        print(dist[i][-1])
