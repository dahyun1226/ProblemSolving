/*
백준 온라인 저지
12100 2048(Easy)
https://www.acmicpc.net/problem/12100
삼성 SW 역량 테스트 기출 문제 빨리 푸는 연습 해보기.
구현 위주의 문제이다.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//위아래왼오
int n;
int board[20][20];
int newboard[20][20];
int dp[20][20][1024];
int maxnum = 0;
queue<int> qs;
void up() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (newboard[j][i] != 0) {
        qs.push(newboard[j][i]);
      }
    }
    int num = 0;
    while (!qs.empty()) {
      int temp = qs.front();
      qs.pop();
      if (!qs.empty()) {
        if (qs.front() == temp) {
          newboard[num][i] = temp * 2;
          maxnum = max(maxnum, newboard[num][i]);
          qs.pop();
          num++;
        } else {
          newboard[num][i] = temp;
          num++;
        }
      } else {
        newboard[num][i] = temp;
        maxnum = max(maxnum, newboard[num][i]);
        num++;
      }
    }
    for (int j = num; j < n; j++) {
      newboard[j][i] = 0;
    }
  }
}

void down() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (newboard[n - j - 1][i] != 0) {
        qs.push(newboard[n - j - 1][i]);
      }
    }
    int num = 0;
    while (!qs.empty()) {
      int temp = qs.front();
      qs.pop();
      if (!qs.empty()) {
        if (qs.front() == temp) {
          newboard[n - num - 1][i] = temp * 2;
          maxnum = max(maxnum, newboard[n - num - 1][i]);
          qs.pop();
          num++;
        } else {
          newboard[n - num - 1][i] = temp;
          num++;
        }
      } else {
        newboard[n - num - 1][i] = temp;
        maxnum = max(maxnum, newboard[n - num - 1][i]);
        num++;
      }
    }
    for (int j = num; j < n; j++) {
      newboard[n - j - 1][i] = 0;
    }
  }
}

void left() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (newboard[i][j] != 0) {
        qs.push(newboard[i][j]);
      }
    }
    int num = 0;
    while (!qs.empty()) {
      int temp = qs.front();
      qs.pop();
      if (!qs.empty()) {
        if (qs.front() == temp) {
          newboard[i][num] = temp * 2;
          maxnum = max(maxnum, newboard[i][num]);
          qs.pop();
          num++;
        } else {
          newboard[i][num] = temp;
          num++;
        }
      } else {
        newboard[i][num] = temp;
        maxnum = max(maxnum, newboard[i][num]);
        num++;
      }
    }
    for (int j = num; j < n; j++) {
      newboard[i][j] = 0;
    }
  }
  return;
}

void right() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (newboard[i][n - j - 1] != 0) {
        qs.push(newboard[i][n - j - 1]);
      }
    }
    int num = 0;
    while (!qs.empty()) {
      int temp = qs.front();
      qs.pop();
      if (!qs.empty()) {
        if (qs.front() == temp) {
          newboard[i][n - num - 1] = temp * 2;
          maxnum = max(maxnum, newboard[i][n - num - 1]);
          qs.pop();
          num++;
        } else {
          newboard[i][n - num - 1] = temp;
          num++;
        }
      } else {
        newboard[i][n - num - 1] = temp;
        maxnum = max(maxnum, newboard[i][n - num - 1]);
        num++;
      }
    }
    for (int j = num; j < n; j++) {
      newboard[i][n - j - 1] = 0;
    }
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  for (int ex = 0; ex < 1024; ex++) {
    vector<int> q;
    q.push_back(ex % 4);
    q.push_back((ex / 4) % 4);
    q.push_back((ex / 16) % 4);
    q.push_back((ex / 64) % 4);
    q.push_back((ex / 256) % 4);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        newboard[i][j] = board[i][j];
    for (int i = 0; i < 5; i++) {
      if (q[i] == 0) {
        //if (ex == 1023)cout << "a";
        up();
      }
      if (q[i] == 1) {
        //if (ex == 1023)cout << "b";
        down();
      }
      if (q[i] == 2) {
        //if (ex == 1023)cout << "c";
        left();
      }
      if (q[i] == 3) {
        //if (ex == 1023)cout << "d";
        right();
      }
    }
    // if (ex == 1023) {
    //   for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //       cout << newboard[i][j];
    //     }
    //     cout << endl;
    //   }
    // }
  }
  cout << maxnum;
}