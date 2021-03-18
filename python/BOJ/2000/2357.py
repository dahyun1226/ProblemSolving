# 백준 온라인 저지 2357번: 최솟값과 최댓값
# 세그먼트 트리로 무난하게 풀 수 있을 것으로 보인다.
import sys

MAX_NUM = 1000000001
N, M = map(int, sys.stdin.readline().split())
maxTree = []
minTree = []
minTwo = 1


def minfind(l, r, nodel, noder, nodenum):
    if l <= nodel and noder <= r:
        return minTree[nodenum]
    if r < nodel or noder < l:
        return MAX_NUM
    mid = int((nodel + noder) / 2)
    return min(minfind(l, r, nodel, mid, nodenum * 2), minfind(l, r, mid + 1, noder, nodenum * 2 + 1))


def maxfind(l, r, nodel, noder, nodenum):
    if l <= nodel and noder <= r:
        return maxTree[nodenum]
    if r < nodel or noder < l:
        return 0
    mid = int((nodel + noder) / 2)
    return max(maxfind(l, r, nodel, mid, nodenum * 2), maxfind(l, r, mid + 1, noder, nodenum * 2 + 1))


while minTwo < N:
    minTwo *= 2
for i in range(minTwo):
    minTree.append(0)
    maxTree.append(0)
for i in range(N):
    nums = int(sys.stdin.readline())
    minTree.append(nums)
    maxTree.append(nums)
for i in range(minTwo - N):
    minTree.append(MAX_NUM)
    maxTree.append(0)
for i in range(minTwo - 1, 0, -1):
    minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1])
    maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1])
for i in range(M):
    l, r = map(int, sys.stdin.readline().split())
    print(minfind(l, r, 1, minTwo, 1), maxfind(l, r, 1, minTwo, 1))
