# 백준 온라인 저지 1305번: 광고
# fail의 이해

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


l = int(input())
ad = input()
print(l - makeFail(ad)[-1])
