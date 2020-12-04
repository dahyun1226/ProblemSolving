# 백준 온라인 저지 1948번: 임계경로

n = int(input())
m = int(input())
topo = [0] * n
go = [[] for i in range(n)]
rego = [[] for i in range(n)]
for i in range(m):
    a, b, t = list(map(int, input().split()))
    go[a - 1].append([b - 1, t])
    rego[b - 1].append([a - 1, t])
    topo[b - 1] += 1
FirstCity, lastCity = list(map(int, input().split()))
FirstCity -= 1
lastCity -= 1
maxValue = [0] * n
q = [FirstCity]
answer = 0
roadAnswer = 0
maxValue[FirstCity] = 0
while len(q) > 0:
    now = q.pop()
    for i in range(len(go[now])):
        next, cost = go[now][i]
        if maxValue[next] < maxValue[now] + cost:
            maxValue[next] = maxValue[now] + cost
        topo[next] -= 1
        if next == lastCity:
            answer = max(maxValue[now] + cost, answer)
            continue
        if topo[next] == 0:
            q.append(next)
# 역으로 찾기
q = [lastCity]
visited = [0] * n
while len(q) > 0:
    now = q.pop()
    for i in range(len(rego[now])):
        next, cost = rego[now][i]
        if maxValue[now] - maxValue[next] == cost:
            roadAnswer += 1
            if visited[next] == 0:
                q.append(next)
                visited[next] = 1
print(answer)
print(roadAnswer)
