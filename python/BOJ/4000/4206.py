# 백준 온라인 저지 4206번: 피보나치 단어

def makeFail(n: str):
    fail = [0] * len(n)
    matched = 0
    for index in range(1, len(n)):
        while matched > 0 and n[index] != n[matched]:
            matched = fail[matched - 1]
        if n[index] == n[matched]:
            matched += 1
            fail[index] = matched
    return fail


failn = []
nums = [str(0)] * 102
nums[1] = str(1)
for i in range(2, 101):
    nums[i] = nums[i - 1] + nums[i - 2]
    # i는 27이다
    if len(nums[i]) > 1000000:
        break


def kmp(h: str, n: str):
    result = []
    matched = 0
    fail = makeFail(n)
    for index in range(0, len(h)):
        while matched > 0 and h[index] != n[matched]:
            matched = fail[matched - 1]
        if h[index] == n[matched]:
            matched += 1
            if matched == len(n):
                result.append(index - matched + 1)
                matched = fail[matched - 1]
    return len(result)


tc = 1
while True:
    try:
        n = int(input())
        bits = input()
        dp = [0] * 102
        if bits == '0': dp[0] = 1
        if bits == '1': dp[1] = 1
        for index in range(2, n + 1):
            if len(nums[index]) < len(bits) and index <= 30:
                continue
            dp[index] = dp[index - 1] + dp[index - 2]
            if index <= 30:
                dp[index] += kmp(
                    nums[index - 1][max(0, len(nums[index - 1]) - len(bits) + 1):] + nums[index - 2][
                                                                                     :min(len(bits) - 1,
                                                                                          len(nums[index - 2]))], bits)
            else:
                dp[index] += (dp[30] - dp[29] - dp[28])
        print("Case " + str(tc) + ": " + str(dp[n]))
        tc += 1
    except EOFError:
        break
