#include <string>
#include <vector>
using namespace std;

long long dp[300001][2];
vector<int> children[300001];
int parent[300001];
vector<int> sales2;
void gdp(int root) {
  if (children[root].size() == 0) {
    dp[root][0] = 0;
    dp[root][1] = sales2[root - 1];
    return;
  }
  long long minchildrens = 0;
  for (int i = 0; i < children[root].size(); i++) {
    gdp(children[root][i]);
    minchildrens += min(dp[children[root][i]][0], dp[children[root][i]][1]);
  }
  dp[root][1] = minchildrens + sales2[root-1];
  dp[root][0] = __LONG_LONG_MAX__;
  for (int i = 0; i < children[root].size(); i++) {
    long long casei =
        minchildrens - min(dp[children[root][i]][0], dp[children[root][i]][1]) + dp[children[root][i]][1];
    dp[root][0] = min(dp[root][0], casei);
  }
  return;
}

int solution(vector<int> sales, vector<vector<int>> links) {
  sales2 = sales;
  for (int i = 0; i < links.size(); i++) {
    children[links[i][0]].push_back(links[i][1]);
    parent[links[i][1]] = links[i][0];
  }
  gdp(1);
  long long answer = min(dp[1][0],dp[1][1]);
  return answer;
}