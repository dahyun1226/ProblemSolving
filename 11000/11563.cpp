/*
백준 온라인 저지
11563번 연돌이와 고잠녀
https://www.acmicpc.net/problem/11563
브루트 포스라는 힌트를 받았다.
2000개의 변 * 2000개의 변 해서 400만.
문제는 변과 변 사이의 거리를 구하는 것이다.
직선이 아닌 선분이라는 점이 중요한데, 직선과 직선이라면 경우의 수가 작은 반면,
선분이면 꽤나 존재한다. 근데 결국, 만나지 않는다면야 네개의 점 중 하나에서
나머지 선분까지의 거리가 된다. 선분에서 수선의 발까지 구할 수 있다면, 그게 가장
짧을 것이다. 아니면 그냥 점끼리의 거리이고. 만나는 지의 여부를 ccw로 구할 수
있는데, 0인 경우가 있다. 이 때 선분 사이에 사이에 있는지 확인해주면 된다. 수선의
발이 선분에 닿는지 여부도 구해야하는데, 그냥 둔각 확인 해주면 된다. 이 과정은
확실히 조금 더러운 것 같다. ps의 운명인가... 기하문제의 운명인가... 20200424
*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define mp make_pair
using namespace std;
pair<pair<double, double>, pair<double, double>> sline[2000];
pair<pair<double, double>, pair<double, double>> aline[2000];

double crossproduct(double ax, double ay, double bx, double by) {
  return ax * by - ay * bx;
}

int ccw(double ax, double ay, double bx, double by, double cx, double cy) {
  double answer = crossproduct(bx - ax, by - ay, cx - ax, cy - ay);
  if (answer > 0)
    return 1;
  else if (answer == 0)
    return 0;
  else
    return -1;
}

double distanceBetweenDot(pair<double, double> a, pair<double, double> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}

bool cross(int s, int a) {
  int s2a1ccw1 =
      ccw(sline[s].first.first, sline[s].first.second, sline[s].second.first,
          sline[s].second.second, aline[a].first.first, aline[a].first.second);
  int s2a1ccw2 = ccw(sline[s].first.first, sline[s].first.second,
                     sline[s].second.first, sline[s].second.second,
                     aline[a].second.first, aline[a].second.second);
  int crossConstraint1 = s2a1ccw1 * s2a1ccw2;
  int s1a2ccw1 =
      ccw(aline[s].first.first, aline[s].first.second, aline[s].second.first,
          aline[s].second.second, sline[a].first.first, sline[a].first.second);
  int s1a2ccw2 = ccw(aline[s].first.first, aline[s].first.second,
                     aline[s].second.first, aline[s].second.second,
                     sline[a].second.first, sline[a].second.second);
  int crossConstraint2 = s1a2ccw1 * s1a2ccw2;
  if (crossConstraint1 < 0 && crossConstraint2 < 0)
    return 1;
  if (crossConstraint1 == 0) {
    if (s2a1ccw1 == 0) {
      if ((sline[s].first.first <= aline[a].first.first &&
           sline[s].second.first >= aline[a].first.first) ||
          (sline[s].first.first >= aline[a].first.first &&
           sline[s].second.first <= aline[a].first.first))
        return 1;
    } else {
      if ((sline[s].first.first <= aline[a].second.first &&
           sline[s].second.first >= aline[a].second.first) ||
          (sline[s].first.first >= aline[a].second.first &&
           sline[s].second.first <= aline[a].second.first))
        return 1;
    }
  } else if (crossConstraint2 == 0) {
    if (s1a2ccw1 == 0) {
      if ((aline[a].first.first <= sline[s].first.first &&
           aline[a].second.first >= sline[s].first.first) ||
          (aline[a].first.first >= sline[s].first.first &&
           aline[a].second.first <= sline[s].first.first))
        return 1;
    } else {
      if ((aline[a].first.first <= sline[s].second.first &&
           aline[a].second.first >= sline[s].second.first) ||
          (aline[a].first.first >= sline[s].second.first &&
           aline[a].second.first <= sline[s].second.first))
        return 1;
    }
  }
  return 0;
}

double distanceBetweenDotAndLine(pair<double, double> d, int l,
                                 bool dotIsAnam) {
  if (dotIsAnam) {
    if (distanceBetweenDot(d, sline[l].first) *
                    distanceBetweenDot(d, sline[l].first) +
                distanceBetweenDot(sline[l].first, sline[l].second) *
                    distanceBetweenDot(sline[l].first, sline[l].second) >=
            distanceBetweenDot(d, sline[l].second) *
                distanceBetweenDot(d, sline[l].second) &&
        distanceBetweenDot(d, sline[l].second) *
                    distanceBetweenDot(d, sline[l].second) +
                distanceBetweenDot(sline[l].first, sline[l].second) *
                    distanceBetweenDot(sline[l].first, sline[l].second) >=
            distanceBetweenDot(d, sline[l].first) *
                distanceBetweenDot(d, sline[l].first))
      return abs(crossproduct(sline[l].first.first - d.first,
                              sline[l].first.second - d.second,
                              sline[l].second.first - d.first,
                              sline[l].second.second - d.second)) /
             distanceBetweenDot(sline[l].first, sline[l].second);
  } else {
    if (((distanceBetweenDot(d, aline[l].first) *
              distanceBetweenDot(d, aline[l].first) +
          distanceBetweenDot(aline[l].first, aline[l].second) *
              distanceBetweenDot(aline[l].first, aline[l].second)) >=
         (distanceBetweenDot(d, aline[l].second) *
          distanceBetweenDot(d, aline[l].second))) &&
        ((distanceBetweenDot(d, aline[l].second) *
              distanceBetweenDot(d, aline[l].second) +
          distanceBetweenDot(aline[l].first, aline[l].second) *
              distanceBetweenDot(aline[l].first, aline[l].second)) >=
         (distanceBetweenDot(d, aline[l].first) *
          distanceBetweenDot(d, aline[l].first))))
      return abs(crossproduct(aline[l].first.first - d.first,
                              aline[l].first.second - d.second,
                              aline[l].second.first - d.first,
                              aline[l].second.second - d.second)) /
             distanceBetweenDot(aline[l].first, aline[l].second);
  }
  return 100000;
}

double distanceBetweenLine(int s, int a) {
  if (cross(s, a))
    return 0;
  double distance = 100000;
  distance = min(distance, distanceBetweenDot(sline[s].first, aline[a].first));
  distance = min(distance, distanceBetweenDot(sline[s].second, aline[a].first));
  distance = min(distance, distanceBetweenDot(sline[s].first, aline[a].second));
  distance =
      min(distance, distanceBetweenDot(sline[s].second, aline[a].second));
  distance = min(distance, distanceBetweenDotAndLine(aline[a].first, s, 1));
  distance = min(distance, distanceBetweenDotAndLine(aline[a].second, s, 1));
  distance = min(distance, distanceBetweenDotAndLine(sline[s].first, a, 0));
  distance = min(distance, distanceBetweenDotAndLine(sline[s].second, a, 0));
  return distance;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> sline[i].first.first >> sline[i].first.second >>
        sline[i].second.first >> sline[i].second.second;
  for (int i = 0; i < m; i++)
    cin >> aline[i].first.first >> aline[i].first.second >>
        aline[i].second.first >> aline[i].second.second;
  double answer = 100000;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      {
        answer = min(answer, distanceBetweenLine(i, j));
        if (answer == 0)
          break;
      }
      if (answer == 0)
        break;
    }
  // cout<<answer;
  printf("%.10lf\n", answer);
  return 0;
}