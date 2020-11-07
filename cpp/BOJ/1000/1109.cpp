/*
백준 온라인 저지
1109번 섬
https://www.acmicpc.net/problem/1109
먼저 섬의 번호를 정해준다.(landNumbering)
그 이후 가장 바깥에 있는 물부터 시작해서 (그걸 위해서 맨 바깥쪽에 물을 다 추가했다.)
각 섬마다 내부의 바다를 탐색하는 bfs를 통해
섬들의 연결 리스트를 만들어 준다.
최종적으로 연결리스트를 dfs로 섬의 높이를 구한다.
참고 풀이
https://lyzqm.blogspot.com/2017/11/1109.html
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXDEEP 1000
int n, m;
bool board[53][53];
int landNumBoard[53][53];
int landNum = 0;
int movey[] = {0, 0, -1, 1, 1, 1, -1, -1};
int movex[] = {1, -1, 0, 0, 1, -1, 1, -1};
vector<int> adj[MAXDEEP];
vector<int> landPosition[MAXDEEP];
queue<int> nowProcess;
bool isAdj[MAXDEEP][MAXDEEP];
int deeps[MAXDEEP];

int dfs(int here) {
  int thisdeep = 0;
  for (int i = 0; i < adj[here].size(); i++) {
    thisdeep = max(dfs(adj[here][i]) + 1, thisdeep);
  }
  deeps[thisdeep]++;
  return thisdeep;
}

void landNumbering(int y, int x, int num) {
  landNumBoard[y][x] = num;
  queue<int> q;
  q.push(y * m + x);
  while (!q.empty()) {
    int nowy = q.front() / m;
    int nowx = q.front() % m;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int nexty = nowy + movey[i];
      int nextx = nowx + movex[i];
      if (nexty >= 0 && nextx >= 0 && nexty < n && nextx < m &&
          landNumBoard[nexty][nextx] == 0 && board[nexty][nextx] == 1) {
        q.push(nexty * m + nextx);
        landPosition[num].push_back(nexty * m + nextx);
        landNumBoard[nexty][nextx] = num;
      }
    }
  }
  landNum++;
}

void adjSeaByLandNum(int num) {
  queue<int> q;
  for (int i = 0; i < landPosition[num].size(); i++) {
    q.push(landPosition[num][i]);
  }
  if (num == 0) {
    q.push(0);
  }
  while (!q.empty()) {
    int nowy = q.front() / m;
    int nowx = q.front() % m;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nexty = nowy + movey[i];
      int nextx = nowx + movex[i];
      if (nexty >= 0 && nextx >= 0 && nexty < n && nextx < m &&
          landNumBoard[nexty][nextx] == 0 && board[nexty][nextx] == 0) {
        landNumBoard[nexty][nextx] = 7;
        q.push(nexty * m + nextx);
      } else if (board[nexty][nextx] == 1 &&
                 landNumBoard[nexty][nextx] != num &&
                 isAdj[num][landNumBoard[nexty][nextx]] == 0) {
        isAdj[num][landNumBoard[nexty][nextx]] = 1;
        adj[num].push_back(landNumBoard[nexty][nextx]);
        nowProcess.push(landNumBoard[nexty][nextx]);
      }
    }
  }
}

int main() {
  //입력받기
  bool noLand = true;
  cin >> n >> m;
  string putboard;
  for (int j = 0; j < m + 2; j++) {
    board[0][j] = 0;
    board[n + 1][j] = 0;
  }
  for (int i = 1; i < n + 1; i++) {
    cin >> putboard;
    board[i][0] = 0;
    board[i][n + 1] = 0;
    for (int j = 1; j < m + 1; j++) {
      if (putboard[j - 1] == 'x') {
        noLand = false;
        board[i][j] = 1;
      } else {
        board[i][j] = 0;
      }
    }
  }
  n += 2;
  m += 2;
  // 섬이 없는 예외 상황
  if (noLand) {
    cout << -1;
    return 0;
  }
  fill(&isAdj[0][0], &isAdj[0][0] + MAXDEEP * MAXDEEP, 0);
  fill(&landNumBoard[0][0], &landNumBoard[0][0] + 53 * 53, 0);
  landNum = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 1 && landNumBoard[i][j] == 0) {
        landNumbering(i, j, landNum);
      }
    }
  nowProcess.push(0);
  while (!nowProcess.empty()) {
    adjSeaByLandNum(nowProcess.front());
    nowProcess.pop();
  }
  int maxdeep = dfs(0);
  for (int i = 0; i < maxdeep - 1; i++)
    cout << deeps[i] << " ";
    cout << deeps[maxdeep - 1];
  return 0;
}