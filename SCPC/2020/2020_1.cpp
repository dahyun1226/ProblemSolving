#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    int k;
    vector<int> a, b;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      int puta;
      cin >> puta;
      a.push_back(puta);
    }
    for (int i = 0; i < n; i++) {
      int putb;
      cin >> putb;
      b.push_back(putb);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> answervec;
    for (int i = 0; i < k; i++) {
      answervec.push_back(a[i] + b[k - i - 1]);
    }
    sort(answervec.begin(), answervec.end());
    int answer = answervec[k - 1];
    cout << "Case #" << tc << endl;
    cout << answer << endl;
  }
  return 0;
}