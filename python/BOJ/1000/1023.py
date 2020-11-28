# 백준 온라인 저지 1023번: 괄호 문자열
# https://sgc109.tistory.com/128 참고 블로그
# dp[i][j] : 이미 i개의 문자가 정해졌고 짝이 지어지지않은 열린 괄호의 수가 현재 j 개일 때 괄호 문자열의 수

dp = []


def go(pos, openBracket):
    if pos == n:
        return openBracket == 0
    if dp[pos][openBracket] != -1:
        return dp[pos][openBracket]
    dp[pos][openBracket] = 0
    dp[pos][openBracket] += go(pos + 1, openBracket + 1)
    if openBracket > 0:
        dp[pos][openBracket] += go(pos + 1, openBracket - 1)
    return dp[pos][openBracket]


if __name__ == '__main__':
    n = int(input())
    # k = input()
    appendList = []
    for i in range(0, 51):
        appendList.append(-1)
    for i in range(0, 51):
        appendListPut =appendList.copy()
        dp.append(appendListPut)
    print(go(0, 0))
