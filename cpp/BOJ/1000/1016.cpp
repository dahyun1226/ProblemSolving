/*
백준 온라인 저지
1016번 제곱 ㄴㄴ 수
https://www.acmicpc.net/problem/1016
잘못 생각한 문제.
소수를 제대로 이해하도록 하자...
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long minnum, maxnum;
  cin >> minnum >> maxnum;
  // 간단한 소수 체크
  bool cantDivide[1000001];
  long long answer = maxnum - minnum + 1;
  fill(&cantDivide[0], &cantDivide[0] + 1000001, false);

  for (long long i = 2; i < 1000010; i++) {
    long long dividenum = i * i;
    long long initnum = dividenum + minnum - minnum % dividenum;
    if (minnum % dividenum == 0)
      initnum -= dividenum;
    for (long long j = initnum; j >= minnum && j <= maxnum; j += dividenum) {
      cantDivide[j - minnum] = true;
    }
  }

  for (int i = 0; i < maxnum - minnum + 1; i++) {
    if (cantDivide[i])
      answer--;
  }
  cout << answer;
  return 0;
}
