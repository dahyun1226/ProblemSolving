#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dist[301][301];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
  fill(&dist[0][0], &dist[0][0] + 301 * 301, 700000000);
  for (int i = 0; i < fares.size(); i++) {
    dist[fares[i][0]][fares[i][1]] = fares[i][2];
    dist[fares[i][1]][fares[i][0]] = fares[i][2];
  }
  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  int answer = dist[s][a] + dist[s][b];
  for (int i = 1; i <= n; i++) {
    answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
  }
  cout << answer << endl;
  return answer;
}
