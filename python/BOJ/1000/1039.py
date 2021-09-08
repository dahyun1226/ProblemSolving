# 백준 온라인 저지 1039번: 교환
from queue import Queue

n, k = list(map(int, input().split(" ")))
m = len(str(n))
if m == 1:
    print(-1)
    exit()
dp = [False] * 2000001
q = Queue()
q.put([n, 0])
answer = -1
while not q.empty():
    now = q.get()
    for i in range(0, m - 1):
        for j in range(i + 1, m):
            before = str(now[0])
            after = before[:i]
            if len(after) > 0 and after[0] == "0":
                continue
            after += before[j]
            if after[0] == "0":
                continue
            after += before[i + 1:j] + before[i] + before[j + 1:]
            next = int(after)
            if not dp[next * ((now[1] + 1) % 2 + 1)]:
                if (now[1] + 1 - k) % 2 == 0:
                    answer = max(next, answer)
                if now[1] + 1 < k:
                    dp[next * ((now[1] + 1) % 2 + 1)] = True
                    q.put([next, now[1] + 1])
print(answer)
