#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
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
    
    int state1, state2;
    cout << "Case #" << tc << endl;
    cout << state1 << " " << state2 << endl;
  }
  return 0;
}