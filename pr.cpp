#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
/*
포인트는 무조건 거리가 2라는 것.
경우의 수는 6가지. R시작.
*/
#define BIGINT 100000000
int main() {
  int r, g, realb;
  cin >> r >> g >> realb;
  string flower;
  cin >> flower;
  char f[] = {'R', 'G', 'B'};
  int mincost = BIGINT;
  int minnum = BIGINT;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        if (i == j || i == k || j == k)
          continue;
        char a = f[i]; // 3으로 나눈 수.
        char b = f[j];
        char c = f[k];
        int fn[100];
        fn['R'] = 0;
        fn['B'] = 0;
        fn['G'] = 0;
        int num = 0;
        for (int fi = 0; fi < flower.size(); fi++) {
          if (fi % 3 == 0) {
            if (flower[fi] == a) {
              continue;
            } else if (flower[fi] == b) {
              num++;
              fn[b]--;
              fn[a]++;
            } else if (flower[fi] == c) {
              num++;
              fn[a]++;
              fn[c]--;
            }
          }
          if (fi % 3 == 1) {
            if (flower[fi] == b) {
              continue;
            } else if (flower[fi] == a) {
              num++;
              fn[a]--;
              fn[b]++;
            } else if (flower[fi] == c) {
              num++;
              fn[c]--;
              fn[b]++;
            }
          }
          if (fi % 3 == 2) {
            if (flower[fi] == c) {
              continue;
            } else if (flower[fi] == b) {
              num++;
              fn[b]--;
              fn[c]++;
            } else if (flower[fi] == a) {
              num++;
              fn[a]--;
              fn[c]++;
            }
          }
        }
        int cost =
            max(fn['R'], 0) * r + max(fn['G'], 0) * g + max(fn['B'], 0) * realb;
        if (cost < mincost) {
          mincost = cost;
          minnum = num;
        } else if (cost == mincost) {
          minnum = min(minnum, num);
        }
      }
  cout << mincost << " " << minnum;
}

// rrggb

// rgbrg
// g 2개 뽑고 2개 넣어야함.
// b 1개 뽑고 1개 넣어야함.
// r 1개 뽑고 1개 넣어야함
// 비용 0 횟수4
// rbgrb
// g 1개 뽑고 0개 넣기
// b 0개 뽑고 1개 넣기
// r 1개 뽑고 1개 넣기
// 비용 b 횟수 2
// grbgr
// gbrgb
// bgrbg
// brgbr