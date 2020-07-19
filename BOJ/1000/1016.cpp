/*
백준 온라인 저지
1016번 제곱 ㄴㄴ 수
https://www.acmicpc.net/problem/1016
20200718
min max는 둘다 long long 값.
결국 100만개니까, 다 해보면 될 듯? 결국 4, 9 이런식으로 나눠지니까.
10^12니까. 제곱수는 10^6까지밖에 안된다.
근데 이 제곱수는 10^3의 제곱이잖아? 1000개다.각각 1000개만 하면 된다는 거지.
근데 이 제곱수에서도 겹치는게 있다. 소수만 하면 된다.
먼저 소수를 여유있게 1200까지 구해두자.
시간초과네?
왜 안되는지 모르겠다.
10000 1000000
500000 1234567
같은 예시들 다 맞는데.
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long minnum, maxnum;
  cin >> minnum >> maxnum;
  // 간단한 소수 체크
  bool isPrimeNum[1500];
  fill(&isPrimeNum[0], &isPrimeNum[0] + 1500, true);
  isPrimeNum[0] = false;
  isPrimeNum[1] = false;
  for (long long i = 2; i * i < 1500; i++) {
    for (long long j = 2; i * j < 1500; j++) {
      isPrimeNum[i * j] = false;
    }
  }

  vector<long long> prime;
  for (long long i = 2; i < 1500; i++) {
    if (isPrimeNum[i]) {
      prime.push_back(i * i);
    }
  }

  long long answer = maxnum - minnum + 1;
  for (long long i = minnum; i <= maxnum; i++) {
    for (long long j = 0; j < prime.size(); j++) {
      if (i % prime[j] == 0) {
        answer--;
        break;
      }
    }
  }
  cout << answer;
  return 0;
}