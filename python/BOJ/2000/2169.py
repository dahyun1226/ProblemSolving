# 백준 온라인 저 2169번: 로봇 조종하기

def lineDown():
    values = list(map(int, input().split()))
    leftSum = [0] * (m + 2)
    rightSum = [0] * (m + 2)
    # 부분합 저장
    for i in range(1, m + 1):
        leftSum[i] = leftSum[i - 1] + values[i - 1]
        rightSum[m - i + 1] = rightSum[m - i + 2] + values[m - i]
    for i in range(m):
        for plus in range(m - i):
            if downLineLeft[i + plus] < upLine[i] + leftSum[i + plus + 1] - leftSum[i]:
                downLineLeft[i + plus] = upLine[i] + leftSum[i + plus + 1] - leftSum[i]
            else:
                break
    for i in range(m - 1, -1, -1):
        for minus in range(i + 1):
            if downLineRight[i - minus] < upLine[i] + rightSum[i - minus + 1] - rightSum[i + 2]:
                downLineRight[i - minus] = upLine[i] + rightSum[i - minus + 1] - rightSum[i + 2]
            else:
                break
    for i in range(m):
        upLine[i] = max(downLineRight[i], downLineLeft[i])


n, m = list(map(int, input().split()))
upLine = [-10000000] * m
upLine[0] = 0
for _ in range(n):
    downLineLeft = [-10000000] * m
    downLineRight = [-10000000] * m
    lineDown()
print(downLineLeft[m - 1])
