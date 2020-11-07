#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool order[20][91];

vector<string> solution(vector<string> orders, vector<int> course) {
  fill(&order[0][0], &order[0][0] + 20 * 91, 0);
  for (int i = 0; i < orders.size(); i++) {
    for (int j = 0; j < orders[i].size(); j++) {
      order[i][orders[i][j]] = 1;
    }
  }
  for (int i = 0; i < orders.size(); i++)
    for (int j = 1; j < orders.size(); j++) {
      if (j <= i)
        continue;
      vector<string> now;
      for (int k = 65; k <= 90; k++) {
        if (order[i][k] == order[j][k] && order[i][k] == 1) {
          char a = k;
          string put = "";
          put += a;
          now.push_back(put);
        }
      }
        for (int p = 0; p < course.size(); p++) {
          // now중 course[i]사이즈인것 넣기.
          if (now.size() >= course[p]) {
            for (int x = 0; x < now.size(); x++) {
              cout << now[x] << " ";
            }
            cout << endl;
          }
        }
    }
  vector<string> answer;
  sort(answer.begin(), answer.end());
  return answer;
}

// int main() {
//   int n, m;
//   cin >> n >> m;
//   vector<string> o;
//   vector<int> c;
//   for (int i = 0; i < n; i++) {
//     string put;
//     cin >> put;
//     o.push_back(put);
//   }
//   for (int i = 0; i < m; i++) {
//     int put;
//     cin >> put;
//     c.push_back(put);
//   }
//   vector<string> answer = solution(o, c);
//   for (int i = 0; i < answer.size(); i++) {
//     cout << answer[i] << endl;
//   }
// }