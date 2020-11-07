/*
백준 온라인 저지
1019번 책 페이지
https://www.acmicpc.net/problem/1019
수는 10억까지.
*/
#include <iostream>
#include <vector>
using namespace std;
long long allnum[10];
long long numDevideLeft[10];
long long numDevideRight[10];
long long numByTenPower[10];

template <typename T> void c(T t) { cout << t << " "; }

long long npow(long long n) {
  if (n == 0)
    return 1;
  return npow(n - 1) * 10;
}

int main() {

  fill(&allnum[0], &allnum[0] + 10, 0);
  fill(&numDevideLeft[0], &numDevideLeft[0] + 10, 0);
  fill(&numDevideRight[0], &numDevideRight[0] + 10, 0);
  fill(&numByTenPower[0], &numByTenPower[0] + 10, 0);
  long long n;
  cin >> n;
  long long realn = n;
  int tenPower = 0;
  numDevideLeft[0] = n;
  numByTenPower[1] = n;
  while (n >= 10) {
    tenPower++;
    numByTenPower[tenPower] = n % 10;
    numDevideLeft[tenPower] = (n - numByTenPower[tenPower]) / 10;
    numDevideRight[tenPower] = realn - numDevideLeft[tenPower] * npow(tenPower);
    n /= 10;
    if (n < 10) {
      numByTenPower[tenPower + 1] = numDevideLeft[tenPower];
      numDevideRight[tenPower + 1] = realn;
    }
  }
  // for (int i = 0; i <= tenPower+1; i++) {
  //   c(numByTenPower[i]);
  //   c(numDevideLeft[i]);
  //   c(numDevideRight[i]);
  //   cout << endl;
  // }
  for (int num = 0; num < 10; num++)
    for (int jari = 1; jari <= tenPower + 1; jari++) {
      if (num == 0) {
        allnum[num] += (numDevideLeft[jari] - 1) * npow(jari - 1);
      } else {
        allnum[num] += numDevideLeft[jari] * npow(jari - 1);
      }
      if (num < numByTenPower[jari]) {
        allnum[num] += npow(jari - 1);
      } else if (num == numByTenPower[jari]) {
        allnum[num] += numDevideRight[jari - 1] + 1;
      }
    }
  for (int i = 0; i < 9; i++)
    cout << allnum[i] << " ";
  cout << allnum[9];
}
