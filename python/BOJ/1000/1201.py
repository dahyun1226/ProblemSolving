# 백준 온라인 저지 1201번: NMK
# 핵심은 M * K의 그룹을 상대적으로 각각 만든다는 것
# 풀이과정이 너무 천재적인데...? 나눈다는 생각을 내가 할 수 있을까 싶다.
# 10 3 4 case
N, M, K = list(map(int, input().split()))
if N < M + K - 1:
    print(-1)
    exit()
elif N > M * K:
    print(-1)
    exit()
raw = []
for i in range(1, N + 1):
    raw.append(i)
# 나누는 건 K빼고 M-1개니까 (N-K)/(M-1)
answer = raw[:K]
answer.sort(reverse=True)
batch = []
if K != N:
    quoitent = int((N - K) / (M - 1))
    remainder = int((N - K) - quoitent * (M - 1))
    for i in range(0, remainder):
        batch.append(quoitent + 1)
    for i in range(remainder, M - 1):
        batch.append(quoitent)
index = K
for i in batch:
    tmp = raw[index: index + i]
    tmp.sort(reverse=True)
    answer += tmp
    index += i
for i in range(len(answer)):
    if i != len(answer) - 1:
        print(answer[i], end=' ')
    else:
        print(answer[i])
