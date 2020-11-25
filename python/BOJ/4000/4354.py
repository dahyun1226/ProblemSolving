# 백준 온라인 저지 4354번: 문자열 제곱
# 전체 길이 - 실패 함수의 마지막 값이 반복되는 문자라는게 핵심이다.
# 하지만 그것만으로는 부족하다. ababa같은 경우도 있기 때문이다. 이 수가 정확히 나누어 떨어져야한다.
if __name__ == '__main__':
    while True:
        s = input()
        if s == '.': break
        lens = len(s)
        fail = [0] * lens
        matched = 0
        for index in range(1, lens):
            while matched > 0 and s[index] != s[matched]:
                matched = fail[matched - 1]
            if s[index] == s[matched]:
                matched += 1
                fail[index] = matched
        x = fail.pop()
        if x == 0:
            print(1)
        elif int(lens) % int(lens - x) != 0:
            print(1)
        else:
            print(int(lens / (lens - x)))
