# 백준 온라인 저지 10265: MT

def dfs(start):
    gone[start] = True
    # 아직 안가본 곳
    if gone[to[start]] is False:
        dfs(to[start])
        if realCycle[start] is False:
            cycleMap[cycle[to[start]]][1] += 1
            cycle[start] = cycle[to[start]]
    # 아직 안만들어진 사이클인 경우
    elif cycle[to[start]] == -1:
        global totalCycleNum
        totalCycleNum += 1
        cycleMap[totalCycleNum] = [0, 0]
        makeCycle(to[start], start, totalCycleNum)
    # 가봤으나 사이클이 없는 경우이거나 이미 만들어진 사이클인 경우
    else:
        cycleMap[cycle[to[start]]][1] += 1
        cycle[start] = cycle[to[start]]


def makeCycle(start, end, cycleNum):
    cycleMap[cycleNum][0] += 1
    cycle[start] = cycleNum
    realCycle[start] = True
    if start is end:
        return
    makeCycle(to[start], end, cycleNum)


n, k = list(map(int, input().split(" ")))
to = list(map(int, input().split(" ")))
to.insert(0, 0)
totalCycleNum = 0

# cycle check
gone = [False] * (n + 1)
cycle = [-1] * (n + 1)
realCycle = [False] * (n + 1)
cycleMap = {}
for i in range(1, n + 1):
    if gone[i] is False:
        dfs(i)

dp = [False] * (n + 1)
for p in range(1, totalCycleNum + 1):
    cycle = cycleMap[p]
    dp2 = dp.copy()
    for i in range(cycle[0], cycle[0] + cycle[1] + 1):
        for j in range(0, n + 1):
            if dp2[j] is True and j + i <= n:
                dp[j + i] = True
        dp[i] = True
dp[0] = True
for s in range(k, -1, -1):
    if dp[s]:
        print(s)
        exit()
