#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
// 산업경영공학부
// 2016170813 강다현
// Queueing Theory를 풀어본다.

double power(double n, int m) {
  if (m == 0)
    return 1;
  if (m == 1)
    return n;
  else
    return n * power(n, m - 1);
}

double fact(double n) {
  if (n == 1 || n == 0)
    return 1;
  else
    return n * fact(n - 1);
}

int main() {
  double lambda, mu, law, server, hiringCost, delayCost, lq, totalCost, p0,
      allcn;
  cout << "lambda : ";
  cin >> lambda;
  cout << "mu : ";
  cin >> mu;
  cout << "server : ";
  cin >> server;
  delayCost = 8600;
  hiringCost = 16000;
  // cout << "DelayCost : ";
  // cin >> delayCost;
  // cout << "HiringCost : ";
  // cin >> hiringCost;
  law = lambda / (mu * server);
  allcn = 1;
  for (int i = 0; i < server; i++) {
    allcn += (power(lambda / mu, i) / (fact(i)));
  }
  allcn += power(lambda / mu, server) / (fact(server)) / (1 - law);
  p0 = 1 / allcn;
  lq = (p0 * power(lambda / mu, server) * law) /
       (fact(server) * (1 - law) * (1 - law));
  delayCost = delayCost *= lq;
  hiringCost = hiringCost *= server;
  totalCost = delayCost + hiringCost;
  cout << "p0 : " << p0 << endl;
  cout << "lq : " << lq << endl;
  cout << "DelayCost : " << delayCost << endl;
  cout << "HiringCost : " << hiringCost << endl;
  cout << "TotalCost : " << totalCost << endl;
  return 0;
}