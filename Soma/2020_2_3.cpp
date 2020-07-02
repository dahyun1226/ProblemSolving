/*
소프트웨어 마에스트로 3번: 채널링
라인스위핑 쉬운문제.
*/
#include <iostream>
#include <queue>
#include <vector>
#define mp make_pair
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<pair<int, int>> q;
  int ns[100000];
  int win[100000];
  int n, s, e;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> e;
    q.push(mp(-s, i));
    ns[i] = s;
    q.push(mp(-e, i));
  }
  int num = 0;
  int beforetime = 0;
  int sametimeattacknum = 0;
  while (!q.empty()) {
    int nowtime = -q.top().first;
    int player = q.top().second;
    q.pop();
    if (ns[player] == nowtime) {
      win[player] = num;
      num += 1;
    } else {
      num -= 1;
    }
  }
  for (int i = 0; i < n; i++)
    cout << win[i] << "\n";
  return 0;
}