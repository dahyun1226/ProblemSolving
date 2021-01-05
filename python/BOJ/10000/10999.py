# 백준 온라인 저지 10999번: 구간 합 구하기 2
# 레이지 프로파게이션

def propagate(nodenum, nodel, noder):
    if tree[nodenum][1] != 0 and nodenum < two:
        if nodenum * 2 >= two:
            tree[nodenum * 2][0] += tree[nodenum][1]
            tree[nodenum * 2 + 1][0] += tree[nodenum][1]
        else:
            tree[nodenum * 2][1] += tree[nodenum][1]
            tree[nodenum * 2 + 1][1] += tree[nodenum][1]
        tree[nodenum][0] += (noder - nodel + 1) * tree[nodenum][1]
        tree[nodenum][1] = 0


def update(l, r, val, nodenum, nodel, noder):
    propagate(nodenum, nodel, noder)
    if noder < l or r < nodel:
        return
    if l <= nodel and noder <= r:
        if nodenum >= two:
            tree[nodenum][0] += val
            return
        else:
            tree[nodenum][1] += val
            propagate(nodenum, nodel, noder)
            return
    mid = int((nodel + noder) / 2)
    update(l, r, val, nodenum * 2, nodel, mid)
    update(l, r, val, nodenum * 2 + 1, mid + 1, noder)
    tree[nodenum][0] = tree[nodenum * 2][0] + tree[nodenum * 2 + 1][0]


def sum(l, r, nodenum, nodel, noder):
    propagate(nodenum, nodel, noder)
    if noder < l or r < nodel:
        return 0
    if l <= nodel and noder <= r:
        return tree[nodenum][0]
    mid = int((nodel + noder) / 2)
    return sum(l, r, nodenum * 2, nodel, mid) + sum(l, r, nodenum * 2 + 1, mid + 1, noder)


N, M, K = list(map(int, input().split()))
tree = []
two = 1
while two <= N:
    two *= 2
for i in range(two * 2):
    tree.append([0, 0])
for i in range(N):
    tree[two + i][0] = int(input())
for i in range(two - 1, 0, -1):
    tree[i][0] = tree[i * 2][0] + tree[i * 2 + 1][0]
for i in range(M + K):
    query = list(map(int, input().split()))
    if query[0] == 1:
        update(query[1], query[2], query[3], 1, 1, two)
    else:
        print(sum(query[1], query[2], 1, 1, two))
