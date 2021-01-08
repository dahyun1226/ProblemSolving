# 백준 온라인 저지 3392번: 화성 지도
# line sweeping
# 구간이지만 정확하게는 lazy propagation이 아니다.

from functools import cmp_to_key


def update(l, r, nodenum, nodel, noder, inout):
    if r < nodel or noder < l:
        return
    if l <= nodel and noder <= r:
        segmentTree[nodenum][1] += inout
    elif nodenum < two:
        mid = int((nodel + noder) / 2)
        update(l, r, nodenum * 2, nodel, mid, inout)
        update(l, r, nodenum * 2 + 1, mid + 1, noder, inout)
    if segmentTree[nodenum][1] > 0:
        segmentTree[nodenum][0] = noder - nodel + 1
    else:
        if nodenum >= two:
            segmentTree[nodenum][0] = 0
        else:
            segmentTree[nodenum][0] = segmentTree[nodenum * 2][0] + segmentTree[nodenum * 2 + 1][0]


def compare(x, y):
    if y[0] < x[0]:
        return 1
    else:
        return -1


N = int(input())
xlist = []
for i in range(N):
    x1, y1, x2, y2 = list(map(int, input().split()))
    xlist.append([x1, y1, y2, 1])
    xlist.append([x2, y1, y2, -1])
xlist = sorted(xlist, key=cmp_to_key(compare))
two = 2
while two < 30000:
    two *= 2
segmentTree = []
for i in range(two * 2):
    segmentTree.append([0, 0])
sum = 0
lastx = 0
flag = 0
for x, y1, y2, inout in xlist:
    if flag:
        sum += (x - lastx) * segmentTree[1][0]
    update(y1 + 1, y2, 1, 1, two, inout)
    flag = 1
    lastx = x
print(sum)
