/*
소프트웨어 마에스트로 2번: 최고의 팀
팀 만드는 거야 뭐 유니온 파인드를 사용하면 될 거고,
직사각형 만드는 거야 x최대최소 y최대최소 하면 쉽게 구할 수 있다.
10만의 관계 쿼리를 x최대최소 y최대최소를 계속 부모가 가지고 있고 누적해가는걸로
구하면 된다. 최대값은 long
*/
#include <iostream>
#include <vector>
using namespace std;

int parent[300001];
long maxx[300001];
long maxy[300001];
long minx[300001];
long miny[300001];

int find(int child) {
  if (parent[child] == child)
    return child;
  parent[child] = find(parent[child]);
  return parent[child];
}

long uni(int i, int j) { //작은게 부모로!
  int a = find(i);
  int b = find(j);
  if (a == b)
    return 0;
  if (a > b) {
    int tem = b;
    b = a;
    a = tem;
  }
  parent[b] = a;
  maxx[a] = max(maxx[b], maxx[a]);
  minx[a] = min(minx[b], minx[a]);
  maxy[a] = max(maxy[b], maxy[a]);
  miny[a] = min(miny[b], miny[a]);
  return (maxx[a] - minx[a]) * 2 + (maxy[a] - miny[a]) * 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long answer = 0;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    long x, y;
    cin >> x >> y;
    maxx[i] = x;
    minx[i] = x;
    maxy[i] = y;
    miny[i] = y;
  }
  for (int j = 0; j < m; j++) {
    int a, b;
    cin >> a >> b;
    answer = max(answer, uni(a, b));
  }
  cout << answer;
  return 0;
}