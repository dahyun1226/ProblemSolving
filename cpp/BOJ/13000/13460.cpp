/*
백준 온라인 저지
13460번 구슬 탈출 2
https://www.acmicpc.net/problem/13460
삼성 SW 역량 테스트 기출 문제 빨리 푸는 연습 해보기.
구현 위주의 문제이다.
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<string> board;
int dp[11][11][11][11];
int movey[4] = {1, -1, 0, 0};
int movex[4] = {0, 0, -1, 1};
int ry, rx, by, bx, oy, ox;
void solve(int ry, int rx, int by, int bx, int num) {
  //cout << ry << " " << rx << " " << by << " " << bx << " " << num << endl;
  if (num >= 10)
    return;
  if (dp[ry][rx][by][bx] <= num)
    return;
  dp[ry][rx][by][bx] = num;
  for (int i = 0; i < 4; i++) {
    int nry = ry;
    int nrx = rx;
    int nby = by;
    int nbx = bx;
    bool flag = false;
    bool osuccess = false;
    bool breakcase = false;
    while (!flag) {
      nry += movey[i];
      nrx += movex[i];
      if (board[nry][nrx] == '#' || (nry == nby && nrx == nbx)) {
        flag = true;
        nry -= movey[i];
        nrx -= movex[i];
      }
      if (board[nry][nrx] == 'O') {
        flag = true;
        osuccess = true;
      }
    }
    flag = false;
    while (!flag) {
      nby += movey[i];
      nbx += movex[i];
      if (board[nby][nbx] == 'O') {
        breakcase = true;
        break;
      }
      if (board[nby][nbx] == '#' || (nry == nby && nrx == nbx)) {
        flag = true;
        nby -= movey[i];
        nbx -= movex[i];
      }
    }
    if (breakcase) {
      continue;
    }
    if (osuccess) {
      dp[nry][nrx][nby][nbx] = min(dp[nry][nrx][nby][nbx], num + 1);
      return;
    }
    flag = false;
    while (!flag) {
      nry += movey[i];
      nrx += movex[i];
      if (board[nry][nrx] == '#' || (nry == nby && nrx == nbx)) {
        flag = true;
        nry -= movey[i];
        nrx -= movex[i];
      }
    }
    solve(nry, nrx, nby, nbx, num + 1);
  }
  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  fill(&dp[0][0][0][0], &dp[0][0][0][0] + 11 * 11 * 11 * 11, 100);
  for (int i = 0; i < n; i++) {
    string putstring;
    cin >> putstring;
    board.push_back(putstring);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (board[i][j] == 'R') {
        ry = i;
        rx = j;
      }
      if (board[i][j] == 'B') {
        by = i;
        bx = j;
      }
      if (board[i][j] == 'O') {
        oy = i;
        ox = j;
      }
    }
  }
  solve(ry, rx, by, bx, 0);
  int answer = 100;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (dp[oy][ox][i][j] < answer)
        answer = dp[oy][ox][i][j];
    }
  }
  if (answer > 10) {
    cout << -1;
    return 0;
  }
  cout << answer;
  return 0;
}

// 6 6
// ######
// ##...#
// #....#
// #..#.#
// #RBO.#
// ######
// 답이 4가 나와야한다.