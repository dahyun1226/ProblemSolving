# 백준 온라인 저지 11585번: 속타는 저녁 메뉴
# 단순히 반복되는지만 찾으면 된다...
# 쉬운 kmp 문제

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


num = int(input())
a = input().split()
b = input().split()
count = num - makeFail(b)[-1]
print(1, "/", int(num / int(num / count)), sep='')
