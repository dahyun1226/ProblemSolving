# 백준 온라인 저지 2401번: 최대 문자열 붙여넣기
# kmp와 dp의 만남

def makeFail(n: str):
    fail = []
    for i in range(len(n)):
        fail.append(0)
    matched = 0
    for index in range(1, len(n)):
        while matched > 0 and n[index] != n[matched]:
            matched = fail[matched - 1]
        if n[index] == n[matched]:
            matched += 1
            fail[index] = matched
    return fail


long = input()
num = int(input())
short = []
shortFail = []
dp = [0] * (len(long) + 1)
for i in range(num):
    short.append(input())
    shortFail.append(makeFail(short[i]))
matchedMemory = [0] * 500
for index in range(1, len(long) + 1):
    dp[index] = dp[index - 1]
    for shortNum in range(num):
        while matchedMemory[shortNum] > 0 and short[shortNum][matchedMemory[shortNum]] != long[index - 1]:
            matchedMemory[shortNum] = shortFail[shortNum][matchedMemory[shortNum] - 1]
        if short[shortNum][matchedMemory[shortNum]] == long[index - 1]:
            matchedMemory[shortNum] += 1
            if matchedMemory[shortNum] == len(short[shortNum]):
                dp[index] = max(dp[index], dp[index - len(short[shortNum])] + len(short[shortNum]))
                matchedMemory[shortNum] = shortFail[shortNum][-1]
print(dp[-1])
