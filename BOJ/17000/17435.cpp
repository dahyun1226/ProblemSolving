/*
백준 온라인 저지
17435번 합성함수와 쿼리
https://www.acmicpc.net/problem/17435
희소 테이블 연습문제이다.
https://blog.naver.com/kks227/220793361738
희소 테이블은 위 사이트에서 공부할 수 있다.
희소 테이블 그 자체라 어렵지 않게 풀 수 있다.
200000*log(2)500000의 공간복잡도를 가진다.
20200415
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int m, q, n, x;
int twosquared[20];
int fx[200001][20]; // fx[a][b]에서 b는 2의 b승
int f(int n, int x) {
  int realx = x;
  int realn = n;
  for (int i = 19; i >= 0; i--) {
    if (realn >= twosquared[i]) {
      realn -= twosquared[i];
      realx = fx[realx][i];
    }
    if (realn == 0) {
      return realx;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m;
  for (int i = 1; i <= m; i++)
    cin >> fx[i][0];
  cin >> q;
  twosquared[0] = 1;
  for (int i = 1; i < 20; i++)
    twosquared[i] = twosquared[i - 1] * 2;
  for (int i = 1; i <= 19; i++)
    for (int j = 1; j <= m; j++) {
      fx[j][i] = fx[fx[j][i - 1]][i - 1];
    }
  for (int i = 0; i < q; i++) {
    cin >> n >> x;
    cout << f(n, x) << "\n";
  }
  return 0;
}