/*
백준 온라인 저지
2839번 설탕 배달
https://www.acmicpc.net/problem/2839
20200720
단순한게 풀었는데, 그리 단순하지만은 않았던 문제랄까.
*/
#include <iostream>
using namespace std;
int main() {
  int board[30];
  fill(&board[0], &board[0] + 30, 5000);
  int n;
  int answer = 0;
  cin >> n;
  if (n >= 30) {
    answer += ((n - 15) / 15) * 3;
    n -= (((n - 15) / 15) * 15);
  }
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 6; k++) {
        if (0 <= 3 * j + k * 5 && 3 * j + k * 5 < 30)
          board[3 * j + k * 5] = min(k + j, board[3 * j + k * 5]);
      }
    }
  }
  if (board[n] == 5000) {
    cout << -1;
    return 0;
  } else
    cout << answer + board[n];
}