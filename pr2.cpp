#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int dp[1001][1001] = {
    0,
};
int n, d;
int board[1001][1001];
int movey[] = {0, 0, 1, -1};
int movex[] = {1, -1, 0, 0};

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> d;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  queue<pair<int,int> > q;
  q.push(make_pair(1002,d));
  while (!q.empty()) {
    int y = q.front().first / 1001;
    int x = q.front().first % 1001;
    int num = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nexty = y + movey[i];
      int nextx = x + movex[i];
      if (nexty < 1 || nextx < 1 || nextx > n || nexty > n) {
        continue;
      }
      if (dp[nexty][nextx] >= num - board[y][x] || num - board[y][x] <= board[n][n])
        continue;
      dp[nexty][nextx] = num - board[y][x];
      q.push(
          make_pair((y + movey[i]) * 1001 + x + movex[i], num - board[y][x]));
    }
  }
  if (dp[n][n] - board[n][n] <= 0) {
    cout << -1;
    return 0;
  }
  cout << dp[n][n] - board[n][n];
}