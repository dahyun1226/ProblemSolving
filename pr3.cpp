#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int s[300001];
int n;
int k;
int main() {
  // ios_base ::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  for (int i = 1; i <= k; i++) {
    int answer = 0;
    int l, r;
    cin >> l >> r;
    queue<int> q;
    int g[1000001] = {
        0,
    };
    for (int j = l; j <= r; j++) {
      g[s[j]]++;
      if (g[s[j]] == 1) {
        q.push(s[j]);
      }
    }
    while (!q.empty()) {
      answer += q.front() * (1 + g[q.front()]) * g[q.front()] / 2;
      q.pop();
    }
    cout << answer << endl;
  }
}